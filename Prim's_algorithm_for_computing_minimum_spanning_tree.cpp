#include <iostream>
#include <vector>
#include <cfloat>


int main()
{
    int n, m;
    std::cin >> n >> m;
    std::vector<std::vector<float>> edgeTable(n + 1, std::vector<float>(n + 1, FLT_MAX));
    for (int k = 0; k < m; k++) {
        int i, j, w;
        std::cin >> i >> j >> w;
        edgeTable[i][j] = w;
        edgeTable[j][i] = w;
    }

    int s;
    std::cin >> s;

    std::vector<float> primTable(n + 1, FLT_MAX);
    std::vector<bool> selectedNode(n + 1, false);
    std::vector<int> parentTable(n + 1, 0);
    primTable[s] = 0;
    selectedNode[s] = true;

    int currentNodeId = s;
    int totalWeigth = 0;
    for (int i = 1; i < n; i++) {
        for (int j = 1; j <= n; j++) {
            if (selectedNode[j] == false) {
                if (primTable[j] > edgeTable[currentNodeId][j]) {
                    primTable[j] = edgeTable[currentNodeId][j];
                    parentTable[j] = currentNodeId;
                }
            }
        }

        float minWeight = FLT_MAX;
        int minId;
        for (int j = 1; j <= n; j++) {
            if (selectedNode[j] == false && primTable[j] < minWeight) {
                minId = j;
                minWeight = primTable[j];
            }
        }

        currentNodeId = minId;
        totalWeigth += minWeight;
        selectedNode[minId] = true;
    }

    for (int i = 1; i < n; i++) {
        std::cout << parentTable[i] << " ";
    }
    std::cout << parentTable[n] << std::endl;

    std::cout << totalWeigth;

    return 0;
}
