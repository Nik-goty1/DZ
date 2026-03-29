#include "../../Public/Actors/Character.h"

#include "../../Public/Scene.h"
#include "../../Public/Actors/DroppedItem.h"

Character::Character(std::string name, Scene* scene) : Actor(name), inventory(this)
{
    this->scene = scene;
}

void Character::showInventory()
{
    std::cout << name << "'s inventory: " << '\n';
    inventory.showInventory();
}

void Character::dropItem(const std::string& name, int quantity)
{
    Item* item;

    if (inventory.dropItem(name, item, quantity))
    {
        scene->AddActor(new DroppedItem(item, quantity));
        std::cout << "Dropped " << name << " x" << quantity << '\n';
    }
    else
    {
        std::cout << "No such item to drop!" << '\n';
    }
}

void Character::pickUpItem(const std::string& name)
{
    Actor** actors = scene->getActors();
    int count = scene->getActorsCount();

    for (int i = 0; i < count; i++)
    {
        if (actors[i]->getType() == "DroppedItem")
        {
            DroppedItem* dropped = (DroppedItem*)actors[i];

            if (dropped->item->getName() == name)
            {
                inventory.addItem(dropped->item, dropped->quantity);

                scene->RemoveActor(i);


                std::cout << "Picked up " << name << " x" << dropped->quantity << '\n';
                return;
            }
        }
    }
    
    std::cout << "No such item on the ground!" << '\n';
}

void Character::interactWithChest(const std::string& chestName)
{
    Actor** actors = scene->getActors();
    int count = scene->getActorsCount();

    for (int i = 0; i < count; i++)
    {
        if (actors[i]->getName() == chestName)
        {
            Chest* chest = dynamic_cast<Chest*>(actors[i]);
            if (chest)
            {
                float dx = transform->Position.X - chest->transform->Position.X;
                float dy = transform->Position.Y - chest->transform->Position.Y;
                float distance = std::sqrt(dx * dx + dy * dy);

                if (distance < 1.5f)
                {
                    std::cout << name << " opened the chest: " << chestName << '\n';
                    return;
                }
                else
                {
                    std::cout << "Chest is too far! Distance: " << distance << '\n';
                    return;
                }
            }
        }
    }
    std::cout << "Chest not found!" << '\n';
}
