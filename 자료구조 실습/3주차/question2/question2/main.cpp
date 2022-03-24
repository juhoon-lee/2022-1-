#include <iostream>
#include <string>
using namespace std;

int main(int argc, const char * argv[]) {
    int orderSize = 0;
    int filledStackSize = 0;
    string expresstion = "";
    
    cin >> orderSize;
    int* stackArray = new int[50];
    
    for (int i = 0; i < orderSize; i++) {
        cin >> expresstion;
        
        for (int j = 0; j < expresstion.size(); j++) {
            if (j % 2 == 0) {
                cout << expresstion[j] << "";
            }
            else {
                if (expresstion[j] == '+' || expresstion[j] == '-') {
                    
                }
                else if (expresstion[j] == '*'){
                    
                }
            }
        }
        
    }
    

    
    return 0;
}
