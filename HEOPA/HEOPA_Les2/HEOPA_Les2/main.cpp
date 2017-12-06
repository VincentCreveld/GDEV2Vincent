#include <iostream>

#include <vector>
#include <algorithm>
#include <functional>
#include <string>
#include <stdlib.h>
#include <math.h>

using namespace std;

template <typename T>
void PrintVector(std::vector<T> vec, std::string name) {
	std::cout << std::endl << name << std::endl << "=================" <<  std::endl;
	vector<T>::iterator it = vec.begin();
	while (it != vec.end()) {
		std::cout << " " << *it;
		++it;
	}
	std::cout << std::endl << "=================" << std::endl;
}

std::string StringToUpper(std::string input) {
	std::string output = input;
	std::transform(output.begin(), output.end(), output.begin(), toupper);
	return output;
}

int main() {
	vector<string> colours{ "red", "green", "white", "blue", "orange", "green", "orange", "black", "purple" };
	PrintVector(colours, "colours");
	// gebruik functies uit <algorithm> en <functional> om (steeds vanuit een ORIGINELE kopie van deze vector)
	// 1) de vector in 2 nieuwe vectoren te splitsen, 1 met alles wat alfabetisch voor 'purple' komt, 1 met alles er na
	// 2) alle elementen UPPERCASE te maken.
	// 3) alle dubbele te verwijderen

	// 1) create copy and sort alphabetically
	vector<string> coloursCopyAlphabetical = colours;
	std::sort(coloursCopyAlphabetical.begin(), coloursCopyAlphabetical.end());
	PrintVector(coloursCopyAlphabetical, "coloursAlphabetical");

	vector<string> coloursBeforePurple = coloursCopyAlphabetical;
	auto itLess = std::copy_if(coloursCopyAlphabetical.begin(), coloursCopyAlphabetical.end(), coloursBeforePurple.begin(), bind2nd(std::less<std::string>(), "purple"));
	coloursBeforePurple.resize(std::distance(coloursBeforePurple.begin(), itLess));
	PrintVector(coloursBeforePurple, "coloursBefore");

	vector<string> coloursAfterPurple = coloursCopyAlphabetical;
	auto itGreater = std::copy_if(coloursCopyAlphabetical.begin(), coloursCopyAlphabetical.end(), coloursAfterPurple.begin(), bind2nd(std::greater<std::string>(), "purple"));
	coloursAfterPurple.resize(std::distance(coloursAfterPurple.begin(), itGreater));
	PrintVector(coloursAfterPurple, "coloursAfter");

	std::cout << std::endl;

	// 2)
	vector<string> coloursCopyCAPS = colours;
	transform(coloursCopyCAPS.begin(), coloursCopyCAPS.end(), coloursCopyCAPS.begin(), StringToUpper);
	PrintVector(coloursCopyCAPS, "coloursCAPS");

	// 3)
	vector<string> coloursCopyDouble = coloursCopyAlphabetical;
	vector<std::string>::iterator itDouble = coloursCopyDouble.begin();
	itDouble = std::unique(coloursCopyDouble.begin(), coloursCopyDouble.end());
	coloursCopyDouble.resize(std::distance(coloursCopyDouble.begin(), itDouble));
	PrintVector(coloursCopyDouble, "ColoursNoDouble");
		

	vector<double> numbers{ 10, 324422, 6, -23, 234.5, 654.1, 3.1242, -9.23, 635 };
	// gebruik functies uit <algorithm> en <functional> om (steeds vanuit een ORIGINELE kopie van deze vector)
	// 1) alle negatieve elementen te verwijderen
	// 2) voor alle elementen te bepalen of ze even of oneven zijn
	// 3) de som, het gemiddelde, en het product van alle getallen te berekenen

	// print out content:
	
	// 1)
	vector<double> numbersCopy = numbers;
	auto itNum1 = std::copy_if(numbers.begin(), numbers.end(), numbersCopy.begin(), bind2nd(std::greater<double>(), 0));
	numbersCopy.resize(std::distance(numbersCopy.begin(), itNum1));
	PrintVector(numbersCopy, "numbers Greater");

	// 2) Een decimaal getal is per definitie oneven, dit is waarom ik de floor(abs(*itA)) != abs(*itA) check. Dit bekijkt of het getal integer of double/float is
	vector<double> numbersCopyEven;
	vector<double> numbersCopyUneven;
	vector<double>::iterator itA = numbers.begin();
	while (itA != numbers.end()) {
		if ((int)floor(abs(*itA)) % 2 == 1 || floor(abs(*itA)) != abs(*itA)) {
			numbersCopyUneven.push_back(*itA);
		}
		else {
			numbersCopyEven.push_back(*itA);
		}
		++itA;
	}

	PrintVector(numbersCopyEven, "numbers Even");
	PrintVector(numbersCopyUneven, "numbers Uneven");

	// 3)
	double sum = 0;
	double product = 1;
	double average = 0;

	for (auto& n : numbers)
		sum += n;
	for (auto& n : numbers)
		product *= n;
	double temp = 0;
	int count = 0;
	for (auto& n : numbers) {
		temp += n;
		count++;
	}
	average = (temp / count);

	std::cout << "sum: " << sum << " product: " << product << " average: " << average << std::endl;

	system("pause");
	return 0;
}

