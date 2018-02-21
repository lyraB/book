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
    cout<<"�������ţ�";
    cin>>id;
    cout<<"������������";
    cin>>name;
    cout<<"������н�ʣ�";
    cin>>wage;
    cout<<"������������";
    cin>>seniority;
    Librarian librarian(id,name,id,wage,seniority);
    librario.input();
    if( librario.add(librarian))
    {
        if(librario.output())
        {
            cout<<"��ӳɹ�"<<endl;
            system("pause");
            return true;
        }
        else
        {
            cerr<<"������Ϣ���ļ�ʧ��"<<endl;
        }
    }
    cerr<<"���ʧ��"<<endl;
    system("pause");
    return false;
}
bool Librarian_serv::change()
{
    system("cls");
    string id,name,wage,seniority;
    int choice;
    cout<<"��������Ҫ�޸ĵ���Աid��";
    cin>>id;
    librario.input();
    Librarian librarian=librario.get_librarian(id);
    do
    {
        cout<<"��ѡ���޸����ݣ�"<<endl
          <<"1.����"<<endl
          <<"2.����"<<endl
          <<"3.����"<<endl
          <<"4.�˳�"<<endl;
        cin>>choice;
        switch(choice)
        {
        case 1:
            cout<<"������";
            cin>>name;
            librarian.set_name(name);
            break;
        case 2:
            cout<<"���ʣ�";
            cin>>wage;
            librarian.set_wage(wage);
            break;
        case 3:
            cout<<"������";
            cin>>seniority;
            librarian.set_seniority(seniority);
            break;
        case 4:
            break;
        default:
            cerr<<"�������"<<endl;
        }
    }
    while(choice!=4);
    if(librario.change(id,librarian))
    {
        if(librario.output())
        {
            cout<<"�޸ĳɹ�"<<endl;
            system("pause");
            return true;
        }
        else
        {
            cerr<<"�ļ���д��ʧ�ܣ�"<<endl;
        }
    }
    cerr<<"�޸�ʧ�ܣ�"<<endl;
    system("pause");
    return false;
}
bool Librarian_serv::dele()
{
    system("cls");
    string id;
    cout<<"������Ҫɾ���Ĺ�����Ա���:";
    cin>>id;
    librario.input();
    if(librario.dele(id))
    {
        if(librario.output())
        {
            cout<<"ɾ���ɹ�"<<endl;
            system("pause");
            return true;
        }
        else
        {
            cerr<<"�ļ�д��ʧ��"<<endl;
        }
    }
    cerr<<"ɾ��ʧ��"<<endl;
    system("pause");
    return false;
}
bool Librarian_serv::show()
{
    system("cls");
    string id;
    cout<<"�������ѯ��Ա���ţ�";
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
    cout<<"�������ţ�";
    cin>>id;
    cout<<"������������";
    cin>>name;
    cout<<"�������Ա�";
    cin>>sex;
    cout<<"���������֤�ţ�";
    cin>>reader_id;
    Reader reader(id,name,id,sex,reader_id);
    readerio.input();
    if( readerio.add(reader))
    {
        if(readerio.output())
        {
            cout<<"��ӳɹ�"<<endl;
            system("pause");
            return true;
        }
        else
        {
            cerr<<"������Ϣʧ��"<<endl;
        }
    }
    cerr<<"���ʧ��"<<endl;
    system("pause");
    return false;
}
bool Reader_serv::change()
{
    system("cls");
    string id,name,sex,reader_id;
    int choice;
    cout<<"��������Ҫ�޸ĵ���Աid��";
    cin>>id;
    readerio.input();
    Reader reader=readerio.get_reader(id);
    do
    {
        cout<<"��ѡ���޸����ݣ�"<<endl
          <<"1.����"<<endl
          <<"2.�Ա�"<<endl
          <<"3.���֤��"<<endl
          <<"4.�˳�"<<endl;
        cin>>choice;
        switch(choice)
        {
        case 1:
            cout<<"������";
            cin>>name;
            reader.set_name(name);
            break;
        case 2:
            cout<<"�Ա�";
            cin>>sex;
            reader.set_sex(sex);
            break;
        case 3:
            cout<<"���֤�ţ�";
            cin>>reader_id;
            reader.set_reader_id(reader_id);
            break;
        case 4:
            break;
        default:
            cerr<<"�������"<<endl;
        }
    }
    while(choice!=4);
    if(readerio.change(id,reader))
    {
        if(readerio.output())
        {
            cout<<"�޸ĳɹ�"<<endl;
            system("pause");
            return true;
        }
        else
        {
            cerr<<"�ļ���д��ʧ�ܣ�"<<endl;
        }
    }
    cerr<<"�޸�ʧ�ܣ�"<<endl;
    system("pause");
    return false;
}
bool Reader_serv::dele()
{
    system("cls");
    string id;
    cout<<"������Ҫɾ���Ĺ�����Ա���:";
    cin>>id;
    readerio.input();
    if(readerio.dele(id))
    {
        if(readerio.output())
        {
            cout<<"ɾ���ɹ�"<<endl;
            system("pause");
            return true;
        }
        else
        {
            cerr<<"�ļ�д��ʧ��"<<endl;
        }
    }
    cerr<<"ɾ��ʧ��"<<endl;
    system("pause");
    return false;
}
bool Reader_serv::show()
{
    system("cls");
    string id;
    cout<<"�������ѯ��Ա���ţ�";
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
    cout<<"�������鼮��ţ�";
    cin>>id;
    cout<<"������������";
    cin>>name;
    cout<<"����������磺";
    cin>>publisher;
    cout<<"������۸�";
    cin>>price;
    Book book(id,name,publisher,price,"�ݲ����");
    bookio.input();
    if(bookio.add(book))
    {
        if(bookio.output())
        {
            cout<<"ͼ�����ɹ�"<<endl;
            return true;
        }
    }
    cout<<"ͼ�����ʧ�ܣ�"<<endl;
    return false;
}
bool Book_serv::borrow_book(string id_reader)
{
    string id_book,data_borrow,data_back,data_return;
    cout<<"�������鼮��ţ�";
    cin>>id_book;
    Data d1(time(0));
    Data d2(time(0)+5184000);
    Borrow borrow(id_book,id_reader,d1.show(),d2.show(),"δ��",time(0));
    bookio.input();
    borrowio.input();
    if(bookio.change(id_book,"�ѽ��")&&borrowio.add(borrow))
    {
        if(bookio.output()&&borrowio.output())
        {
            cout<<"����ɹ�"<<endl;
            system("pause");
            return true;
        }
        else
        {
            cerr<<"������Ϣ���ļ�ʧ��"<<endl;
        }
    }
    cerr<<"����ʧ��"<<endl;
    system("pause");
    return false;
}
bool Book_serv::return_book(string id_reader)
{
    system("cls");
    string id_book;
    cout<<"������ͼ���ţ�";
    cin>>id_book;
    Data d1(time(0));
    bookio.input();
    borrowio.input();
    if(bookio.change(id_book,"δ���")&&borrowio.return_book(id_book,id_reader,d1.show()))
    {
        if(bookio.output()&&borrowio.output())
        {
            cout<<"����ɹ�"<<endl;
            system("pause");
            return true;
        }
        else
        {
            cerr<<"�ļ���д��ʧ�ܣ�"<<endl;
            return false;
        }
    }
    cerr<<"����ʧ��"<<endl;
    system("pause");
    return false;
}
bool Book_serv::dele_book()
{
    system("cls");
    string id;
    cout<<"������Ҫɾ�����鼮���:";
    cin>>id;
    bookio.input();
    if(bookio.dele(id))
    {
        if(bookio.output())
        {
            cout<<"ɾ���ɹ�"<<endl;
            system("pause");
            return true;
        }
        else
        {
            cerr<<"�ļ�д��ʧ��"<<endl;
        }
    }
    cerr<<"ɾ��ʧ��"<<endl;
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
            cout<<"1.���鼮��Ų���"<<endl
                 <<"2.���鼮���Ʋ���"<<endl
                 <<"3.�˳�"<<endl;
            cin>>choice;
            switch(choice)
            {
            case 1:
                cout<<"�������ѯ�鼮��ţ�";
                cin>>variable;
                book=bookio.get_book_id(variable);
                book.out();
                system("pause");
                break;
            case 2:
                cout<<"����������鼮���ƣ�";
                cin>>variable;
                book=bookio.get_book_id(variable);
                book.out();
                system("pause");
                break;
            case 3:
                break;
            default:
                cerr<<"�������"<<endl;
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
    cout<<"�����鼮���"<<endl;
    cin>>id;
    borrowio.input();
    borrowio.seekrt_bybook(id,time(0));
}
bool Borrow_serv::add()
{
    string id_book,id_reader,data_borrow,data_back,data_return;
    cout<<"�������鼮��ţ�";
    cin>>id_book;
    cout<<"��������߱�ţ�";
    cin>>id_reader;
    Data d1(time(0));
    Data d2(time(0)+5184000);
    Borrow borrow(id_book,id_reader,d1.show(),d2.show(),"δ��",time(0));
    borrowio.input();
    if( borrowio.add(borrow))
    {
        if(borrowio.output())
        {
            cout<<"����ɹ�"<<endl;
            system("pause");
            return true;
        }
        else
        {
            cerr<<"������Ϣ���ļ�ʧ��"<<endl;
        }
    }
    cerr<<"����ʧ��"<<endl;
    system("pause");
    return false;
}
bool Borrow_serv::back()
{
    system("cls");
    string id_book,id_reader;
    cout<<"������ͼ���ţ�";
    cin>>id_book;
    cout<<"��������߱�ţ�";
    cin>>id_reader;
    Data d1(time(0));
    borrowio.input();
    if(borrowio.return_book(id_book,id_reader,d1.show()))
    {
        if(borrowio.output())
        {
            if(status == "out circulation")
                cout<<"���ĳɹ�"<<endl;
            else if (status == "in circulation")
                cout<<"����ɹ�"<<endl;
            system("pause");
            return true;
        }
        else
            cerr<<"�ļ���д��ʧ�ܣ�"<<endl;
    }
    else
    {
        if(status == "out circulation")
            cerr<<"����ʧ��"<<endl;
        else if (status == "in circulation")
            cerr<<"����ʧ��"<<endl;
    }
    system("pause");
    return false;
}
