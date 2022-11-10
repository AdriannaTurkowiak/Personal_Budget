#include "PersonalBudget.h"

void PersonalBudget::userRegister()
{
    userManager.userRegister();
}
void PersonalBudget::incomeRegister()
{
    moneyManager->incomeRegister();
}
void PersonalBudget::expenseRegister()
{
    moneyManager->expenseRegister();
}
void PersonalBudget::logIn()
{
    userManager.userLogIn();
    if(userManager.isUserLogged()){
        moneyManager = new MoneyManager(INCOME_FILE_NAME,userManager.getIdOfLoggedUser(), EXPENSE_FILE_NAME);
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
        cout << "2. Add expense" << endl;
        cout << "3. Exit" << endl;
        cout << "---------------------------" << endl;
        cout << "Your choice: " << endl;
        cin >> selection;

  return selection;
}
