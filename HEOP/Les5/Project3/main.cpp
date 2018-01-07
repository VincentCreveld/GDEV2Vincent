#include "Bankrekening.h"

//Bankrekening* bankRekening;

int main(){
	Bankrekening* bankRekening = new Bankrekening(100.0);
	Transactie tBij1 = Transactie(false, 1000.50, Datum(1, 12, 1999));
	Transactie tBij2 = Transactie(false, 86.75, Datum(2, 12, 2000));
	Transactie tBij3 = Transactie(false, 10.00, Datum(3, 2, 2001));
	Transactie tAf1 = Transactie(true, 0.50, Datum(4, 5, 2009));
	Transactie tAf2 = Transactie(true, 8.46, Datum(5, 7, 2010));
	Transactie tAf3 = Transactie(true, 765.00, Datum(6, 9, 2013));


	*bankRekening + tBij2;
	*bankRekening - tAf3;
	*bankRekening - tAf2;

	std::cout << bankRekening->getSaldo() << std::endl;
	std::cout << *(bankRekening) << std::endl;

	*bankRekening + tBij1;
	*bankRekening + tBij3;
	*bankRekening - tAf1;

	std::cout << *(bankRekening) << std::endl;

	system("pause");
	return 0;
}