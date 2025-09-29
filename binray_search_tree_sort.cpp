#include <iostream>
#include <vector>

class Node {
public:
    int key;
    Node* left;
    Node* right;

    Node(int newKey) {
        key = newKey;
        left = NULL;
        right = NULL;
    }
};

class BST {
public:
    Node* root;
    
    BST(int rootKey) {
        root = new Node(rootKey);
    }

    void addNode(Node* parent, int key) {
        if (key <= parent->key) {
            if (parent->left == NULL) parent->left = new Node(key);
            else addNode(parent->left, key);
        }
        else {
            if (parent->right == NULL) parent->right = new Node(key);
            else addNode(parent->right, key);
        }
    }

    void inOrder(Node* parent, std::vector<int>& inOrderList) {
        if (parent == NULL) return;

        inOrder(parent->left, inOrderList);
        inOrderList.push_back(parent->key);
        inOrder(parent->right, inOrderList);
        return;
    }


    int findKeyDepth(int key, int rootDepth, Node* parent, std::vector<int>& findPath) {
        if (parent == NULL) return -1;
        
        findPath.push_back(parent -> key);
        if (parent->key == key) return rootDepth;
        
        rootDepth++;
        if (parent->key >= key) return findKeyDepth(key, rootDepth, parent->left, findPath);
        else return findKeyDepth(key, rootDepth, parent->right, findPath);
    }
};

int main()
{
    int n, k;
    std::cin >> n >> k;

    std::vector<int> a; 
    int temp;
    for (int i = 0; i < n; i++) {
        std::cin >> temp;
        a.push_back(temp);
    }

    BST bst(a[0]);
    for (int i = 1; i < n; i++) {
        bst.addNode(bst.root, a[i]);
    }

    std::vector<int> inOrderList;

    bst.inOrder(bst.root, inOrderList);
    int findKey = inOrderList[k - 1];
    
    std::vector<int> findPath;
    int findKeyDepth = bst.findKeyDepth(findKey, 1, bst.root, findPath);


    std::cout << findKeyDepth << std::endl;
    for (auto i : findPath) {
        if (i == findKey) {
            std::cout << i;
            break;
        }
        std::cout << i << " ";
    }

    return 0;
}
