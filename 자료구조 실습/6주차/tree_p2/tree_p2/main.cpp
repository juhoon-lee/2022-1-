#include <iostream>
#include <vector>
#include <string>
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
    void maxChild(int data);
    void findParent(int data);
    
private:
    
    node* root;
    vector<node*> nodeList;
    int find(int data, vector<node*>& list);
};





Tree::Tree(int data) {
    
    node* rootNode = new node(data, NULL);
    root = rootNode;
    nodeList.push_back(rootNode);
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
    
    if (find(data, nodeList) != -1) {
        cout << -1 << endl;
        return;
    }
    
    int idx = find(parData, nodeList);
    
    if (idx == -1) {
        cout << -1 << endl;
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
        cout << -1 << endl;
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
    int childIdx = find(data, child);
    child.erase(child.begin() + childIdx);
    nodeList.erase(nodeList.begin() + idx);
    delete delNode;
}

void Tree::printParnet(int data) {
    
    int idx = find(data, nodeList);
    if (idx == -1) {
        cout << -1 << endl;
        return;
    }
    
    node* curNode = nodeList[idx]->parent;
    cout << curNode->data << endl;
}

void Tree::printChild(int data) {
    
    int idx = find(data, nodeList);
    if (idx == -1) {
        cout << -1 << endl;
        return;
    }
    
    vector<node*>& child = nodeList[idx]->childList;
    for (int i = 0; i < child.size(); i++) {
        cout << child[i]->data << " ";
    }
    if (child.size() == 0)
    {
        cout << -1;
    }
    cout << endl;
}



void Tree::maxChild(int data) {
    int idx = find(data, nodeList);
    if (idx == -1) {
        cout << -1 << endl;
        return;
    }
    int max = 0;
    vector<node*>& child = nodeList[idx]->childList;
    if (child.size() == 0)
    {
        cout << -1 << endl;
        return;
    }
    
    for (int i = 0; i < child.size(); i++) {
        if (child[i]->data > max)
        {
            max = child[i]->data;
        }
    }
    cout << max << endl;
}



void Tree::findParent(int data) {
    
    int idx = find(data, nodeList);
    node* currentNode = nodeList[idx]->parent;
    while (true)
    {
        cout << currentNode->data << " ";
        
        if (currentNode->parent != NULL) {
            currentNode = currentNode->parent;
            continue;
        }
        break;
    }
    cout << endl;
}


int main(int argc, const char* argv[]) {
    Tree a = Tree(1);
    
    int nodeCount = 0;
    int orderCount = 0;
    int x, y = 0;
    
    cin >> nodeCount >> orderCount;
    for (int i = 0; i < nodeCount-1; i++)
    {
        cin >> x >> y;
        a.insertNode(x,y);
    }
    
    for (int i = 0; i < orderCount; i++)
    {
        cin >> x;
        a.findParent(x);
    }
    
    return 0;
    
}
