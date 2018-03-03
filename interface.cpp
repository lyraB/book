#include <iostream>
#include "Service_h.h"
#include <stdlib.h>
#include "interface_h.h"
using namespace std;
void interface::signin()
{
    string id,type;
    do
    {
        cout<<"请输入账号：";
        cin>>id;
        type = us.signin(id);
    }
    while(type=="Wrong！");
    system("pause");
    if(type=="no")
        Admini_show(id);
    else if(type=="reader")
        Reader_show(id);
    else if(type=="librarian")
        Librari_show(id);
}
void interface::Admini_show(string id)
{
    int choice;
    do
    {
        system("cls");
        cout<<"1.图书信息管理"<<endl
             <<"2.工作人员管理"<<endl
             <<"3.读者信息管理"<<endl
             <<"4.个人信息管理"<<endl
             <<"5.退出"<<endl;
        cout<<"============="<<endl;
        cin>>choice;
        switch(choice)
        {
        case 1:
            bs.face_ad();
            break;
        case 2:
            ls.face_ad();
            break;
        case 3:
            rs.face_ad();
            break;
        case 4:
            us.change(id);
            break;
        case 5:
            break;
        default:
            cerr<<"输入错误！"<<endl;
        }
    }
    while(choice!=5);
}
void interface::Librari_show(string id)
{
    string id_reader;
    int choice;
    do
    {
        system("cls");
        cout<<"1.图书信息管理"<<endl
             <<"2.读者信息查询"<<endl
             <<"3.修改密码"<<endl
             <<"4.退出"<<endl;
        cout<<"============="<<endl;
        cin>>choice;
        system("cls");
        switch(choice)
        {
        case 1:
            bs.face_li();
            break;
        case 2:
            cout<<"输入需要查询的读者信息："<<endl;
            cin>>id_reader;
            rs.show(id_reader);
            break;
        case 3:
            ls.change_pass(id);
            break;
        case 4:
            break;
        default:
            cerr<<"输入错误！"<<endl;
        }
    }
    while(choice!=4);
}
void interface::Reader_show(string id)
{
    int choice;
    do
    {
        system("cls");
        cout<<"1.借书"<<endl
             <<"2.还书"<<endl
             <<"3.图书查询"<<endl
             <<"4.未还信息查询"<<endl
             <<"5.借阅历史"<<endl
             <<"6.修改密码"<<endl
             <<"7.个人信息查询"<<endl
             <<"8.退出"<<endl;
        cout<<"============="<<endl;
        cin>>choice;
        system("cls");
        switch(choice)
        {
        case 1:
            bs.borrow_book(id);
            break;
        case 2:
            bs.return_book(id);
            break;
        case 3:
            bs.show_book();
            break;
        case 4:
            bs.check_byreader(id);
            break;
        case 5:
            bs.show_borrow(id);
            break;
        case 6:
            rs.change_pass(id);
            break;
        case 7:
            rs.show(id);
            break;
        case 8:
            break;
        default:
            cerr<<"输入错误！"<<endl;
        }
    }
    while(choice!=8);
}
