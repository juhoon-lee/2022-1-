#include <iostream>
#include <vector>
using namespace std;

struct node {
    int key;
    node* parent;
    node* left;
    node* right;
    
    node(int key) {
        this->key = key;
        parent = left = right = NULL;
    }
};

class binarySearchTree {
public:
    binarySearchTree();
    node* search(node* curNode, int key);
    void insert(int key);
    void remove(int key);
    
private:
    node* root;
};

binarySearchTree::binarySearchTree() {
    root = NULL;
}

node* binarySearchTree::search(node *curNode, int key) {
    if (curNode == NULL) {
        return NULL;
    }
    
    if (curNode->key == key) {
        return curNode;
    }
    else if (curNode->key < key) {
        return search(curNode->right, key);
    }
    else {
        return search(curNode->left, key);
    }
}

void binarySearchTree::insert(int key) {
    if (search(root, key) != NULL) {
        return;
    }
    
    node* newNode = new node(key);
    if (root == NULL) {
        root = newNode;
        return;
    }
    
    node* curNode = root;
    node* parNode = NULL;
    
    while (curNode != NULL) {
        parNode = curNode;
        if (curNode->key < key) {
            curNode = curNode->right;
        }
        else {
            curNode = curNode->left;
        }
    }
    
    newNode->parent = parNode;
    if (parNode->key < key) {
        parNode->right = newNode;
    }
    else {
        parNode->left = newNode;
    }
}

void binarySearchTree::remove(int key) {
    node* delNode = search(root, key);
    if (delNode == NULL) {
        return;
    }
    
    node* parNode = delNode->parent;
    node* childNode;
    
    if (delNode->left == NULL && delNode->right == NULL) {
        childNode = NULL;
    }
    else if (delNode->left == NULL && delNode->right != NULL) {
        childNode = delNode->right;
    }
    else if (delNode->left != NULL && delNode->right == NULL) {
        childNode = delNode->right;
    }
    else {
        childNode = delNode->right;
        while (childNode->left != NULL) {
            childNode = childNode->left;
        }
        delNode->key = childNode->key;
        delNode = childNode;
        parNode = delNode->parent;
        childNode = delNode->right;
    }
    
    if (parNode == NULL) {
        root = childNode;
        root->parent = NULL;
    }
    else if (delNode == parNode->left) {
        parNode->left = childNode;
        if (childNode != NULL) {
            childNode->parent = parNode;
        }
    }
    else {
        parNode->right = childNode;
        if (childNode != NULL) {
            childNode->parent = parNode;
        }
    }
    delete delNode;
}

int main() {
    binarySearchTree bt = binarySearchTree();
    bt.insert(5);
    bt.insert(3);
    bt.insert(6);
    bt.insert(7);
    bt.insert(1);
    bt.insert(2);
    bt.insert(10);
    
    bt.remove(5);
    
    return 0;
}
