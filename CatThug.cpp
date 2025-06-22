#include "CatThug.hpp"

CatThug::CatThug() : Creature() {
    setCategory(HUMANOID);
    setSchool(MYTH);
    weapons_ = {};
    notorietyLevel_ = ROOKIE;
    isWanted_ = false;
}

CatThug::CatThug(const std::string& name, Category category, School school, int health, int level, bool isHostile, std::vector<Weapon> weapons, Notoriety notoriety, bool isWanted) : Creature(name, category, school, health, level, isHostile) {
    weapons_ = weapons;
    notorietyLevel_ = notoriety;
    isWanted_ = isWanted;
}

void CatThug::setWeapons(const std::vector<Weapon>& weapons) {
    weapons_ = weapons;
}

std::vector<CatThug::Weapon> CatThug::getWeapons() const {
    return weapons_;
}

bool CatThug::addWeapon(const Weapon& weapon) {
    std::string upperWeaponName = "";

    for (char c : weapon.weaponName_) {
        upperWeaponName += c;
    }

    int curr_weapon = 0;

    while ((curr_weapon < weapons_.size())) {
        std::string upperCurrWeaponName = "";

        for (char c : weapons_[curr_weapon].weaponName_) {
            upperCurrWeaponName += std::toupper(c);
        }

        if (upperCurrWeaponName == upperWeaponName) {
            weapons_[curr_weapon].weaponDamage_ = std::max(weapons_[curr_weapon].weaponDamage_, weapon.weaponDamage_);
            return false;
        }

        curr_weapon += 1;

    }

    weapons_.push_back(weapon);
    return true;
}

bool CatThug::removeWeapon(const Weapon& weapon) {
    std::string upperWeaponName = "";

    for (char c : weapon.weaponName_) {
        upperWeaponName += std::toupper(c);
    }

    int curr_weapon = 0;

    while ((curr_weapon < weapons_.size())) {
        std::string upperCurrWeaponName = "";

        for (char c : weapons_[curr_weapon].weaponName_) {
            upperCurrWeaponName += std::toupper(c);
        }

        if (upperCurrWeaponName == upperWeaponName) {
            weapons_.erase(weapons_.begin() + curr_weapon);
            return true;
        }

        curr_weapon += 1;

    }

    return false;
}

void CatThug::setNotoriety(const Notoriety& notoriety) {
    notorietyLevel_ = notoriety;
}

std::string CatThug::getNotoriety() const {
    if (notorietyLevel_ == ROOKIE) {
        return "ROOKIE";
    } else if (notorietyLevel_ == THIEF) {
        return "THIEF";
    } else if (notorietyLevel_ == ENFORCER) {
        return "ENFORCER";
    } else {
        return "MOB_BOSS";
    }
}

void CatThug::setIsWanted(const bool& isWanted) {
    isWanted_ = isWanted;
}

bool CatThug::isWanted() const {
    return isWanted_;
}

void CatThug::display() const {
    std::cout << getName() << std::endl;
    std::cout << "Category: " << getCategory() << std::endl;
    std::cout << "School: " << getSchool() << std::endl;
    std::cout << "Weapons:" << std::endl;
    for (int i = 0; i < weapons_.size(); i++) {
        std::cout << weapons_[i].weaponName_ << ": " << weapons_[i].weaponDamage_ << ", ";
        if (weapons_[i].isRanged_ == true) {
           std::cout << "RANGED" << std::endl; 
        } else {
            std::cout << "NOT RANGED" << std::endl; 
        }
    }
    std::cout << "Notoriety: " << getNotoriety() << std::endl;
    std::cout << "Health: " << getHealth() << std::endl;
    std::cout << "Level: " << getLevel() << std::endl;
    
    if (isWanted_ == true) {
        std::cout << "Is Wanted: TRUE" << std::endl;
    } else {
        std::cout << "Is Wanted: FALSE" << std::endl;
    }

    if (isHostile() == true) {
        std::cout << "Hostile: TRUE" << std::endl;
    } else {
        std::cout << "Hostile: FALSE" << std::endl;
    }
}

bool operator==(const CatThug& catThug1, const CatThug& catThug2) {
    if ((catThug1.getName() == catThug2.getName()) && (catThug1.getNotoriety() == catThug2.getNotoriety()) && (catThug1.isWanted() == catThug2.isWanted())) {
        return true;
    }
    return false;
}