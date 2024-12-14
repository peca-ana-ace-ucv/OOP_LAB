#include <iostream>
#include <vector>
#include <algorithm> // For func sort

using namespace std;

// Template class to manage a list of elements
template <typename T>
class ListManager
{
private:
    vector<T> elements; // List of elements

public:
    // Add element to the list
    void addElement(T element)
    {
        elements.push_back(element);
    }

    // Return index of an element based on the key
    int findElementByKey(int key)
    {
        for (int i = 0; i < elements.size(); ++i)
        {
            if (elements[i].getKey() == key)
                return i; // Return the index if found
        }
        return -1; // Return -1 if not found
    }

    // Remove element from the list based on index
    void removeElementByIndex(int index)
    {
        if (index < 0 || index >= elements.size())
        {
            cout << "Invalid index. No element removed." << endl;
            return;
        }
        elements.erase(elements.begin() + index);
        cout << "Element at index " << index << " removed successfully." << endl;
    }

    // Display all keys in the list
    void displayKeys()
    {
        if (elements.empty())
        {
            cout << "List is empty." << endl;
            return;
        }

        cout << "Keys in the list:" << endl;

        for (int i = 0; i < elements.size(); ++i)
            cout << elements[i].getKey() << " ";

        cout << endl;
    }

    // Sort the list in ascending or descending order based on the key
    void sortList(bool ascending = true)
    {
        sort(elements.begin(), elements.end(), [ascending](T a, T b)
            {
                return ascending ? a.getKey() < b.getKey() : a.getKey() > b.getKey();
            });

        cout << "List sorted in " << (ascending ? "ascending" : "descending") << " order based on key." << endl;
    }
};

// Example class to demonstrate the functionality
class Element
{
private:
    int key;      // Key attribute
    string name;  // Some additional data

public:
    // Constructor
    Element(int k, string n) : key(k), name(n) {}

    // Getter for the key
    int getKey() { return key; }

    // Display element info
    void display()
    {
        cout << "Key: " << key << ", Name: " << name << endl;
    }
};

int main()
{
    // Create a ListManager for elements of type Element
    ListManager<Element> manager;

    // Add elements to the list
    manager.addElement(Element(5, "Alice"));
    manager.addElement(Element(2, "Bob"));
    manager.addElement(Element(8, "Charlie"));

    // Display keys
    manager.displayKeys();

    // Find an element by key
    int keyToFind = 2;

    int index = manager.findElementByKey(keyToFind);

    if (index != -1)
        cout << "Element with key " << keyToFind << " found at index " << index << "." << endl;
    else
        cout << "Element with key " << keyToFind << " not found." << endl;

    // Remove an element by index
    manager.removeElementByIndex(1);

    // Display keys again
    manager.displayKeys();

    // Sort the list in descending order
    manager.sortList(false);

    // Display keys after sorting
    manager.displayKeys();

    return 0;
}