#include <iostream>
#include <cfloat>
#include <vector>

int main()
{
	int n, m;
	std::cin >> n >> m;
	std::vector<std::vector<float>> edgeTable(n + 1, std::vector<float>(n + 1, -1));

	for (int k = 0; k < m; k++) {
		int i, j;
		float w;
		std::cin >> i >> j >> w;
		edgeTable[i][j] = w;
	}

	int s;
	std::cin >> s;

	std::vector<float> dijkstraTable(n + 1, FLT_MAX);
	std::vector<bool> choosedTable(n + 1, false);
	std::vector<int> parentTable(n + 1, 0);
	dijkstraTable[s] = 0;
	choosedTable[s] = true;

	int currenNodeId = s;
	for (int i = 1; i < n; i++) {
		for (int j = 1; j <= n; j++) {
			if (edgeTable[currenNodeId][j] != -1 && choosedTable[j] == false && dijkstraTable[j] > edgeTable[currenNodeId][j] + dijkstraTable[currenNodeId]) {
				dijkstraTable[j] = edgeTable[currenNodeId][j] + dijkstraTable[currenNodeId];
				parentTable[j] = currenNodeId;
			}
		}

		int minId;
		float minWeight = FLT_MAX;
		for (int j = 1; j <= n; j++) {
			if(choosedTable[j] == false && dijkstraTable[j] < minWeight){
				minId = j;
				minWeight = dijkstraTable[j];
			}
		}
		currenNodeId = minId;
		choosedTable[currenNodeId] = true;
	}


	for (int i = 1; i < n; i++) {
		std::cout << dijkstraTable[i] << " ";
	}
	std::cout << dijkstraTable[n] << std::endl;

	for (int i = 1; i < n; i++) {
		std::cout << parentTable[i] << " ";
	}
	std::cout << parentTable[n];

	return 0;
}
