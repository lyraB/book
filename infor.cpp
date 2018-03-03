#include <iostream>
#include <string>
#include "infor_h.h"
using namespace std;
Book::Book()
{
    id = "no";
    name = "no";
    publisher = "no";
    price = "no";
    status = "incirculation";
}
Book::Book(string id,string name,string publisher,string price,string status)
{
    this->id = id;
    this->name = name;
    this->publisher = publisher;
    this->price = price;
    this->status = status;
}
void Book::out()
{
    cout<<"��ţ�"<<id<<endl
         <<"������"<<name<<endl
         <<"�۸�"<<price<<endl
         <<"�����磺"<<publisher<<endl
         <<"״̬��"<<status<<endl;
}
Borrow::Borrow()
{
    id_book = "no";
    id_reader = "no";
    data_borrow = "no";
    data_back = "no";
    data_return = "notreturned";
    borrow_time = 0;
}
Borrow::Borrow(string id_book,string id_reader,string data_borrow,string data_back,string data_return,int time)
{
    this->id_book = id_book;
    this->id_reader = id_reader;
    this->data_borrow = data_borrow;
    this->data_back = data_back;
    this->data_return = data_return;
    this->borrow_time = time;
}
void Borrow::out()
{
    cout<<"��ţ�"<<id_book<<endl
         <<"���߱�ţ�"<<id_reader<<endl
         <<"�������ڣ�"<<data_borrow<<endl
         <<"Ӧ�����ڣ�"<<data_back<<endl
         <<"�������ڣ�"<<data_return<<endl;
    return;
}
