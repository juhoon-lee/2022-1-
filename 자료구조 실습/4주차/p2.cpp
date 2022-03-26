#include <iostream>
#include <string>
using namespace std;

struct node {
    int data;
    node* next;
};

class listQueue {
public:
    listQueue();
    bool empty();
    void enqueue(int data);
    int dequeue();

private:
    node* frontNode;
    node* rearNode;
    int nodeCount;
};

listQueue::listQueue() {
    frontNode = NULL;
    rearNode = NULL;
    nodeCount = 0;
}

bool listQueue::empty() {
    return (nodeCount == 0);
}


void listQueue::enqueue(int data) {
    node* newNode = new node;
    newNode->data = data;
    newNode->next = NULL;
    if (empty()) {
        frontNode = rearNode = newNode;
    }
    else {
        rearNode->next = newNode;
        rearNode = newNode;
    }
    nodeCount++;
}

int listQueue::dequeue() {
   
    node* currentNode = frontNode;
    int temp = frontNode->data;
    if (nodeCount == 1) {
        frontNode = rearNode = NULL;
    }
    else {
        frontNode = frontNode->next;
    }
    delete currentNode;
    nodeCount--;

    return temp;
}


int main() {
    listQueue p1 = listQueue();
    listQueue p2 = listQueue();

    int orderCount = 0;
    int cardCount = 0;
    int cardHealth = 0;
    

    cin >> orderCount;

    for (int i = 0; i < orderCount; i++)
    {
        int round = 0;
        int p1WinCount = 0;
        int p2WinCount = 0;
        int currentP1 = 0;
        int currentP2 = 0;

        cin >> cardCount;
        for (int j = 0; j < cardCount; j++)
        {
            cin >> cardHealth;
            p1.enqueue(cardHealth);
        }

        for (int j = 0; j < cardCount; j++)
        {
            cin >> cardHealth;
            p2.enqueue(cardHealth);
        }

        for (int j = 0; j < cardCount; j++)
        {
            round++;
            currentP1 += p1.dequeue();
            currentP2 += p2.dequeue();

            if (currentP1 > currentP2)
            {
                p1WinCount++;
                currentP1 = currentP1 - currentP2;
                currentP2 = 0;
                cout << "Round" << round << " " << p1WinCount << ":" << p2WinCount << endl;
            }
            else if (currentP1 < currentP2)
            {
                p2WinCount++;
                currentP2 = currentP2 - currentP1;
                currentP1 = 0;
                cout << "Round" << round << " " << p1WinCount << ":" << p2WinCount << endl;
            }
            else if (currentP1 == currentP2)
            {
                currentP1 = currentP2 = 0;
            }

        }

        if (p1WinCount > p2WinCount)
        {
            cout << "Winner p1" << endl;
        }
        else if (p1WinCount < p2WinCount)
        {
            cout << "Winner p2" << endl;
        }
        else if (p1WinCount == p2WinCount)
        {
            cout << "Draw" << endl;
        }


    }

    return 0;
}
