#include <iostream>
#include <thread>
#include <chrono>
#include <iomanip>
#include <string>
using namespace std;

//Function for Help Menu
void helpMenu() {
    cout << "==================== Help Menu ====================\n";
    cout << "\n              Welcome to Tic-Tac-Toe!\n\n";
    cout << "    How to Play:-\n\n";
    cout << "1. The game is played on a 3x3 grid.\n";
    cout << "2. Two players take turns: Player 1 uses 'X' and Player 2 uses 'O'.\n";
    cout << "3. To make a move, enter the number corresponding to the grid position:\n\n";
    cout<<"\t         |           |           \n";
    cout<<"\t   1     |     2     |    3      \n";
    cout<<"\t         |           |           \n";
    cout<<"\t---------|-----------|-----------\n";
    cout<<"\t         |           |           \n";
    cout<<"\t   4     |     5     |     6     \n";
    cout<<"\t         |           |           \n";
    cout<<"\t---------|-----------|-----------\n";
    cout<<"\t         |           |           \n";
    cout<<"\t   7     |     8     |     9     \n";
    cout<<"\t         |           |           \n";
    cout<<"\t         |           |           \n";
    cout << "\n4. The goal is to get three of your marks in a row:\n";
    cout << "   - Horizontally\n";
    cout << "   - Vertically\n";
    cout << "   - Diagonally\n\n";
    cout << "5. The game ends in a win if a player achieves this, or in a draw if the grid is full.\n\n";
    cout << "\t\t\t------------------------\n";
    cout << "\t\t\t|   Scoring Criteria   |\n";
    cout << "\t\t\t------------------------\n\n";
    cout << "1. 5 points for Regular Win.\n";
    cout << "2. 10 points for Diagonal win.\n";
    cout << "3. 0 point for a tie.\n";
    cout << "\t\t\t------------\n";
    cout << "\t\t\t|   Tips   |\n";
    cout << "\t\t\t------------\n\n";
    cout << "- Think ahead and try to block your opponent's moves.\n";
    cout << "- Have fun!\n";
    cout << "===================================================\n\n";
}

// Structure to store player records
struct PlayerRecord {
    string name;
    int totalWins = 0;
    int totalPoints = 0;
    int tieCount = 0;
};

//Global Variables
int choice,row,column;
char board[3][3]={{'1','2','3'},{'4','5','6'},{'7','8','9'}};
char turn='X';
bool draw=false;
PlayerRecord player1,player2 ;

//Function to animate Screen Outputs
void animated_display(const string& text) {
    for (char c : text) {
        cout << c;
        cout.flush();
        this_thread::sleep_for(chrono::milliseconds(50));
    }
    cout << endl;
}

//Function to Get Player Names
void get_player_names() {
    system("cls");
    animated_display("\n\tWELCOME TO TIC-TAC-TOE!\n\n");

    cin.ignore();
    cout << "-Enter name for Player 1 [X]: ";
    getline(cin, player1.name);
    if (player1.name.empty()) player1.name = "Player X";

    cout << "-Enter name for Player 2 [O]: ";
    getline(cin, player2.name);
    if (player2.name.empty()) player2.name = "Player O";

    system("cls");
    animated_display("\n\tLET'S START THE GAME!\n\n");
}

//Function to display Game Board
void display_board(){

system("cls");
cout<<"\n\tT I C   T A C   T O E   G A M E\n\n";
cout << "\t" << player1.name << " [X] \n\t" << player2.name << " [O]\n\n";
cout<<"\t         |           |           \n";
cout<<"\t   "<<board[0][0]<<"     |     "<<board[0][1]<<"     |    " <<board[0][2]<<"     \n";
cout<<"\t         |           |           \n";
cout<<"\t---------|-----------|-----------\n";
cout<<"\t         |           |           \n";
cout<<"\t   "<<board[1][0]<<"     |     "<<board[1][1]<<"     |     " <<board[1][2]<<"     \n";
cout<<"\t         |           |           \n";
cout<<"\t---------|-----------|-----------\n";
cout<<"\t         |           |           \n";
cout<<"\t   "<<board[2][0]<<"     |     "<<board[2][1]<<"     |     " <<board[2][2]<<"     \n";
cout<<"\t         |           |           \n";
cout<<"\t         |           |           \n";

}

//Function for player turns
void player_turn(){

     if (turn == 'X')
        cout << "\n\n\t" << player1.name << " [X] turn: ";
    else if (turn == 'O')
        cout << "\n\n\t" << player2.name << " [O] turn: ";
        cin>>choice;
//Input validation
        if(!cin>>choice){
        cin.clear();
        cin.ignore(1000,'\n');
        cout<<"\tEnter an integer! (1-9)\n";
        player_turn();
    }

else {

//Switch statement to choose position on the Table
switch(choice){
case 1:
    row=0;
    column=0;
    break;
case 2:
    row=0;
    column=1;
    break;
case 3:
    row=0;
    column=2;
    break;
case 4:
   row=1;
    column=0;
    break;
case 5:
    row=1;
    column=1;
    break;
case 6:
    row=1;
    column=2;
    break;
case 7:
    row=2;
    column=0;
    break;
case 8:
    row=2;
    column=1;
    break;
case 9:
   row=2;
    column=2;
    break;
default:
    cout<<"\tInvalid choice!\n";
    player_turn();
    return;
}

//if statements to occupy positions and assign Player's Symbol
if(turn=='X'&& board[row][column] !='X' && board[row][column] !='O'){
    board[row][column]='X';
    turn='O';}

else  if(turn=='O'&& board[row][column] !='X' && board[row][column] !='O'){
    board[row][column]='O';
    turn='X';
  }
else{
    cout<<"\n\n     Space is already filled!!!\n         ---> Try Again <---\n";
player_turn();
 }

}
}

