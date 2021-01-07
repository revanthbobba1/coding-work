#include <windows.h>
#include <stdio.h>
#include <iostream>
#include <time.h>

using namespace std;

const int n = 20;

COORD coord={0,0};
void gotoxy(int x,int y) {
    coord.X=x;
    coord.Y=y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),coord);
}
struct location {
 int color = 0;
 int numPieces = 0;
};
class Piece{
 private:
 int location;
 int color;
 public:
 Piece();
 void setPiece(int, int);
 int getLocation(){return(location);}
 int getColor(){return(color);}
 void display();
};
class Board{
 private:
 Piece list[20];
 location loc[28]; //bar is 26 and 27 for 2 colors
 int status = 1; // 1 for player 1, -1 for player 2
 int pieceAtLoc(int, int);
 void move();
 void turn();
 int diceRoll();
 int checkmove(int, int);
 void display();
 int rboard = 0, wboard = 0;
 void checkHome();
 void firstMove();
 void checkBar();
 void endGame();
 bool checkeg = true;

 public:
 Board();
 void execute();
};
void Board::display(){
 gotoxy(0,0);
 cout<<"Home";
 for(int i = 1; i < 13; i++) {
 gotoxy(5*i,2);
 if(loc[i].color == 1) {
 cout<<"R";
 }
 else if(loc[i].color == 2) {
 cout<<"W";
 }
 gotoxy(5*i,3);
 if(loc[i].numPieces == 0) {
 cout<<" ";
 }
 else {
 cout<<loc[i].numPieces<<endl;
 }
 gotoxy(5*i,1);
 cout<<i;
 }
 gotoxy(12,11);
 int x = 0;
 cout<<"Number of Pieces on Bar: "<<"Red - "<<loc[26].numPieces<<" "<<"White - "<<loc[27].numPieces;
 for(int i = 24; i > 12; i--) {
 gotoxy(5*(24-i),18);
 if(loc[i].numPieces == 0) {
 cout<<" ";
 }
 else{
 gotoxy((5*(24-i)) + 4,18);
 cout<<loc[i].numPieces<<endl;
 }
 gotoxy((5*(24-i)) + 4,19);
 if(loc[i].color == 1) {
 cout<<"R";
 }
 else if(loc[i].color == 2) {
 cout<<"W";
 }
 gotoxy((5*(24-i)) + 4,20);
 cout<<i;
 }
 gotoxy(0,21);
 cout<<"Home";
 gotoxy(0,23);
 cout<<endl;

}
Piece::Piece() {
 location = 99;
 color = 0;
}
void Piece::setPiece(int sloc, int scolor) {
 location = sloc;
 color = scolor;
}
void Piece::display() {
 cout<<endl<<endl;
cout<<"location is: "<<location<<endl;
 if(color == 1) {
 cout<<"color is: Red"<<endl;
 }
 else if(color == 2) {
 cout<<"color is: White"<<endl;
 }
}
Board::Board() {

 list[0].setPiece(1,1);
 list[1].setPiece(1,1);
 list[2].setPiece(6,1);
 list[3].setPiece(6,1);
 list[4].setPiece(8,1);
 list[5].setPiece(8,1);
 list[6].setPiece(8,1);
 list[7].setPiece(12,1);
 list[8].setPiece(12,1);
 list[9].setPiece(12,1);
 list[10].setPiece(14,2);
 list[11].setPiece(14,2);
 list[12].setPiece(14,2);
 list[13].setPiece(17,2);
 list[14].setPiece(17,2);
 list[15].setPiece(19,2);
 list[16].setPiece(19,2);
 list[17].setPiece(19,2);
 list[18].setPiece(24,2);
 list[19].setPiece(24,2);


/*
 list[0].setPiece(20,1);
 list[1].setPiece(23,1);
 list[2].setPiece(24,1);
 list[3].setPiece(20,1);
 list[4].setPiece(19,1);
 list[5].setPiece(20,1);
 list[6].setPiece(20,1);
 list[7].setPiece(22,1);
 list[8].setPiece(16,2);
*/
/*
 list[0].setPiece(2,2);
 list[1].setPiece(3,2);
 list[2].setPiece(4,2);
 list[3].setPiece(2,2);
 list[4].setPiece(1,2);
 list[5].setPiece(2,2);
 list[6].setPiece(2,2);
 list[7].setPiece(7,2);
 list[8].setPiece(16,1);
*/
int x,y;

for(int i = 0; i < n; i++){
 x=list[i].getLocation();
 loc[x].numPieces++;
 y = list[i].getColor();
 loc[x].color = y;
 }
}

