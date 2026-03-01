#include <iostream>
#include <iomanip>
#include <vector>
#include <string>
#include <cmath>
using namespace std;

int BF(string s,string t){
    int i = 0,j = 0;
    while(i < s.length() && j < t.length()){
        if(s[i] == t[j]){
            i++,j++;
        }else{
            i = i - j + 1;
            j = 0;
        }
    }
    if(j >= t.length()) return i - t.length();
    else return -1;

}

int main(){
    string s = "abcdede",t = "cde";
    cout << BF(s,t);
    return 0;
}