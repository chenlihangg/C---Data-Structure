#include "SqStack.h"

// eg_1 将算术表达式exp转化为后缀表达式postexp
void trans(char *exp,char postexp[]){
    char e;
    SqStack *st;
    InitStack(st);
    int i = 0;          // i作为postexp的下标
    cout << exp << endl;
    while(*exp!='\0'){
        switch(*exp){
            case '(':{
                Push(st,'(');
                exp++;
                break;
            }
            case ')':{
                Pop(st,e);            // 取栈顶元素
                while(e != '('){
                    postexp[i] = e;
                    i++;
                    Pop(st,e);
                }                          // 将非左括号的所有运算符全部入后缀表达式
                exp++;
                break;
            }
            case '+':                      // 加法和减法逻辑同理
            case '-':{
                while(!EmptyStack(st)){
                    GetTop(st,e);
                    if(e != '('){
                        Pop(st,e);
                        postexp[i++] = e;
                    }else{
                        break;
                    }
                }
                Push(st,*exp);
                exp++;
                break;
            }
            case '*':
            case '/':{
                while(!EmptyStack(st)){
                    GetTop(st,e);
                    if(e == '*' || e == '/'){
                        Pop(st,e);
                        postexp[i++] = e;
                    }else{
                        break;
                    }
                }
                Push(st,*exp);
                exp++;
                break;

            }
            default:{
                while(*exp >= '0' && *exp <= '9'){
                    postexp[i++] = *exp;
                    exp++;
                }
                postexp[i++] = '#';
            }
        }

        Display(st);
    }
    // 运算符栈中可能还有残余的运算符，需要将其全部入后缀表达式
    while(!EmptyStack(st)){
        Pop(st,e);
        postexp[i++] = e;
    }
    postexp[i] = '\0';
    
    DestoryStack(st);
}
void transTest(){
    char exp[] = "(56-20)/(4+2)";
    cout << "算术表达式:" << exp << endl;
    char postexp[MaxSize];
    trans(exp,postexp);
    cout << "后缀表达式:" << postexp << endl;
}

int main(){
    // transTest();
    // test();
    return 0;
}