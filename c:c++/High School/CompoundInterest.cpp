#include <iostream>
#include <iomanip>
#include <math.h>
#include <fstream>

using namespace std;

ifstream myIn ("S://Public/CS/input.txt");
ofstream Output;

int main () {




    cout<<setprecision(2);
    cout.setf(ios::fixed|ios::showpoint);
    Output<<setprecision(2);
    Output.setf(ios::fixed|ios::showpoint);




    int P, user ;
    double calc, myCalc [11], b, r, n;




    if (myIn.is_open()) {
        myIn >> P;
        myIn >> r;
        myIn >> n;
    }
    myIn.close();

    r = r / 100;
    b = r/n;
    b++;

    for(int a = 0; a < 11; a++){
        calc = pow(b, a*n );
        calc = calc * P;
        myCalc[a] = calc;
        cout<<a<<" - "<<myCalc[a];
        cout<<endl;
    }

    cout<<endl;

    cout<<"Which year's amount do you want (0-10)?"<<endl;
    cin>>user;

    if(user > 10){
        cout<<"Enter a different number"<<endl;
    }
    else{
    Output.open("H://potter1.txt");
    Output << myCalc[user];
    Output.close();
    }

return 0;
}
