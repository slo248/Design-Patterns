#include <bits/stdc++.h>
using namespace std;

class DiscountStrategy {
   public:
    virtual double applyDiscount(double price) = 0;
};

class QuarterDiscount : public DiscountStrategy {
   public:
    double applyDiscount(double price) { return price * 0.75; }
};

class SummerDiscount : public DiscountStrategy {
   public:
    double applyDiscount(double price) {
        if (price > LIM_BILL) return price * 0.7;
        return price * 0.4;
    }

   private:
    const int LIM_BILL = 200000;
};

class ChristmasDiscount : public DiscountStrategy {
   public:
    double applyDiscount(double price) {
        if (price > LIM_BILL) return price * 0.9;
        return price * 0.5;
    }

   private:
    const int LIM_BILL = 300000;
};

class Ticket {
   public:
    Ticket(double price = 0) : mPrice(price), mStrategy(nullptr) {}
    ~Ticket() {
        if (mStrategy != nullptr) delete mStrategy;
    }

    void setDiscount(DiscountStrategy* strategy) {
        if (mStrategy != nullptr) delete mStrategy;
        mStrategy = strategy;
    }

    double getPrice() const {
        if (mStrategy == nullptr) return mPrice;
        return mStrategy->applyDiscount(mPrice);
    }

   private:
    double mPrice;
    DiscountStrategy* mStrategy;
};

int main() {
    Ticket a(220000);

    cout << "Case 1: No discount" << endl;
    cout << "Ticket's cost: " << std::to_string(a.getPrice()) << " VND." << endl
         << endl;

    a.setDiscount(new QuarterDiscount);
    cout << "Case 2: Quarter discount" << endl;
    cout << "Ticket's cost: " << std::to_string(a.getPrice()) << " VND." << endl
         << endl;

    a.setDiscount(new SummerDiscount);
    cout << "Case 3: Summer discount" << endl;
    cout << "Ticket's cost: " << std::to_string(a.getPrice()) << " VND." << endl
         << endl;

    a.setDiscount(new ChristmasDiscount);
    cout << "Case 4: Christmas discount" << endl;
    cout << "Ticket's cost: " << std::to_string(a.getPrice()) << " VND."
         << endl;

    return 0;
}
