#include <iostream>
#include <vector>
#include <algorithm>

int divideCount = 0, sortingCount = 0;

void swap(int& a, int& b) {
	int temp = a;
	a = b;
	b = temp;

	return;
}

int partition(std::vector<int>& numberList, int left, int right) {
	if (left >= right) return -1;

	int pivot = numberList[left];
	int i = left, j = left + 1;

	while (j <= right) {
		if (numberList[j] <= pivot) {
			i++;
			swap(numberList[i], numberList[j]);
		}
		j++;
	}

	swap(numberList[left], numberList[i]);

	return i;
}

float BFPRT(std::vector<int> numberList, int ithSmallest) {
	int n = numberList.size();
	//if (n == 1) return numberList[0];
	if (n <= 5) {
		sortingCount++;
		std::sort(numberList.begin(), numberList.end());
		return numberList[ithSmallest - 1];
	} else {
		std::vector<float> mediumList;
		for (int i = 0; i < n / 5; i++) {
			std::vector<int> groupList(numberList.begin() + i * 5, numberList.begin() + (i + 1) * 5);
			sortingCount++;
			std::sort(groupList.begin(), groupList.end());
			mediumList.push_back(groupList[2]);
		}
		
		divideCount++;
		//int mediumOfmedium = BFPRT(std::vector<int>(mediumList.begin(), mediumList.end()), ((n / 5 + 1) / 2));
		std::sort(mediumList.begin(), mediumList.end());
		int mediumOfmedium = mediumList[(n / 5 + 1) / 2 - 1];

		//Finding The Medium Of Medium
		for (int i = 0; i < n; i++) {
			if (numberList[i] == mediumOfmedium) {
				swap(numberList[0], numberList[i]);
				break;
			}
		}

		//Partion
		sortingCount++;
		int mediumRank = partition(numberList, 0, n - 1);

		//Judge mediumRank
		if (mediumRank == ithSmallest - 1) return numberList[mediumRank];
		else if (mediumRank < ithSmallest - 1) {
			divideCount++;
			return BFPRT(std::vector<int>(numberList.begin()+mediumRank + 1, numberList.end()), ithSmallest - mediumRank - 1);
		}
		else {
			divideCount++;
			return BFPRT(std::vector<int>(numberList.begin(), numberList.begin() + mediumRank), ithSmallest);
		}
	}


}


int main()
{
	int n, i;
	std::cin >> n >> i;
	std::vector<int> numberList;
	int temp;
	for (int k = 0; k < n; k++) {
		std::cin >> temp;
		numberList.push_back(temp);
	}

	float mediumValue = BFPRT(numberList, i);


	std::cout << mediumValue << std::endl << divideCount << std::endl << sortingCount;

	return 0;
}
