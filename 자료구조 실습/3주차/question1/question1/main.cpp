#include <iostream>
#include <string>
using namespace std;

int main(int argc, const char * argv[]) {
    int stackSize = 0;
    int orderSize = 0;
    int filledStackSize = 0;
    string order = "";
    
    cin >> stackSize >> orderSize;
    int* stackArray = new int[stackSize];
    
    for (int i = 0; i < orderSize; i++) {
        cin >> order;
        
        if (order == "size") {
            cout << filledStackSize << endl;
        }
        else if (order == "empty") {
            if (filledStackSize == 0) {
                cout << 1 << endl;
            }
            else {
                cout << 0 << endl;
            }
        }
        else if (order == "top") {
            if (filledStackSize == 0) {
                cout << -1 << endl;
            }
            else {
                cout << stackArray[filledStackSize-1] << endl;
            }
        }
        else if (order == "push") {
            int data;
            cin >> data;
            if (filledStackSize == stackSize) {
                cout << "FULL" << endl;
            }
            else {
                stackArray[filledStackSize] = data;
                filledStackSize++;
            }
        }
        else if (order == "pop") {
            if (filledStackSize == 0) {
                cout << -1 << endl;
            }
            else {
                cout << stackArray[filledStackSize-1] << endl;
                stackArray[filledStackSize-1] = 0;
                filledStackSize--;
            }
        }
    }
    
   
    
    
    return 0;
}
