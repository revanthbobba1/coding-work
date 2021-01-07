#include <iostream>
#include <fstream>

using namespace std;

const int n = 8;

class Quote {
    private:
        string first;
        string last;
        string q;
    public:
        Quote();
        string getFirst(){return(first);}
        string getLast(){return(last);}
        string getq(){return(q);}
        void set(string, string, string);
        void operator=(Quote);
        int operator> (Quote);
};

Quote::Quote() {
     first = "John";
     last = "Doe";
     q = "Crystal Clear";
}

void Quote::set(string lastn, string firstn, string quoten) {
    first = firstn;
    last = lastn;
    q = quoten;
}

int Quote::operator> (Quote q2) {
    string str1 = getLast() + getFirst() + getq();
    string str2 = q2.getLast() + q2.getFirst() + q2.getq();
        if (str1 > str2) {
            return 1;
        }
        else if (str1 < str2) {
            return 0;
        }
}

void Quote::operator= (Quote q2) {
    set(q2.getLast(), q2.getFirst(), q2.getq());
}

int main () {
    ifstream myIn ("E://input.txt");
    ofstream myOut;

    Quote qarray[n];

    string lastn, firstn, quoten;


    if (myIn.is_open()) {
        for(int a = 0; a < n; a++) {
            getline(myIn, lastn, ',');
            getline(myIn, firstn, ',');
            getline(myIn, quoten, '\n');
            qarray[a].set(lastn, firstn, quoten);
        }

    }
    myIn.close();


    Quote temp;

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
        /*
        cout<<qarray[x].getLast()<<endl;
        cout<<qarray[x].getFirst()<<endl;
        cout<<qarray[x].getq()<<endl;
        cout<<endl;
        */

        myOut<<qarray[x].getLast()<<endl;
        myOut<<qarray[x].getFirst()<<endl;
        myOut<<qarray[x].getq()<<endl;
        myOut<<endl;
    }
    myOut.close();

return 0;
}
