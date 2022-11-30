#include <iostream>
#include <ctime>

#include "PersonalBudget.h"

using namespace std;

int main() {
    PersonalBudget personalBudget("Users.xml", "Income.xml", "Expense.xml");

    char selection;

    while (true) {
        selection = personalBudget.mainMenu();

        switch (selection) {
        case '1':
            personalBudget.userRegister();
            break;
        case '2': {
            personalBudget.logIn();
            {
                while(personalBudget.isUserLogged()) {
                    system("cls");
                    selection = personalBudget.userMenu();

                    switch (selection) {
                    case '1':
                        personalBudget.incomeRegister();
                        break;
                    case '2':
                        personalBudget.expenseRegister();
                        break;
                    case '3':
                        personalBudget.currentMonthBalance();
                        break;
                    case '4':
                        personalBudget.lastMonthBalance();
                        break;
                    case '5':
                        personalBudget.selectedPeriodBalance();
                        break;
                    case '6':
                        personalBudget.changePassword();
                        break;
                    case '7':
                        personalBudget.logout();
                        break;
                    default:
                        cout << "There is no such option in the menu!" << endl << endl;
                        system("pause");
                        break;
                    }
                }
            }
        }
        break;
        case '3':
            exit (0);
            break;

        default:
            cout << "There is no such option in the menu!" << endl;
            system("pause");
            break;
        }
    }

    return 0;
}
