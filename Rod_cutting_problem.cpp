#include <iostream>
#include <vector>

int main()
{
	int k;
	std::cin >> k;
	std::vector<int> p(k + 1, 0);
	std::vector<int> maxPriceTable(k + 1, 0);
	std::vector<int> bestDevideTable(k + 1, 0);

	for (int i = 1; i <= k; i++) {
		std::cin >> p[i];
	}

	// Bottom Up Build Max Price Table
	for (int i = 1; i <= k; i++) {
		int maxPrice = 0;
		for (int j = i; j >= 1; j--) {
			if(p[j] + maxPriceTable[i - j] >= maxPrice){
				maxPrice = p[j] + maxPriceTable[i - j];
				bestDevideTable[i] = j;
			}
			maxPriceTable[i] = maxPrice;
		}
	}

	std::cout << maxPriceTable[k] << std::endl;

	// Cut Count
	int numberOfRods = 0;
	int remainLength = k;
	std::vector<int> rodsLength;
	while (remainLength > 0) {
		int bestCut = bestDevideTable[remainLength];
		rodsLength.push_back(bestCut);
		numberOfRods++;
		remainLength -= bestCut;
	}

	std::cout << numberOfRods << std::endl;

	std::cout << k << "=" << rodsLength[0];
	for (int i = 1; i < rodsLength.size(); i++) {
		std::cout << "+" << rodsLength[i];
	}

	return 0;
}