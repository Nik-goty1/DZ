#include <iostream>
#include <string>

#include "Public/Scene.h"
#include "Public/Actors/Character.h"
#include "Public/Actors/Chest.h" 
#include "Public/Item.h"

using namespace std;

int main()
{
    Scene scene;

    Item sword("Steel Sword");
    Item axe("Vibranium Battle Axe");
    Item food("Mivina");
    Item gold("Gold Coins");

    Character FallenGod("Fallen God", &scene);

    FallenGod.transform->Position.X = 0.0f;
    FallenGod.transform->Position.Y = 0.0f;

    FallenGod.getInventory().addItem(&sword);
    FallenGod.getInventory().addItem(&axe);
    FallenGod.getInventory().addItem(&food, 5);

    Chest* treasureChest = new Chest("Ancient Chest", 1.0f, 1.0f);
    treasureChest->inventory.addItem(&gold, 100); 
    scene.AddActor(treasureChest);

    cout << "--- Initial State ---" << endl;
    FallenGod.showInventory();
    cout << endl;

    cout << "--- Attempting to open chest (Distance: ~1.41) ---" << endl;
    FallenGod.interactWithChest("Ancient Chest");
    cout << endl;

    cout << "--- Moving away and trying again ---" << endl;
    FallenGod.transform->Position.X = 10.0f;
    FallenGod.transform->Position.Y = 10.0f;
    FallenGod.interactWithChest("Ancient Chest");
    cout << endl;

    cout << "--- Dropping item ---" << endl;
    FallenGod.dropItem("Steel Sword");
    cout << endl;

    FallenGod.showInventory();
    cout << endl;

    return 0;
}