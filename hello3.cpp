#include<iostream>
#include<vector>
#include<limits>
using namespace std;
class TicTacToe{
    private:
    vector<vector<char>>board;
    char currentplayer;
    int movescount=0;
    public:
    TicTacToe(){
        board=vector<vector<char>>(3,vector<char>(3,' '));
        currentplayer = 'X';
        movescount = 0;
    }
    void displayBoard(){
        cout<<"\nCurrent Board:\n";
        cout<<" 1 2 3\n";
        for(int i=0;i<3;i++){
            cout<<i+1<<"";
            for(int j=0;j<3;j++){
                cout<<board[i][j];
                if(j<2)cout<<"|";

            }
            cout<<endl;
            if(i<2)cout<<"----------\n";
        }
        cout<<endl;
    }
    bool getPlayerInput(){
        int row,col;
        while(true){
            cout<<"Player "<<currentplayer<<",enter your move(row column):";
            cin>>row>>col;
            if(cin.fail()){
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(),'\n');
                cout<<"Invalid input!Please enter numbers:\n";
                continue;
            }
            row--;
            col--;
            if(row<0 || row>2 || col<0 || col>2){
                cout<<"Invalid position !Please enter row and column between 1-3.\n";
            }
            else if(board[row][col] != ' '){
                cout<<"That position is already taken!Please choose another.\n";
            }
            else{
                board[row][col]=currentplayer;
                movescount++;
                return true;
            }
            }
        }
        bool checkWin(){
            for(int i=0;i<3;i++){
                if(board[i][0]==currentplayer && board[i][1]==currentplayer && board[i][2]==currentplayer){
                    return true;
                }
            }
            for(int i=0;i<3;i++){
                if(board[0][i] ==currentplayer && board[1][i]==currentplayer && board[2][i]==currentplayer){
                    return true;
                }
            }
            if(board[0][0]==currentplayer && board[1][1]==currentplayer && board[2][2]==currentplayer){
                return true;
            }
            if(board[0][2]==currentplayer && board[1][1]==currentplayer && board[2][0]==currentplayer){
                return true;
            }
             return false;
        }
        bool checkDraw(){
            return movescount == 9;
        }
        void switchPlayer(){
            currentplayer = (currentplayer == 'X')?'O':'X';
        }
        void displayResult(bool win){
            displayBoard();
            if(win){
                cout<<"Congratulations! Player"<<currentplayer<<"wins!\n";
            }else{
                cout<<"Game over!It's a draw!\n";
            }
        }
        void resetGame(){
            board = vector<vector<char>>(3,vector<char>(3,' '));
                currentplayer='X';
                movescount=0;
            }
        void playGame(){
            bool gameOver=false;
            bool win=false;
            cout<<"===TIC-TAC-TOE GAME===\n";
            cout<<"Players X and O will take turns\n";
            cout<<"Enter row and column to select a position\n";
            while(!gameOver){
                displayBoard();
                getPlayerInput();
                win = checkWin();
                if(win){
                    gameOver=true;
                    displayResult(true);
                }
                else if(checkDraw()){
                    gameOver=true;
                    displayResult(false);
                }
                else{
                    switchPlayer();
                }          
            }
        }
        bool askPlayAgain(){
            char choice;
            cout<<"\nPlay again?(y/n):";
            cin>>choice;
            cin.ignore(numeric_limits<streamsize>::max(),'\n');
            return (choice=='y'||choice=='Y');
        }
    };

int main(){
    bool playAgain=true;
    cout<<"Welcome to Tic-Tac-Toe!\n";
    while(playAgain){
            TicTacToe game;
            game.playGame();
            playAgain=game.askPlayAgain();

    }
    cout<<"Thanks for playing Goodbye!\n";
    return 0;
}
