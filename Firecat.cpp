#include "Firecat.hpp"

Firecat::Firecat() : Creature() {
    setCategory(ANIMAL);
    setSchool(FIRE);
    flameColor_ = ORANGE;
    flameIntensity_ = 1;
    arsonist_ = false;
}

Firecat::Firecat(const std::string& name, Category category, School school, int health, int level, bool isHostile, FlameColor flameColor, int flameIntensity, bool arsonist) : Creature(name, category, school, health, level, isHostile) {
    flameColor_ = flameColor;
    flameIntensity_ = flameIntensity;
    arsonist_ = arsonist;
}

void Firecat::setFlameColor(const FlameColor& flameColor) {
    flameColor_ = flameColor;
}

std::string Firecat::getFlameColor() const {
    if (flameColor_ == RED) {
        return "RED";
    } else if (flameColor_ == ORANGE) {
        return "ORANGE";
    } else if (flameColor_ == BLUE) {
        return "BLUE";
    } else {
        return "WHTIE";
    }
}

bool Firecat::setFlameIntensity(const int& flameIntensity) {
    if (flameIntensity <= 0) {
        return false;
    }
    flameIntensity_ = flameIntensity;
    return true;
}

int Firecat::getFlameIntensity() const {
    return flameIntensity_;
}

void Firecat::setArsonist(const bool& arsonist) {
    arsonist_ = arsonist;
}

bool Firecat::isArsonist() const {
    return arsonist_;
}

void Firecat::display() const {
    std::cout << getName() << std::endl;
    std::cout << "Category: " << getCategory() << std::endl;
    std::cout << "School: " << getSchool() << std::endl;
    std::cout << "Flame Color: " << getFlameColor() << std::endl;
    std::cout << "Flame Intensity: " << getFlameIntensity() << std::endl;
    std::cout << "Health: " << getHealth() << std::endl;
    std::cout << "Level: " << getLevel() << std::endl;
    
    if (arsonist_ == true) {
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

bool operator==(const Firecat& firecat1, const Firecat& firecat2) {
    if ((firecat1.getName() == firecat2.getName()) && (firecat1.getFlameColor() == firecat2.getFlameColor()) && (firecat1.isArsonist() == firecat2.isArsonist())) {
        return true;
    }
    return false;
}