void Board::move() {

 srand(time(NULL));

 firstMove();

 int x = 0;
 int y = 0;
 int movep = 0;
 int checker = 0;
 int locMovePiece = 0;
 int tripdice = 0;
 int quaddice = 0;

while (checkeg){

 endGame();

 checkBar();

 int dice1 = rand()%6;
 dice1++;
 dice1=5;
 cout<<dice1<<endl;
 int dice2 = rand()%6;
 dice2++;
 dice2=5;
 cout<<dice2<<endl;
 int both = dice1 + dice2;

 if(dice1 == dice2){
     cout<<"You have rolled doubles "<<endl;
     tripdice = dice1 * 3;
     quaddice = dice1 * 4;
 }

 checkHome();

 cout<<"Enter location of piece to move: "<<endl;
 cin>>locMovePiece;
 cout<<"Enter how many spaces you want to move: "<<endl;
 cin>>movep;

 if(dice1 == movep || dice2 == movep|| both == movep|| tripdice == movep|| quaddice == movep){
 cout<<endl<<endl;
 for(int i = 0; i < n; i++) {
 if(locMovePiece == list[i].getLocation()){
 if(list[i].getColor() == 1) {

 if( (locMovePiece + movep) > 24) {
        //cout<<locMovePiece<<endl;
        //cout<<loc[20].numPieces<<endl;
        //system("PAUSE");

        if(loc[locMovePiece].numPieces > 1) {
            loc[locMovePiece].numPieces--;
            //cout<<loc[locMovePiece].numPieces<<endl;
            //system("PAUSE");
        }
        else if (loc[locMovePiece].numPieces == 1){
            loc[locMovePiece].numPieces = 0;
            loc[locMovePiece].color = 0;
            //cout<<loc[locMovePiece].numPieces<<endl;
            //system("PAUSE");
        }
 }
 else {


 if(loc[locMovePiece+movep].color==2 ){
 if(loc[movep + locMovePiece].numPieces == 1){
 loc[locMovePiece].numPieces--;

 if(loc[locMovePiece].numPieces == 0) {
 loc[locMovePiece].color=0;
 }
 loc[movep + locMovePiece].color--;
 for(int j=0; j<n; j++){
 if(list[j].getLocation()==locMovePiece+movep){
 list[j].setPiece(99,0);
 break;
 }
 }
 list[i].setPiece(movep + locMovePiece, 1);

 loc[27].numPieces++;
 loc[27].color = 2;
 }
 }
 else {
 loc[locMovePiece].numPieces--;
 if(loc[locMovePiece].numPieces == 0) {
 loc[locMovePiece].color=0;
 }
 loc[movep + locMovePiece].numPieces++;
 if(loc[movep + locMovePiece].numPieces <= 1) {
 loc[movep + locMovePiece].color=1;
 }
 list[i].setPiece(movep + locMovePiece, 1);
 }
 }
 }

 if(list[i].getColor() == 2) {
 movep = movep * -1;

 if( (locMovePiece + movep) < 1) {
        //cout<<locMovePiece<<endl;
        //cout<<loc[locMovePiece].numPieces<<endl;
        //system("PAUSE");

        if(loc[locMovePiece].numPieces > 1) {
            loc[locMovePiece].numPieces--;
            //cout<<loc[locMovePiece].numPieces<<endl;
            //system("PAUSE");
        }
        else if (loc[locMovePiece].numPieces == 1){
            loc[locMovePiece].numPieces = 0;
            loc[locMovePiece].color = 0;
            //cout<<loc[locMovePiece].numPieces<<endl;
            //system("PAUSE");
        }
 }
 else {

 if(loc[locMovePiece+movep].color==1 ){
 if(loc[movep + locMovePiece].numPieces == 1){
 loc[locMovePiece].numPieces--;
 if(loc[locMovePiece].numPieces == 0) {
 loc[locMovePiece].color = 0;
 }
 for(int j=0; j<n; j++){
 if(list[j].getLocation()==locMovePiece+movep){
 list[j].setPiece(99,0);
 break;
 }
 }
 loc[movep + locMovePiece].color = 2;
 list[i].setPiece(movep + locMovePiece, 2);

 loc[26].numPieces++;
 loc[26].color = 1;
 }
 }
 else {
 loc[locMovePiece].numPieces--;
 if(loc[locMovePiece].numPieces == 0) {
 loc[locMovePiece].color = 0;
 }
 loc[movep + locMovePiece].numPieces++;
 if(loc[movep + locMovePiece].numPieces <= 1) {
 loc[movep + locMovePiece].color = 2;
 }
 list[i].setPiece(movep + locMovePiece, 2);
 }
 }
 }
 break;
 }
 }
 }

 else {
 cout<<"Not allowed, try again"<<endl;
 }
 char ask = ' ';
 cout<<"Do you want to move other piece"<<endl;
 cin>>ask;

 if(ask == 'y') {
        endGame();
 cout<<"Enter location of piece to move: "<<endl;
 cin>>locMovePiece;
 cout<<"Enter how many spaces you want to move: "<<endl;
 cin>>movep;

 if(dice1 == movep || dice2 == movep|| both == movep|| tripdice == movep|| quaddice == movep){
 cout<<endl<<endl;
 for(int i = 0; i < n; i++) {
 if(locMovePiece == list[i].getLocation()){
 if(list[i].getColor() == 1) {

 if( (locMovePiece + movep) > 24) {
        //cout<<locMovePiece<<endl;
        //cout<<loc[20].numPieces<<endl;
        //system("PAUSE");

        if(loc[locMovePiece].numPieces > 1) {
            loc[locMovePiece].numPieces--;
            //cout<<loc[locMovePiece].numPieces<<endl;
            //system("PAUSE");
        }
        else if (loc[locMovePiece].numPieces == 1){
            loc[locMovePiece].numPieces = 0;
            loc[locMovePiece].color = 0;
            //cout<<loc[locMovePiece].numPieces<<endl;
            //system("PAUSE");
        }
 }
 else {


 if(loc[locMovePiece+movep].color==2 ){
 if(loc[movep + locMovePiece].numPieces == 1){
 loc[locMovePiece].numPieces--;

 if(loc[locMovePiece].numPieces == 0) {
 loc[locMovePiece].color=0;
 }
 loc[movep + locMovePiece].color--;
 for(int j=0; j<n; j++){
 if(list[j].getLocation()==locMovePiece+movep){
 list[j].setPiece(99,0);
 break;
 }
 }
 list[i].setPiece(movep + locMovePiece, 1);

 loc[27].numPieces++;
 loc[27].color = 2;
 }
 }
 else {
 loc[locMovePiece].numPieces--;
 if(loc[locMovePiece].numPieces == 0) {
 loc[locMovePiece].color=0;
 }
 loc[movep + locMovePiece].numPieces++;
 if(loc[movep + locMovePiece].numPieces <= 1) {
 loc[movep + locMovePiece].color=1;
 }
 list[i].setPiece(movep + locMovePiece, 1);
 }
 }
 }

 if(list[i].getColor() == 2) {
 movep = movep * -1;

 if( (locMovePiece + movep) > 1) {
        //cout<<locMovePiece<<endl;
        //cout<<loc[locMovePiece].numPieces<<endl;
        //system("PAUSE");

        if(loc[locMovePiece].numPieces > 1) {
            loc[locMovePiece].numPieces--;
            //cout<<loc[locMovePiece].numPieces<<endl;
            //system("PAUSE");
        }
        else if (loc[locMovePiece].numPieces == 1){
            loc[locMovePiece].numPieces = 0;
            loc[locMovePiece].color = 0;
            //cout<<loc[locMovePiece].numPieces<<endl;
            //system("PAUSE");
        }
 }
 else {

 if(loc[locMovePiece+movep].color==1 ){
 if(loc[movep + locMovePiece].numPieces == 1){
 loc[locMovePiece].numPieces--;
 if(loc[locMovePiece].numPieces == 0) {
 loc[locMovePiece].color = 0;
 }
 for(int j=0; j<n; j++){
 if(list[j].getLocation()==locMovePiece+movep){
 list[j].setPiece(99,0);
 break;
 }
 }
 loc[movep + locMovePiece].color = 2;
 list[i].setPiece(movep + locMovePiece, 2);

 loc[26].numPieces++;
 loc[26].color = 1;
 }
 }
 else {
 loc[locMovePiece].numPieces--;
 if(loc[locMovePiece].numPieces == 0) {
 loc[locMovePiece].color = 0;
 }
 loc[movep + locMovePiece].numPieces++;
 if(loc[movep + locMovePiece].numPieces <= 1) {
 loc[movep + locMovePiece].color = 2;
 }
 list[i].setPiece(movep + locMovePiece, 2);
 }
 }
 }
 break;
 }
 }
 }

 else {
 cout<<"Not allowed, try again"<<endl;
 }
 endGame();
 }

 system("cls");
 display();
 endGame();
 }

}

