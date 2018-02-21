#include "User_h.h"
#include <iostream>
using namespace std;
User::User(string id,string name,string password,string type)
{
    this->id = id;
    this->name = name;
    this->password = password;
    this->type = type;
}
User::User()
{
    id = "no";
    name = "no";
    password = "no";
    type = "no";
}
void User::out()
{
    cout<<"编号："<<id<<endl
         <<"姓名："<<name<<endl;
}
string User::show()
{
    return id+" "+name+" "+password+" ";
}
Librarian::Librarian():User()
{
    wage = "no";
    seniority = "no";
}
Librarian::Librarian(string id,string name,string password,string wage,string seniority):User(id,name,password,"librarian")
{
    this->wage = wage;
    this->seniority = seniority;
}
void Librarian::out()
{
    User::out();
    cout<<"工资："<<wage<<endl
         <<"资历："<<seniority<<endl;
}
string Librarian::show()
{
    return this->get_id()+" "+this->get_name()+" "+this->get_password()+" "+wage+" "+seniority;
}
Reader::Reader():User()
{
    sex = "no";
    reader_id = "no";
}
Reader::Reader(string id,string name,string password,string sex,string reader_id):User(id,name,password,"reader")
{
    this->sex = sex;
    this->reader_id = reader_id;
}
void Reader::out()
{
    User::out();
    cout<<"性别："<<sex<<endl
         <<"身份证号："<<reader_id<<endl;
    return;
}
