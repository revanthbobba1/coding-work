#include <iostream>
#include <string>
#include <sstream>
#include <stdlib.h>
#include <list>
#include <vector>
#include <fstream>

using namespace std;

int main () {

    for(int w = 0; w < 5; w++){

    int grid [8][8];

    for(int i = 0; i < 8; i++){
        for(int j = 0; j < 8; j++){
            grid [i][j] = {-1};
        }
    }

    int taker;
    int abc = 0;

    //inputs how many different rows will be lit

    cout << "Enter number of inputs" << endl;
    cin >> taker;


    //input lights to the array

    vector<string> vecvar;
    string xer;



        string taker2;
        cout << "Enter row/column" << endl;
        for(int f = 0; f < taker-1; f++){
        getline(cin, xer, ' ');
        vecvar.push_back(xer);
        }
        getline(cin, xer, '\n');
        vecvar.push_back(xer);

        for(int k = 0; k < vecvar.size(); k++){
            cout<<vecvar[k]<<endl;
        }

        for(int y = 0; y < taker; y++){

        taker2 = vecvar[y];
        cout<<"taker2: "<<taker2<<endl;

        int x = atoi(taker2.substr(0,1).c_str());
        cout<<"x: "<<x<<endl;
        x--;
        int siz = taker2.size()-1;


        for (int j = 0; j < siz; j++) {
            int y = atoi(taker2.substr(j+1,1).c_str());
            y--;
            grid [x][y] = {1};
            abc++;
        }

    }



    cout << endl << "You have initially turned on " << abc << " tile(s)" << endl << endl;


//inputting where the user wants the "button" and how many "buttons"

    string button;
    int butnum;

    cout << "Enter total amount of buttons" << endl;
    cin >> butnum;

    for(int i = 0; i < butnum; i++) {

    cout << "Enter where you want the button to be" << endl;
    cin >> button;

    int xcoor = 0;
    int ycoor = 0;

    xcoor = atoi(button.substr(0,1).c_str());
    ycoor = atoi(button.substr(1,1).c_str());

    xcoor--;
    ycoor--;

//lighting space up and also checking if the space is on the board

    grid[xcoor][ycoor] = grid[xcoor][ycoor] * -1;

    if((xcoor + 1 < 8) && (xcoor + 1 > -1) && (ycoor < 8) && (ycoor > -1)) {
            grid[xcoor + 1][ycoor] = grid[xcoor + 1][ycoor] * -1;
    }
    if((xcoor - 1 < 8) && (xcoor - 1 > -1) && (ycoor < 8) && (ycoor > -1)) {
            grid[xcoor - 1][ycoor] = grid[xcoor - 1][ycoor] * -1;
    }
    if((ycoor + 1 < 8) && (ycoor + 1 > -1) && (xcoor < 8) && (xcoor > -1)) {
            grid[xcoor][ycoor + 1] = grid[xcoor][ycoor + 1] * -1;
    }
    if((ycoor - 1 < 8) && (ycoor - 1 > -1) && (xcoor < 8) && (xcoor > -1)) {
            grid[xcoor][ycoor - 1] = grid[xcoor][ycoor - 1] * -1;
    }
    if((xcoor + 2 < 8) && (xcoor + 2 > -1) && (ycoor < 8) && (ycoor > -1)) {
            grid[xcoor + 2][ycoor] = grid[xcoor + 2][ycoor] * -1;
    }
    if((xcoor - 2 < 8) && (xcoor - 2 > -1) && (ycoor < 8) && (ycoor > -1)) {
            grid[xcoor - 2][ycoor] = grid[xcoor - 2][ycoor] * -1;
    }
    if((ycoor + 2 < 8) && (ycoor + 2 > -1) && (xcoor < 8) && (xcoor > -1)) {
            grid[xcoor][ycoor + 2] = grid[xcoor][ycoor + 2] * -1;
    }
    if((ycoor - 2 < 8) && (ycoor - 2 > -1) && (xcoor < 8) && (xcoor > -1)) {
            grid[xcoor][ycoor - 2] = grid[xcoor][ycoor - 2] * -1;
    }
    if((ycoor + 1 < 8) && (ycoor - 1 > 0) && (xcoor + 1 < 8) && (xcoor - 1 > 0)) {
            grid[xcoor + 1][ycoor + 1] = grid[xcoor + 1][ycoor + 1] * -1;
    }
    if((ycoor + 1 < 8) && (ycoor + 1 > -1) && (xcoor - 1 < 8) && (xcoor -1 > -1)) {
            grid[xcoor - 1][ycoor + 1] = grid[xcoor - 1][ycoor + 1] * -1;
    }
    if((ycoor - 1 < 8) && (ycoor - 1 > -1) && (xcoor + 1 < 8) && (xcoor + 1 > -1)) {
            grid[xcoor + 1][ycoor - 1] = grid[xcoor + 1][ycoor - 1] * -1;
    }
    if((ycoor - 1 < 8) && (ycoor - 1 > -1) && (xcoor - 1 < 8) && (xcoor - 1 > -1)) {
            grid[xcoor - 1][ycoor - 1] = grid[xcoor - 1][ycoor - 1] * -1;
    }


    }

    int check = 0;

    for(int i = 0; i < 8; i++){
        for(int j = 0; j < 8; j++){
            if(grid [i][j] == 1) {
                check++;
            }
        }
    }

    cout << "Total number of lit lights are : " << check << endl << endl << endl;

    }

    return 0;
}
