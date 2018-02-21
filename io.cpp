#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include "io_h.h"
#include "User_h.h"
using namespace std;

//User 的 文件 读写

bool Userio::output()
{
    fstream outfile("User.txt",ios::out);
    if(!outfile.good())
    {
        cerr<<"打开错误!"<<endl;
        return false;
    }
    vector<User>::iterator itor=userio.begin();//begin返回向量首元素的迭代器
    for(;itor!=userio.end();itor++)
    {
        if(itor!=userio.end())
        {
            outfile<<itor->show()<<itor->get_type()<<endl;
        }
    }
    outfile.close();
    return true;
}
bool Userio::input()
{
    fstream infile("User.txt",ios::in);
    if(!infile.good())
    {
        cerr<<"打开错误！"<<endl;
        return false;
    }
    userio.clear();
    while(!infile.eof())
    {
        string id,name,password, type;
        infile>>id>>name>>password>>type;
        if(infile.eof()) break;
        User user(id,name,password,type);
        userio.push_back(user);
    }
    infile.close();
    return true;
}
bool Userio::add(User user)
{
    vector<User>::iterator itor=userio.begin();
    for (;itor!=userio.end();itor++)
    {
        if(itor->get_id()==user.get_id())
            return false;
    }
    userio.push_back(user);
    return true;
}
bool Userio::change(string id,User user)
{
    vector<User>::iterator itor=userio.begin();
    for (;itor!=userio.end();itor++)
    {
        if(itor->get_id()==id)
        {
            if(user.get_name()!="no")
            {
               itor->set_name(user.get_name());
            }
            if(user.get_password()!="no")
            {
               itor->set_password(user.get_password());
            }
            if(user.get_type()!="no")
            {
               itor->set_type(user.get_type());
            }
        }
        return true;
    }
    return false;
}
bool Userio::dele(string id)
{
    vector<User>::iterator itor=userio.begin();
    for (;itor!=userio.end();itor++)
    {
        if(itor->get_id()==id)
        {
            userio.erase(itor);
            return true;
        }
    }
    return false;
}

//Librarian 的 文件 读写

bool Librario::output()
{
    Userio::output();
    fstream outfile("Librarian.txt",ios::out);
    if(!outfile)
    {
        cerr<<"打开错误!"<<endl;
        return false;
    }
    vector<Librarian>::iterator itor=librario.begin();
    for(;itor!=librario.end();itor++)
    {
        if(itor!=librario.end())
        {
            outfile<<itor->show()<<endl;
        }
    }
    outfile.close();
    return true;
}
bool Librario::input()
{
    Userio::input();
    fstream infile("Librarian.txt",ios::in);
    if(!infile)
    {
        cerr<<"打开错误！"<<endl;
        return false;
    }
    librario.clear();
    while(!infile.eof())
    {
        string id,name,password,seniority,wage;
        infile>>id>>name>>password>>wage>>seniority;
        if(infile.eof()) break;
        Librarian libra(id,name,password,wage,seniority);
        librario.push_back(libra);
    }
    infile.close();
    return true;
}
bool Librario::add(Librarian libra)
{
    User user(libra.get_id(),libra.get_name(),libra.get_password(),"librarian");
    Userio::add(user);
    vector<Librarian>::iterator itor=librario.begin();
    for (;itor!=librario.end();itor++)
    {
        if(itor->get_id()==libra.get_id())
            return false;
    }
    librario.push_back(libra);
    return true;
}
bool Librario::change(string id,Librarian libra)
{
    User user(libra.get_id(),libra.get_name(),libra.get_password(),"librarian");
    Userio::change(id,user);
    vector<Librarian>::iterator itor=librario.begin();
    for (;itor!=librario.end();itor++)
    {
        if(itor->get_id()==id)
        {
            if(libra.get_name()!="no")
            {
               itor->set_name(libra.get_name());
            }
            if(libra.get_password()!="no")
            {
               itor->set_password(libra.get_password());
            }
            if(libra.get_wage()!="no")
            {
               itor->set_wage(libra.get_wage());
            }
            if(libra.get_seniority()!="no")
            {
               itor->set_seniority(libra.get_seniority());
            }
        }
        return true;
    }
    return false;
}
bool Librario::dele(string id)
{
    Userio::dele(id);
    vector<Librarian>::iterator itor=librario.begin();
    for (;itor!=librario.end();itor++)
    {
        if(itor->get_id()==id)
        {
            librario.erase(itor);
            return true;
        }
    }
    return false;
}

