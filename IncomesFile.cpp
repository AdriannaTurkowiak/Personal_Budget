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

    return;
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
        newIncome.setIncomeId(atoi(MCD_2PCSZ(xml.GetData())));

        xml.FindElem("UserID");
        newIncome.setUserId(atoi(MCD_2PCSZ(xml.GetData())));

        xml.FindElem("IncomeDate");
        newIncome.setDate(MCD_2PCSZ(xml.GetData()));

        xml.FindElem("IncomeItem");
        newIncome.setItem(MCD_2PCSZ(xml.GetData()));

        xml.FindElem("IncomeAmount");
        newIncome.setAmount(atoi(MCD_2PCSZ(xml.GetData())));

        xml.OutOfElem();
        incomes.push_back(newIncome);
    }
    return incomes;
}

