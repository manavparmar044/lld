#include <iostream>
#include <vector>
using namespace std;

// ---------------- Product ----------------
class Product {
    int id;
    string name;
    double price;

public:
    Product(int id, string name, double price) {
        this->id = id;
        this->name = name;
        this->price = price;
    }

    int getId() { return id; }
    string getName() { return name; }
    double getPrice() { return price; }

    void showProduct() {
        cout << "🛍️ " << name << " (ID: " << id << ") - Rs." << price << endl;
    }
};

// ---------------- CartItem ----------------
class CartItem {
    Product* product;
    int quantity;

public:
    CartItem(Product* p, int qty) {
        product = p;
        quantity = qty;
    }

    double getItemTotal() {
        return product->getPrice() * quantity;
    }

    void showItem() {
        cout << product->getName() << " x " << quantity 
             << " = Rs." << getItemTotal() << endl;
    }
};

// ---------------- Cart ----------------
class Cart {
    vector<CartItem*> items;

public:
    void addItem(Product* p, int qty) {
        items.push_back(new CartItem(p, qty));
        cout << "✅ Added to cart: " << p->getName() << " x" << qty << endl;
    }

    void showCart() {
        cout << "\n🛒 Cart Summary:\n";
        double total = 0;
        for (CartItem* item : items) {
            item->showItem();
            total += item->getItemTotal();
        }
        cout << "-------------------------\n";
        cout << "💵 Total: Rs." << total << endl;
    }

    ~Cart() {
        for (CartItem* item : items)
            delete item;
    }
};

// ---------------- User ----------------
class User {
    string name;
    int id;
    Cart* cart;

public:
    User(string name, int id) {
        this->name = name;
        this->id = id;
        cart = new Cart();
    }

    void addToCart(Product* p, int qty) {
        cart->addItem(p, qty);
    }

    void viewCart() {
        cout << "\n👤 User: " << name << " (ID: " << id << ")";
        cart->showCart();
    }

    ~User() {
        delete cart;
    }
};

int main() {
    // Create products
    Product* p1 = new Product(101, "Laptop", 55000);
    Product* p2 = new Product(102, "Mouse", 700);
    Product* p3 = new Product(103, "Keyboard", 1200);

    // Create a user
    User* user1 = new User("Manav", 1);

    // Add to cart
    user1->addToCart(p1, 1);
    user1->addToCart(p2, 2);
    user1->addToCart(p3, 1);

    // View cart
    user1->viewCart();

    // Clean up
    delete user1;
    delete p1;
    delete p2;
    delete p3;

    return 0;
}
