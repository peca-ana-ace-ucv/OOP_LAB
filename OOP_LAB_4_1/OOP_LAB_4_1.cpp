#include <iostream>
#include <string>
using namespace std;

// Product Class
class Product 
{
private:
    string name;
    double price;
    bool isOnPromotion;

public:
    Product(string name, double price, bool isOnPromotion = false)
        : name(name), price(price), isOnPromotion(isOnPromotion) {}

    void display() 
    {
        cout << "Product: " << name << ", Price: $" << price << ", Promotion: " << (isOnPromotion ? "Yes" : "No") << endl;
    }

    string getName() 
    { 
        return name; 
    }
    double getPrice() 
    { 
        return price; 
    }
    bool getIsOnPromotion() 
    { 
        return isOnPromotion; 
    }
    void setPrice(double newPrice) 
    { 
        price = newPrice; 
    }
    void setIsOnPromotion(bool promotion) 
    { 
        isOnPromotion = promotion; 
    }
};

// Category Class
class Category 
{
private:
    string name;
    Product* products[10];
    int productCount;

public:
    Category(string name) : name(name), productCount(0) {}

    void addProduct(Product* product)
    {
        if (productCount < 10) {
            products[productCount++] = product;
        }
        else 
        {
            cout << "Category is full." << endl;
        }
    }

    void displayProducts() 
    {
        cout << "Category: " << name << endl;
        for (int i = 0; i < productCount; i++) 
        {
            products[i]->display();
        }
    }

    Product* getProduct(int index) 
    { 
        return products[index]; 
    }
    int getProductCount()
    { 
        return productCount; 
    }
};

// OnlineShop Class
class OnlineShop 
{
private:
    Category* categories[5];
    int categoryCount;

public:
    OnlineShop() : categoryCount(0) {}

    void addCategory(Category* category) 
    {
        if (categoryCount < 5) 
        {
            categories[categoryCount++] = category;
        }
        else 
        {
            cout << "Shop is full." << endl;
        }
    }

    void displayAllProducts() 
    {
        for (int i = 0; i < categoryCount; i++)
        {
            categories[i]->displayProducts();
        }
    }

    void displayPromotionalProducts() 
    {
        for (int i = 0; i < categoryCount; i++) 
        {
            for (int j = 0; j < categories[i]->getProductCount(); j++)
            {
                if (categories[i]->getProduct(j)->getIsOnPromotion())
                {
                    categories[i]->getProduct(j)->display();
                }
            }
        }
    }

    void searchProduct(string name, double minPrice, double maxPrice)
    {
        for (int i = 0; i < categoryCount; i++)
        {
            for (int j = 0; j < categories[i]->getProductCount(); j++) 
            {
                Product* p = categories[i]->getProduct(j);
                if (p->getName().find(name) != string::npos && p->getPrice() >= minPrice && p->getPrice() <= maxPrice) 
                {
                    p->display();
                }
            }
        }
    }
};

// Main Function
int main() {
    OnlineShop shop;

    // Create categories
    Category electronics("Electronics");
    Category clothing("Clothing");

    // Create products
    Product laptop("Laptop", 1200.00);
    Product smartphone("Smartphone", 800.00, true);
    Product tshirt("T-Shirt", 20.00);
    Product jeans("Jeans", 50.00, true);

    // Add products to categories
    electronics.addProduct(&laptop);
    electronics.addProduct(&smartphone);
    clothing.addProduct(&tshirt);
    clothing.addProduct(&jeans);

    // Add categories to shop
    shop.addCategory(&electronics);
    shop.addCategory(&clothing);

    // Display all products
    shop.displayAllProducts();

    // Display promotional products
    shop.displayPromotionalProducts();

    // Search for products
    cout << "\nSearching for products with name containing 'Shirt' and price between $10 and $30:" << endl;
    shop.searchProduct("Shirt", 10, 30);

    return 0;
}