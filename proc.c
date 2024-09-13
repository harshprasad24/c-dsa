#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define Max_book 100
#define Max_Title_length 100

// Define the Book structure
struct Book {
    char title[Max_Title_length];
    char author[100];
    int year;
    int available;
    int borrowed; // New flag to indicate whether the book has been borrowed
    struct Book *prev; 
    struct Book *next; 
};

// Define the Library structure
struct Library {
    struct Book books[Max_book];
    int count;
};

// Function to add a book to the library
void AddBook(struct Library *lib, char *title, char *author, int year) {
    if (lib->count < Max_book) {
        struct Book *newBook = &lib->books[lib->count];
        strcpy(newBook->title, title);
        strcpy(newBook->author, author);
        newBook->year = year;
        newBook->available = 1;
        newBook->borrowed = 0; // Initialize borrowed flag to 0
        lib->count++;
        printf("Book \"%s\" added to the library.\n", title);
    } else {
        printf("Library is full. Cannot add more books.\n");
    }
}

// Function to register a student
void registerStudent() {
    printf("Enter your name: ");
    char name[100];
    scanf("%s", name);  // Corrected to read a string with spaces
    printf("Enter your Registration No: ");
    char Reg_no[100];
    scanf("%s", Reg_no);
    printf("Registration successful!\n");
}

// Function to borrow a book
void borrowBook(struct Library *lib) {
    char bookName[100];
    printf("Enter the book name you want to borrow: ");
    scanf("%s", bookName);
    
    // Search for the book in the library
    for (int i = 0; i < lib->count; i++) {
        if (strcmp(lib->books[i].title, bookName) == 0) {
            if (lib->books[i].available > 0 && !lib->books[i].borrowed) {
                printf("Book \"%s\" is available for borrowing.\n", bookName);
                lib->books[i].available--;
                lib->books[i].borrowed = 1; // Set borrowed flag to 1
                printf("You have successfully issued \"%s\".\n", bookName);
            } else {
                printf("Book \"%s\" is currently not available or already borrowed.\n", bookName);
            }
            return;  // Exit the function after processing
        }
    }
    printf("Book \"%s\" not found in the library.\n", bookName);
}

// Function to return a book
void returnBook(struct Library *lib) {
    char bookName[100];
    printf("Enter the book name you want to return: ");
    scanf("%s", bookName);
    
    // Search for the book in the library
    for (int i = 0; i < lib->count; i++) {
        if (strcmp(lib->books[i].title, bookName) == 0) {
            if (lib->books[i].borrowed) { // Check if the book has been borrowed
                lib->books[i].available++;
                lib->books[i].borrowed = 0; // Reset borrowed flag to 0
                printf("You have successfully returned \"%s\".\n", bookName);
            } else {
                printf("Book \"%s\" has not been borrowed.\n", bookName);
            }
            return;  // Exit the function after processing
        }
    }
    printf("Book \"%s\" not found in your borrowed list.\n", bookName);
}

// Function to display available books in the library
void displayBooks(struct Library *lib) {
    printf("Available books in the library:\n");
    for (int i = 0; i < lib->count; i++) {
        printf("Title: %s\n", lib->books[i].title);
        printf("Author: %s\n", lib->books[i].author);
        printf("Year: %d\n", lib->books[i].year);
        printf("Available: %d\n", lib->books[i].available);
        printf("Borrowed: %s\n", lib->books[i].borrowed ? "Yes" : "No"); // Print borrowed status
        printf("\n");
    }
}

int main() {
    struct Library library = { .count = 0 }; // Initialize the library
    
    // Adding some initial books to the library
    AddBook(&library, "Book1", "Author1", 2000);
    AddBook(&library, "Book2", "Author2", 2005);
    AddBook(&library, "Book3", "Author3", 2010);

    registerStudent();  // Register the student

    int choice;
    do {
        printf("\nMenu:\n");
        printf("1. Add a book\n");
        printf("2. Borrow a book\n");
        printf("3. Return a book\n");
        printf("4. Display available books\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter book details:\n");
                char title[Max_Title_length];
                char author[100];
                int year;
                printf("Title: ");
                scanf("%s", title);
                printf("Author: ");
                scanf("%s", author);
                printf("Year: ");
                scanf("%d", &year);
                AddBook(&library, title, author, year);
                break;
            case 2:
                displayBooks(&library);
                borrowBook(&library);
                break;
            case 3:
                returnBook(&library);
                break;
            case 4:
                displayBooks(&library);
                break;
            case 5:
                printf("Exiting program.\n");
                break;
            default:
                printf("Invalid choice. Please enter a valid option.\n");
        }
    } while (choice != 5);

    return 0;
}