#include <iostream>
#include <stdlib.h>
#include <string>
#include <ctime>
#include "io_h.h"
#include "Service_h.h"
#include "data_h.h"
using namespace std;

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
bool Librarian_serv::change()
{
    system("cls");
    string id,name,wage,seniority;
    int choice;
    cout<<"请输入你要修改的人员id：";
    cin>>id;
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
bool Librarian_serv::dele()
{
    system("cls");
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
bool Librarian_serv::show()
{
    system("cls");
    string id;
    cout<<"输入待查询人员工号：";
    cin>>id;
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
bool Reader_serv::change()
{
    system("cls");
    string id,name,sex,reader_id;
    int choice;
    cout<<"请输入你要修改的人员id：";
    cin>>id;
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
bool Reader_serv::dele()
{
    system("cls");
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
bool Reader_serv::show()
{
    system("cls");
    string id;
    cout<<"输入待查询人员工号：";
    cin>>id;
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
    Book book(id,name,publisher,price,"暂不外借");
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
    Borrow borrow(id_book,id_reader,d1.show(),d2.show(),"未还",time(0));
    bookio.input();
    borrowio.input();
    if(bookio.change(id_book,"已借出")&&borrowio.add(borrow))
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
    system("cls");
    string id_book;
    cout<<"请输入图书编号：";
    cin>>id_book;
    Data d1(time(0));
    bookio.input();
    borrowio.input();
    if(bookio.change(id_book,"未借出")&&borrowio.return_book(id_book,id_reader,d1.show()))
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
    cerr<<"还书失败"<<endl;
    system("pause");
    return false;
}
bool Book_serv::dele_book()
{
    system("cls");
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
    system("cls");
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
                book=bookio.get_book_id(variable);
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
    system("cls");
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
bool Borrow_serv::add()
{
    string id_book,id_reader,data_borrow,data_back,data_return;
    cout<<"请输入书籍编号：";
    cin>>id_book;
    cout<<"请输入读者编号：";
    cin>>id_reader;
    Data d1(time(0));
    Data d2(time(0)+5184000);
    Borrow borrow(id_book,id_reader,d1.show(),d2.show(),"未还",time(0));
    borrowio.input();
    if( borrowio.add(borrow))
    {
        if(borrowio.output())
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
bool Borrow_serv::back()
{
    system("cls");
    string id_book,id_reader;
    cout<<"请输入图书编号：";
    cin>>id_book;
    cout<<"请输入读者编号：";
    cin>>id_reader;
    Data d1(time(0));
    borrowio.input();
    if(borrowio.return_book(id_book,id_reader,d1.show()))
    {
        if(borrowio.output())
        {
            if(status == "out circulation")
                cout<<"借阅成功"<<endl;
            else if (status == "in circulation")
                cout<<"还书成功"<<endl;
            system("pause");
            return true;
        }
        else
            cerr<<"文件再写入失败！"<<endl;
    }
    else
    {
        if(status == "out circulation")
            cerr<<"借阅失败"<<endl;
        else if (status == "in circulation")
            cerr<<"还书失败"<<endl;
    }
    system("pause");
    return false;
}
