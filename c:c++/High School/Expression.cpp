#include <iostream>
#include <stdlib.h>
using namespace std;

class ENode{
private:
    char data;
    int Val;
    ENode *left;
    ENode *right;
public:
    ENode(char c, ENode *l, ENode *r){data=c,left=l,right=r;}
    char getChar(){return data;}
    int getVal(){return Val;}
    void setVal(int i){Val=i;}
    ENode* getLeft(){return left;}
    ENode* getRight(){return right;}
    void setLeft(ENode *l){left=l;}
    void setRight(ENode *r){right=r;}
};

class E{
private:
    ENode *first;
public:
   E(){first=NULL;}
   void calc(ENode*);
   ENode* insertt(string&);
   ENode* getFirst(){return first;}
};

void E::calc(ENode *current){
    if(current->getLeft()!=NULL){
        calc(current->getLeft());
    }
    if(current->getRight()!=NULL){
        calc(current->getRight());
    }
    if(current->getChar()=='*'){
        current->setVal(current->getLeft()->getVal()*current->getRight()->getVal());
    }
    else if(current->getChar()=='+'){
        current->setVal(current->getLeft()->getVal()+current->getRight()->getVal());
    }
    else if(current->getChar()=='-'){
        current->setVal(current->getLeft()->getVal()-current->getRight()->getVal());
    }
}

ENode* E::insertt(string &ex){
    ENode* newbie=new ENode(ex[0],NULL,NULL);
    if(ex[0]!='*' && ex[0]!='+' && ex[0]!='-'){
       newbie->setVal(ex[0]-'0');
    }
    if(first==NULL){
        first=newbie;
    }
    ex.erase(0,1);
    if(newbie->getChar()=='*' || newbie->getChar()=='+' || newbie->getChar()=='-'){
        newbie->setLeft(insertt(ex));
        newbie->setRight(insertt(ex));
    }
    return newbie;
}

int main(){
    string input;
    cout<<"Enter an expression: "<<endl;
    cin>>input;
    E e;
    e.insertt(input);
    e.calc(e.getFirst());
    cout<<e.getFirst()->getVal()<<endl;
    return 0;
}
