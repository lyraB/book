#ifndef SERVICE_H_H_INCLUDED
#define SERVICE_H_H_INCLUDED
#include "io_h.h"
class User_serv
{
private:
    Userio userio;
public:
    bool add();
    string signin(string);
    bool change(string);
};
class Librarian_serv
{
private:
    Librario librario;
public:
    bool add();
    bool change(string);
    bool dele();
    bool show(string);
    bool change_pass(string);
    void face_ad();
};
class Reader_serv
{
private:
    Readerio readerio;
public:
    bool add();
    bool change(string);
    bool dele();
    bool show(string);
    bool change_pass(string);
    void face_ad();
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
    bool repair_book(string);
    bool show_book();
    bool show_borrow(string);
    void check_bybook();
    void check_byreader(string);
    void face_ad();
    void face_li();
};
#endif // SERVICE_H_H_INCLUDED
