#ifndef INFOR_H_H_INCLUDED
#define INFOR_H_H_INCLUDED
#include <string>
using namespace std;
class Book
{
private:
    string id,name,publisher,price,status;
public:
    Book();
    Book(string,string,string,string,string);
    string get_id(){return id;}
    string get_name(){return name;}
    string get_publisher(){return publisher;}
    string get_price(){return price;}
    string get_status(){return status;}
    void set_status(string status){this->status = status;}
    void out();
    string show(){return id+" "+name+" "+publisher+" "+price+" "+status;}
};

class Borrow
{
private:
    string id_book,id_reader,data_borrow,data_back,data_return;
    int borrow_time;
public:
    Borrow();
    Borrow(string,string,string,string,string,int);
    string get_id_book(){return id_book;}
    string get_id_reader(){return id_reader;}
    string get_data_borrow(){return data_borrow;}
    string get_data_back(){return data_back;}
    string get_data_return(){return data_return;}
    int get_time(){return borrow_time;}
    void set_data_return(string data){this->data_return = data;}
    void out();
    string get_string(){return id_book+" "+id_reader+" "+data_borrow+" "+data_back+" "+data_return+" ";}
};

#endif // INFOR_H_H_INCLUDED
