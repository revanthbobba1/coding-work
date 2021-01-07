#include <iostream>
#include <vector>
#include <fstream>


using namespace std;

int main () {

vector<int> vecvar;

vecvar.push_back(1);
vecvar.push_back(2);
vecvar.push_back(3);

string x;
cout<<"enter"<<endl;
getline(cin, x, ' ');

cout<<x<<endl;



for(int i = 0; i < vecvar.size(); i++){
cout<<vecvar[i];
}
}
