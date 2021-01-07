#include <iostream>
#include <math.h>

using namespace std;

int main () {

    int a, x, c;
    cout<<"Enter a number"<<endl;
    cin>>a;
    x = sqrt(a);
    cout<<"square root of the number is: "<<x<<endl;

    if (x > 0) {
            for(int b = x; b > 0; b-- ) {
                if(a % (b*b) == 0) {
                    cout<<"The largest number that evenly divides "<<a<<" is: "<<b<<endl;
                    c = b;
                    b = 0;
                }

                else {
                    continue;
                }

                if(b == 1) {
                    c = a;
                }

            }

            cout<<c<<endl;


    }


return 0;
}
