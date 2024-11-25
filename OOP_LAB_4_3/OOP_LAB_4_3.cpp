#include <iostream>
#include <string>

using namespace std;

// Client Class
class Client
{
private:
    string name;

public:
    Client(string n) : name(n) {}

    string getName()
    {
        return name;
    }

    void display()
    {
        cout << "Client Name: " << name << endl;
    }
};

// Review Class
class Review
{
private:
    string content;
    Client reviewer;

public:
    Review(string c, Client r) : content(c), reviewer(r) {}

    string getContent()
    {
        return content;
    }

    string getReviewerName()
    {
        return reviewer.getName();
    }

    void display()
    {
        cout << "Review by " << reviewer.getName() << ": " << content << endl;
    }
};

// Book Class
class Book
{
private:
    string title;
    string author;
    Review* reviews[10];  // Fixed-size array of pointers to Review objects
    int reviewCount;

public:
    Book(string t, string a) : title(t), author(a), reviewCount(0) {}

    string getTitle()
    {
        return title;
    }

    string getAuthor()
    {
        return author;
    }

    // Use dynamic allocation for the reviews array
    void addReview(Review* review)
    {
        if (reviewCount < 10)
        {
            reviews[reviewCount++] = review;  // Add the pointer to the review array
            cout << "Review added for book: " << title << endl;
        }
        else
            cout << "Cannot add more reviews, book already has maximum reviews." << endl;
    }

    void displayReviews()
    {
        cout << "Reviews for \"" << title << "\" by " << author << ":" << endl;
        for (int i = 0; i < reviewCount; ++i)
            reviews[i]->display();  // Dereference the pointer to call the display method
    }

    void searchReviews(string text)
    {
        cout << "Searching for \"" << text << "\" in reviews of \"" << title << "\":" << endl;
        bool found = false;
        for (int i = 0; i < reviewCount; ++i)
        {
            if (reviews[i]->getContent().find(text) != string::npos || reviews[i]->getReviewerName().find(text) != string::npos)
            {
                reviews[i]->display();  // Dereference the pointer to call the display method
                found = true;
            }
        }
        if (!found)
            cout << "No matching reviews found." << endl;
    }
};

// Main Function
int main()
{
    // Create clients
    Client client1("Alice");
    Client client2("Bob");

    // Create books
    Book book1("The Great Gatsby", "F. Scott Fitzgerald");
    Book book2("1984", "George Orwell");

    // Create reviews and associate them with clients
    Review* review1 = new Review("An amazing read with deep characters.", client1);
    Review* review2 = new Review("A timeless classic.", client2);
    Review* review3 = new Review("A thought-provoking book about society.", client1);
    Review* review4 = new Review("Very relevant even today.", client2);

    // Add reviews to books
    book1.addReview(review1);
    book1.addReview(review2);
    book2.addReview(review3);
    book2.addReview(review4);

    // Display reviews for each book
    cout << "\n--- Displaying Reviews ---" << endl;
    book1.displayReviews();
    book2.displayReviews();

    // Search for text in reviews
    cout << "\n--- Searching Reviews ---" << endl;
    book1.searchReviews("classic");
    book2.searchReviews("society");
    book1.searchReviews("Alice");

    // Clean up dynamic memory
    delete review1;
    delete review2;
    delete review3;
    delete review4;

    return 0;
}