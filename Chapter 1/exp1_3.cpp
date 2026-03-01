#include <iostream>
#include <iomanip>
#include <vector>
#include <string>
#include <cmath>
using namespace std;

// 判断一个输入的整数是否为素数
int main(){
    int num;
    bool judge = true;
    cout << "请输入一个正整数，并判断该数是否为素数" << endl;
    cin >> num;
    if(num == 2) judge = true;
    // // 方法一
    // for(int i = 2;i < num;i++){
    //     if(num % i == 0) {
    //         judge = false;
    //         break;
    //     }
    // }

    // 方法二
    for(int i = 2;i < sqrt(num);i++){
        if(num * i == 0){
            judge = false;
            break;
        }
    }

    if(judge){
        cout << "该数是素数" << endl;
    }else{
        cout << "该数不是素数" << endl;
    }

    return 0;
}