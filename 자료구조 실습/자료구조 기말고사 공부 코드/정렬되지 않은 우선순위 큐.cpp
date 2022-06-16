#include <iostream>
#include <vector>
using namespace std;

struct compare {
    bool operator()(const int& e1, const int& e2) const {
        return e1 < e2;
    }
};

class unsortedSeqPQ {
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

int unsortedSeqPQ::size() {
    return (int)seq.size();
}

bool unsortedSeqPQ::empty() {
    return (seq.size() == 0);
}

void unsortedSeqPQ::insert(int e) {
    seq.push_back(e);
}

int unsortedSeqPQ::min() {
    if (empty()) {
        return -1;
    }
    
    compare C;
    int minVal = seq[0];
    
    for (int i = 0; i < seq.size(); i++) {
        if (C(seq[i], minVal)) {
            minVal = seq[i];
        }
    }
    return minVal;
}

void unsortedSeqPQ::removeMin() {
    if (empty()) {
        return;
    }
    compare C;
    int minIdx = 0;
    
    for (int i = 0; i < seq.size(); i++) {
        if (C(seq[i], seq[minIdx])) {
            minIdx = i;
        }
    }
    seq.erase(seq.begin() + minIdx); // iterator를 이용한 지우기
}

void unsortedSeqPQ::printPQ() {
    for (int i = 0; i < seq.size(); i++) {
        cout << seq[i] << " ";
    }
    cout << endl;
}

int main() {
    unsortedSeqPQ pq = unsortedSeqPQ();
    pq.insert(1);
    pq.insert(5);
    pq.insert(3);
    
    cout << pq.min() << endl;
    pq.removeMin();
    cout << pq.min() << endl;
    
    pq.printPQ();
    
    return 0;
}
