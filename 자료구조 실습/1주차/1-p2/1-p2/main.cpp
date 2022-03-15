//
//  main.cpp
//  1-p2
//
//  Created by 이주훈 on 2022/03/04.
//

#include <iostream>
#include <string>
using namespace std;

int main(int argc, const char * argv[]) {
    
    int commandCount;
    int arraySize;
    int * array;
    string command;
    int index;
    int startIndex, endIndex;
    
    cin >> commandCount >> arraySize;
    array = new int [arraySize];
    
    int temp;
    for (int i = 0; i < arraySize; i++) {
        cin >> temp;
        array[i] = temp;
    }
    
    for (int i = 0; i < commandCount; i++) {
        cin >> command;
        if (command == "shift") {
            cin >> index;
            int temp;
            
            for (int j = 0; j < index ; j++) {
                temp = array[arraySize-1];
                for (int k = arraySize-2; k > -1 ; k--) {
                    array[k + 1] = array[k];
                }
                array[0] = temp;
            }
        } else if (command == "reverse") {
            cin >> startIndex >> endIndex;
            int * temp = new int [endIndex - startIndex + 1];
            
            for (int i = 0 ; i < endIndex - startIndex + 1; i++) {
                temp[i] = array[startIndex + i];
            }
            
            for (int i = 0 ; i < endIndex - startIndex + 1; i++) {
                array[endIndex - i] = temp[i];
            }

        } else if (command == "print") {
            for (int i = 0; i < arraySize; i++) {
                cout << array[i] << " ";
            }
            cout << endl;
        }
    }
    return 0;
}
