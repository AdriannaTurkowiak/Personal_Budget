#include "UserFile.h"

void UserFile::saveUserInFile(User newUser)
{
    CMarkup xml;
    bool fileExists = xml.Load(USER_FILE_NAME);

    if (!fileExists) {
        xml.AddElem("PersonalData");
    }

    xml.FindElem();
    xml.IntoElem();

    xml.AddElem("SingleUser");
    xml.IntoElem();
    xml.AddElem( "UserID", newUser.getId());
    xml.AddElem( "Login", newUser.getLogin());
    xml.AddElem( "Password", newUser.getPassword());
    xml.AddElem( "Name", newUser.getName());
    xml.AddElem( "Surname", newUser.getSurname());
    xml.OutOfElem();

    xml.Save(USER_FILE_NAME);

    return;
}
vector <User> UserFile::readFile()
{

    User newUser;

    CMarkup xml;
    xml.Load (USER_FILE_NAME);

    xml.FindElem("PersonalData");
    xml.IntoElem();
    while(xml.FindElem("SingleUser")) {
        xml.IntoElem();

        xml.FindElem("UserID");
        newUser.setId(atoi(MCD_2PCSZ(xml.GetData())));

        xml.FindElem("Login");
        newUser.setLogin(MCD_2PCSZ(xml.GetData()));

        xml.FindElem("Password");
        newUser.setPassword(MCD_2PCSZ(xml.GetData()));

        xml.FindElem("Name");
        newUser.setName(MCD_2PCSZ(xml.GetData()));

        xml.FindElem("Surname");
        newUser.setSurname(MCD_2PCSZ(xml.GetData()));

        xml.OutOfElem();
        users.push_back(newUser);
    }

    return users;
}

