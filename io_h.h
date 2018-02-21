#ifndef IO_H_H_INCLUDED
#define IO_H_H_INCLUDED
#include <vector>
#include "User_h.h"
#include "infor_h.h"
#include <string>
using namespace std;
//User 文件读写
class Userio
{
private:
    vector <User> userio;
public:
    bool input();
    bool output();
    bool add(User);
    bool change(string,User);
    bool dele(string);
};
//Librarian 文件读写
class Librario:public Userio
{
private:
    vector <Librarian> librario;
public:
    bool input();
    bool output();
    bool add(Librarian);
    bool change(string,Librarian);
    bool dele(string);
    Librarian get_librarian(string);
};
//Reader 文件读写
class Readerio:public Userio
{
private:
    vector <Reader> readio;
public:
    bool input();
    bool output();
    bool add(Reader);
    bool change(string,Reader);
    bool dele(string);
    Reader get_reader(string);
};
class Bookio
{
private:
    vector<Book>bookio;
public:
    bool input();
    bool output();
    bool add(Book);
    bool change(string,string);
    bool dele(string);
    Book get_book_id(string id);
    Book get_book_name(string name);
    void show(string id);
};
class Borrowio
{
private:
    vector <Borrow> borrio;
public:
    bool input();
    bool output();
    bool add(Borrow);
    bool return_book(string,string,string);
    void seekrt_bybook(string,int);
    void seekrt_byreader(string,int);
    Borrow get_bybook(string);
    Borrow get_byreader(string);
};
#endif // IO_H_H_INCLUDED
