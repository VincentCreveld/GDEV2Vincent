#include "Bankrekening.h"



Bankrekening::Bankrekening(double saldo) : saldo(saldo)
{
	transactieLog = new std::queue<Transactie>();
}

Bankrekening Bankrekening::operator+(const Transactie & transactie) const
{
	if (transactie.getIsAfschrijving() == false) {
		double tempSaldo = saldo + transactie.getAmt();
		Bankrekening::transactieLog->push(transactie);
		return Bankrekening(tempSaldo);
	}
	else {
		throw std::invalid_argument("Illegal operation!");
		//std::cout << "Illegal operation!" << std::endl;
		return Bankrekening(saldo);
	}
}

Bankrekening Bankrekening::operator-(const Transactie & transactie) const
{
	if (transactie.getIsAfschrijving()) {
		double tempSaldo = saldo - transactie.getAmt();
		Bankrekening::transactieLog->push(transactie);
		return Bankrekening(tempSaldo);
	}
	else {
		throw std::invalid_argument("Illegal operation!");
		//std::cout << "Illegal operation!" << std::endl;
		return Bankrekening(saldo);
	}
}

void Bankrekening::displayLog() const
{
	printQueue(*transactieLog);
}

void Bankrekening::printQueue(std::queue<Transactie> q) const {
	if (q.empty()) {
		std::cout << "No transactions left!" << std::endl;
	}
	while (!q.empty()) {
		q.front().GetDetails();
		q.pop();
	}
	std::cout << std::endl;
}

double Bankrekening::getSaldo()
{
	return saldo;
}

std::ostream & operator<<(std::ostream & lhs, const Bankrekening & rekening)
{
	lhs << "#Bankrekening" << std::endl;
	rekening.displayLog();
	return lhs;
}
