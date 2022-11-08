#include "UserManager.h"

void UserManager::userRegister()
{
    user = getNewUserData();
    users.push_back(user);
    userFile.saveUserInFile(user);

    cout << endl << "New user is registered." << endl << endl;
    system("pause");
}
int UserManager::getNewUserId()
{
    if (users.empty() == true)
        return 1;
    else
        return users.back().getId() + 1;
}
User UserManager::getNewUserData()
{
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
bool UserManager::isThereLogin(string login)
{
    for(int i = 0; i < (int) users.size(); i++)
    {
        if(users[i].getLogin() == login){

            cout << endl << "There is user with this login. Try again" << endl;
            return true;
        }
    }
    return false;
}
void UserManager::incomeRegister()
{
    income = getNewIncomeInfo();
    incomes.push_back(income);
    incomesFile.saveIncomeInFile(income);
}
int UserManager::getNewIncomeId()
{
    if (incomes.empty() == true)
        return 1;
    else
        return incomes.back().getIncomeId() + 1;
}
Incomes UserManager::getNewIncomeInfo()
{
    Incomes newIncome;
    newIncome.setIncomeId(getNewIncomeId());

    //tu potrzeba przeslac userId

    int amount;
    string date, item;

    cout << "Enter date of income: ";
    cin >> date;
    newIncome.setDate(date);

    cout << "Enter item of income: " << endl;
    cin >> item;
    newIncome.setItem(item);

    cout << "Enter amount of income: " << endl;
    cin >> amount;
    newIncome.setAmount(amount);

    return newIncome;
}
