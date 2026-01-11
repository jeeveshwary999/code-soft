#include<iostream>
#include<cstdlib>
#include<ctime>
using namespace std;
int main(){
    int secretNumber,guess;
    srand(time(0));
    secretNumber = rand() % 100 + 1;
    cout<<"Number Guessing Game(1 to 100)\n";
    do{
        cout<<"Enter your guess : " ;
        cin>>guess;
        if(guess > secretNumber){
            cout<<"Too high! Try again.\n";
        }
        else if(guess < secretNumber){
            cout<<"Too low! Try again.\n";
        }
        else{
            cout<<"Correct!You  guessed the number.\n";
        }
    }while(guess != secretNumber);
    return 0;
    }
