#include <iostream>
#include <iomanip>
#include <vector>
#include <string>
#include <cmath>
using namespace std;

double func(double x,int n){
    if(n == 1) return x;
    else if(n % 2 == 0){
        double y = func(x,n/2);
        return y * y;
    }else if(n % 2 == 1){
        double y = func(x,n/2);
        return y * y * x;
    }else{
        return 0;
    }
}


int main(){
    double num = 1.5;
    cout << func(num,6);
    return 0;
}
