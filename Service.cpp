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
         if(ch==8) //�˸�
         {
            if(index!=0)
            {
               cout<<char(8)<<" "<<char(8);
               index--;
            }
         }
         else if(ch=='\r') //�س���
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
    cout<<"�������ţ�";
    cin>>id;
    cout<<"������������";
    cin>>name;
    cout<<"���������룺";
    cin>>password;
    User user(id,name,password,"no");
    userio.input();
    if( userio.add(user))
    {
        if(userio.output())
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
            cout<<"�����������룺";
            password = cin_pass();
            if(user.get_password()==password)
            {
                cout<<"��¼�ɹ���"<<endl;
                return user.get_type();
            }
            else
                cout<<"�������"<<endl;
        }
        while(password!=user.get_password());
    }
    else
        cout<<"�˺Ŵ���"<<endl;
    cout<<"��¼ʧ�ܣ�"<<endl;
    return "Wrong��";
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
        cout<<"��ѡ���޸����ݣ�"<<endl
          <<"1.����"<<endl
          <<"2.����"<<endl
          <<"3.�˳�"<<endl;
        cin>>choice;
        switch(choice)
        {
        case 1:
            cout<<"������";
            cin>>name;
            user.set_name(name);
            break;
        case 2:
            cout<<"���룺";
            cin>>password;
            user.set_password(password);
            break;
        case 3:
            break;
        default:
            cerr<<"�������"<<endl;
        }
    }
    while(choice!=3);
    if(userio.change(id,user))
    {
        if(userio.output())
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
bool Librarian_serv::change(string id)
{
    //system("cls");
    string name,wage,seniority;
    int choice;
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
bool Librarian_serv::change_pass(string id)
{
    string password;
    cout<<"���������룺"<<endl;
    password = cin_pass();
    Librarian l;
    cout<<password<<endl;
    l.set_password(password);
    librario.input();
    if(librario.change(id,l))
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
    //system("cls");
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
        cout<<"1.������Ա��Ϣ¼��"<<endl
             <<"2.������Ա��Ϣɾ��"<<endl
             <<"3.������Ա��Ϣ�޸�"<<endl
             <<"4.������Ա��Ϣ��ѯ"<<endl
             <<"5.�˳�"<<endl;
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
            cout<<"��������Ҫ�޸ĵ���Աid��";
            cin>>id;
            change(id);
            break;
        case 4:
            cout<<"�������ѯ��Ա���ţ�";
            cin>>id;
            show(id);
            break;
        case 5:
            break;
        default:
            cerr<<"�������"<<endl;
        }
    }
    while(choice!=5);
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
bool Reader_serv::change(string id)
{
    //system("cls");
    string name,sex,reader_id;
    int choice;
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
bool Reader_serv::change_pass(string id)
{

    string password;
    cout<<"���������룺"<<endl;
    password = cin_pass();
    Reader r;
    r.set_password(password);
    readerio.input();
    if(readerio.change(id,r))
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
    //system("cls");
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
        cout<<"1.������Ϣ¼��"<<endl
             <<"2.������Ϣɾ��"<<endl
             <<"3.������Ϣ�޸�"<<endl
             <<"4.������Ϣ��ѯ"<<endl
             <<"5.�˳�"<<endl;
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
            cout<<"��������Ҫ�޸ĵĶ��߱�ţ�";
            cin>>id;
            change(id);
            break;
        case 4:
            cout<<"�������ѯ���߱�ţ�";
            cin>>id;
            show(id);
            break;
        case 5:
            break;
        default:
            cerr<<"�������"<<endl;
        }
    }
    while(choice!=5);
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
    Book book(id,name,publisher,price,"incirculation");
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
    Borrow borrow(id_book,id_reader,d1.show(),d2.show(),"notreturned",time(0));
    bookio.input();
    borrowio.input();
    if(bookio.change(id_book,"outcirculation")&&borrowio.add(borrow))
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
    //system("cls");
    string id_book;
    cout<<"������ͼ���ţ�";
    cin>>id_book;
    Data d1(time(0));
    bookio.input();
    borrowio.input();
    if(bookio.change(id_book,"incirculation")&&borrowio.return_book(id_book,id_reader,d1.show()))
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
    else
        cerr<<"����ʧ��"<<endl;
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
    //system("cls");
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
    //system("cls");
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
                book=bookio.get_book_name(variable);
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
    cout<<"�����鼮���"<<endl;
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
        cout<<"1.ͼ����Ϣ¼��"<<endl
             <<"2.ɾ��ͼ��"<<endl
             <<"3.ͼ��ά��"<<endl
             <<"4.�˳�"<<endl;
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
            cout<<"������Ҫά�޵��鼮��ţ�"<<endl;
            cin>>id;
            repair_book(id);
            break;
        case 4:
            break;
        default:
            cerr<<"�������"<<endl;
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
        cout<<"1.��ѯͼ����Ϣ"<<endl
             <<"2.��ѯ����δ����Ϣ"<<endl
             <<"3.ͼ��ά��"<<endl
             <<"4.�˳�"<<endl;
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
                cout<<"1.����ͼ���Ų�ѯ"<<endl
                     <<"2.���ն��߱�Ų�ѯ"<<endl
                     <<"3.�˳�"<<endl;
                cin>>choice2;
                 system("cls");
                switch(choice2)
                {
                case 1:
                    check_bybook();
                    break;
                case 2:
                    cout<<"���������"<<endl;
                    cin>>id;
                    check_byreader(id);
                    break;
                case 3:
                    break;
                default:
                    cerr<<"�������"<<endl;
                }
            }
            while(choice2!=3);
            break;
        case 3:
            cout<<"������Ҫά�޵��鼮��ţ�"<<endl;
            cin>>id;
            repair_book(id);
            break;
        case 4:
            break;
        default:
            cerr<<"�������"<<endl;
        }
        system("pause");
    }
    while(choice1!=4);
}
