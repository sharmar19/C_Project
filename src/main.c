#include <stdio.h>
#include "../include/library.h" //include folder

int main() {
    int choice;
    while(1) {
        printf("\n=== Library Management System ===\n");
        printf("1. Add Book\n");
        printf("2. List Books\n");
        printf("3. Add Member\n");
        printf("4. Exit\n");
        printf("Enter choice: ");
        
        if (scanf("%d", &choice) != 1) {
            printf("Invalid input. Please enter a number.\n"); //invalid input handling
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
                add_member();
                break;
            case 4:
                printf("Exiting system...\n");
                return 0;
            default:
                printf("Invalid choice! Try again.\n"); //invalid choice handling
        }
    }
    return 0;
}