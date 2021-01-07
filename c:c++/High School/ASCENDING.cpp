#include <iostream>
#include <stdlib.h>
#include <string>

using namespace std;

int main () {
    string inp1;
    string first1;
    string subinp1;
    string subinp2;
    string checksize;
    int checka, checkb;
    string checkas, checkbs;
    string outter;

cout<<"enter a string of numbers: "<<endl;
cin>>inp1;
first1 = inp1[0];
int a = atoi(first1.c_str());
subinp1 = inp1.substr(1,a);

cout<<endl<<endl;

int siz = inp1.size();

subinp2 = inp1.substr(a+1,siz);
subinp2 = subinp2 + subinp1;

int sizes = subinp2.size();

cout<<endl<<endl<<endl;
cout<<"Final Result: "<<subinp1;

for(int i = 0; i < sizes-1; i++) {

checkas = subinp2.substr(sizes-1-i,1);
checkbs = subinp2.substr(sizes-2-i,1);

checka = atoi(checkas.c_str());
checkb = atoi(checkbs.c_str());



if(checkb > checka) {
    cout<<" "<<checkb;
}
else{
    //checkas = subinp2.substr(sizes-2-i,2);
    //cout<<"    "<<checkb;
}

}

return 0;

}
