#ifndef USER_H_H_INCLUDED
#define USER_H_H_INCLUDED
#include <string>
using namespace std;
class User
{
private:
    string name;
    string id;
    string password;
    int type;
public:
    User();
    User(string id,string name,string password,int type);
    string get_name(){return name;}
    string get_id(){return id;}
    string get_password(){return password;}
    int get_type(){return type;}
    void set_id(string id){this->id = id;}
    void set_name(string name){this->name = name;}
    void set_password(string password){this->password = password;}
    void set_type(int type){this->type = type;}
    string show();
};
class Administration:public User
{
public:

};
class Librarian:public User
{
private:
    int wage;//工资
    string seniority;//资历
public:
    Librarian();
    Librarian(string,string,string,int,string);
    int get_wage(){return wage;}
    string get_seniority(){return seniority;}
    void set_wage(int wage){this->wage = wage;}
    void set_seniority(string seniority){this->seniority = seniority;}
};
class Reader:public User
{
private:
    int age;
    string reader_id;
public:
    Reader();
    Reader(string,string,string,int,string);
    int get_age(){return age;}
    string get_reader_id(){return reader_id;}
    void set_age(int age){this->age = age;}
    void set_seniority(string reader_id){this->reader_id = reader_id;}
};
class Book
{

};
#endif // USER_H_H_INCLUDED
