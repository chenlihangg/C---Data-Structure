#include <iostream>
#include <cmath>
using namespace std;
int main(){
    cout << "请输入一个整数" << endl;
    int num;
    cin >> num;
    int sum = 0;
    for(int i = 1;i <= num;i++){
        sum += i;
    }
    cout << "从1到该整数求和得到：" << sum << endl;
}