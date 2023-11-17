#include <bits/stdc++.h>
using namespace std;

class MilkTeaComponent {
   public:
    virtual ~MilkTeaComponent() {}
    virtual int getCost() = 0;
};

class MilkTea : public MilkTeaComponent {
   public:
    ~MilkTea() { cout << "Milk tea is removed!" << endl; };
    int getCost() { return 30000; }
};

class MilkTeaDecorator : public MilkTeaComponent {
   public:
    MilkTeaDecorator(MilkTeaComponent* wrappee) : mWrappee(wrappee) {}
    ~MilkTeaDecorator() { delete mWrappee; }
    virtual int getCost() = 0;

   protected:
    MilkTeaComponent* mWrappee;
};

class Default : public MilkTeaDecorator {
   public:
    Default(MilkTeaComponent* wrappee) : MilkTeaDecorator(wrappee) {
        cout << "Default type is created!" << endl;
    }
    int getCost() { return mWrappee->getCost(); }
};

class Bubble : public MilkTeaDecorator {
   public:
    Bubble(MilkTeaComponent* wrappee) : MilkTeaDecorator(wrappee) {}
    virtual int getCost() = 0;
};

class WhiteBubble : public Bubble {
   public:
    WhiteBubble(MilkTeaComponent* wrappee) : Bubble(wrappee) {
        cout << "White bubble is added!" << endl;
    }
    ~WhiteBubble() { cout << "White bubble is removed!" << endl; }
    int getCost() { return 7000 + mWrappee->getCost(); }
};

class BlackBubble : public Bubble {
   public:
    BlackBubble(MilkTeaComponent* wrappee) : Bubble(wrappee) {
        cout << "Black bubble is added!" << endl;
    }
    ~BlackBubble() { cout << "Black bubble is removed!" << endl; }
    int getCost() { return 10000 + mWrappee->getCost(); }
};

class EggPudding : public MilkTeaDecorator {
   public:
    EggPudding(MilkTeaComponent* wrappee) : MilkTeaDecorator(wrappee) {
        cout << "Egg pudding is added!" << endl;
    }
    ~EggPudding() { cout << "Egg pudding is removed!" << endl; }
    int getCost() { return 5000 + mWrappee->getCost(); }
};

class FruitPudding : public MilkTeaDecorator {
   public:
    FruitPudding(MilkTeaComponent* wrappee) : MilkTeaDecorator(wrappee) {
        cout << "Fruit padding is added!" << endl;
    }
    ~FruitPudding() { cout << "Fruit pudding is removed!" << endl; }
    int getCost() { return 6000 + mWrappee->getCost(); }
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
