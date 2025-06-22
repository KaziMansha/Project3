#ifndef FIRECAT_H
#define FIRECAT_H

#include "Creature.hpp"
#include <string>
#include <iostream>

class Firecat : public Creature {

    public:
        enum FlameColor {RED, ORANGE, BLUE, WHITE};

        Firecat();

        Firecat(const std::string& name, Category category = ANIMAL, School school = FIRE, int health = 1, int level = 1, bool isHostile = false, FlameColor flameColor = ORANGE, int flameIntensity = 1, bool arsonist = false);

        void setFlameColor( const FlameColor& flameColor);

        std::string getFlameColor() const;

        bool setFlameIntensity(const int& flameIntensity);

        int getFlameIntensity() const;

        void setArsonist(const bool& arsonist);

        bool isArsonist() const;

        virtual void display() const override;

        friend bool operator==(const Firecat& firecat1, const Firecat& firecat2);
        
    private:
        FlameColor flameColor_;
        int flameIntensity_;
        bool arsonist_;
};

#endif