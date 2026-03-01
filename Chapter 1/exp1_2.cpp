#include <iostream>
#include <iomanip>
#include <vector>
#include <string>
#include <cmath>
using namespace std;

int main(){
    float num;
    cout << "请输入一个正整数n" << endl;
    cin >> num;
    cout << "log2(n)的大小为:" << log(num)/log(2) << endl;
    cout << "sqrt(n)的大小为:" << sqrt(num) << endl;
    cout << "2的n次方为:" << pow(2,num) << endl;
    float sum = 1;
    for(int i = 1;i <= num;i++){
        sum *= i;
    }
    cout << "n的阶乘为:" << sum << endl;
    
    return 0;
}