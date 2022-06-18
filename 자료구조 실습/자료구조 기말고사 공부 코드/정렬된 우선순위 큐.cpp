#include <iostream>
#include <vector>
using namespace std;

struct compare {
    bool operator()(const int& e1, const int& e2) const {
        return e1 < e2;
    }
};

class sortedSeqPQ {
public:
    int size();
    bool empty();
    void insert(int e);
    int min();
    void removeMin();
    void printPQ();
    
private:
    vector<int> seq;
};

int sortedSeqPQ::size() {
    return (int)seq.size()-1;
}

bool sortedSeqPQ::empty() {
    return (seq.size() == 0);
}

void sortedSeqPQ::insert(int e) {
    compare C;
    int idx = 0;
    for (idx = 0; idx < seq.size(); idx++) {
        if (C(seq[idx], e)) {
            break;
        }
    }
    seq.insert(seq.begin() + idx, e);
}

int sortedSeqPQ::min() {
    if (empty()) {
        return -1;
    }
    return seq.back();
}

void sortedSeqPQ::removeMin() {
    if (empty()) {
        return;
    }
    seq.pop_back();
}

void sortedSeqPQ::printPQ() {
    for (int i = 0; i < seq.size(); i++) {
        cout << seq[i] << " ";
    }
    cout << endl;
}

int main() {
    sortedSeqPQ pq = sortedSeqPQ();
    
    pq.insert(1);
    pq.insert(5);
    pq.insert(3);
    
    pq.printPQ();
    
    return 0;
}
