#include "AdptArray.h"
#include "book.h"
#include "Person.h"
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <assert.h>

int main()
{
    printf("BOOKS\n");
    // Create books
    pbook b1 = creat_book("book A", 123);
    pbook b2 = creat_book("book B", 456);

    // Initialize an AdptArray of books and check empty array behaviour
    PAdptArray books = CreateAdptArray(copy_book, delete_book, print_book);
    printf("size after init: %d\n", GetAdptArraySize(books));
    pbook b = GetAdptArrayAt(books, 3);
    assert(b == NULL);

    // insert some books and check sizes
    SetAdptArrayAt(books, 1, b1);
    printf("size after inserting to index 1: %d\n", GetAdptArraySize(books));
    SetAdptArrayAt(books, 10, b2);
    printf("size after inserting to index 10: %d\n", GetAdptArraySize(books));
    b = GetAdptArrayAt(books, 9);
    assert(b == NULL);
    b = GetAdptArrayAt(books, 10);
    printf("The book at index 10 is: %s, %d\n", b->name, b->serial_number);

    printf("\nPERSONS\n");
    // Create books
    pperson p1 = creat_person("firstname1", "lastname1", 123);
    pperson p2 = creat_person("firstname2", "lastname2", 456);

    // Initialize an AdptArray of persons
    PAdptArray persons = CreateAdptArray(copy_person, delete_person, print_person);

    // insert some books and check sizes
    SetAdptArrayAt(persons, 0, p1);
    printf("size after inserting to index 0: %d\n", GetAdptArraySize(persons));
    SetAdptArrayAt(persons, 6, p2);
    printf("size after inserting to index 6: %d\n", GetAdptArraySize(persons));
    pperson p = GetAdptArrayAt(persons, 2);
    assert(p == NULL);
    p = GetAdptArrayAt(persons, 0);
    printf("The book at index 0 is: %s, %s, %d\n", p->first_name, p->last_name, p->id);

    printf("\nPrint books array:\n");
    PrintDB(books);
    printf("\nPrint persons array:\n");
    PrintDB(persons);

    delete_book(b1);
    delete_book(b2);
    delete_book(b);
    delete_person(p1);
    delete_person(p2);
    delete_person(p);
    DeleteAdptArray(books);
    DeleteAdptArray(persons);
    

    return 0;
}