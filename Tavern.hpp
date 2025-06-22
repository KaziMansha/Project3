#ifndef TAVERN_H
#define TAVERN_H

#include "Creature.hpp"
#include "MagicalBag.hpp"
#include <iostream>
#include <iomanip>
#include <cmath>

class Tavern : public MagicalBag<Creature*> {

    public:
        Tavern();

        bool enterTavern(Creature* newCreature);
        bool exitTavern(Creature* oldCreature);

        int getLevelSum() const;
        int getCreatureCount() const;
        int getHostileCount() const;
        double calculateHostilePercentage() const;

        int tallyCategory(const std::string& category) const;
        int tallySchool(const std::string& category) const;

        int releaseCreaturesBelowLevel(int level = 0);
        int releaseCreaturesOfCategory(const std::string& category = "ALL");
        int releaseCreaturesOfSchool(const std::string& school = "ALL");

        void tavernReport() const;
        void displayCreatures() const;

    private:
        int totalLevel_;
        int creatureCount_;
};

#endif