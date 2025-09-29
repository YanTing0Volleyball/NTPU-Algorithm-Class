#include <iostream>
#include <vector>

struct item {
	item(int i, int va, int w, int vo) {
		id = i;
		value = va;
		weight = w;
		volume = vo;
	}

	int id;
	int value;
	int weight;
	int volume;
};

int max(int a, int b) {
	if (a >= b) return a;
	else return b;
}

int main()
{
	int N, W, V;
	std::cin >> N >> W >> V;
	std::vector<int> c(N);
	std::vector<int> w(N);
	std::vector<int> v(N);

	for (int i = 0; i < N; i++) {
		std::cin >> c[i];
	}
	for (int i = 0; i < N; i++) {
		std::cin >> w[i];
	}
	for (int i = 0; i < N; i++) {
		std::cin >> v[i];
	}
	std::vector<item> itemList;
	for (int i = 0; i < N; i++) itemList.push_back(item(i + 1, c[i], w[i], v[i]));

	std::vector<std::vector<std::vector<int>>> valuemp(N + 1, std::vector<std::vector<int>>(W + 1, std::vector<int>(V + 1, 0)));
	
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= W; j++) {
			for (int k = 1; k <= V; k++) {
				if (itemList[i - 1].weight > j || itemList[i - 1].volume > k) valuemp[i][j][k] = valuemp[i - 1][j][k];
				else {
					valuemp[i][j][k] = max(valuemp[i - 1][j][k], itemList[i - 1].value + valuemp[i - 1][j - itemList[i - 1].weight][k - itemList[i - 1].volume]);
				}
			}
		}
	}

	std::cout << valuemp[N][W][V] << std::endl;

	int numberOfItem = 0;
	std::vector<int> pickItemId;

	while (N > 0) {
		if (valuemp[N][W][V] != valuemp[N - 1][W][V]) {
			pickItemId.push_back(N);
			W -= itemList[N - 1].weight;
			V -= itemList[N - 1].volume;
			numberOfItem++;
		}
		N--;
	}

	std::cout << numberOfItem << std::endl;
	std::cout << "(" << pickItemId[numberOfItem - 1];
	for (int i = numberOfItem - 2; i >= 0; i--) {
		std::cout << "," << pickItemId[i];
	}
	std::cout << ")";

	return 0;
}