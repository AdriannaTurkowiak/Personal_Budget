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

/*

time_t now = time(0);
tm *ltm = localtime(&now);

int year = 1900 + ltm->tm_year;
int month = 1 + ltm->tm_mon;
int day = ltm->tm_mday;
cout << year <<"-"<< month << "-" << day << endl;

*/

    return 0;
}