Librarian Librario::get_librarian(string id)
{
    vector<Librarian>::iterator itor=librario.begin();
    for (;itor!=librario.end();itor++)
    {
        if(itor->get_id()==id)
        {
            return *itor;
        }
    }
    Librarian wrong;
    return wrong;
}

//Reader 的 文件 读写

bool Readerio::output()
{
    Userio::output();
    fstream outfile("Reader.txt",ios::out);
    if(!outfile)
    {
        cerr<<"打开错误!"<<endl;
        return false;
    }
    vector<Reader>::iterator itor=readio.begin();
    for(;itor!=readio.end();itor++)
    {
        if(itor!=readio.end())
        {
            outfile<<itor->show()<<endl;
        }
    }
    outfile.close();
    return true;
}
bool Readerio::input()
{
    Userio::input();
    fstream infile("Reader.txt",ios::in);
    if(!infile)
    {
        cerr<<"打开错误！"<<endl;
        return false;
    }
    readio.clear();
    while(!infile.eof())
    {
        string id,name,password,read_id,age;
        infile>>id>>name>>password>>age>>read_id;
        if(infile.eof()) break;
        Reader reader(id,name,password,age,read_id);
        readio.push_back(reader);
    }
    infile.close();
    return true;
}
bool Readerio::add(Reader reader)
{
    User user(reader.get_id(),reader.get_name(),reader.get_password(),"reader");
    if(Userio::add(user))
    {
        vector<Reader>::iterator itor=readio.begin();
        readio.push_back(reader);
        return true;
    }
    return false;
}
bool Readerio::change(string id,Reader reader)
{
    User user(reader.get_id(),reader.get_name(),reader.get_password(),"reader");
    Userio::change(id,user);
    vector<Reader>::iterator itor=readio.begin();
    for (;itor!=readio.end();itor++)
    {
        if(itor->get_id()==id)
        {
            if(reader.get_name()!="no")
            {
               itor->set_name(reader.get_name());
            }
            if(reader.get_password()!="no")
            {
               itor->set_password(reader.get_password());
            }
            if(reader.get_sex()!="no")
            {
               itor->set_sex(reader.get_sex());
            }
            if(reader.get_reader_id()!="no")
            {
               itor->set_reader_id(reader.get_reader_id());
            }
        }
        return true;
    }
    return false;
}
bool Readerio::dele(string id)
{
    Userio::dele(id);
    vector<Reader>::iterator itor=readio.begin();
    for (;itor!=readio.end();itor++)
    {
        if(itor->get_id()==id)
        {
            readio.erase(itor);
            return true;
        }
    }
    return false;
}
Reader Readerio::get_reader(string id)
{
    vector<Reader>::iterator itor=readio.begin();
    for (;itor!=readio.end();itor++)
    {
        if(itor->get_id()==id)
        {
            return *itor;
        }
    }
    Reader wrong;
    return wrong;
}


//书籍信息

bool Bookio::input()
{
    fstream infile("Book.txt",ios::in);
    if(!infile.good())
    {
        cerr<<"打开错误！"<<endl;
        return false;
    }
    bookio.clear();
    while(!infile.eof())
    {
        string id,name,publisher,price,status;
        infile>>id>>name>>publisher>>price>>status;
        if(infile.eof()) break;
        Book book(id,name,publisher,price,status);
        bookio.push_back(book);
    }
    infile.close();
    return true;
}
bool Bookio::output()
{
    fstream outfile("Book.txt",ios::out);
    if(!outfile.good())
    {
        cerr<<"打开错误!"<<endl;
        return false;
    }
    vector<Book>::iterator itor=bookio.begin();//begin返回向量首元素的迭代器
    for(;itor!=bookio.end();itor++)
    {
        if(itor!=bookio.end())
        {
            outfile<<itor->show()<<endl;
        }
    }
    outfile.close();
    return true;
}
bool Bookio::add(Book book)
{
    vector<Book>::iterator itor=bookio.begin();
    for (;itor!=bookio.end();itor++)
    {
        if(itor->get_id()==book.get_id())
        {
            cout<<"书籍编号重复"<<endl;
            return false;
        }

    }
    bookio.push_back(book);
    return true;
}
bool Bookio::change(string id,string status)
{
    vector<Book>::iterator itor=bookio.begin();
    for (;itor!=bookio.end();itor++)
    {
        if(itor->get_id()==id)
        {
            if(itor->get_status() == "已借出"&&status == "已借出")
            {
                cout<<"已借出"<<endl;
                return false;
            }
            if(itor->get_status() == "暂不外借"&&status == "已借出")
            {
                cout<<"暂不外借"<<endl;
                return false;
            }
            if(itor->get_status() == "已借出"&&status == "未借出")
            {
                cout<<"书籍已在库"<<endl;
                return false;
            }
            itor->set_status(status);
            return true;
        }
    }
    return false;
}
bool Bookio::dele(string id)
{
    vector<Book>::iterator itor=bookio.begin();
    for (;itor!=bookio.end();itor++)
    {
        if(itor->get_id()==id)
        {
            bookio.erase(itor);
            return true;
        }
    }
    return false;
}
Book Bookio::get_book_id(string id)
{
    vector<Book>::iterator itor=bookio.begin();
    for (;itor!=bookio.end();itor++)
    {
        if(itor->get_id()==id)
        {
            return *itor;
        }
    }
    Book wrong;
    return wrong;
}
Book Bookio::get_book_name(string name)
{
    vector<Book>::iterator itor=bookio.begin();
    for (;itor!=bookio.end();itor++)
    {
        if(itor->get_name()==name)
        {
            return *itor;
        }
    }
    Book wrong;
    return wrong;
}
//借还信息

