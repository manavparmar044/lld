#include <iostream>
#include <unordered_map>
using namespace std;

// ------------------- Product -------------------
class Product {
    string name;
    int price;
    int quantity;

public:
    Product(string name, int price, int quantity) {
        this->name = name;
        this->price = price;
        this->quantity = quantity;
    }

    string getName() { return name; }
    int getPrice() { return price; }
    int getQuantity() { return quantity; }

    void reduceQuantity() {
        if (quantity > 0) quantity--;
    }

    void showInfo() {
        cout << name << " | Rs." << price << " | Qty: " << quantity << endl;
    }
};

// ------------------- Inventory -------------------
class Inventory {
    unordered_map<int, Product*> products; // slotId -> Product*

public:
    void addProduct(int slotId, Product* p) {
        products[slotId] = p;
    }

    Product* getProduct(int slotId) {
        if (products.count(slotId)) {
            return products[slotId];
        }
        return nullptr;
    }

    void showInventory() {
        cout << "\n🧾 Available Products:\n";
        for (auto pair : products) {
            cout << "Slot " << pair.first << " -> ";
            pair.second->showInfo();
        }
    }

    ~Inventory() {
        for (auto pair : products) delete pair.second;
    }
};

// ------------------- VendingMachine -------------------
class VendingMachine {
    Inventory inventory;
    int balance;

public:
    VendingMachine() {
        balance = 0;
    }

    void loadInventory() {
        inventory.addProduct(1, new Product("Chips", 20, 5));
        inventory.addProduct(2, new Product("Coke", 30, 3));
        inventory.addProduct(3, new Product("Snickers", 25, 2));
    }

    void insertMoney(int amount) {
        if (amount <= 0) {
            cout << "❌ Invalid amount.\n";
            return;
        }
        balance += amount;
        cout << "💰 Rs." << amount << " inserted. Current balance: Rs." << balance << endl;
    }

    void selectProduct(int slotId) {
        Product* product = inventory.getProduct(slotId);
        if (!product) {
            cout << "❌ Invalid slot selected.\n";
            return;
        }

        if (product->getQuantity() == 0) {
            cout << "⚠️ " << product->getName() << " is out of stock.\n";
            return;
        }

        if (balance < product->getPrice()) {
            cout << "❌ Not enough balance to buy " << product->getName() << ".\n";
            return;
        }

        // Dispense
        product->reduceQuantity();
        balance -= product->getPrice();
        cout << "✅ Dispensed: " << product->getName() << ". Remaining balance: Rs." << balance << endl;
    }

    void refund() {
        cout << "💸 Refunding Rs." << balance << endl;
        balance = 0;
    }

    void showMenu() {
        inventory.showInventory();
    }
};

int main() {
    VendingMachine vm;
    vm.loadInventory();

    vm.showMenu();
    vm.insertMoney(50);
    vm.selectProduct(2);  // Buy Coke
    vm.selectProduct(1);  // Buy Chips
    vm.refund();          // Refund remaining money

    return 0;
}
