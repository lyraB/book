#ifndef IO_H_H_INCLUDED
#define IO_H_H_INCLUDED
#include <vector>
#include "User_h.h"
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
    void show(string id);
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
    void show(string id);
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
    void show(string id);
};

#endif // IO_H_H_INCLUDED
