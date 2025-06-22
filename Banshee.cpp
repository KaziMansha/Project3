#include "Banshee.hpp"

Banshee::Banshee() : Creature() {
    setCategory(UNDEAD);
    setSchool(DEATH);
    spectralAura_ = RED;
    screamVolume_ = 1;
    fearInducing_ = false;
}

Banshee::Banshee(const std::string& name, Category category, School school, int health, int level, bool isHostile, Aura spectralAura, int screamVolume, bool fearInducing) : Creature(name, category, school, health, level, isHostile) {
    spectralAura_ = spectralAura;
    screamVolume_ = screamVolume;
    fearInducing_ = fearInducing;
}

void Banshee::setAura(const Aura& spectralAura) {
    spectralAura_ = spectralAura;
}

std::string Banshee::getAura() const {
    if (spectralAura_ == RED) {
        return "RED";
    } else if (spectralAura_ == BLUE) {
        return "BLUE";
    } else if (spectralAura_ == GRAY) {
        return "GRAY";
    } else {
        return "GREEN";
    }
}

bool Banshee::setScreamVolume(const int& screamVolume) {
    if (screamVolume <= 0) {
        return false;
    }

    screamVolume_ = screamVolume;
    return true;
}

int Banshee::getScreamVolume() const {
    return screamVolume_;
}

void Banshee::setFearInducing(const bool& fearInducing) {
    fearInducing_ = fearInducing;
}

bool Banshee::isFearInducing() const {
    return fearInducing_;
}

void Banshee::display() const {
    std::cout << getName() << std::endl;
    std::cout << "Category: " << getCategory() << std::endl;
    std::cout << "School: " << getSchool() << std::endl;
    std::cout << "Aura Color: " << getAura() << std::endl;
    std::cout << "Scream Level: " << getScreamVolume() << std::endl;
    std::cout << "Health: " << getHealth() << std::endl;
    std::cout << "Level: " << getLevel() << std::endl;
    
    if (fearInducing_ == true) {
        std::cout << "Fear Inducing: TRUE" << std::endl;
    } else {
        std::cout << "Fear Inducing: FALSE" << std::endl;
    }

    if (isHostile() == true) {
        std::cout << "Hostile: TRUE" << std::endl;
    } else {
        std::cout << "Hostile: FALSE" << std::endl;
    }
}

bool operator==(const Banshee& banshee1, const Banshee& banshee2) {
    if ((banshee1.getName() == banshee2.getName()) && (banshee1.getAura() == banshee2.getAura()) && (banshee1.isFearInducing() == banshee2.isFearInducing())) {
        return true;
    }
    return false;
}