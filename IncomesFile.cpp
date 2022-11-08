#include "IncomesFile.h"

void IncomesFile::saveFile()
{
CMarkup xml;
xml.AddElem( "IncomeData");                   //tytul pliku
xml.IntoElem();
xml.AddElem( "IncomeID", "001");
xml.AddElem( "UserID", "01" );
xml.AddElem( "Date", "2022-11-01" );
xml.AddElem( "item", "jedzenie" );
xml.AddElem( "amount", "10" );
xml.Save( "Incomes.xml");
}
