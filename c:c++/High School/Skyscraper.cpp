#include<iostream>
#include<iomanip>
#include<stdlib.h>
#include<string>
#include<string.h>
using namespace std;

int main(){
    char grid[4][4] = {{' ', ' ',' ',' '},{' ',' ',' ',' '},{' ',' ',' ',' '},{' ',' ',' ',' '}};
    char top[4];
    char left[4];
    char right[4];
    char bottom[4];

    string boardTop;
    string boardRow1;
    string boardRow2;
    string boardRow3;
    string boardRow4;//      3221,41,22,14,231422,2313
    string boardBottom;
    cout<<"Enter: "<<endl;
    getline(cin, boardTop, ',');
    getline(cin, boardRow1, ',');
    getline(cin, boardRow2, ',');
    getline(cin, boardRow3, ',');
    getline(cin, boardRow4, ',');
    getline(cin, boardBottom, '\n');
    //cout<<boardTop<<" "<<boardRow1<<" "<<boardRow2<<" "<<boardRow3<<" "<<boardRow4<<" "<<boardBottom;
    for(int i=0;i<4;i++){
     top[i] = boardTop[i];
    }
    cout<<endl;
    if(boardRow1.length() == 6){
        left[0] = boardRow1[0];
        for(int i=0;i<4;i++){
            grid[0][i] = boardRow1[i+1];
        }
        right[0] = boardRow1[5];
    }
    else if(boardRow1.length() == 2){
        left[0] = boardRow1[0];
        right[0] = boardRow1[1];
    }


    if(boardRow2.length() == 6){
        left[1] = boardRow2[0];
        for(int i=0;i<4;i++){
            grid[1][i] = boardRow2[i+1];
        }
        right[1] = boardRow2[5];
    }
    else if(boardRow2.length() == 2){
        left[1] = boardRow2[0];
        right[1] = boardRow2[1];
    }


    if(boardRow3.length() == 6){
        left[2] = boardRow3[0];
        for(int i=0;i<4;i++){
            grid[2][i] = boardRow3[i+1];
        }
        right[2] = boardRow3[5];
    }
    else if(boardRow3.length() == 2){
        left[2] = boardRow3[0];
        right[2] = boardRow3[1];
    }


    if(boardRow4.length() == 6){
        left[3] = boardRow4[0];
        for(int i=0;i<4;i++){
            grid[3][i] = boardRow4[i+1];
        }
        right[3] = boardRow4[5];
    }
    else if(boardRow4.length() == 2){
        left[3] = boardRow4[0];
        right[3] = boardRow4[1];

    }
    for(int i=0;i<4;i++){
     bottom[i] = boardBottom[i];
    }


        for(int i=0;i<4;i++){
        if(top[i] == '4'){
            for(int j=0;j<4;j++){
                grid[j][i] = ((char) ((int)'1'+j));
            }
        }
    }
        for(int i=0;i<4;i++){
        if(left[i] == '4'){
            for(int j=0;j<4;j++){
                grid[i][j] = ((char) ((int)'1'+j));
            }
        }
    }
     for(int i=0;i<4;i++){
        if(right[i] == '4'){
            for(int j=0;j<4;j++){
                grid[i][3-j] = ((char) ((int)'1'+j));
            }
        }
    }
     for(int i=0;i<4;i++){
        if(bottom[i] == '4'){
            for(int j=0;j<4;j++){
                grid[3-j][i] = ((char) ((int)'1'+j));
            }
        }
    }
    for(int i=0;i<4;i++){
        if(top[i] == '1'){
                grid[0][i] = '4';
            }
        }
        for(int i=0;i<4;i++){
        if(left[i] == '1'){
                grid[i][0] = '4';

        }
    }
     for(int i=0;i<4;i++){
        if(right[i] == '1'){
                grid[i][3] = '4';

        }
    }
     for(int i=0;i<4;i++){
        if(bottom[i] == '1'){
                grid[3][i] = '4';

        }
    }
    bool flag1, flag2, flag3, flag4 = false;

    for(int i=0;i<4;i++){
            flag1 = flag2 = flag3 = flag4 = false;
            for(int j=0;j<4;j++){

        if(grid[j][i] == '1'){
           flag1=true;
        }
        if(grid[j][i] == '2'){
           flag2=true;
        }
        if(grid[j][i] == '3'){
           flag3=true;
        }
        if(grid[j][i] == '4'){
           flag4=true;
        }
    }
    for(int k=0;k<4;k++){
        if(grid[k][i] == '0' && flag1==false && flag2==true && flag3==true && flag4==true){
            grid[k][i] = '1';
        }
        else if(grid[k][i] == '0' && flag2==false && flag1==true && flag3==true && flag4==true){
            grid[k][i] = '2';
        }
        else if(grid[k][i] == '0' && flag3==false && flag1==true && flag2==true && flag4==true){
            grid[k][i] = '3';
        }
        else if(grid[k][i] == '0' && flag1==true && flag2==true && flag3==true && flag4==false){
            grid[k][i] = '4';
        }
    }
    }

    for(int i=0;i<4;i++){
            flag1 = flag2 = flag3 = flag4 = false;
            for(int j=0;j<4;j++){

        if(grid[i][j] == '1'){
           flag1=true;
        }
        if(grid[i][j] == '2'){
           flag2=true;
        }
        if(grid[i][j] == '3'){
           flag3=true;
        }
        if(grid[i][j] == '4'){
           flag4=true;
        }
    }
    for(int k=0;k<4;k++){
        if(grid[i][k] == '0' && flag1==false && flag2==true && flag3==true && flag4==true){
            grid[i][k] = '1';
        }
        else if(grid[i][k] == '0' && flag2==false && flag1==true && flag3==true && flag4==true){
            grid[i][k] = '2';
        }
        else if(grid[i][k] == '0' && flag3==false && flag1==true && flag2==true && flag4==true){
            grid[i][k] = '3';
        }
        else if(grid[i][k] == '0' && flag1==true && flag2==true && flag3==true && flag4==false){
            grid[i][k] = '4';
        }
    }
    }



    cout<<" ";
    for(int i=0;i<4;i++){
    cout<<" "<<top[i];
    }
    cout<<endl;
    cout<<left[0];
    for(int i=0;i<4;i++){
    cout<<" "<<grid[0][i];
    }
    cout<<" "<<right[0];
    cout<<endl;
    cout<<left[1];
    for(int i=0;i<4;i++){
    cout<<" "<<grid[1][i];
    }
    cout<<" "<<right[1];
    cout<<endl;
    cout<<left[2];
    for(int i=0;i<4;i++){
    cout<<" "<<grid[2][i];
    }
    cout<<" "<<right[2];
    cout<<endl;
    cout<<left[3];
    for(int i=0;i<4;i++){
    cout<<" "<<grid[3][i];
    }
    cout<<" "<<right[3];
    cout<<endl;
    cout<<" ";
     for(int i=0;i<4;i++){
    cout<<" "<<bottom[i];
    }
    cout<<endl<<endl;
    string s;
    cout<<"Enter your 5 values: "<<endl;
    for(int i=0;i<5;i++){
        getline(cin, s);
        int a = (int)s[0] - (int)'1';
        int b = (int)s[1] - (int)'1';
        cout<<grid[a][b]<<endl;
    }


    return 0;
    }
