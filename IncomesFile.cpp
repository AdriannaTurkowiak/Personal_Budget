#include "IncomesFile.h"

void IncomesFile::saveFile(Incomes newIncome)
{
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

vector <Incomes> IncomesFile::readFile(int loggedUserId)
{
   Incomes newIncome;

    CMarkup xml;
    xml.Load ("Income.xml");

    xml.FindElem("IncomeData");
    xml.IntoElem();
        while(xml.FindElem("SingleIncome")){
                xml.IntoElem();

                xml.FindElem("IncomeID");
                newIncome.setIncomeId(atoi(MCD_2PCSZ(xml.GetData())));

                xml.FindElem("UserID");
                newIncome.setUserId(atoi(MCD_2PCSZ(xml.GetData())));

                xml.FindElem("Date");
                newIncome.setDate(MCD_2PCSZ(xml.GetData()));

                xml.FindElem("Item");
                newIncome.setItem(MCD_2PCSZ(xml.GetData()));

                xml.FindElem("Amount");
                newIncome.setAmount(atoi(MCD_2PCSZ(xml.GetData())));

    xml.OutOfElem();
    incomes.push_back(newIncome);}

return incomes;
}
