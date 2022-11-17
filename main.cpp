#include <iostream>
#include <ctime>

#include "PersonalBudget.h"

using namespace std;

int main()
{
PersonalBudget personalBudget("Users.xml", "Income.xml", "Expense.xml");

char selection;
system("cls");

cout << " >>> MAIN MENU <<<" << endl;
cout << "---------------------------" << endl;
cout << "1. Add user to a file" << endl;
cout << "2. LogIn" << endl;
cout << "3. Exit" << endl;
cout << "---------------------------" << endl;
cout << "Your choice: " << endl;

cin >> selection;
 while (true) {
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
                            personalBudget.compareDate();
                            break;
                        case '4':
                            personalBudget.findToday();
                            break;
                        case '5':
                            //personalBudget.compareDate();
                            break;
                        case '6':
                            exit (0);
                            break;
                        }
                    }
                }
            }
            break;
        case '3':
            exit (0);
            break;
}
 }

    return 0;
}
