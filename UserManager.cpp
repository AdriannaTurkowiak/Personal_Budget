#include "UserManager.h"

void UserManager::userRegister() {
    user = getNewUserData();
    users.push_back(user);
    userFile.saveUserInFile(user);

    cout << endl << "New user is registered." << endl << endl;
    system("pause");
}

int UserManager::getNewUserId() {
    if (users.empty() == true)
        return 1;
    else
        return users.back().getId() + 1;
}

User UserManager::getNewUserData() {
    User newUser;
    newUser.setId(getNewUserId());

    string login, password, name, surname;

    do {
        cout << "Enter login: ";
        cin >> login;
        newUser.setLogin(login);
    } while (isThereLogin(newUser.getLogin()) == true);

    cout << "Enter Password: " << endl;
    cin >> password;
    newUser.setPassword(password);

    cout << "Enter Name: " << endl;
    cin >> name;
    newUser.setName(name);

    cout << "Enter Surname: " << endl;
    cin >> surname;
    newUser.setSurname(surname);

    return newUser;
}

bool UserManager::isThereLogin(string login) {
    for(int i = 0; i < (int) users.size(); i++) {
        if(users[i].getLogin() == login) {

            cout << endl << "There is user with this login. Try again" << endl;
            return true;
        }
    }
    return false;
}

int UserManager::getIdOfLoggedUser() {
    return loggedUserId;
}

void UserManager::userLogIn() {
    string login = "", password = "";

    cout << endl << "Enter login: ";
    cin >> login;

    for (int i = 0; i < (int) users.size(); i++) {
        if (users[i].getLogin() == login) {
            for (int quantity = 3; quantity > 0; quantity--) {
                cout << "Enter password. Attempts left: " << quantity << ": ";
                cin >> password;

                if (users[i].getPassword() == password) {
                    cout << endl << "You logged in." << endl << endl;
                    system("pause");
                    loggedUserId = users[i].getId();
                    return;
                }
            }
            cout << "Wrong password entered 3 times." << endl;
            system("pause");
            return;
        }
    }
    cout << "There is no user with this login" << endl << endl;
    system("pause");
    return;
}

bool UserManager::isUserLogged() {
    if (loggedUserId > 0)
        return true;
    else {
        return false;
    }
}
