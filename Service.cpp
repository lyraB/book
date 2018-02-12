#include <iostream>
#include <stdlib.h>
#include "io_h.h"
#include "Service_h.h"
using namespace std;
bool Librarian_serv::add()
{
    string id,name,seniority;
    int wage;
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
