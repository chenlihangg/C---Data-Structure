#include <iostream>
#include <iomanip>
#include <vector>
#include <string>
#include <cmath>
using namespace std;

// 递归求解：从x，借助y移动到z
void Hanoi1(int n,char X,char Y,char Z){
    if(n == 1){
        cout << "从" << X << "移动到" << Z << endl;
    }else{
        Hanoi1(n-1,X,Z,Y);                  // 先把n-1个移到y上
        cout << "从" << X << "移动到" << Z << endl;
        Hanoi1(n-1,Y,X,Z);                  // 把剩下的n-1个移到z上
    }
}



int main(){
    char X = 'X',Y = 'Y',Z = 'Z';
    Hanoi1(11,X,Y,Z);
    return 0;
}