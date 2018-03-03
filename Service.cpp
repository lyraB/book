#include <iostream>
#include <stdlib.h>
#include <string>
#include <ctime>
#include <cstring>
#include<conio.h>
#include "io_h.h"
#include "Service_h.h"
#include "data_h.h"
using namespace std;
string cin_pass()
{
     int index=0;
     char password[20];
     while(1)
     {
         char ch;
         ch=getch();
         if(ch==8) //退格
         {
            if(index!=0)
            {
               cout<<char(8)<<" "<<char(8);
               index--;
            }
         }
         else if(ch=='\r') //回车键
         {
            password[index]='\0';
            cout<<endl;
            break;
        }
         else
         {
              cout<<"*";
              password[index++]=ch;
         }
     }
     string p = password;
     return p;
}
bool User_serv::add()
{
    string id,name,password;
    cout<<"请输入编号：";
    cin>>id;
    cout<<"请输入姓名：";
    cin>>name;
    cout<<"请输入密码：";
    cin>>password;
    User user(id,name,password,"no");
    userio.input();
    if( userio.add(user))
    {
        if(userio.output())
        {
            cout<<"添加成功"<<endl;
            system("pause");
            return true;
        }
        else
        {
            cerr<<"保存信息到文件失败"<<endl;
        }
    }
    cerr<<"添加失败"<<endl;
    system("pause");
    return false;
}
string User_serv::signin(string id)
{
    string password;
    User user;
    userio.input();
    user = userio.get_user(id);
    if(user.get_id()!="no")
    {
        do
        {
            cout<<"输入您的密码：";
            password = cin_pass();
            if(user.get_password()==password)
            {
                cout<<"登录成功！"<<endl;
                return user.get_type();
            }
            else
                cout<<"密码错误！"<<endl;
        }
        while(password!=user.get_password());
    }
    else
        cout<<"账号错误！"<<endl;
    cout<<"登录失败！"<<endl;
    return "Wrong！";
}
bool User_serv::change(string id)
{
    system("cls");
    string name,password;
    int choice;
    userio.input();
    User user=userio.get_user(id);
    do
    {
        cout<<"请选择修改内容："<<endl
          <<"1.姓名"<<endl
          <<"2.密码"<<endl
          <<"3.退出"<<endl;
        cin>>choice;
        switch(choice)
        {
        case 1:
            cout<<"姓名：";
            cin>>name;
            user.set_name(name);
            break;
        case 2:
            cout<<"密码：";
            cin>>password;
            user.set_password(password);
            break;
        case 3:
            break;
        default:
            cerr<<"输入错误！"<<endl;
        }
    }
    while(choice!=3);
    if(userio.change(id,user))
    {
        if(userio.output())
        {
            cout<<"修改成功"<<endl;
            system("pause");
            return true;
        }
        else
        {
            cerr<<"文件再写入失败！"<<endl;
        }
    }
    cerr<<"修改失败！"<<endl;
    system("pause");
    return false;
}
bool Librarian_serv::add()
{
    string id,name,seniority,wage;
    cout<<"请输入编号：";
    cin>>id;
    cout<<"请输入姓名：";
    cin>>name;
    cout<<"请输入薪资：";
    cin>>wage;
    cout<<"请输入资历：";
    cin>>seniority;
    Librarian librarian(id,name,id,wage,seniority);
    librario.input();
    if( librario.add(librarian))
    {
        if(librario.output())
        {
            cout<<"添加成功"<<endl;
            system("pause");
            return true;
        }
        else
        {
            cerr<<"保存信息到文件失败"<<endl;
        }
    }
    cerr<<"添加失败"<<endl;
    system("pause");
    return false;
}
bool Librarian_serv::change(string id)
{
    //system("cls");
    string name,wage,seniority;
    int choice;
    librario.input();
    Librarian librarian=librario.get_librarian(id);
    do
    {
        cout<<"请选择修改内容："<<endl
          <<"1.姓名"<<endl
          <<"2.工资"<<endl
          <<"3.资历"<<endl
          <<"4.退出"<<endl;
        cin>>choice;
        switch(choice)
        {
        case 1:
            cout<<"姓名：";
            cin>>name;
            librarian.set_name(name);
            break;
        case 2:
            cout<<"工资：";
            cin>>wage;
            librarian.set_wage(wage);
            break;
        case 3:
            cout<<"资历：";
            cin>>seniority;
            librarian.set_seniority(seniority);
            break;
        case 4:
            break;
        default:
            cerr<<"输入错误！"<<endl;
        }
    }
    while(choice!=4);
    if(librario.change(id,librarian))
    {
        if(librario.output())
        {
            cout<<"修改成功"<<endl;
            system("pause");
            return true;
        }
        else
        {
            cerr<<"文件再写入失败！"<<endl;
        }
    }
    cerr<<"修改失败！"<<endl;
    system("pause");
    return false;
}
bool Librarian_serv::change_pass(string id)
{
    string password;
    cout<<"输入新密码："<<endl;
    password = cin_pass();
    Librarian l;
    cout<<password<<endl;
    l.set_password(password);
    librario.input();
    if(librario.change(id,l))
    {
        if(librario.output())
        {
            cout<<"修改成功"<<endl;
            system("pause");
            return true;
        }
        else
        {
            cerr<<"文件再写入失败！"<<endl;
        }
    }
    cerr<<"修改失败！"<<endl;
    system("pause");
    return false;

}
bool Librarian_serv::dele()
{
    //system("cls");
    string id;
    cout<<"请输入要删除的工作人员编号:";
    cin>>id;
    librario.input();
    if(librario.dele(id))
    {
        if(librario.output())
        {
            cout<<"删除成功"<<endl;
            system("pause");
            return true;
        }
        else
        {
            cerr<<"文件写入失败"<<endl;
        }
    }
    cerr<<"删除失败"<<endl;
    system("pause");
    return false;
}
bool Librarian_serv::show(string id)
{
    //system("cls");
    if(librario.input())
    {
        Librarian l=librario.get_librarian(id);
        l.out();
        system("pause");
        return true;
    }
    else
        return false;
}
void Librarian_serv::face_ad()
{
    string id;
    int choice;
    do
    {
        system("cls");
        cout<<"1.工作人员信息录入"<<endl
             <<"2.工作人员信息删除"<<endl
             <<"3.工作人员信息修改"<<endl
             <<"4.工作人员信息查询"<<endl
             <<"5.退出"<<endl;
        cin>>choice;
        system("cls");
        switch(choice)
        {
        case 1:
            add();
            break;
        case 2:
            dele();
            break;
        case 3:
            cout<<"请输入你要修改的人员id：";
            cin>>id;
            change(id);
            break;
        case 4:
            cout<<"输入待查询人员工号：";
            cin>>id;
            show(id);
            break;
        case 5:
            break;
        default:
            cerr<<"输入错误！"<<endl;
        }
    }
    while(choice!=5);
}
bool Reader_serv::add()
{
    string id,name,sex,reader_id;
    cout<<"请输入编号：";
    cin>>id;
    cout<<"请输入姓名：";
    cin>>name;
    cout<<"请输入性别：";
    cin>>sex;
    cout<<"请输入身份证号：";
    cin>>reader_id;
    Reader reader(id,name,id,sex,reader_id);
    readerio.input();
    if( readerio.add(reader))
    {
        if(readerio.output())
        {
            cout<<"添加成功"<<endl;
            system("pause");
            return true;
        }
        else
        {
            cerr<<"保存信息失败"<<endl;
        }
    }
    cerr<<"添加失败"<<endl;
    system("pause");
    return false;
}
bool Reader_serv::change(string id)
{
    //system("cls");
    string name,sex,reader_id;
    int choice;
    readerio.input();
    Reader reader=readerio.get_reader(id);
    do
    {
        cout<<"请选择修改内容："<<endl
          <<"1.姓名"<<endl
          <<"2.性别"<<endl
          <<"3.身份证号"<<endl
          <<"4.退出"<<endl;
        cin>>choice;
        switch(choice)
        {
        case 1:
            cout<<"姓名：";
            cin>>name;
            reader.set_name(name);
            break;
        case 2:
            cout<<"性别：";
            cin>>sex;
            reader.set_sex(sex);
            break;
        case 3:
            cout<<"身份证号：";
            cin>>reader_id;
            reader.set_reader_id(reader_id);
            break;
        case 4:
            break;
        default:
            cerr<<"输入错误！"<<endl;
        }
    }
    while(choice!=4);
    if(readerio.change(id,reader))
    {
        if(readerio.output())
        {
            cout<<"修改成功"<<endl;
            system("pause");
            return true;
        }
        else
        {
            cerr<<"文件再写入失败！"<<endl;
        }
    }
    cerr<<"修改失败！"<<endl;
    system("pause");
    return false;
}
bool Reader_serv::change_pass(string id)
{

    string password;
    cout<<"输入新密码："<<endl;
    password = cin_pass();
    Reader r;
    r.set_password(password);
    readerio.input();
    if(readerio.change(id,r))
    {
        if(readerio.output())
        {
            cout<<"修改成功"<<endl;
            system("pause");
            return true;
        }
        else
        {
            cerr<<"文件再写入失败！"<<endl;
        }
    }
    cerr<<"修改失败！"<<endl;
    system("pause");
    return false;
}
bool Reader_serv::dele()
{
    //system("cls");
    string id;
    cout<<"请输入要删除的工作人员编号:";
    cin>>id;
    readerio.input();
    if(readerio.dele(id))
    {
        if(readerio.output())
        {
            cout<<"删除成功"<<endl;
            system("pause");
            return true;
        }
        else
        {
            cerr<<"文件写入失败"<<endl;
        }
    }
    cerr<<"删除失败"<<endl;
    system("pause");
    return false;
}
bool Reader_serv::show(string id)
{
    //system("cls");
    if(readerio.input())
    {
        Reader reader=readerio.get_reader(id);
        reader.out();
        system("pause");
        return true;
    }
    else
        return false;
}
void Reader_serv::face_ad()
{
    string id;
    int choice;
    do
    {
        system("cls");
        cout<<"1.读者信息录入"<<endl
             <<"2.读者信息删除"<<endl
             <<"3.读者信息修改"<<endl
             <<"4.读者信息查询"<<endl
             <<"5.退出"<<endl;
        cin>>choice;
        system("cls");
        switch(choice)
        {
        case 1:
            add();
            break;
        case 2:
            dele();
            break;
        case 3:
            cout<<"请输入你要修改的读者编号：";
            cin>>id;
            change(id);
            break;
        case 4:
            cout<<"输入待查询读者编号：";
            cin>>id;
            show(id);
            break;
        case 5:
            break;
        default:
            cerr<<"输入错误！"<<endl;
        }
    }
    while(choice!=5);
}
bool Book_serv::add()
{
    string id,name,publisher,price;
    cout<<"请输入书籍编号：";
    cin>>id;
    cout<<"请输入书名：";
    cin>>name;
    cout<<"请输入出版社：";
    cin>>publisher;
    cout<<"请输入价格：";
    cin>>price;
    Book book(id,name,publisher,price,"incirculation");
    bookio.input();
    if(bookio.add(book))
    {
        if(bookio.output())
        {
            cout<<"图书入库成功"<<endl;
            return true;
        }
    }
    cout<<"图书入库失败！"<<endl;
    return false;
}
bool Book_serv::borrow_book(string id_reader)
{
    string id_book,data_borrow,data_back,data_return;
    cout<<"请输入书籍编号：";
    cin>>id_book;
    Data d1(time(0));
    Data d2(time(0)+5184000);
    Borrow borrow(id_book,id_reader,d1.show(),d2.show(),"notreturned",time(0));
    bookio.input();
    borrowio.input();
    if(bookio.change(id_book,"outcirculation")&&borrowio.add(borrow))
    {
        if(bookio.output()&&borrowio.output())
        {
            cout<<"借书成功"<<endl;
            system("pause");
            return true;
        }
        else
        {
            cerr<<"保存信息到文件失败"<<endl;
        }
    }
    cerr<<"借书失败"<<endl;
    system("pause");
    return false;
}
bool Book_serv::return_book(string id_reader)
{
    //system("cls");
    string id_book;
    cout<<"请输入图书编号：";
    cin>>id_book;
    Data d1(time(0));
    bookio.input();
    borrowio.input();
    if(bookio.change(id_book,"incirculation")&&borrowio.return_book(id_book,id_reader,d1.show()))
    {
        if(bookio.output()&&borrowio.output())
        {
            cout<<"还书成功"<<endl;
            system("pause");
            return true;
        }
        else
        {
            cerr<<"文件再写入失败！"<<endl;
            return false;
        }
    }
    else
        cerr<<"还书失败"<<endl;
    system("pause");
    return false;
}
bool Book_serv::repair_book(string id)
{
    bookio.input();
    if(bookio.change(id,"notforcirculation"))
    {
        if(bookio.output()&&borrowio.output())
        {
            cout<<"出库成功"<<endl;
            system("pause");
            return true;
        }
        else
        {
            cerr<<"文件再写入失败！"<<endl;
            return false;
        }
    }
    cerr<<"出库失败"<<endl;
    system("pause");
    return false;
}
bool Book_serv::dele_book()
{
    //system("cls");
    string id;
    cout<<"请输入要删除的书籍编号:";
    cin>>id;
    bookio.input();
    if(bookio.dele(id))
    {
        if(bookio.output())
        {
            cout<<"删除成功"<<endl;
            system("pause");
            return true;
        }
        else
        {
            cerr<<"文件写入失败"<<endl;
        }
    }
    cerr<<"删除失败"<<endl;
    system("pause");
    return false;
}
bool Book_serv::show_book()
{
    //system("cls");
    string variable;
    Book book;
    int choice;
    if(bookio.input())
    {
        do
        {
            cout<<"1.按书籍编号查找"<<endl
                 <<"2.按书籍名称查找"<<endl
                 <<"3.退出"<<endl;
            cin>>choice;
            switch(choice)
            {
            case 1:
                cout<<"输入待查询书籍编号：";
                cin>>variable;
                book=bookio.get_book_id(variable);
                book.out();
                system("pause");
                break;
            case 2:
                cout<<"输入待查找书籍名称：";
                cin>>variable;
                book=bookio.get_book_name(variable);
                book.out();
                system("pause");
                break;
            case 3:
                break;
            default:
                cerr<<"输入错误！"<<endl;
            }
        }
        while(choice!=3);
        return true;
    }
    return false;
}
bool Book_serv::show_borrow(string id_reader)
{
    //system("cls");
    if(borrowio.input())
    {
        Borrow borrow;
        borrow=borrowio.get_byreader(id_reader);
        borrow.out();
        system("pause");
        return true;
    }
    return false;
}
void Book_serv::check_bybook()
{
    string id;
    cout<<"输入书籍编号"<<endl;
    cin>>id;
    borrowio.input();
    borrowio.seekrt_bybook(id,time(0));
}
void Book_serv::check_byreader(string id)
{
    borrowio.input();
    borrowio.seekrt_byreader(id,time(0));
}
void Book_serv::face_ad()
{
    string id;
    int choice;
    do
    {
        system("cls");
        cout<<"1.图书信息录入"<<endl
             <<"2.删除图书"<<endl
             <<"3.图书维修"<<endl
             <<"4.退出"<<endl;
        cin>>choice;
        system("cls");
        switch(choice)
        {
        case 1:
            add();
            break;
        case 2:
            dele_book();
            break;
        case 3:
            cout<<"输入需要维修的书籍编号："<<endl;
            cin>>id;
            repair_book(id);
            break;
        case 4:
            break;
        default:
            cerr<<"输入错误！"<<endl;
        }
        system("pause");
    }
    while(choice!=4);
}
void Book_serv::face_li()
{
    string id;
    int choice1,choice2;
    do
    {
        system("cls");
        cout<<"1.查询图书信息"<<endl
             <<"2.查询到期未还信息"<<endl
             <<"3.图书维修"<<endl
             <<"4.退出"<<endl;
        cin>>choice1;
        system("cls");
        switch(choice1)
        {
        case 1:
            show_book();
            break;
        case 2:
            do
            {
                cout<<"1.按照图书编号查询"<<endl
                     <<"2.按照读者编号查询"<<endl
                     <<"3.退出"<<endl;
                cin>>choice2;
                 system("cls");
                switch(choice2)
                {
                case 1:
                    check_bybook();
                    break;
                case 2:
                    cout<<"输入读书编号"<<endl;
                    cin>>id;
                    check_byreader(id);
                    break;
                case 3:
                    break;
                default:
                    cerr<<"输入错误！"<<endl;
                }
            }
            while(choice2!=3);
            break;
        case 3:
            cout<<"输入需要维修的书籍编号："<<endl;
            cin>>id;
            repair_book(id);
            break;
        case 4:
            break;
        default:
            cerr<<"输入错误！"<<endl;
        }
        system("pause");
    }
    while(choice1!=4);
}
