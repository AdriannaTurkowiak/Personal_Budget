#include "PersonalBudget.h"

void PersonalBudget::userRegister() {
    userManager.userRegister();
}

void PersonalBudget::incomeRegister() {
    moneyManager->incomeRegister();
}

void PersonalBudget::expenseRegister() {
    moneyManager->expenseRegister();
}

void PersonalBudget::logIn() {
    userManager.userLogIn();
    if(userManager.isUserLogged()) {
        moneyManager = new MoneyManager(INCOME_FILE_NAME,userManager.getIdOfLoggedUser(), EXPENSE_FILE_NAME);
    }
}

bool PersonalBudget::isUserLogged() {
    return userManager.isUserLogged();
}

char PersonalBudget::mainMenu() {

char selection = {0};

    system("cls");
    cout << " >>> MAIN MENU <<<" << endl;
    cout << "---------------------------" << endl;
    cout << "1. Add user to a file" << endl;
    cout << "2. LogIn" << endl;
    cout << "3. Exit" << endl;
    cout << "---------------------------" << endl;
    cout << "Your choice: " << endl;

    selection = AuxiliaryMethods::loadCharacter();

    return selection;
}

char PersonalBudget::userMenu() {

    char selection;

    cout << " >>> USER MENU <<<" << endl;
    cout << "---------------------------" << endl;
    cout << "1. Add income" << endl;
    cout << "2. Add expense" << endl;
    cout << "3. Current month balance" << endl;
    cout << "4. Last month balance" << endl;
    cout << "5. Selected period balance" << endl;
    cout << "6. Change password" << endl;
    cout << "7. Logout" << endl;
    cout << "---------------------------" << endl;
    cout << "Your choice: " << endl;

    selection = AuxiliaryMethods::loadCharacter();

    return selection;
}

void PersonalBudget::currentMonthBalance() {
   moneyManager->currentMonthBalance();
}

void PersonalBudget::lastMonthBalance() {
    moneyManager->lastMonthBalance();
}

void PersonalBudget::selectedPeriodBalance() {
    moneyManager->selectedPeriodBalance();
}

void PersonalBudget::changePassword() {
    userManager.changePassword();
}

void PersonalBudget::logout() {
    userManager.logout();
}
