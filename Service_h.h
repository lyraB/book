#ifndef SERVICE_H_H_INCLUDED
#define SERVICE_H_H_INCLUDED
#include "io_h.h"
class Administration_serv
{
public:

};
class Librarian_serv
{
private:
    Librario librario;
public:
    bool add();
    bool change();
    bool dele();
    bool show();
};
class Reader_serv
{
private:
    Readerio readerio;
public:
    bool add();
    bool change();
    bool dele();
    bool show();
};
class Book_serv
{
private:
    Bookio bookio;
    Borrowio borrowio;
public:
    bool add();
    bool borrow_book(string);
    bool return_book(string);
    bool dele_book();
    void show_book();
    void show_borrow();
    void check();
};
#endif // SERVICE_H_H_INCLUDED
