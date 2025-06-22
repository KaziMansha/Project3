#include "Tavern.hpp"

Tavern::Tavern() {
    totalLevel_ = 0;
    creatureCount_ = 0;
}

bool Tavern::enterTavern(Creature* newCreature) {
    if (!contains(newCreature)) {
        if (add(newCreature)) {
            totalLevel_ += newCreature->getLevel();
            creatureCount_++;
            return true;
        }
    }
    return false;
}

bool Tavern::exitTavern(Creature* oldCreature) {
    if (remove(oldCreature)) {
        totalLevel_ -= oldCreature->getLevel();
        creatureCount_--;
        return true;
    }
    return false;
}

int Tavern::getLevelSum() const {
    return totalLevel_;
}

int Tavern::getCreatureCount() const {
    return creatureCount_;
}

int Tavern::getHostileCount() const {
    int count = 0;
    for (int i = 0; i < item_count_; i++) {
        if (items_[i]->isHostile()) {
            count++;
        }
    }
    return count;
}

double Tavern::calculateHostilePercentage() const {
    if (creatureCount_ == 0) return 0.0;
    double percent = (static_cast<double>(getHostileCount()) / creatureCount_) * 100;
    return std::round(percent * 100) / 100;
}

int Tavern::tallyCategory(const std::string& category) const {
    int count = 0;
    for (int i = 0; i < item_count_; i++) {
        if (items_[i]->getCategory() == category) {
            count++;
        }
    }
    return count;
}

int Tavern::tallySchool(const std::string& school) const {
    int count = 0;
    for (int i = 0; i < item_count_; i++) {
        if (items_[i]->getSchool() == school) {
            count++;
        }
    }
    return count;
}

int Tavern::releaseCreaturesBelowLevel(int level) {
    if (level <= 0) return 0;
    int removed = 0;
    for (int i = 0; i < item_count_; i++) {
        if (items_[i]->getLevel() < level) {
            totalLevel_ -= items_[i]->getLevel();
            remove(items_[i]);
            creatureCount_--;
            removed++;
        }
    }
    return removed;
}

int Tavern::releaseCreaturesOfCategory(const std::string& category) {
    if (category == "ALL") {
        int removed = creatureCount_;
        clear();
        creatureCount_ = 0;
        totalLevel_ = 0;
        return removed;
    }

    int removed = 0;
    for (int i = 0; i < item_count_; i++) {
        if (items_[i]->getCategory() == category) {
            totalLevel_ -= items_[i]->getLevel();
            remove(items_[i]);
            creatureCount_--;
            removed++;
        }
    }
    return removed;
}

int Tavern::releaseCreaturesOfSchool(const std::string& school) {
    if (school == "ALL") {
        int removed = creatureCount_;
        clear();
        creatureCount_ = 0;
        totalLevel_ = 0;
        return removed;
    }

    int removed = 0;
    for (int i = 0; i < item_count_; i++) {
        if (items_[i]->getSchool() == school) {
            totalLevel_ -= items_[i]->getLevel();
            remove(items_[i]);
            creatureCount_--;
            removed++;
        }
    }
    return removed;
}

void Tavern::tavernReport() const {
    std::cout << "CATEGORY COUNT:\n";
    std::cout << "MAGICAL: " << tallyCategory("MAGICAL") << "\n";
    std::cout << "UNDEAD: " << tallyCategory("UNDEAD") << "\n";
    std::cout << "ANIMAL: " << tallyCategory("ANIMAL") << "\n";
    std::cout << "HUMANOID: " << tallyCategory("HUMANOID") << "\n";
    std::cout << "CATEGORY_UNKNOWN: " << tallyCategory("CATEGORY_UNKNOWN") << "\n\n";

    std::cout << "SCHOOL COUNT:\n";
    std::cout << "FIRE: " << tallySchool("FIRE") << "\n";
    std::cout << "ICE: " << tallySchool("ICE") << "\n";
    std::cout << "STORM: " << tallySchool("STORM") << "\n";
    std::cout << "LIFE: " << tallySchool("LIFE") << "\n";
    std::cout << "MYTH: " << tallySchool("MYTH") << "\n";
    std::cout << "DEATH: " << tallySchool("DEATH") << "\n";
    std::cout << "SCHOOL_UNKNOWN: " << tallySchool("SCHOOL_UNKNOWN") << "\n\n";

    std::cout << "AVERAGE LEVEL: ";
    if (creatureCount_ > 0)
        std::cout << totalLevel_ / creatureCount_ << "\n";
    else
        std::cout << "0\n";

    std::cout << std::fixed << std::setprecision(2);
    std::cout << "HOSTILE: " << calculateHostilePercentage() << "\n";
}

void Tavern::displayCreatures() const {
    for (int i = 0; i < item_count_; ++i) {
        items_[i]->display();
        std::cout << "-------------------------\n";
    }
}