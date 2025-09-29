#include <iostream>
#include <vector>
#include <queue>

struct node {
    node(int k, int v) {
        key = k;
        value = v;
        left = nullptr;
        right = nullptr;
    }

    int key;
    int value;
    node* left;
    node* right;
};

struct cmp
{
    bool operator ()(node* a, node* b){
        return a->key > b->key;
    }
};

void inOrderTraversal(node* node, std::vector<std::string>& huffmanCodeMap, std::string code) {
    if (node == nullptr) return;
    if (node->value != -1) huffmanCodeMap[node->value] = code;
    inOrderTraversal(node->left, huffmanCodeMap, code + '0');
    inOrderTraversal(node->right, huffmanCodeMap, code + '1');
    return;
}

int main()
{
    int n;
    std::cin >> n;
    std::vector<int> f(n);
    for (int i = 0; i < n; i++) {
        std::cin >> f[i];
    }

    std::priority_queue<node*, std::vector<node*>, cmp> nodePQ;
    for (int i = 0; i < n; i++) {
        node* temp = new node(f[i], i);
        nodePQ.push(temp);
    }

    while (nodePQ.size() != 1) {
        node* leftNode = nodePQ.top();
        nodePQ.pop();
        node* rightNode = nodePQ.top();
        nodePQ.pop();
        node* mergeNode = new node(leftNode->key + rightNode->key, -1);
        mergeNode->left = leftNode;
        mergeNode->right = rightNode;
        nodePQ.push(mergeNode);
    }

    node* rootNode = nodePQ.top();
    std::vector<std::string> huffmanCodeMap(n);

    inOrderTraversal(rootNode, huffmanCodeMap, "");

    std::cout << n << std::endl;
    std::cout << huffmanCodeMap[0];
    for (int i = 1; i < n; i++) {
        std::cout << " " << huffmanCodeMap[i];
    }

    return 0;
}
