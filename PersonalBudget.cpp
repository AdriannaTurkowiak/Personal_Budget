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
