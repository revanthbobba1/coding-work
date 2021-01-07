#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
#include <math.h>
#include <fstream>
#include <time.h>
#include <stdlib.h>
#include <sstream>


using namespace std;

template <class potter>

void Bubble(potter a[], int n){

    for(int x=0; x<n; x++){
        for(int y=x; y<n; y++){
            if(a[x]>a[y]){
                potter temp=a[x];
                a[x]=a[y];
                a[y]=temp;
            }
        }
    }
}

void Bsort(vector <string> &vs){

    for(int x=0; x<vs.size(); x++){
        for(int y=x; y<vs.size(); y++){
            if(vs[x].size()>vs[y].size()){
                string temp=vs[x];
                vs[x]=vs[y];
                vs[y]=temp;
            }
        }
    }
}

void Isort(int intary[], int n){

    for(int x=0; x<n; x++){
        for(int y=x; y<n; y++){
            if(intary[x]>intary[y]){
                int temp=intary[x];
                intary[x]=intary[y];
                intary[y]=temp;
            }
        }
    }
}

void Dsort(double doubleary[],  int n){

    for(int x=0; x<n; x++){
        for(int y=x; y<n; y++){
            if(doubleary[x]>doubleary[y]){
                double temp=doubleary[x];
                doubleary[x]=doubleary[y];
                doubleary[y]=temp;
            }
        }
    }
}

void Csort(char charary[],  int n){

    for(int x=0; x<n; x++){
        for(int y=x; y<n; y++){
            if(charary[x]>charary[y]){
                char temp=charary[x];
                charary[x]=charary[y];
                charary[y]=temp;
            }
        }
    }
}

class Binary {
    private:
        string expression;
        int realval = 0;
    public:
        void input();
        void display();
        void convertSI();
        void convertIS();
        void operator-();
        void operator+(Binary);
        int getrealval();
        vector<string> temp;
};

void Binary::input() {
    cout<<"Enter a binary number: "<<endl;
    cin>>expression;
}



void Binary::convertSI() {
    for(int a = (expression.size() - 1); a > -1; a--) {
        if(expression[a] == '1') {
            realval = realval + pow(2, a);;
        }
    }
}

int Binary::getrealval() {
    return realval;
}

void Binary::operator+(Binary temp) {
    cout<<endl;
    realval = realval + temp.getrealval();
    cout<<realval<<endl;
    convertIS();
    display();
}



void Binary::convertIS() {
    int counter = 0;
    int nrealval = realval;
    while (nrealval != 0) {
        temp[counter] = nrealval % 2;
        nrealval = nrealval / 2;
        counter++;
    }

}


void Binary::display() {
    for (int g = temp.size()-1; g > 0; g--) {
        temp[g] = expression[(temp.size() - 1) - g];
        cout<<temp[g]<<endl;
    }

    cout<<expression<<endl;
    cout<<realval<<endl;
}

void Binary::operator-() {
    for(int b = 0; b < expression.size(); b++) {
        if(expression[b] == '1') {
            expression[b] = '0';
        }
        else{
            expression[b] = '1';
        }
    }
}
