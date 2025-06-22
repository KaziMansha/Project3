#ifndef BANSHEE_H
#define BANSHEE_H

#include "Creature.hpp"
#include <string>

class Banshee : public Creature {

    public:
        enum Aura {RED, BLUE, GRAY, GREEN};

        Banshee();

        Banshee(const std::string& name, Category category = UNDEAD, School school = DEATH, int health = 1, int level = 1, bool isHostile = false, Aura spectralAura = RED, int screamVolume = 1, bool fearInducing = false);

        void setAura(const Aura& spectralAura);

        std::string getAura() const;

        bool setScreamVolume(const int& screamVolune);

        int getScreamVolume() const;

        void setFearInducing(const bool& fearInducing);

        bool isFearInducing() const;

        virtual void display() const override;

        friend bool operator==(const Banshee& banshee1, const Banshee& banshee2);

    private:
        Aura spectralAura_;
        int screamVolume_;
        bool fearInducing_;
};

#endif