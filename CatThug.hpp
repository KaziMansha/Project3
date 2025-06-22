#ifndef CATTHUG_H
#define CATTHUG_H

#include "Creature.hpp"
#include <string>
#include <vector>
#include <algorithm>
#include <cctype>

class CatThug : public Creature {

    public:

        struct Weapon {
            std::string weaponName_;
            int weaponDamage_;
            bool isRanged_;
        };

        enum Notoriety {ROOKIE, THIEF, ENFORCER, MOB_BOSS};

        CatThug();

        CatThug(const std::string& name, Category category = HUMANOID, School school = MYTH, int health = 1, int level = 1, bool isHostile = false, std::vector<Weapon> weapons = {}, Notoriety notoriety = ROOKIE, bool isWanted = false);
    
        void setWeapons(const std::vector<Weapon>& weapons);

        std::vector<Weapon> getWeapons() const;

        bool addWeapon(const Weapon& weapon);

        bool removeWeapon(const Weapon& weapon);

        void setNotoriety(const Notoriety& notoriety);

        std::string getNotoriety() const;

        void setIsWanted(const bool& isWanted);

        bool isWanted() const;

        virtual void display() const override;

        friend bool operator==(const CatThug& catThug1, const CatThug& catThug2);

    private:
        std::vector<Weapon> weapons_;
        Notoriety notorietyLevel_;
        bool isWanted_;
};

#endif