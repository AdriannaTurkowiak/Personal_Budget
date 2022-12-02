#include "IncomesFile.h"

void IncomesFile::saveIncomeInFile(Incomes newIncome) {
    CMarkup xml;
    bool fileExists = xml.Load(INCOME_FILE_NAME);

    if (!fileExists) {
        xml.AddElem("IncomeData");
    }

    xml.FindElem();
    xml.IntoElem();

    xml.AddElem("SingleIncome");
    xml.IntoElem();
    xml.AddElem( "IncomeID", newIncome.getIncomeId());
    xml.AddElem( "UserID", newIncome.getUserId());
    xml.AddElem( "Date", newIncome.getDate());
    xml.AddElem( "Item", newIncome.getItem());
    xml.AddElem( "Amount", newIncome.getAmount());
    xml.OutOfElem();
    xml.Save(INCOME_FILE_NAME);
}

vector <Incomes> IncomesFile::readFile(int loggedUserId) {
    Incomes newIncome;

    CMarkup xml;
    xml.Load (INCOME_FILE_NAME);

    xml.FindElem("IncomeData");
    xml.IntoElem();

    while(xml.FindElem("SingleIncome")) {
        xml.IntoElem();

        xml.FindElem("IncomeID");
        int incomeId = stoi(xml.GetData());
        newIncome.setIncomeId(incomeId);

        xml.FindElem("UserID");
        int userId = stoi(xml.GetData());
        newIncome.setUserId(userId);

        xml.FindElem("Date");
        string date = xml.GetData();
        newIncome.setDate(date);

        xml.FindElem("Item");
        string item = xml.GetData();
        newIncome.setItem(item);

        xml.FindElem("Amount");
        string amount = xml.GetData();
        newIncome.setAmount(amount);

        xml.OutOfElem();
        incomes.push_back(newIncome);
    }
    return incomes;
}
