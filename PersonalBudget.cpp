#include "PersonalBudget.h"

void PersonalBudget::userRegister()
{
    userManager.userRegister();
}
void PersonalBudget::incomeRegister()
{
    incomeManager->incomeRegister();
}
void PersonalBudget::logIn()
{
    userManager.userLogIn();
    if(userManager.isUserLogged()){
        incomeManager = new IncomeManager(INCOME_FILE_NAME,userManager.getIdOfLoggedUser());
    }
}
bool PersonalBudget::isUserLogged()
{
    return userManager.isUserLogged();
}
char PersonalBudget::userMenu()
{
  char selection;

        cout << " >>> USER MENU <<<" << endl;
        cout << "---------------------------" << endl;
        cout << "1. Add income" << endl;
        cout << "2. Exit" << endl;
        cout << "---------------------------" << endl;
        cout << "Your choice: " << endl;
        cin >> selection;

  return selection;
}