bool Borrowio::input()
{
    fstream infile("Borrow.txt",ios::in);
    if(!infile.good())
    {
        cerr<<"打开错误！"<<endl;
        return false;
    }
    borrio.clear();
    while(!infile.eof())
    {
        string id_book,id_reader,data_borrow,data_back,data_return;
        int time;
        infile>>id_book>>id_reader>>data_borrow>>data_back>>data_return>>time;
        if(infile.eof()) break;
        Borrow borrow(id_book,id_reader,data_borrow,data_back,data_return,time);
        borrio.push_back(borrow);
    }
    infile.close();
    return true;
}
bool Borrowio::output()
{
    fstream outfile("Borrow.txt",ios::out);
    if(!outfile.good())
    {
        cerr<<"打开错误!"<<endl;
        return false;
    }
    vector<Borrow>::iterator itor=borrio.begin();
    for(;itor!=borrio.end();itor++)
    {
        if(itor!=borrio.end())
        {
            outfile<<itor->get_string()<<itor->get_time()<<endl;
        }
    }
    outfile.close();
    return true;
}
bool Borrowio::add(Borrow bor)
{
    borrio.push_back(bor);
    return true;
}
bool Borrowio::return_book(string id_book,string id_reader,string data)
{
    vector<Borrow>::iterator itor=borrio.begin();
    for (;itor!=borrio.end();itor++)
    {
        if(itor->get_id_book()==id_book)
        {
            if(itor->get_id_reader()==id_reader)
            {
                if(itor->get_data_return()=="未还")
                {
                    itor->set_data_return(data);
                    return true;
                }
            }
        }
    }
    return false;
}
void Borrowio::seekrt_bybook(string id_book,int time_now)
{
    vector<Borrow>::iterator itor=borrio.begin();
    int i = 1;
    for (;itor!=borrio.end();itor++)
    {
        if(itor->get_id_book()==id_book&&(itor->get_time())+5184000>=time_now)
        {
            i = 0;
            cout<<"书籍编号："<<id_book<<endl
                  <<"读者编号："<<itor->get_id_reader()<<endl
                  <<"应还日期："<<itor->get_data_return()<<endl;
        }
    }
    if(i)
        cout<<"无未还信息"<<endl;
}
void Borrowio::seekrt_byreader(string id_reader,int time_now)
{
    vector<Borrow>::iterator itor=borrio.begin();
    int i = 1;
    for (;itor!=borrio.end();itor++)
    {
        if(itor->get_id_reader()==id_reader&&(itor->get_time())+5184000>=time_now)
        {
            i = 0;
            cout<<"书籍编号："<<itor->get_id_book()<<endl
                  <<"读者编号："<<id_reader<<endl
                  <<"应还日期："<<itor->get_data_return()<<endl;
        }
    }
    if(i)
        cout<<"无未还信息"<<endl;
}
Borrow Borrowio::get_bybook(string id)
{
    vector<Borrow>::iterator itor=borrio.begin();
    for (;itor!=borrio.end();itor++)
    {
        if(itor->get_id_book()==id)
        {
            return *itor;
        }
    }
    Borrow wrong;
    return wrong;
}
Borrow Borrowio::get_byreader(string id)
{
    vector<Borrow>::iterator itor=borrio.begin();
    for (;itor!=borrio.end();itor++)
    {
        if(itor->get_id_reader()==id)
        {
            return *itor;
        }
    }
    Borrow wrong;
    return wrong;
}
