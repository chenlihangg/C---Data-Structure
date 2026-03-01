#include <iostream>
#include <iomanip>
#include <vector>
#include <string>
#include <cmath>
using namespace std;

int fun(int num){
    if(num <= 1) return num;
    else{
        return num * (fun(num-1) - fun(num - 2)) + fun(num - 1);
    }
}

int main(){
    int num;
    cin >> num;
    cout << fun(num) << endl;
    return 0;
}