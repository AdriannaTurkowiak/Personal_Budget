#ifndef USER_H
#define USER_H

#include <iostream>
#include "Markup.h"

using namespace std;

class User {
    int Id;
    string login, password, name, surname;

public:
    void setId (int newId);
    void setLogin (string newLogin);
    void setPassword (string newPassword);
    void setName (string newName);
    void setSurname (string newSurname);

    int getId ();
    string getLogin ();
    string getPassword ();
    string getName ();
    string getSurname ();
};

#endif
