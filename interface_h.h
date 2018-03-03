#ifndef INTERFACE_H_H_INCLUDED
#define INTERFACE_H_H_INCLUDED
#include "Service_h.h"
class interface
{
private:
    User_serv us;
    Librarian_serv ls;
    Reader_serv rs;
    Book_serv bs;
public:
    void signin();
    void Admini_show(string id);
    void Librari_show(string id);
    void Reader_show(string id);
};

#endif // INTERFACE_H_H_INCLUDED
