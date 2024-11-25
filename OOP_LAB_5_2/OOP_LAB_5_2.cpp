#include <iostream>
#include <string>

using namespace std;

class Product 
{
public:
    string name;
    float price;
    Product(string n = "", float p = 0) : name(n), price(p) {}
};

class Department 
{
    Product products[100];
    int productCount;
public:
    Department() : productCount(0) {}

    void addProduct(Product p) 
    {
        if (productCount < 100)
            products[productCount++] = p;
    }

    Product* findProduct(string name) 
    {
        for (int i = 0; i < productCount; i++)
            if (products[i].name == name)
                return &products[i];
        return nullptr;
    }

    void removeProduct(string name) 
    {
        for (int i = 0; i < productCount; i++) 
        {
            if (products[i].name == name) 
            {
                for (int j = i; j < productCount - 1; j++)
                    products[j] = products[j + 1];

                productCount--;
                break;
            }
        }
    }

    void displayProducts() 
    {
        for (int i = 0; i < productCount; i++)
            cout << products[i].name << " - $" << products[i].price << endl;
    }
};

class Order 
{
    Product items[100];
    int itemCount;
public:
    Order() : itemCount(0) {}

    void addProduct(Product p) 
    {
        if (itemCount < 100)
            items[itemCount++] = p;
    }

    float computeTotal() 
    {
        float total = 0;
        for (int i = 0; i < itemCount; i++)
            total += items[i].price;
        return total;
    }

    void findProductInOrder(string name) 
    {
        for (int i = 0; i < itemCount; i++)
            if (items[i].name == name)
                cout << "Found in order: " << items[i].name << " - $" << items[i].price << endl;
    }
};

int main() 
{
    // Create departments
    Department shoes, toys;

    // Add products to departments
    shoes.addProduct(Product("Nike Air", 100));
    shoes.addProduct(Product("Adidas Boost", 120));
    toys.addProduct(Product("Lego Set", 50));
    toys.addProduct(Product("Action Figure", 30));

    // Display products
    cout << "Shoes department:" << endl;
    shoes.displayProducts();
    cout << "Toys department:" << endl;
    toys.displayProducts();

    // Find and remove a product
    Product* found = shoes.findProduct("Nike Air");
    if (found) cout << "Found product: " << found->name << " - $" << found->price << endl;
    shoes.removeProduct("Nike Air");

    cout << "After removing Nike Air:" << endl;
    shoes.displayProducts();

    // Create orders
    Order order1, order2;
    order1.addProduct(Product("Adidas shoes", 120));
    order1.addProduct(Product("Lego Set", 50));
    order2.addProduct(Product("Action Figure", 30));

    // Search product in orders
    cout << "Searching for Lego Set in orders:" << endl;
    order1.findProductInOrder("Lego Set");
    order2.findProductInOrder("Lego Set");

    // Compute total order values
    cout << "Order 1 total: $" << order1.computeTotal() << endl;
    cout << "Order 2 total: $" << order2.computeTotal() << endl;

    return 0;
}