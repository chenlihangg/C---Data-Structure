#include "SqQueue.h"

void Lineup(SqQueue *&q){
    cout << "请输入病人的病历号" << endl;
    string order;
    cin >> order;
    cout << "病人" << order << "已成功排队" << endl;
    EnQueue(q,order);
}

void Treat(SqQueue *&q){
    string order;
    cout << "病人" << order << "已成功就诊" << endl;
    DeQueue(q,order);
}

void detect(SqQueue *&q){
    for(int i = q->front + 1;i <= q->rear;i++){
        cout << "第" << i - q->front << "位病人:病历号为:" << q->data[i] << endl; 
    }
}



void Menu(){
    SqQueue *q;
    InitQueue(q);

    cout << "欢迎使用医院管理程序" << endl;
    cout << "请输入您的需求,1-排队,2-就诊,3-查看排队,4-不在排队且余下依次就诊,5-下班" << endl;
    int choice;
    while(cin >> choice){
        if(choice == 1){
            Lineup(q);
        }else if(choice == 2){
            Treat(q);
        }else if(choice == 3){
            detect(q);
        }else if(choice == 4){
            detect(q);
            break;
        }else if(choice == 5){
            break;
        }else{
            cout << "您的输入有误，请重新输入" << endl;
        }
    }

    DestoryQueue(q);
}


int main(){

    Menu();
    return 0;
}