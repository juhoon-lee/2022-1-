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
    void printParnet(int data);
    void printChild(int data);
    
private:
    node* root;
    vector<node*> nodeList;
    
    int find(int data, vector<node*>& list);
};

int Tree::find(int data, vector<node *> &list) {
    for (int i = 0; i < list.size(); i++) {
        if (list[i]->data == data) {
            return i;
        }
    }
    return  -1;
}

void Tree::insertNode(int parData, int data) {
    if (find(data, nodeList) != -1) {
        return;
    }
    int idx = find(parData, nodeList);
    if (idx == -1) {
        return;
    }
    node* parNode = nodeList[idx];
    node* newNode = new node(data, parNode);
    parNode->childList.push_back(newNode);
    nodeList.push_back(newNode);
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
    for (int i = 0; i < delNode -> childList.size(); i++) {
        node* tempNode = delNode->childList[i];
        tempNode->parent = parNode;
    }
    vector<node*>& child = parNode->childList;
    child.erase(child.begin() + find(data, child));
    nodeList.erase(nodeList.begin() + idx);
    delete  nodeList[idx]; // 이게 아니라
//    delete delNode; // 이거 아닌가??
}

void Tree::printParnet(int data) {
    int idx = find(data, nodeList);
    if (idx == -1) {
        return;
    }
    
    node* curNode = nodeList[idx]->parent;
    cout << curNode->data << endl;
}

void Tree::printChild(int data) {
    int idx = find(data, nodeList);
    if (idx == -1) {
        return;
    }
    vector<node*>& child = nodeList[idx]->childList;
    for (int i = 0; child.size(); i++) {
        cout << child[i] -> data << " ";
    }
    cout << endl;
}

int main(int argc, const char * argv[]) {
    Tree a = Tree(100);
    
    return 0;
}
