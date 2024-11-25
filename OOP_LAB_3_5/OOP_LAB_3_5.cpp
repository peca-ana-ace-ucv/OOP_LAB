#include <iostream>
#include <string>

using namespace std;

// Define the BankApp class
class BankApp
{
private:
    // Hardcoded username and password
    string username = "user";
    string password = "password";

    // User information
    double balance;
    bool isLoggedIn;

    // Static variable to count the number of users
    static int userCount;

public:
    // Constructor
    BankApp() : balance(0.0), isLoggedIn(false)
    {
        userCount++;
    }

    // Destructor
    ~BankApp()
    {
        userCount--;
    }

    // Function to log in the user
    void login(string user, string pass) 
    {
        if (user == username && pass == password) 
        {
            isLoggedIn = true;
            cout << "Login successful!" << endl;
        }
        else 
            cout << "Invalid username or password!" << endl;
    }

    // Function to deposit money
    void deposit(double amount) 
    {
        if (!isLoggedIn)
        {
            cout << "Please log in first to perform this operation." << endl;
            return;
        }

        if (amount > 0) 
        {
            balance += amount;
            cout << "Deposit successful! Current balance: $" << balance << endl;
        }
        else 
            cout << "Invalid amount. Please enter a positive number." << endl;
    }

    // Function to withdraw money
    void withdraw(double amount) 
    {
        if (!isLoggedIn) 
        {
            cout << "Please log in first to perform this operation." << endl;
            return;
        }

        if (amount > 0 && amount <= balance) 
        {
            balance -= amount;
            cout << "Withdrawal successful! Current balance: $" << balance << endl;
        }
        else 
          if (amount > balance) 
            cout << "Insufficient balance. Current balance: $" << balance << endl;
        else 
            cout << "Invalid amount. Please enter a positive number." << endl;
        
    }

    // Function to display the current balance
    void displayBalance() 
    {
        if (!isLoggedIn) 
        {
            cout << "Please log in first to perform this operation." << endl;
            return;
        }

        cout << "Current balance: $" << balance << endl;
    }

    // Static function to get the number of users
    static int getUserCount() {
        return userCount;
    }
};

// Initialize the static member variable
int BankApp::userCount = 0;

int main() {
    // Create an instance of BankApp
    BankApp bankApp;

    // Login operation
    string username, password;
    cout << "Enter username: ";
    cin >> username;
    cout << "Enter password: ";
    cin >> password;
    bankApp.login(username, password);

    // Perform some operations
    bankApp.deposit(100.0);     // Deposit $100
    bankApp.withdraw(50.0);     // Withdraw $50
    bankApp.displayBalance();   // Display the current balance

    // Display the number of existing users
    cout << "Number of existing users: " << BankApp::getUserCount() << endl;

    return 0;
}
