#include "User_h.h"
User::User(string id,string name,string password,int type)
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
    type = 0;
}
string User::show()
{
    return id+" "+name+" "+password+" ";
}
Librarian::Librarian():User()
{
    wage = 0;
    seniority = "no";
}
Librarian::Librarian(string id,string name,string password,int wage,string seniority):User(id,name,password,1)
{
    this->wage = wage;
    this->seniority = seniority;
}
Reader::Reader():User()
{
    age = 0;
    reader_id = "no";
}
Reader::Reader(string id,string name,string password,int age,string reader_id):User(id,name,password,2)
{
    this->age = age;
    this->reader_id = reader_id;
}
