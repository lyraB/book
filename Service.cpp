#include <iostream>
#include <stdlib.h>
#include "io_h.h"
#include "Service_h.h"
using namespace std;
bool Librarian_serv::add()
{
    string id,name,seniority;
    int wage;
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
