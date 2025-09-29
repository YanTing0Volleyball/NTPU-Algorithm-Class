#include <iostream>
#include <vector>
#include <cfloat>

std::pair<std::vector<float>, bool> BellManFord(std::vector<std::vector<float>> edgeTable, int source) {
	int n = edgeTable.size() - 1;
	std::vector<float> bellManTable(n + 1, FLT_MAX);
	bellManTable[source] = 0;
	
	for (int i = 1; i < n; i++) {
		for (int j = 1; j <= n; j++) {
			for (int k = 1;  k <= n; k++) {
				if (bellManTable[k] > edgeTable[j][k] + bellManTable[j]) {
					bellManTable[k] = edgeTable[j][k] + bellManTable[j];
				}
			}
		}
	}

	bool haveNegativeCycle = false;

	for (int j = 1; j <= n; j++) {
		for (int k = 1; k <= n; k++) {
			if (bellManTable[k] > edgeTable[j][k] + bellManTable[j]) {
				haveNegativeCycle = true;
			}
		}
	}

	return std::pair<std::vector<float>, bool>(bellManTable, haveNegativeCycle);
}

std::vector<float> Dijkstra(std::vector<std::vector<float>> edgeTable, int source) {
	int n = edgeTable.size() - 1;
	std::vector<bool> choosedNode(n + 1, false);
	std::vector<float> dijkstraTable(n + 1, FLT_MAX);
	choosedNode[source] = true;
	dijkstraTable[source] = 0;
	
	int currentNode = source;
	for (int i = 1; i < n; i++) {
		for (int j = 1; j <= n; j++) {
			if (!choosedNode[j] && dijkstraTable[j] > dijkstraTable[currentNode] + edgeTable[currentNode][j]) {
				dijkstraTable[j] = dijkstraTable[currentNode] + edgeTable[currentNode][j];
			}
		}
	
		int minId = -1;
		float minWeight = FLT_MAX;
		for (int j = 1; j <= n; j++) {
			if (!choosedNode[j] && dijkstraTable[j] <= minWeight) {
				minId = j;
				minWeight = dijkstraTable[j];
			}
		}

		currentNode = minId;
		choosedNode[currentNode] = true;
	}

	return dijkstraTable;
}

int main()
{
	int n, m;
	std::cin >> n >> m;

	std::vector<std::vector<float>> edgeTable(n + 1, std::vector<float>(n + 1, FLT_MAX));

	for (int k = 0; k < m; k++) {
		int i, j;
		float w;
		std::cin >> i >> j >> w;
		edgeTable[i][j] = w;
	}

	std::vector<std::vector<float>> bellManFordEdgeTable = edgeTable;
	bellManFordEdgeTable.push_back(std::vector<float>(n + 2, 0));
	for (int i = 1; i <= n; i++) {
		bellManFordEdgeTable[i].push_back(FLT_MAX);
	}
	std::vector<float> bellManTable;
	bool haveNegativeCycle;

	std::pair<std::vector<float>, bool> result = BellManFord(bellManFordEdgeTable, n + 1);
	bellManTable = result.first;
	haveNegativeCycle = result.second;
	
	for (int i = 1; i < n; i++) {
		std::cout << bellManTable[i] << " ";
	}
	std::cout << bellManTable[n] << std::endl << std::endl;

	if (haveNegativeCycle) return 0;

	std::vector<std::vector<float>> johnsonEdgeTable = edgeTable;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			johnsonEdgeTable[i][j] = johnsonEdgeTable[i][j] + bellManTable[i] - bellManTable[j];
		}
	}

	std::vector<std::vector<float>> johnsonTable;
	std::vector<float> temp;
	johnsonTable.push_back(std::vector<float>(n + 1, FLT_MAX));
	for (int i = 1; i <= n; i++) {
		temp = Dijkstra(johnsonEdgeTable, i);
		johnsonTable.push_back(temp);
	}

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			johnsonTable[i][j] = johnsonTable[i][j] - bellManTable[i] + bellManTable[j];
		}
	}

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j < n; j++) {
			if (johnsonTable[i][j] == FLT_MAX) {
				std::cout << "N ";
			}
			else {
				std::cout << johnsonTable[i][j] << " ";
			}
		}
		if (johnsonTable[i][n] == FLT_MAX) {
			std::cout << "N" << std::endl;
		}
		else {
			std::cout << johnsonTable[i][n] << std::endl;
		}
	}

	return 0;
}
