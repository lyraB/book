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
    string type;
public:
    User();
    User(string id,string name,string password,string type);
    string get_name(){return name;}
    string get_id(){return id;}
    string get_password(){return password;}
    string get_type(){return type;}
    void set_id(string id){this->id = id;}
    void set_name(string name){this->name = name;}
    void set_password(string password){this->password = password;}
    void set_type(string type){this->type = type;}
    void out();
    string show();
};

class Librarian:public User
{
private:
    string wage,seniority;
public:
    Librarian();
    Librarian(string,string,string,string,string);
    string get_wage(){return wage;}
    string get_seniority(){return seniority;}
    void set_wage(string wage){this->wage = wage;}
    void set_seniority(string seniority){this->seniority = seniority;}
    void out();
    string show();
};
class Reader:public User
{
private:
    string sex;
    string reader_id;
public:
    Reader();
    Reader(string,string,string,string,string);
    string get_sex(){return sex;}
    string get_reader_id(){return reader_id;}
    void set_sex(string sex){this->sex = sex;}
    void set_reader_id(string reader_id){this->reader_id = reader_id;}
    void out();
    string show(){return this->get_id()+" "+this->get_name()+" "+this->get_password()+" "+sex+" "+reader_id;}
};

#endif // USER_H_H_INCLUDED
