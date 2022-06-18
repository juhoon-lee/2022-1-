#include <iostream>
#include <vector>
using namespace std;

class graph {
public:
    void set(int n);
    void insert(int src, int dst);
    void DFS(int x);
private:
    vector<bool> visited;
    vector<vector<int>> nodes;
    int cnt;
};

void graph::set(int n) {
    for (int i = 0; i < n+1; i++) {
        visited.push_back(false);
    }
    
    for (int i = 0; i < n+1; i++) {
        vector<int> temp;
        nodes.push_back(temp);
    }
    cnt = 0;
}

void graph::insert(int src, int dst) {
    nodes[src].push_back(dst);
    nodes[dst].push_back(src);
}

void graph::DFS(int x) {
    visited[x] = true;
    cnt++;
    cout << x << " ";
    for (int i = 0; i < nodes[x].size(); i++) {
        int t = nodes[x][i];
        if (!visited[t]) {
            DFS(t);
        }
    }
}

// ==============================================================================================

int main() {
    int testCount, nodeCount ,edgeCount;
    cin >> testCount;
    
    for (int i = 0; i < testCount; i++) {
        graph gh = graph();
        cin >> nodeCount >> edgeCount;
        gh.set(nodeCount);
        for (int j = 0; j < edgeCount; j++) {
            int src,dst;
            cin >> src >> dst;
            gh.insert(src, dst);
        }
        gh.DFS(1);
        cout << endl;
    }
    
    return 0;
}
