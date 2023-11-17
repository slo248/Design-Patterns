#include <bits/stdc++.h>
using namespace std;

class MilkTeaComponent {
   public:
    MilkTeaComponent(int cost) : mCost(cost) {}
    virtual ~MilkTeaComponent() {}
    virtual int getCost() { return mCost; }

   private:
    int mCost;
};

class MilkTea : public MilkTeaComponent {
   public:
    MilkTea() : MilkTeaComponent(0) {}
    ~MilkTea() { cout << "Milk tea is removed!" << endl; };
};

class MilkTeaDecorator : public MilkTeaComponent {
   public:
    MilkTeaDecorator(MilkTeaComponent* wrappee, int cost)
        : mWrappee(wrappee), MilkTeaComponent(cost) {}
    ~MilkTeaDecorator() { delete mWrappee; }
    int getCost() { return mWrappee->getCost(); }

   private:
    MilkTeaComponent* mWrappee;
};

class Default : public MilkTeaDecorator {
   public:
    Default(MilkTeaComponent* wrappee) : MilkTeaDecorator(wrappee, 30000) {
        cout << "Default type is created!";
        cout << " + " << MilkTeaComponent::getCost() << " VND" << endl;
    }
    int getCost() {
        // doing something else
        return MilkTeaComponent::getCost() + MilkTeaDecorator::getCost();
    }
};

class Bubble : public MilkTeaDecorator {
   public:
    Bubble(MilkTeaComponent* wrappee, int cost)
        : MilkTeaDecorator(wrappee, cost) {}
    virtual int getCost() = 0;
};

class WhiteBubble : public Bubble {
   public:
    WhiteBubble(MilkTeaComponent* wrappee) : Bubble(wrappee, 7000) {
        cout << "White bubble is added!";
        cout << " + " << MilkTeaComponent::getCost() << " VND" << endl;
    }
    ~WhiteBubble() { cout << "White bubble is removed!" << endl; }
    int getCost() {
        // doing something else
        return MilkTeaComponent::getCost() + MilkTeaDecorator::getCost();
    }
};

class BlackBubble : public Bubble {
   public:
    BlackBubble(MilkTeaComponent* wrappee) : Bubble(wrappee, 10000) {
        cout << "Black bubble is added!";
        cout << " + " << MilkTeaComponent::getCost() << " VND" << endl;
    }
    ~BlackBubble() { cout << "Black bubble is removed!" << endl; }
    int getCost() {
        // doing something else
        return MilkTeaComponent::getCost() + MilkTeaDecorator::getCost();
    }
};

class EggPudding : public MilkTeaDecorator {
   public:
    EggPudding(MilkTeaComponent* wrappee) : MilkTeaDecorator(wrappee, 5000) {
        cout << "Egg pudding is added!";
        cout << " + " << MilkTeaComponent::getCost() << " VND" << endl;
    }
    ~EggPudding() { cout << "Egg pudding is removed!" << endl; }
    int getCost() {
        // doing something else
        return MilkTeaComponent::getCost() + MilkTeaDecorator::getCost();
    }
};

class FruitPudding : public MilkTeaDecorator {
   public:
    FruitPudding(MilkTeaComponent* wrappee) : MilkTeaDecorator(wrappee, 6000) {
        cout << "Fruit padding is added!";
        cout << " + " << MilkTeaComponent::getCost() << " VND" << endl;
    }
    ~FruitPudding() { cout << "Fruit pudding is removed!" << endl; }
    int getCost() {
        // doing something else
        return MilkTeaComponent::getCost() + MilkTeaDecorator::getCost();
    }
};

int main() {
    MilkTeaComponent* a = new Default(new MilkTea);
    cout << "The list of available toppings:" << endl;
    cout << "1. White bubble" << endl;
    cout << "2. Black bubble" << endl;
    cout << "3. Egg pudding" << endl;
    cout << "4. Fruit pudding" << endl;
    cout << "Enter the list that you want (end with 0): ";
    bool flag = true;
    while (flag) {
        int t;
        cin >> t;
        switch (t) {
            case 0:
                flag = false;
                break;
            case 1:
                a = new WhiteBubble(a);
                break;
            case 2:
                a = new BlackBubble(a);
                break;
            case 3:
                a = new EggPudding(a);
                break;
            case 4:
                a = new FruitPudding(a);
                break;
            default:
                cout << "Topping with ID = " << t << " is unknown!" << endl;
                break;
        }
    }
    cout << "Total: " << a->getCost() << " VND" << endl;
    delete a;
    return 0;
}
