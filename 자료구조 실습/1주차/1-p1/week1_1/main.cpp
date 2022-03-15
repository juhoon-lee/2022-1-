//
//  main.cpp
//  week1_1
//
//  Created by 이주훈 on 2022/03/04.
//

#include <iostream>
#include <string>

using namespace std;

int main(int argc, const char * argv[]) {
    
    int countCommmand = 0;
    int arraySize = 0;
    
    string currentCommand("");
    int index;
    int value;
    
    cin >> countCommmand >> arraySize;
    
    int * array = new int [arraySize];
    
    for (int i = 0; i < arraySize; i ++) {
        array[i] = 0 ;
    }
    
    for (int i = 0; i < countCommmand; i++) {
        // 구현부
        cin >> currentCommand;
        if (currentCommand == "add") {
            cin >> index >> value;
            for (int i = arraySize - 2; i >= index; i--) {
                array[i+1] = array[i];
            }
            array[index] = value;
        } else if (currentCommand == "print") {
            for (int i = 0 ; i < arraySize; i++) {
                cout << array[i] << " ";
            }
            cout << endl;
        } else if (currentCommand == "remove") {
            cin >> index;
            
            for (int i = index; i < arraySize; i++) {
                array[i] = array[i + 1];
            }
            
            array[arraySize-1] = 0;
            
        } else if (currentCommand == "set") {
            cin >> index >> value;
            array[index] = value;
            
        } else if (currentCommand == "find") {
            cin >> value;
            bool check = false;
            
            for (int i = 0; i < arraySize; i ++) {
                if (array[i] == value) {
                    cout << i << endl;
                    check = true;
                    break;
                }
            }
            
            if (check == true) {
                check = false;
            } else {
                cout << -1 << endl;
            }
            
        }
    }
    return 0;
}


