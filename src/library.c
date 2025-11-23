#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../include/library.h"

const char *BOOK_FILE = "books.txt";
const char *MEMBER_FILE = "members.txt";

void newline(char *str) { //funtion to remove newline character from string
    size_t len = strlen(str);
    if (len > 0 && str[len - 1] == '\n') {
        str[len - 1] = '\0';
    }
}

void add_book() { //function to add book
    Book newBook;
    FILE *fp = fopen(BOOK_FILE, "a"); //Append Text Mode

    if (fp == NULL) {
        printf("Error: Could not open file for writing.\n");
        return;
    }

    printf("\n--- Add New Book ---\n");
    printf("Enter Book ID: ");
    if (scanf("%d", &newBook.id) != 1) {
        printf("Invalid ID.\n");
        return;
    }
    while ((getchar()) != '\n');

    printf("Enter Book Title: ");
    fgets(newBook.title, MAX_TITLE, stdin);
    newline(newBook.title);

    printf("Enter Author Name: ");
    fgets(newBook.author, MAX_AUTHOR, stdin);
    newline(newBook.author);

    newBook.is_issued = 0;

    // Writing format: ID|Title|Author|Status
    fprintf(fp, "%d|%s|%s|%d\n", newBook.id, newBook.title, newBook.author, newBook.is_issued);

    fclose(fp);
    printf("Success: Book '%s' saved to %s.\n", newBook.title, BOOK_FILE);
}

void list_books() { //function to list books
    Book b;
    FILE *fp = fopen(BOOK_FILE, "r"); //Read Text Mode

    if (fp == NULL) {
        printf("\nNo books found (File does not exist).\n");
        return;
    }

    printf("\n%-10s %-30s %-20s %-10s\n", "ID", "Title", "Author", "Status");
    printf("--------------------------------------------------------------------------\n");

    while (fscanf(fp, "%d|%[^|]|%[^|]|%d\n", &b.id, b.title, b.author, &b.is_issued) == 4) {
        printf("%-10d %-30s %-20s %-10s\n", b.id, b.title, b.author, (b.is_issued ? "Issued" : "Available"));
    }
    
    fclose(fp);
    printf("--------------------------------------------------------------------------\n");
}

void search_book_by_id(int searchId) { //function to search book by id
    Book b;
    FILE *fp = fopen(BOOK_FILE, "r");
    int found = 0;

    if (fp == NULL) {
        printf("Error: Database not found.\n");
        return;
    }

    while (fscanf(fp, "%d|%[^|]|%[^|]|%d\n", 
                  &b.id, b.title, b.author, &b.is_issued) == 4) {
        if (b.id == searchId) {
            printf("\n--- Book Found ---\n");
            printf("ID: %d\nTitle: %s\nAuthor: %s\nStatus: %s\n", 
                   b.id, b.title, b.author, (b.is_issued ? "Issued" : "Available"));
            found = 1;
            break;
        }
    }

    if (!found) {
        printf("Book with ID %d not found.\n", searchId);
    }

    fclose(fp);
}

void add_member() { //function to add member
    Member newMember;
    FILE *fp = fopen(MEMBER_FILE, "a");

    if (fp == NULL) {
        printf("Error: Could not open member file.\n");
        return;
    }

    printf("\n--- Add New Member ---\n");
    printf("Enter Member ID: ");
    scanf("%d", &newMember.id);
    while ((getchar()) != '\n'); 

    printf("Enter Member Name: ");
    fgets(newMember.name, MAX_NAME, stdin);
    newline(newMember.name);

    fprintf(fp, "%d|%s\n", newMember.id, newMember.name);
    
    fclose(fp);
    printf("Success: Member '%s' registered.\n", newMember.name);
}

void list_members() { //function to list members
    Member m;
    FILE *fp = fopen(MEMBER_FILE, "r");

    if (fp == NULL) {
        printf("\nNo members registered yet.\n");
        return;
    }

    printf("\n%-10s %-30s\n", "ID", "Name");
    printf("-----------------------------------------\n");

    while (fscanf(fp, "%d|%[^\n]\n", &m.id, m.name) == 2) {
        printf("%-10d %-30s\n", m.id, m.name);
    }

    fclose(fp);
}
