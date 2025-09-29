#include <iostream>
#include <vector>

int main() {
	int w, r;
	std::cin >> w >> r;
	std::vector<int> A;
	std::vector<int> k;
	std::string input;
	std::cin >> input;
	for (int i = input.size() - 1; i >= 0; i--) {
		A.push_back(input[i] - '0');
	}
	std::cin >> input;
	for (int i = input.size() - 1; i >= 0; i--) {
		k.push_back(input[i] - '0');
	}

	// A * k
	std::vector<int> multiplyResult(A.size() + k.size() + 1);
	for (int i = 0; i < w; i++) {
		if (A[i] == 0) continue;
		for (int j = 0; j < k.size(); j++) {
			multiplyResult[i + j] += k[j];
		}
	}

	//Dealing Carry
	for (int i = 0; i < multiplyResult.size() - 1; i++) {
		multiplyResult[i + 1] += multiplyResult[i] / 2;
		multiplyResult[i] %= 2;
	}

	//Output Multiply Result
	int i = multiplyResult.size() - 1;
	while (multiplyResult[i] != 1 && i > 0) i--;
	if (i == 0) std::cout << multiplyResult[i];
	else {
		while(i >= 0) {
			std::cout << multiplyResult[i];
			i--;
		}
	}
	std::cout << std::endl;

	//Output Hash Result
	i = w - 1;
	for (i; i >= w - r; i--) {
		std::cout << multiplyResult[i];
	}


	return 0;
}