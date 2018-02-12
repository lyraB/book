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
            outfile<<itor->get_id()<<" "<<itor->get_name()<<" "<<itor->get_password()<<" "<<itor->get_type();
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
    int i = 0;
    while(!infile.eof())
    {
        string id,name,password;
        int type;
        infile>>id>>name>>password>>type;
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
            if(user.get_type()!=0)
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
void Userio::show(string id)
{
    vector<User>::iterator itor=userio.begin();
    for (;itor!=userio.end();itor++)
    {
        if(itor->get_id()==id)
        {
            cout<<"ID："<<itor->get_id()<<endl
                  <<"姓名："<<itor->get_name()<<endl;
            return;
        }
    }
    cerr<<"Wrong ID!"<<endl;
    return;
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
        //if(itor!=librario.end())
        //{
            outfile<<itor->get_id()<<" "<<itor->get_name()<<" "<<itor->get_password()<<" "
                    <<itor->get_wage()<<" "<<itor->get_seniority()<<endl;
        //}
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
        string id,name,password,seniority;
        int wage;
        infile>>id>>name>>password>>wage>>seniority;
        Librarian libra(id,name,password,wage,seniority);
        librario.push_back(libra);
    }
    infile.close();
}
bool Librario::add(Librarian libra)
{
    User user(libra.get_id(),libra.get_name(),libra.get_password(),1);
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
    User user(libra.get_id(),libra.get_name(),libra.get_password(),1);
    Userio::change(id,user);
    vector<Librarian>::iterator itor=librario.begin();
    for (;itor!=librario.end();itor++)
    {
        if(itor->get_id()==id)
        {
            if(libra.get_wage()!=0)
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
void Librario::show(string id)
{
    Userio::show(id);
    vector<Librarian>::iterator itor=librario.begin();
    for (;itor!=librario.end();itor++)
    {
        if(itor->get_id()==id)
        {
            cout<<"工资："<<itor->get_wage()<<endl
                  <<"资历："<<itor->get_seniority()<<endl;
            return;
        }
    }
    cerr<<"Wrong ID!"<<endl;
    return;
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
            outfile<<itor->get_id()<<" "<<itor->get_name()<<" "<<itor->get_password()<<" "
                    <<itor->get_age()<<" "<<itor->get_reader_id()<<endl;
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
        string id,name,password,read_id;
        int age;
        infile>>id>>name>>password>>age>>read_id;
        Reader reader(id,name,password,age,read_id);
        readio.push_back(reader);
    }
    infile.close();
}
bool Readerio::add(Reader)
{

}
