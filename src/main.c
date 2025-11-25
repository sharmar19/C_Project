#include <stdio.h>
#include <stdlib.h>
#include "../include/library.h" 

int main() {
    int choice;
    int searchId;

    while(1) {
        printf("\nLibrary Management System:\n");
        printf("1. Add Book\n");
        printf("2. List Books\n");
        printf("3. Search Book by ID\n"); 
        printf("4. Add Member\n");
        printf("5. List Members\n");   
        printf("6. Exit\n");
        printf("Enter choice: ");
        
        if (scanf("%d", &choice) != 1) {
            printf("Invalid input. Please enter a number.\n"); 
            while(getchar() != '\n'); 
            continue;
        }

        switch(choice) {
            case 1:
                add_book();
                break;
            case 2:
                list_books();
                break;
            case 3:
                printf("Enter Book ID to search: ");
                if (scanf("%d", &searchId) != 1) {
                    printf("Invalid Input.\n");
                    while(getchar() != '\n');
                } else {
                    search_book_by_id(searchId);
                }
                break;
            case 4:
                add_member();
                break;
            case 5:
                list_members(); 
                break;
            case 6:
                printf("Exiting system...\n");
                return 0;
            default:
                printf("Invalid choice! Try again.\n");
        }
    }
    return 0;
}
