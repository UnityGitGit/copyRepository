#include <iostream>
#include <algorithm>
#include <functional>
#include <numeric>
#include <vector>
#include <string>

template<typename T>
void coutVector(std::vector<T>& colours) {
	std::vector<T>::iterator it = colours.begin();
	while (it != colours.end()) {
		std::cout << *it << " ";
		it++;
	}

	std::cout << std::endl;
}

bool afterPurple(std::string& colour) {
	if (colour.compare("purple") > 0) {
		return true;
	}
	return false;
}
void assignment1(std::vector<std::string> colours) {
	std::sort(colours.begin(), colours.end(), std::less<std::string>());

	std::vector<std::string> beforeColours = colours;
	std::vector<std::string> afterColours = colours;
	std::vector<std::string>::iterator newEnd =
		std::remove_if(beforeColours.begin(), beforeColours.end(), afterPurple);
	beforeColours.erase(newEnd - 1, beforeColours.end());

	std::vector<std::string>::iterator newStart = 
		std::remove_if(afterColours.begin(), afterColours.end(), afterPurple);
	afterColours.erase(afterColours.begin(), newStart);

	std::cout << "Before purple: ";
	coutVector(beforeColours);
	std::cout << "After purple: ";
	coutVector(afterColours);
	std::cout << std::endl;
}

void upperCaseIt(std::string& colour) {
	for (char& c : colour) c = toupper(c);
}
void assignment2(std::vector<std::string> colours) {
	for_each(colours.begin(), colours.end(), upperCaseIt);

	coutVector(colours);
	std::cout << std::endl;
}

void assignment3(std::vector<std::string> colours) {
	std::sort(colours.begin(), colours.end(), std::less<std::string>());

	std::vector<std::string>::iterator it = colours.begin();
	while (it != (colours.end() - 1)) {
		if ((*it).compare(*(it + 1)) == 0) {
			it = colours.erase(it);
		}
		else {
			it++;
		}
	}

	coutVector(colours);
	std::cout << std::endl;
}

bool isNegative(double value) {
	if (value < 0) {
		return true;
	}
	return false;
}
void assignment4(std::vector<double> numbers) {
	std::vector<double>::iterator newEnd = std::remove_if(numbers.begin(), numbers.end(), isNegative);
	numbers.erase(newEnd, numbers.end());

	coutVector(numbers);
	std::cout << std::endl;
}

bool oddNumber(double number) {
	if (number == (int)number) {
		if((int)number % 2 == 0){
			return false;
		}
	}
	return true;
}
bool evenNumber(double number) {
	return !oddNumber(number);
}
void assignment5(std::vector<double> numbers) {
	std::vector<double> evenNumbers = numbers;
	std::vector<double> oddNumbers = numbers;

	std::vector<double>::iterator newEnd = std::remove_if(evenNumbers.begin(), evenNumbers.end(), oddNumber);
	evenNumbers.erase(newEnd, evenNumbers.end());

	newEnd = std::remove_if(oddNumbers.begin(), oddNumbers.end(), evenNumber);
	oddNumbers.erase(newEnd, oddNumbers.end());

	std::cout << "Even numbers: " << std::endl;
	coutVector(evenNumbers);
	std::cout << "Odd numbers: " << std::endl;
	coutVector(oddNumbers);

	std::cout << std::endl;
}

void assignment6(std::vector<double> numbers) {	
	auto sum = std::accumulate(numbers.begin(), numbers.end(), 0.0);
	auto av = sum / numbers.size();
	auto product = std::accumulate(numbers.begin(), numbers.end(), 1.0, std::multiplies<double>());

	std::cout << "Sum of all numbers: " << sum << std::endl;
	std::cout << "Average of all numbers: " << av << std::endl;
	std::cout << "Product of all numbers: " << product << std::endl;
	std::cout << std::endl;
}

int main() {
	std::vector<std::string> colours{ "red", "green", "white", "blue", "orange", "green", "orange", "black", "purple" };

	std::cout << "   Start colours: " << std::endl;
	coutVector(colours);
	std::cout << std::endl;

	// 1) de vector in 2 nieuwe vectoren te splitsen, 1 met alles wat alfabetisch voor 'purple' komt, 1 met alles er na
	std::cout << "1 -> Separate array by purple: " << std::endl;
	assignment1(colours);

	// 2) alle elementen UPPERCASE te maken.
	std::cout << "2 -> Make colours UPPERCASE: " << std::endl;
	assignment2(colours);

	// 3) alle dubbele te verwijderen
	std::cout << "3 -> Remove double values: " << std::endl;
	assignment3(colours);

	std::vector<double> numbers{ 10, 324422, 6, -23, 234.5, 654.1, 3.1242, -9.23, 635, 4 };

	std::cout << "   Start numbers: " << std::endl;
	coutVector(numbers);
	std::cout << std::endl;

	// gebruik functies uit <algorithm> en <functional> om (steeds vanuit een ORIGINELE copie van deze vector)
	// 1) alle negatieve elementen te verwijderen
	std::cout << "1 -> Remove negative values: " << std::endl;
	assignment4(numbers);

	// 2) voor alle elementen te bepalen of ze even of oneven zijn
	std::cout << "2 -> Determine odd and even numbers: " << std::endl;
	assignment5(numbers);

	// 3) de som, het gemiddelde, en het product van alle getallen te berekenen
	std::cout << "3 -> Find the sum, the average and the product of all the numbers: " << std::endl;
	assignment6(numbers);

	std::cin.get();
	return 0;
}