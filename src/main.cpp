#include <iostream>
using namespace std;
void myFunction(int myNumbers[5]) {
    for (int i = 0; i < 5; i++) {
        // cout<< myNumbers[i] << "\n";
        myNumbers[i] += 2;
    }
}
int main(){
    int myNumbers[5] = {10, 20, 30, 40, 50};
    myFunction(myNumbers);
    for (int i = 0; i < 5; i++) {
        cout<< myNumbers[i] << "\n";
    }
    return 0;
}