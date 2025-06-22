#include "Creature.hpp"

Creature::Creature() {
    name_ = "NAMELESS";
    category_ = CATEGORY_UNKNOWN;
    school_ = SCHOOL_UNKNOWN;
    health_ = 1;
    level_ = 1;
    isHostile_ = false;
}

Creature::Creature(const std::string& name, Category category, School school, int health, int level, bool isHostile) {
    setName(name);
    setCategory(category);
    setSchool(school);
    if (!setHealth(health)) {
        health_ = 1;
    }
    if (!setLevel(level)) {
        level_ = 1;
    }
    setHostility(isHostile);
}

bool Creature::setName(const std::string& name) {
    for (char c : name) {
        if (!std::isalpha(c) && c != ' ') {
            return false;
        }
    }

    std::string uppercaseName;
    for (char c : name) {
        if (std::isalpha(c)) {
            uppercaseName += std::toupper(c);
        } else {
            uppercaseName += c;
        }
    }

    name_ = uppercaseName;
    return true;
}

std::string Creature::getName() const {
    return name_;
}

void Creature::setCategory(const Category& category) {
    category_ = category;
}

std::string Creature::getCategory() const {
    if (category_ == MAGICAL) {
        return "MAGICAL";
    } else if (category_ == UNDEAD) {
        return "UNDEAD";
    } else if (category_ == ANIMAL) {
        return "ANIMAL";
    } else if (category_ == HUMANOID) {
        return "HUMANOID";
    } else {
        return "CATEGORY_UNKNOWN";
    }
}

void Creature::setSchool(const School& school) {
    school_ = school;
}

std::string Creature::getSchool() const {
    if (school_ == FIRE) {
        return "FIRE";
    } else if (school_ == ICE) {
        return "ICE";
    } else if (school_ == STORM) {
        return "STORM";
    } else if (school_ == LIFE) {
        return "LIFE";
    } else if (school_ == MYTH) {
        return "MYTH";
    } else if (school_ == DEATH) {
        return "DEATH";
    } else {
        return "SCHOOL_UNKNOWN";
    }
}

bool Creature::setHealth(const int& health) {
     if (health <= 0) {
        return false;
     }

     health_ = health;
     return true;
}

int Creature::getHealth() const {
    return health_;
}

bool Creature::setLevel(const int& level) {
    if (level <= 0) {
        return false;
    }

    level_ = level;
    return true;
}

int Creature::getLevel() const {
    return level_;
}

void Creature::setHostility(const bool& isHostile) {
    isHostile_ = isHostile;
}

bool Creature::isHostile() const {
    return isHostile_;
}