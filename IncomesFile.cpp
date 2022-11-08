#include "IncomesFile.h"

void IncomesFile::saveIncomeInFile(Incomes newIncome)
{
    CMarkup xml;
    bool fileExists = xml.Load("Incomes.xml");

    if (!fileExists) {
        xml.AddElem("IncomeData");
    }
    xml.FindElem();
    xml.IntoElem();

    xml.AddElem( "SingleIncome");
    xml.IntoElem();
    xml.AddElem( "IncomeId", newIncome.getIncomeId());
    xml.AddElem( "UserID", newIncome.getUserId());
    xml.AddElem( "IncomeDate", newIncome.getDate());
    xml.AddElem( "IncomeItem", newIncome.getItem());
    xml.AddElem( "IncomeAmount", newIncome.getAmount());
    xml.OutOfElem();

    xml.Save( "Incomes.xml");
}
vector <Incomes> IncomesFile::readFile()
{
    Incomes newIncome;

    CMarkup xml;
    xml.Load ("Incomes.xml");

    xml.FindElem("IncomeData");
    xml.IntoElem();
    while(xml.FindElem("SingleIncome")) {
        xml.IntoElem();

        xml.FindElem("IncomeId");
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
