#include <iostream>

const int MAX_ITEMS = 10;


class MenuItem {
protected:
    std::string name;
    double price;

public:
    MenuItem(const std::string& n, double p) : name(n), price(p) {}

    virtual double getPrice() const {
        return price;
    }

    virtual std::string getName() const {
        return name;
    }
};


class FoodItem : public MenuItem {
public:
    FoodItem(const std::string& n, double p) : MenuItem(n, p) {}
};


class BeverageItem : public MenuItem {
public:
    BeverageItem(const std::string& n, double p) : MenuItem(n, p) {}
};


class BillingSystem {
private:
    MenuItem* items[MAX_ITEMS]; 
    int itemCount; 

public:
    BillingSystem() : itemCount(0) {}

   
    void addItem(MenuItem* item) {
        if (itemCount < MAX_ITEMS) {
            items[itemCount++] = item;
        } else {
            std::cout << "Cannot add more items. Bill is full." << std::endl;
        }
    }

   
    double calculateTotal() const {
        double total = 0.0;
        for (int i = 0; i < itemCount; ++i) {
            total += items[i]->getPrice();
        }
        return total;
    }
};

int main() {
    
    FoodItem burger("Burger", 5.99);
    FoodItem pizza("Pizza", 8.99);
    BeverageItem cola("Cola", 1.99);
    BeverageItem coffee("Coffee", 2.49);

    
    BillingSystem bill;
    bill.addItem(&burger);
    bill.addItem(&pizza);
    bill.addItem(&cola);
    bill.addItem(&coffee);

    
    std::cout << "Total bill amount: $" << bill.calculateTotal() << std::endl;

    return 0;
}

