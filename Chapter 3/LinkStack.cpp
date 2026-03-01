#include "LinkStack.h"

// eg_1 判断输入的表达式中的括号是否配对（假设只有圆括号）
bool Match(){
    string str;
    cin >> str;
    cout << str << str.size() << endl;
    LinkNode* st; char e;
    InitStack(st);
    bool match = true;
    for(int i = 0; i < str.size() && match == true; i++){
        cout << i << " ";
        if(str[i] == '('){
            Push(st,str[i]);
        }else if(str[i] == ')'){
            if(!EmptyStack(st)) Pop(st,e);
            else match = false;
        }
    }
    Display(st);
    if(!EmptyStack(st)) match = false;
    DestoryStack(st);
    cout << match;
    return match; 
}


int main(){

    // test();
    Match();
    return 0;
}