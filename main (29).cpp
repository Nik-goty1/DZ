#include <iostream>
#include <string>

using namespace std;

class Item{
    string Name;
public:
    Item(string name): Name(name) {}

    string getName(){
        return Name;
    }
};

class ItemSlot{
    Item* item = nullptr;
public:
    void setItem(Item* newItem){
        item = newItem;
    }

    Item* getItem(){
        return item;
    }

    bool isEmpty(){
        return item == nullptr;
    }
};

class Actor{
public:
    void info(){
        cout << "Actor" << endl;
    }
};

class Character: public Actor{
    class Inventory{
        int slots_num;
        ItemSlot* slots;

    public:
        Inventory(int num = 5){
            slots_num = num;
            slots = new ItemSlot[slots_num];
        }

        ~Inventory(){
            delete[] slots;
        }

        bool addItem(Item* item){
            for (int i = 0; i < slots_num; i++){
                if (slots[i].isEmpty()){
                    slots[i].setItem(item);
                    return true;
                }
            }
            return false;
        }

        void showInventory(){
            cout << "\nInventory:" << endl;
            for (int i = 0; i < slots_num; i++){
                if (!slots[i].isEmpty()){
                    cout << "Slot " << i << ": "
                         << slots[i].getItem()->getName() << endl;
                } else{
                    cout << "Slot " << i << ": empty" << endl;
                }
            }
        }
    };

    string name;
    float health;
    Inventory inventory;

public:
    Character(string name, float health): name(name), health(health) {}

    void pickItem(Item* item){
        if (inventory.addItem(item)){
            cout << name << " picked up " << item->getName() << endl;
        } 
        else{
            cout << name << " inventory is full!" << endl;
        }
    }

    void showInventory(){
        inventory.showInventory();
    }

    void info(){
        cout << "Character: " << name << " | Health: " << health << endl;
    }
};

class DroppedItem: public Actor{
    Item item;

public:
    DroppedItem(string name): item(name) {}

    Item* getItem(){
        return &item;
    }

    void info(){
        cout << "Dropped item: " << item.getName() << endl;
    }
};

class Scene{
    Actor** actors;
    int count;
    int capacity;

public:
    Scene(int cap = 10){
        capacity = cap;
        count = 0;
        actors = new Actor*[capacity];
    }

    ~Scene(){
        delete[] actors;
    }

    void AddActor(Actor* actor){
        if (count < capacity) {
            actors[count++] = actor;
        }
    }

    void showScene(){
        cout << "\n--- Scene ---" << endl;
        for (int i = 0; i < count; i++){
            actors[i]->info(); 
        }
    }
};

int main(){
    Item sword("Legendary Sword");
    Item shield("Epic Shield");
    Item hummer("Common Hummer");

    Character hero("Hero", 100);
    Character king("King", 200);

    DroppedItem dropped("Ground Sword");

    Scene scene;
    scene.AddActor(&hero);
    scene.AddActor(&king);
    scene.AddActor(&dropped);

    hero.pickItem(&sword);
    king.pickItem(&shield);
    king.pickItem(&hummer);

    hero.showInventory();
    king.showInventory();

    cout << "\nManual info:" << endl;
    hero.info();
    king.info();
    dropped.info();

    scene.showScene(); 

    return 0;
}