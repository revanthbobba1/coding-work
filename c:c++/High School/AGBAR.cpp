#include <iostream>
#include <string>

using namespace std;

class Card {
    private:
        char suit;
        int numval;
        char val;
        int numsuit;
    public:
        //Card();
        void setSuit(char);
        void setNumval(char);
        char getSuit();
        char getNumval();
        char getVal();
        int getNumsuit();
};

class Play {
    private:
        string strarray[6];
        Card cardarray[6];
    public:
        void input();
        void execute();

};

char Card::getVal() {
    return val;
}


void Play::input () {




    for(int i = 0 ; i < 6; i++) {
    cout<<"Enter: "<<endl;
    cin>>strarray[i];
    }

    for(int i = 0; i < 6; i++) {
        cardarray[i].setNumval(strarray[i][0]);
        cardarray[i].setSuit(strarray[i][1]);
    }

    //for(int i = 0; i < 6; i++) {
      //  cout<<cardarray[i].getNumval();
        //cout<<cardarray[i].getSuit()<<endl;
    //}


}

char Card::getSuit() {
    return suit;
}

int Card::getNumsuit() {
    return numsuit;
}

char Card::getNumval() {

    if(numval == 1) {
       return 'A';
    }
    else if(numval == 10) {
        return 'T';
    }
    else if(numval == 11) {
        return 'J';
    }
    else if(numval == 12) {
        return 'Q';
    }
    else if(numval == 13) {
        return 'K';
    }
    else {
        return numval;
    }

}

void Card::setSuit(char suit1) {
    suit = suit1;
    if(suit == 'C'){
        numsuit = 1;
    }
    else if(suit == 'D'){
        numsuit = 2;
    }
    else if(suit == 'H'){
        numsuit = 3;
    }
    else if(suit == 'S'){
        numsuit = 4;
    }
}

void Card::setNumval(char numval1) {
    val = numval1;
    if(numval1 == 'A') {
        numval = 1;
    }
    else if(numval1 == 'T') {
        numval = 10;
    }
    else if(numval1 == 'J') {
        numval = 11;
    }
    else if(numval1 == 'Q') {
        numval = 12;
    }
    else if(numval1 == 'K') {
        numval = 13;
    }
    else {
        numval = numval1;
    }
}


void Play::execute() {
    Card carray[5];
    int j = 0;
    for(int i = 1; i < 6; i++){
        if(cardarray[i].getSuit() == cardarray[0].getSuit()) {
            carray[j] = cardarray[i];
            j++;
        }
    }

    Card low = carray[0];

    for(int i = 1; i < j; i++) {
            if(low.getNumval()<cardarray[0].getNumval()){
            //if(carray[i].getNumval() < low.getNumval()&& carray[i].getNumval()>cardarray[0].getNumval()) {
                    low = carray[i];
    }
}




for(int i = 0; i < j; i++) {
            if(carray[i].getNumval() < low.getNumval() && carray[i].getNumval() > cardarray[0].getNumval()){
                    low = carray[i];

    }
}

//cout<<"low numval "<<low.getNumval()<<endl;
//cout<<"low suit "<<low.getSuit()<<endl;
//cout<<"carray numval "<<carray[0].getNumval()<<endl;
//cout<<"carray suit"<<carray[0].getSuit()<<endl;


if(low.getNumval() == carray[0].getNumval() && low.getSuit() == carray[0].getSuit()) {
        for(int i = 0; i < j; i++) {
            if(carray[i].getNumval() < low.getNumval()){
                    low = carray[i];

            }
        }

        Card temparray[6];
    int g = 0;
    if(j==0){
            low = cardarray[1];

            for(int i = 1; i < 6; i++){
                    if(cardarray[i].getNumval() < low.getNumval()) {
                        low = cardarray[i];
                    }
            }

            for(int i = 1; i < 6; i++){
                if(cardarray[i].getNumval() == low.getNumval()) {
                    temparray[g] = cardarray[i];
                    g++;
                }

            }
            low = temparray[0];
            for(int i = 0; i < g; i++){
                    if(temparray[i].getNumsuit() < low.getNumsuit()) {
                        low = temparray[i];
                    }
            }
    }



}
cout<<endl;
cout<<"output : "<<low.getVal()<<low.getSuit()<<endl;
//return low.getVal() + low.getSuit();
cout<<endl;
}

int main () {

    Card a;
    Play p;
    for(int i = 0; i < 5;i++){
    p.input();
    p.execute();
    }



return 0;
}
