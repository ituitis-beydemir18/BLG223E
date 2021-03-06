#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>
#include <time.h> /* time */

#include "phonebooktests.h"

void testphonebook()
{
    PhonebookFile bookfile; 
    bookfile.create_file("test_phonebook.dat");
    add_test(bookfile, "Tolga", "12341234");
    add_test(bookfile, "Duygu", "9879878");
    search_test(bookfile, "Tolga");
    search_test(bookfile, "*");
    search_test(bookfile, "Murat");
    bookfile.close_file();
    bookfile.create_file("test_phonebook.dat");
    update_test(bookfile, 0, "Murat", "000000");
    search_test(bookfile, "*");
    search_test(bookfile, "Murat");
    delete_test(bookfile, 1);
    delete_test(bookfile, 0);
    
    srand(clock());
    randomfill(bookfile, 10000);
    multi_read_test(bookfile, 5000);

    bookfile.close_file();
    remove("test_phonebook.dat");
}

void multi_read_test(PhonebookFile& bookfile, int trials)
{

    const short namelen = 6;
    char name[namelen];

    clock_t start = clock();
    for (int i = 0; i < trials; i++)
    {
        randstr(name, namelen, 65, 26);
        bookfile.search_file(name);
    }

    clock_t end = clock();

    cout << "It took " << (double)(end - start) * 1000 / CLOCKS_PER_SEC << " milliseconds to search for "<< trials <<" records" << endl;

    getchar();
}

void add_test(PhonebookFile& bookfile, const char *name, const char *number)
{
    Phone_Record newrecord;

    newrecord.name = new char[strlen(name) + 1];
    strcpy(newrecord.name, name);

    newrecord.phonenum = new char[strlen(number) + 1];
    strcpy(newrecord.phonenum, number);

    bookfile.add_to_file(&newrecord);
    delete[] newrecord.name;
    delete[] newrecord.phonenum;
}

void search_test(PhonebookFile& bookfile, const char *name)
{
    char* searchfor = new char[strlen(name)+1];
    strcpy(searchfor, name);
    bookfile.search_file(searchfor);
    delete[] searchfor;
}

void update_test(PhonebookFile& bookfile, int no, const char *name, const char *number)
{
    Phone_Record newrecord;

    newrecord.name = new char[strlen(name)+1];
    strcpy(newrecord.name, name);

    newrecord.phonenum = new char[strlen(number) + 1];
    strcpy(newrecord.phonenum, number);

    bookfile.update_file(no, &newrecord);

    delete[] newrecord.name;
    delete[] newrecord.phonenum;
}

void delete_test(PhonebookFile& bookfile, int no)
{
    bookfile.remove_from_file(no);
}

void randomfill(PhonebookFile& bookfile, int numofrecords)
{

    const short namelen = 6;
    char name[namelen];
    const short phonelen = 8;
    char phone[phonelen];
    Phone_Record newrecord;
    newrecord.name = new char[namelen];
    newrecord.phonenum = new char[phonelen];

    for (int i = 0; i < numofrecords; i++)
    {
        randstr(name, namelen, 65, 26);
        randstr(phone, phonelen, 48, 10);

        strcpy(newrecord.name, name);
        strcpy(newrecord.phonenum, phone);
        bookfile.add_to_file(&newrecord);
    }

    delete[] newrecord.name;
    delete[] newrecord.phonenum;
}

void randstr(char str[], int len, int start, int end)
{

    for (int i = 0; i < len - 1; i++)
        str[i] = ((char)(start + rand() % end));

    str[len - 1] = '\0';
}
