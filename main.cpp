#include "Tavern.hpp"
#include "Creature.hpp"
#include "Banshee.hpp"
#include "Firecat.hpp"
#include "CatThug.hpp"

int main() {
    // Create some creatures
    Creature* banshee = new Banshee("Wailin Wanda", Creature::UNDEAD, Creature::STORM, 20, 4, true);
    Creature* firecat = new Firecat("Blaze", Creature::ANIMAL, Creature::FIRE, 15, 2, false);
    Creature* thug = new CatThug("Scratch", Creature::HUMANOID, Creature::MYTH, 25, 3, true);
    Creature* mystery = new Banshee("Morg", Creature::MAGICAL, Creature::DEATH, 30, 5, false);
    
    // Create Tavern
    Tavern tavern;

    // Enter creatures into the tavern
    tavern.enterTavern(banshee);
    tavern.enterTavern(firecat);
    tavern.enterTavern(thug);
    tavern.enterTavern(mystery);

    std::cout << "\n--- Tavern Report ---\n";
    tavern.tavernReport();

    std::cout << "\n--- Displaying Creatures ---\n";
    tavern.displayCreatures();

    std::cout << "\n--- Hostile Count: " << tavern.getHostileCount() << "\n";
    std::cout << "--- Hostile Percentage: " << tavern.calculateHostilePercentage() << "%\n";

    std::cout << "\n--- Removing creatures with level < 4 ---\n";
    tavern.releaseCreaturesBelowLevel(4);
    tavern.tavernReport();

    std::cout << "\n--- Removing creatures of category UNDEAD ---\n";
    tavern.releaseCreaturesOfCategory("UNDEAD");
    tavern.tavernReport();

    std::cout << "\n--- Removing all creatures of school DEATH ---\n";
    tavern.releaseCreaturesOfSchool("DEATH");
    tavern.tavernReport();

    std::cout << "\n--- Final Tavern Creatures ---\n";
    tavern.displayCreatures();

    // Clean up dynamic memory
    delete banshee;
    delete firecat;
    delete thug;
    delete mystery;

    return 0;
}
