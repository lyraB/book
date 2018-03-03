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
        cout<<"�������˺ţ�";
        cin>>id;
        type = us.signin(id);
    }
    while(type=="Wrong��");
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
        cout<<"1.ͼ����Ϣ����"<<endl
             <<"2.������Ա����"<<endl
             <<"3.������Ϣ����"<<endl
             <<"4.������Ϣ����"<<endl
             <<"5.�˳�"<<endl;
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
            cerr<<"�������"<<endl;
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
        cout<<"1.ͼ����Ϣ����"<<endl
             <<"2.������Ϣ��ѯ"<<endl
             <<"3.�޸�����"<<endl
             <<"4.�˳�"<<endl;
        cout<<"============="<<endl;
        cin>>choice;
        system("cls");
        switch(choice)
        {
        case 1:
            bs.face_li();
            break;
        case 2:
            cout<<"������Ҫ��ѯ�Ķ�����Ϣ��"<<endl;
            cin>>id_reader;
            rs.show(id_reader);
            break;
        case 3:
            ls.change_pass(id);
            break;
        case 4:
            break;
        default:
            cerr<<"�������"<<endl;
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
        cout<<"1.����"<<endl
             <<"2.����"<<endl
             <<"3.ͼ���ѯ"<<endl
             <<"4.δ����Ϣ��ѯ"<<endl
             <<"5.������ʷ"<<endl
             <<"6.�޸�����"<<endl
             <<"7.������Ϣ��ѯ"<<endl
             <<"8.�˳�"<<endl;
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
            cerr<<"�������"<<endl;
        }
    }
    while(choice!=8);
}
