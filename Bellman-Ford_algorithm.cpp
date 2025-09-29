#include <iostream>
#include <vector>
#include <cfloat>

struct Edge {
    Edge(int f, int t, float w) {
        fromId = f;
        toId = t;
        weight = w;
    }
    Edge() {};
    int fromId;
    int toId;
    float weight;
};


int main()
{
    int n, m;
    std::cin >> n >> m;
    std::vector<Edge> edgeList;
    for (int k = 0; k < m; k++) {
        int i, j;
        float w;
        std::cin >> i >> j >> w;
        edgeList.push_back(Edge(i, j, w));
    }

    int s;
    std::cin >> s;
    
    std::vector<float> BFTable(n + 1, FLT_MAX);
    std::vector<int> parentTable(n + 1, 0);
    BFTable[s] = 0;
    
    for (int i = 0; i < n - 1; i++) {
        for (auto edge : edgeList) {
            if (BFTable[edge.toId] > BFTable[edge.fromId] + edge.weight) {
                BFTable[edge.toId] = BFTable[edge.fromId] + edge.weight;
                parentTable[edge.toId] = edge.fromId;
            }
        }
    }

    for (auto edge : edgeList) {
        if (BFTable[edge.toId] > BFTable[edge.fromId] + edge.weight) {
            std::cout << "There is a negative weight cycle in the graph";
            return 0;
        }
    }

    for (int i = 1; i < n; i++) {
        std::cout << BFTable[i] << " ";
    }
    std::cout << BFTable[n] << std::endl;

    for (int i = 1; i < n; i++) {
        std::cout << parentTable[i] << " ";
    }
    std::cout << parentTable[n];

    return 0;
}
