#pragma once
#include <string>
#include <queue>
#include "Transactie.h"

class Bankrekening
{
public:
	Bankrekening(double saldo);
	Bankrekening operator+(const Transactie& transactie) const;
	Bankrekening operator-(const Transactie& transactie) const;
	friend std::ostream& operator<<(std::ostream& lhs, const Bankrekening & rekening);
	void displayLog() const;
	void printQueue(std::queue<Transactie> q) const;
private:
	double saldo = 0;
	std::queue<Transactie>* transactieLog;
};

