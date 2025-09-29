#include <iostream>
#include <vector>
#include <sstream>
#include <string>

int main()
{
	int m, r;
	std::cin >> m >> r;
	
	std::vector<int> a;
	std::vector<int> k;
	std::string input;

	std::cin >> input;
	input = std::string(input.begin() + 1, input.end() - 1);
	std::stringstream ss(input);
	std::string number;
	while (std::getline(ss, number, ',')) {
		a.push_back(std::stoi(number));
	}

	std::cin >> input;
	input = std::string(input.begin() + 1, input.end() - 1);
	ss.clear();
	ss.str(input);
	while (std::getline(ss, number, ',')) {
		k.push_back(std::stoi(number));
	}

	//Multiply Sum
	int sum = 0;
	for (int i = 0; i <= r; i++) {
		sum += a[i] * k[i];
	}

	std::cout << sum % m;

	return 0;
}
