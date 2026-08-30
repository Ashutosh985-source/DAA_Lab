# Library Book Management
• Store the book ID, title, author, total copies, and available copies using structures.
• Create a menu-driven program to add and search for books, issue and return books, and display
all books currently unavailable.

  #include <stdio.h>
#include <string.h>

#define MAX 100

struct Book {
    int id;
    char title[100];
    char author[100];
    int totalCopies;
    int availableCopies;
};

int main() {
    struct Book books[MAX];
    int count = 0;
    int choice, id, found;

    while (1) {
        printf("\n========== LIBRARY MANAGEMENT ==========\n");
        printf("1. Add Book\n");
        printf("2. Search Book\n");
        printf("3. Issue Book\n");
        printf("4. Return Book\n");
        printf("5. Display Unavailable Books\n");
        printf("6. Display All Books\n");
        printf("7. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {

            // Add Book
            case 1:
                if (count >= MAX) {
                    printf("Library is full!\n");
                    break;
                }

                printf("\nEnter Book ID: ");
                scanf("%d", &books[count].id);

                printf("Enter Book Title: ");
                scanf(" %[^\n]", books[count].title);

                printf("Enter Author Name: ");
                scanf(" %[^\n]", books[count].author);

                printf("Enter Total Copies: ");
                scanf("%d", &books[count].totalCopies);

                books[count].availableCopies =
                    books[count].totalCopies;

                count++;

                printf("Book added successfully!\n");
                break;

            // Search Book
            case 2:
                printf("\nEnter Book ID to search: ");
                scanf("%d", &id);

                found = 0;

                for (int i = 0; i < count; i++) {
                    if (books[i].id == id) {
                        printf("\nBook Found!\n");
                        printf("Book ID          : %d\n", books[i].id);
                        printf("Title            : %s\n", books[i].title);
                        printf("Author           : %s\n", books[i].author);
                        printf("Total Copies     : %d\n",
                               books[i].totalCopies);
                        printf("Available Copies : %d\n",
                               books[i].availableCopies);

                        found = 1;
                        break;
                    }
                }

                if (!found) {
                    printf("Book not found!\n");
                }
                break;

            // Issue Book
            case 3:
                printf("\nEnter Book ID to issue: ");
                scanf("%d", &id);

                found = 0;

                for (int i = 0; i < count; i++) {
                    if (books[i].id == id) {
                        found = 1;

                        if (books[i].availableCopies > 0) {
                            books[i].availableCopies--;
                            printf("Book issued successfully!\n");
                            printf("Available copies: %d\n",
                                   books[i].availableCopies);
                        } else {
                            printf("Book is currently unavailable!\n");
                        }

                        break;
                    }
                }

                if (!found) {
                    printf("Book not found!\n");
                }
                break;

            // Return Book
            case 4:
                printf("\nEnter Book ID to return: ");
                scanf("%d", &id);

                found = 0;

                for (int i = 0; i < count; i++) {
                    if (books[i].id == id) {
                        found = 1;

                        if (books[i].availableCopies <
                            books[i].totalCopies) {

                            books[i].availableCopies++;

                            printf("Book returned successfully!\n");
                            printf("Available copies: %d\n",
                                   books[i].availableCopies);
                        } else {
                            printf("All copies are already available!\n");
                        }

                        break;
                    }
                }

                if (!found) {
                    printf("Book not found!\n");
                }
                break;

            // Display Unavailable Books
            case 5:
                printf("\n===== UNAVAILABLE BOOKS =====\n");

                found = 0;

                for (int i = 0; i < count; i++) {
                    if (books[i].availableCopies == 0) {
                        printf("\nBook ID : %d\n", books[i].id);
                        printf("Title   : %s\n", books[i].title);
                        printf("Author  : %s\n", books[i].author);

                        found = 1;
                    }
                }

                if (!found) {
                    printf("No books are currently unavailable.\n");
                }
                break;

            // Display All Books
            case 6:
                printf("\n========== ALL BOOKS ==========\n");

                if (count == 0) {
                    printf("No books in the library.\n");
                }

                for (int i = 0; i < count; i++) {
                    printf("\nBook ID          : %d\n", books[i].id);
                    printf("Title            : %s\n", books[i].title);
                    printf("Author           : %s\n", books[i].author);
                    printf("Total Copies     : %d\n",
                           books[i].totalCopies);
                    printf("Available Copies : %d\n",
                           books[i].availableCopies);
                }
                break;

            // Exit
            case 7:
                printf("Exiting program...\n");
                return 0;

            default:
                printf("Invalid choice! Please try again.\n");
        }
    }

    return 0;
}
