#include <iostream>

using namespace std;

class listnode {
private:
int data;
listnode *next;
public:
listnode(int d, listnode *n) {data = d, next = n;}
int getData() {return(data);}
listnode* getNext() {return(next);}
void setNext(listnode *n) {next = n;}

};

class list {
private:
listnode *first;
public:
list() {first = NULL;}
void print();
void insert (int x);
void deleteval (int y);
void menu();


};

void list::insert(int x) {
int a=0;
cout << "Enter a value for the listnode: " << endl;
cin >> x;
listnode *newbie = new listnode(x,NULL);

if(first == NULL) {
first = newbie;
}

else if (x <= first->getData()) {
newbie->setNext(first);
first = newbie;
}

else {
listnode *current = first;


while(a==0){
if(x > current->getData() && current->getNext()==NULL){
current->setNext(newbie);
a=1;
}

else if(x > current->getData() && x < current->getNext()->getData()) {
newbie->setNext(current->getNext());
current->setNext(newbie);
a=1;
}


current = current->getNext();
}

}
}

void list::deleteval(int x) {
int a = 0;

cout<<"Enter a value to delete"<<endl;
cin>>x;

listnode *current = first;

if(first == NULL) {
    cout<<"There is nothing in this list"<<endl;
}

else {
    if(x == first->getData()) {
        first = first->getNext();
        }

    else if(x != first->getData() && first->getNext() == NULL) {
        cout<<"This number is not in the list"<<endl;
        }

    else {
        while(a==0) {
            if(x == current->getNext()->getData()) {
                current->setNext(current->getNext()->getNext());
                a=1;
                }
            else if(x == current-> getNext()->getData() && current->getNext()->getNext() == NULL) {
                current->setNext(NULL);
                a = 1;
                }
                else if(current->getNext()->getNext() == NULL && x != current->getNext()->getData()) {
                            cout<<"This number is not in the list"<<endl;
                    }
                    current = current->getNext();
            }

        }


    }
}

void list::print() {
listnode *temp = first;
if(first == NULL) {
temp = NULL;
cout << "There is no list" << endl;
}
else {
while (temp) {
cout<<temp->getData()<< " ";
temp=temp->getNext();
}
cout<<endl;
}

}

void list::menu() {
int val;
char taker;
char asker = 'y';

while(asker = 'y') {
cout<<"Insert (i), delete(d), print(p), or exit(e)? "<<endl;
cin>>taker;
if(taker == 'i'){
insert(val);
}
else if(taker == 'p') {
print();
}
else if(taker == 'd') {
deleteval(val);
}
else if(taker == 'e') {
    break;
}


}
}

int main () {

list l;
l.menu();


return 0;
}