void Board::endGame() {
        if(loc[1].color != 1 && loc[2].color != 1 && loc[3].color != 1 && loc[4].color != 1 && loc[5].color != 1 && loc[6].color != 1 && loc[7].color != 1 && loc[8].color != 1 && loc[9].color != 1 && loc[10].color != 1 && loc[11].color != 1 && loc[12].color != 1 && loc[13].color != 1 && loc[14].color != 1 && loc[15].color != 1 && loc[16].color != 1 && loc[17].color != 1 && loc[18].color != 1 && loc[19].color != 1 && loc[20].color != 1 && loc[21].color != 1 && loc[22].color != 1 && loc[23].color != 1 && loc[24].color != 1){
            checkeg = false;
            cout<<"Player 1 has won the game"<<endl;
        }
        else if(loc[1].color != 2 && loc[2].color != 2 && loc[3].color != 2 && loc[4].color != 2 && loc[5].color != 2 && loc[6].color != 2 && loc[7].color != 2 && loc[8].color != 2 && loc[9].color != 2 && loc[10].color != 2 && loc[11].color != 2 && loc[12].color != 2 && loc[13].color != 2 && loc[14].color != 2 && loc[15].color != 2 && loc[16].color != 2 && loc[17].color != 2 && loc[18].color != 2 && loc[19].color != 2 && loc[20].color != 2 && loc[21].color != 2 && loc[22].color != 2 && loc[23].color != 2 && loc[24].color != 2){
            checkeg = false;
            cout<<"Player 1 has won the game"<<endl;
        }


}


