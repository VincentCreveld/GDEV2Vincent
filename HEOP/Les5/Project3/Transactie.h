#pragma once
#include <iostream>
#include "DatumStruct.h"
class Transactie
{
public:
	Transactie(bool isAfschrijving, double amt, Datum datum);
	void GetDetails();
	double getAmt() const;
	bool getIsAfschrijving() const;
private:
	bool isAfschrijving;
	double amt;
	Datum datum;
};



