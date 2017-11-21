#include "Transactie.h"

Transactie::Transactie(bool isAfschrijving, double amt, Datum datum) : datum(datum), amt(amt), isAfschrijving(isAfschrijving)
{
}


void Transactie::GetDetails(){
	std::cout << "\n----------------------------------------------" << std::endl;
	if (!isAfschrijving){
		std::cout << "Bijschrijving: " << "€ " << amt << std::endl;
	}
	else {
		std::cout << "Afschrijving: " << "€ " << amt << std::endl;
	}
	std::cout << datum.day << "/" << datum.month << "/" << datum.year << "----------------------------------------------" << std::endl;
}

double Transactie::getAmt() const {
	return amt;
}

bool Transactie::getIsAfschrijving() const
{
	return isAfschrijving;
}
