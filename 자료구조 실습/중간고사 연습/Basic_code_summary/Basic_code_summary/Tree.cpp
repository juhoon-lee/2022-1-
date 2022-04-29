#include <iostream>
#include <vector>
using namespace std;

struct node {
    int data;
    node* parent;
    vector<node*> childList;
    node(int data, node* parent) {
        this->data = data;
        this->parent = parent;
    }
};

class Tree {
public:
    Tree(int data);
    void insertNode(int parData, int data);
    void deleteNode(int data);
    void printParent(int data);
    void printChild(int data);
private:
    node* root;
    vector<node*> nodeList;
    
    int find(int data, vector<node*>& list);
};

Tree::Tree(int data) {
    root = new node(data, NULL);
    nodeList.push_back(root);
}

int Tree::find(int data, vector<node*>& list) {
    for (int i = 0; i < list.size(); i++) {
        if (list[i]->data == data) {
            return i;
        }
    }
    return -1;
}

void Tree::insertNode(int parData, int data) {
    if (find(data, nodeList)) {
        return;
    }
    int idx = find(parData, nodeList);
    if (idx == -1) {
        return;
    }
    
    node* parNode = nodeList[idx]; // 노드 리스트에서 부모노드 꺼내기
    node* newNode = new node(data, parNode); // 부모 노드에 붙이기
    parNode->childList.push_back(newNode);
    nodeList.push_back(newNode);
    return;
}

void Tree::deleteNode(int data) {
    int idx = find(data, nodeList);
    if (idx == -1) {
        return;
    }
    
    node* delNode = nodeList[idx];
    if (delNode == root) {
        return;
    }
    
    node* parNode = delNode->parent;
    for (int i = 0; i < delNode->childList.size(); i++) {
        parNode->childList.push_back(delNode->childList[i]);
        delNode->childList[i]->parent = parNode;
    }
    
    vector<node*>& child = parNode->childList;
    child.erase(child.begin() + find(data, child));
    delete delNode;
    nodeList.erase(nodeList.begin() + idx);
    return;
}

void Tree::printParent(int data) {
    int idx = find(data, nodeList);
    if (idx == -1) {
        return;
    }
    
    node* curNode = nodeList[idx];
    cout << curNode->parent->data << endl;
}

void Tree::printChild(int data) {
    int idx = find(data, nodeList);
    if (idx == -1) {
        return;
    }
    vector<node*>& child = nodeList[idx]->childList;
    for (int i = 0; i < child.size(); i++) {
        cout << child[i]->data << " ";
    }
    cout << endl;
}

int main(int argc, const char * argv[]) {
    
    return 0;
}