//Function to check if the game is Over or not
bool game_Over(){

//check win through rows
for(int i=0 ;i<3 ;i++){
    if(board[i][0]==board[i][1] && board[i][0]==board[i][2])
    return false;}

//check win through columns
for(int j=0 ;j<3 ;j++){
    if(board[0][j]==board[1][j] && board[0][j]==board[2][j])
    return false;}

//check diagonal win
if(board[0][0]==board[1][1] && board[0][0]==board[2][2] || board[0][2]==board[1][1] && board[0][2]==board[2][0])
    return false;

//if there is any box not filled
for(int i=0 ;i<3 ; i++){
    for(int j=0 ;j<3 ;j++)
    if(board[i][j]!='X' && board[i][j]!='O')
   {return true;}
   }

//Draw game
draw =true;
return false;


}
// Function to update player records
void update_records() {
    if (!draw) {
        if (turn == 'X') {
        player2.totalWins++;
        player2.totalPoints += 10;
        }
        else if (turn == 'O') {
        player1.totalWins++;
        player1.totalPoints += 10;
        }
    }
     else {
        player1.tieCount++;
        player2.tieCount++;
    }
}

// Function to display player records
void display_records() {
    cout<<"\t\t------------------------\n";
    cout << "\t\t| <-- GAME RECORD -->  |\n";
    cout<<"\t\t------------------------\n\n";
    cout << player1.name << "'s Record:\n\n";
    cout << left << setw(20) <<"\t------------------------------\n ";
    cout << left << setw(20) <<"\t| >Total Wins: " << right << setw(10) << player1.totalWins << " |\n";
    cout << left << setw(20) <<"\t| >Total Points: " << right << setw(10) << player1.totalPoints << " |\n";
    cout << left << setw(20) <<"\t| >Tie Games: " << right << setw(10) << player1.tieCount << " |\n";
    cout << left << setw(20) <<"\t------------------------------\n\n ";

    cout << player2.name << "'s Record:\n\n";
    cout << left << setw(20) <<"\t------------------------------\n ";
    cout << left << setw(20) << "\t| >Total Wins: " << right << setw(10) << player2.totalWins << " |\n";
    cout << left << setw(20) <<"\t| >Total Points: " << right << setw(10) << player2.totalPoints << " |\n";
    cout << left << setw(20) <<"\t| >Tie Games: " << right << setw(10) << player2.tieCount << " |\n";
    cout << left << setw(20) <<"\t------------------------------\n ";

}

int main () {

    int choose;
    char des,playAgain;

//Display Choices
    cout << "\nWelcome to Tic-Tac-Toe!\n\n";
    cout << "1. To Play the Game"<<endl;
    cout << "2. To Help\n\n";
    cout << "-----> ";

//loop to validate the correct choice
    do
    {
    cin>>choose;
    //loop to validate integer entry
    while(!cin>>choose){
    cin.clear();
    cin.ignore(1000,'\n');
    cout<<"-Please select option 1 or 2 !\n";
    cout<<"----->";
    cin>>choose;}

//Statement for choice
switch(choose){
        case 2 : helpMenu();
        cout<<"-Ready to Play?  (Y/N) ";
        cin>>des;
        des = tolower(des);
        if(des != 'y'){
        break;
    }

        case 1 : {

    get_player_names();

    do {
// Reset board and variables
        char initialBoard[3][3] = {{'1', '2', '3'}, {'4', '5', '6'}, {'7', '8', '9'}};
        copy(&initialBoard[0][0], &initialBoard[0][0] + 9, &board[0][0]);
        draw = false;
        turn = 'X';

//What to do until the game end
while(game_Over()){

display_board();
player_turn();
game_Over();

}

//end of game
display_board();
if(turn=='X' && draw==false){
cout<<"---> "<<player2.name <<" won <---\n\n";
cout << "     Congratulations!!!\n\n";
}
else if(turn=='O' && draw==false){
cout<<"---> "<<player1.name <<" won <---\n\n";
cout << "     Congratulations!!!\n\n";
}
else
cout<<"---> Game Draw <---\n\n";

// Update player records
update_records();

// Ask to play again
cout<<"---> Play Again? (Y/N):";
cin>>playAgain;
if(playAgain=='n' || playAgain=='N')
    cout<<"\n                THANKS for playing !\n\n";

    } while (playAgain == 'y' || playAgain == 'Y');

// Display records when exiting
display_records();

        }
        break;

        default :
            cout<<"Invalid Choice. Try again!!!\n";
            cout << "-----> ";
    }

}while(choose!=1 && choose!=2 );


return 0;
}
