#ifndef SERVICE_H_H_INCLUDED
#define SERVICE_H_H_INCLUDED
#include "io_h.h"
class User_serv
{
public:

};
class Librarian_serv
{
private:
    Librario librario;
public:
    bool add();
    bool change();
    bool dele();
    bool show();
};

#endif // SERVICE_H_H_INCLUDED
