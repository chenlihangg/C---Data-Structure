#include <iostream>
#include <iomanip>
#include <vector>
#include <string>
#include <cmath>
#define MaxSize 50
using namespace std;

// 获取next数组,next[j] = k的含义是字符t[j]前面最多的重复子串长度为k
void GetNext(string t,int next[]){
    int j,k;
    j = 0,k = -1;
    next[0] = -1;
    while(j < t.length() - 1){
        if(k == -1 || t[j] == t[k]){
            j++; k++;
            next[j] = k;
        }else{
            k = next[k];
        }
    }
}

// 改进版
void GetNextval(string t,int nextval[]){
    int j,k;
    j = 0,k = -1;
    nextval[0] = -1;
    while(j < t.length() - 1){
        if(k == -1 || t[j] == t[k]){
            j++; k++;
            if(t[j] == t[k]){
                nextval[j] = nextval[k];
            }else{
                nextval[j] = k;
            }
        }else{
            k = nextval[k];
        }
    }
}

int Kmp(string s,string t){
    int Next[MaxSize],i = 0,j = 0;
    GetNextval(t,Next);
    int slength = s.length(),tlength = t.length();
    while(i < slength && j < tlength){
        if(j == -1||s[i] == t[j]){
            i++; j++;
        }else{
            j = Next[j];
        }
    }
    
    if(j >= tlength) return i - t.length();
    else return -1;
}

int main(){
    string s = "ecacccecd",t = "ccecd";
    cout << Kmp(s,t);
    return 0;
}