#include<iostream>
#include<stdlib.h>

using namespace std;

int f = 0;

class bnode{
    private:
        char data;
        bnode *nextl;
        bnode *nextr;
    public:
        bnode (char d, bnode *l, bnode *r) {
            data = d;
            nextl = l;
            nextr = r;
            }
        char getData() {
            return data;
        }
        bnode *getNextLeft() {
            return nextl;
        }
        bnode *getNextRight() {
            return nextr;
        }
        void setLeft(bnode *n) {
            nextl = n;
        }
        void setRight(bnode *n) {
            nextr = n;
        }
};

class b{
    private:
        bnode *first;
        bnode *l;
        bnode *r;
    public:
        b() {
            first = NULL;
            l = NULL;
            r = NULL;
        }
        bnode *getFirst() {return first;}
        void insertt (char x);
        void print (bnode *cp);

};

void b::insertt(char x) {
    int lf = 0, rf = 0;
    bnode *cp = first;
    bnode *pp = first;
    if(f == 0) {
        bnode *newbie = new bnode(x, NULL, NULL);
        first = newbie;
        f = 1;
       }
       else if (f == 1) {
            while(cp != NULL) {
                pp = cp;
                if(x <= cp->getData()) {
                    if(cp->getNextLeft() == NULL)
                        lf = 1;
                    cp = cp->getNextLeft();

                }
                else {
                    if(cp->getNextRight() == NULL)
                        rf = 1;
                    cp = cp->getNextRight();
                }
            }
            bnode *newbie = new bnode(x, NULL, NULL);
            if(lf == 1) {
                pp->setLeft(newbie);
            }
            if(rf==1) {
                pp->setRight(newbie);
            }
       }
};

void b::print(bnode*cp) {

    //cout<<cp->getData();
    if(cp->getNextLeft() != NULL) {
        print(cp->getNextLeft());
    }

    cout<<cp->getData();
    if(cp->getNextRight() != NULL) {
        print(cp->getNextRight());
    }
    //cout<<cp->getData();
};

int main () {
    b var;
    string word;
    int y = 0;

    cout<<"Enter a Word: "<<endl;
    cin>>word;
    while(word[y]){
        var.insertt(word[y]);
        y++;
    }
    var.print(var.getFirst());
return 0;
}
