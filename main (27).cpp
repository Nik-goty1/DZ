#include <iostream>
#include <string>
using namespace std;

class character {
    string name;
    float health;
    float max_health;
    bool is_dead;

    void UpdateIsDead(){
        this->is_dead = getHealth() <= 0;
        if (is_dead) {
            cout << this->name << " has died!" << endl;
        }
    }

public:
    character(string name, float health) {
        this->name = name;
        this->health = health;
        this->max_health = health; 
        UpdateIsDead();
    }

    void getinfo() {
        cout << "Name: " << name << "; Health: " << health << "/" << max_health << ";\n";
    }

    float getHealth() {
        return health;
    }

    void setHealth(float health){
        this->health = health;
        if (this->health < 0) {
            this->health = 0;
        }
        if (this->health > max_health) {
            this->health = max_health;
        }
        UpdateIsDead();
    }

    void heal(float heal_amount) {
        setHealth(getHealth() + heal_amount);
    }

    void damage(float damage_amount) {
        setHealth(getHealth() - damage_amount);
    }

    string getName() {
        return name;
    }
};

class warrior : public character {
    float strength;
public:
    warrior(string name, float health, float strength) : character(name, health) {
        this->strength = strength;
    }

    void attack(character* victim) {
        victim->damage(strength);
    }

    float getDamage() {
        return strength;
    }

    void getinfo() {
        cout << "Name: " << getName() << "; Health: " << getHealth() << "; Strength: " << getDamage() << ";\n";
    }
};

class Zealot : public character {
    float mana;
public:
    Zealot(string name, float health, float mana) : character(name, health) {
        this->mana = mana;
    }

    void heal(character* target, float heal_amount) {
        if (heal_amount > mana) {
            cout << "Not enough mana!" << endl;
            return;
        }
        target->heal(heal_amount);
        this->mana -= heal_amount;
    }

    float getMana() {
        return mana;
    }

    void getinfo() {
        cout << "Name: " << getName() << "; Health: " << getHealth() << "; Mana: " << getMana() << ";\n";
    }
};

class Necromancer: public Zealot{
    
public:

    Necromancer(string name, float health, float mana): Zealot(name, health, mana){}
  
  void revive(character* target){
      if (target->getHealth() <= 0){
          (*target).setHealth(15);
      }
  }
    
};

class Thief: public warrior{
    
public:
    Thief(string name, float health, float strength): warrior(name, health, strength){
        strength /= 2;
    }
    
    void stealLife(character* target) {
        float damage_dealt = getDamage();
        attack(target);
        heal(damage_dealt * 0.5);
    }
    
};

int main() {
    warrior w1("uno", 100, 150);
    warrior w2("dos", 50, 30);
    Zealot zealot1("tres", 100, 10);
    Necromancer necromancer("Necromancer", 100, 16);
    Thief thief("Thief", 100, 42);

    w1.getinfo();
    w2.getinfo();
    cout << "--------------------" << endl;

    w1.attack(&w2);
    w2.attack(&w1);

    w1.getinfo();
    w2.getinfo();
    cout << "--------------------" << endl;

    zealot1.getinfo();
    zealot1.heal(&w1, 5);
    
    w1.getinfo();
    cout << "--------------------" << endl;
    
    zealot1.getinfo();
    cout << "==========================" << endl;
    
    necromancer.getinfo();
    w2.getinfo();
    necromancer.revive(&w2);
    w2.getinfo();
    cout << "==========================" << endl;
    
    thief.getinfo();
    thief.damage(51);
    thief.getinfo();
    necromancer.getinfo();
    thief.stealLife(&necromancer);
    necromancer.getinfo();
    thief.getinfo();

    return 0;
}



/*

1. Клас - це як шаблон за яким потім буде створений екземпляр - конкретний приклад.
2. Об'єкт класу - це конкретний приклад якогось класу.Можно сказати похідна від класу
3. Конструктор - це такий метод класа який викликається автоматично при створенні об'єкту класу
4. Використовується для визначення подальших даних як недоступні
5. Використовується для визначення подальших даних як доступні
6. Успадкування - це можливість створювати дочірні класи на основі батьківських.Дочірні класи мають доступ до всіх полів класу
7. Це приклад успадкування.Warrior дочірній,а Character батьківський
8. Вони використовуються для отримання доступу к даним з приватних полів класу
9. Дає змогу доступитися до полів класу через їх вказівник
10. Інкапсуляція використовуються для захисту потрібних розробнику полів класу
11. Він вказує на поточний екземпляр класу
*/