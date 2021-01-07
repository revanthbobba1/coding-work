#include "H://Myheader.h"

const int n = 1000;

int main () {

    ofstream Output("H://Output.txt");


    srand(time(NULL));

    int iarray[n];

        for(int a = 0; a < n; a++) {
            int random = rand()%1000;
            iarray[a] = random;
        }

    double darray[n];

    for(int e = 0; e < n; e++) {
        int random2 = rand()%999;
        double divrandom2 = random2 / 1000.00;
        darray[e] = divrandom2;
        }

    char carray[n];

    for(int i = 0; i < n; i++) {
        int random3 = rand()%255;
        carray[i] = char(random3);
    }



    Bubble(iarray,n);
    Bubble(darray,n);
    Bubble(carray,n);

    Output.open("E://Output.txt");
    for(int cd = 0; cd < n; cd++) {

    if(cd % 10 == 0) {
            if(cd != 0) {

                Output<<endl;
            }

        }
        Output<<iarray[cd]<< " ";


    }

    Output<<endl<<endl<<endl;

    for(int ab = 0; ab < n; ab++) {

     if(ab % 10 == 0) {
            if(ab != 0){
                Output<<endl;
            }

    }
        Output<<darray[ab]<< " ";

    }

    Output<<endl<<endl<<endl;

    for(int bc = 0; bc < n; bc++) {

     if(bc % 10 == 0) {
            if (bc != 0){
                Output<<endl;
            }

        }

        Output<<carray[bc]<< " ";
    }
    Output.close();

return 0;
}


