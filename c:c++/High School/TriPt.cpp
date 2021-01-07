#include <iostream>
#include <fstream>

using namespace std;

const int n = 8;

class ThreeDPoint {
    private:
        int first;
        int last;
        int q;
    public:
        ThreeDPoint();
        int getFirst(){return(first);}
        int getLast(){return(last);}
        int getq(){return(q);}
        void set(int, int, int);
        void operator=(ThreeDPoint);
        int operator> (ThreeDPoint);
};

ThreeDPoint::ThreeDPoint() {
     first = 0;
     last = 0;
     q = 0;
}

void ThreeDPoint::set(int x, int y, int z) {
    first = y;
    last = x;
    q = z;
}

int ThreeDPoint::operator> (ThreeDPoint q2) {
    int str1 = getLast() + getFirst() + getq();
    int str2 = q2.getLast() + q2.getFirst() + q2.getq();
        if (str1 > str2) {
            return 1;
        }
        else if (str1 < str2) {
            return 0;
        }
}

void ThreeDPoint::operator= (ThreeDPoint q2) {
    set(q2.getLast(), q2.getFirst(), q2.getq());
}

int main () {
    ifstream myIn ("E://input.txt");
    ofstream myOut;

    ThreeDPoint qarray[n];

    int x, y, z;


    if (myIn.is_open()) {
        for(int a = 0; a < n; a++) {
            getline(myIn, x, ',');
            getline(myIn, y, ',');
            getline(myIn, z, '\n');
            qarray[a].set(x, y, z);
        }

    }
    myIn.close();


    ThreeDPoint temp;

    for(int x=0; x<n; x++){
        for(int y=x; y<n; y++){
            if(qarray[x].operator> (qarray[y]) ) {
                temp.operator= (qarray[x]);
                qarray[x].operator= (qarray[y]);
                qarray[y].operator= (temp);
            }
        }
    }

    myOut.open("E://Output.txt");

    for (int x = 0; x < n; x++) {
        myOut<<qarray[x].getLast()<<endl;
        myOut<<qarray[x].getFirst()<<endl;
        myOut<<qarray[x].getq()<<endl;
        myOut<<endl;
    }
    myOut.close();

return 0;
}
