#include <iostream>

using namespace std;

void input (int &a) {

cout<<"Enter a number"<<endl;
cin>>a;
}

    int f(int a) {

        if(a > 9) {
            return (a-1) - (a-2);
        }

        else if ((a<=9) && (a % 2 == 1)) {
            return (a-3) + 5;
        }

        else {
            return 2 * a;
        }


    }



int main () {

int a;
input(a);
cout<<f(a)<<endl;

return 0;
}
