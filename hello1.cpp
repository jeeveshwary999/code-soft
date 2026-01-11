#include<iostream>
using namespace std;
int main(){
    char op;
    double num1,num2;
    cout<<"Enter operation(+,-,*,/): ";
    cin>>op;
    cout<<"Enter two integers: ";
    cin>>num1>>num2;
    switch(op){
        case '+':
        cout<<"Add: "<<num1+num2<<endl;
        break;
        case '-':
        cout<<"Sub: "<<num1-num2<<endl;
        break;
        case '*':
        cout<<"Mul: "<<num1*num2<<endl;
        break;
        case '/':
        if(num2!=0){
            cout<<"Div: "<<num1/num2<<endl;
        }
        else{
            cout<<"Error"<<endl;
        }
    }
    return 0;
}