void Board::checkHome() {
    bool checkerred = true;
    bool checkerwhite = true;
    for(int i = 0; i < n; i++) {
        if(list[i].getColor() == 1){
            if(list[i].getLocation() == 19 ||list[i].getLocation() == 20 || list[i].getLocation() == 21 || list[i].getLocation() == 22 || list[i].getLocation() == 23 || list[i].getLocation() == 24 ){
            }
            else{
                checkerred = false;
            }
        }
            if(list[i].getColor() == 2){
                if(list[i].getLocation() == 1 ||list[i].getLocation() == 2 || list[i].getLocation() == 3 || list[i].getLocation() == 4 || list[i].getLocation() == 5 || list[i].getLocation() == 6 ){
                }
                else {
                    checkerwhite = false;
                }
            }
    }

    if(checkerred == true) {
        cout<<"Red player (player 1) can go home "<<endl;
    }

    if(checkerwhite == true ) {
        cout<<"White player (player 2) can go home "<<endl;
    }
}

void Board::firstMove() {
    cout<<endl<<endl<<endl;

    bool c = true;

    while(c){

        int dicer1 = rand()%6;
        dicer1++;

        int dicer2 = rand()%6;
        dicer2++;

        int playr = dicer1 + dicer2;
        cout<<"Player 1's dice roll result is: "<<playr<<endl<<endl<<endl;


        int dicew1 = rand()%6;
        dicew1++;

        int dicew2 = rand()%6;
        dicew2++;

        int playw = dicew1 + dicew2;
        cout<<"Player 2's dice roll result is: "<<playw<<endl<<endl<<endl;

        if(playr > playw) {
            cout<<"Player 1 goes first"<<endl<<endl;
            c = false;
        }
        else if (playw > playr) {
            cout<<"Player 2 goes first"<<endl<<endl;
            c = false;
        }

    }
}

void Board::checkBar() {
    if(loc[26].numPieces > 0) {
        cout<<"Player 1 MUST move piece from the bar before proceeding"<<endl;
    }
    else if(loc[27].numPieces > 0) {
        cout<<"Player 2 MUST move piece from the bar before proceeding"<<endl;
    }
}


void Board::execute() {
 display();
 move();
}

int main() {
 Board b;
 Piece p;
 b.execute();

return 0;
}
