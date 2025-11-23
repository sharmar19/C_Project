#ifndef LIBRARY_H
#define LIBRARY_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_TITLE 100
#define MAX_AUTHOR 100
#define MAX_NAME 100

typedef struct { //structure for book details
    int id;
    char title[MAX_TITLE];
    char author[MAX_AUTHOR];
    int is_issued; // 0 for available, 1 for issued
} Book;

typedef struct { //structure for member details
    int id;
    char name[MAX_NAME];
} Member;

//book management functions
void add_book();
void list_books();
void search_book_by_id(int id);

//member management functions
void add_member();
void list_members();

#endif