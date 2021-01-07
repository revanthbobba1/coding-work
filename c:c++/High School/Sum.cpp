#include <iostream>

using namespace std;

class Addition {
    private:
        int a,b,c;
    public:
        int d;
        void input();
        void summ();
        void display();
        int geta();
        void operator-();
        void operator+(Addition);

};

void Addition::input() { //You dont need a mutator because the function is already in the class. input() is already in the class
    cout<<"Enter numbers: "<<endl;
    cin>>a>>b>>c;
}

void Addition::summ() {
    d = a+b+c; //don't need to say "Addition d;" because d is already in the class
}

void Addition::display() {
    cout<<a<<b<<c<<endl;
    summ(); //don't use potter.summ(); becuase summ () is already in the class
    cout<<"sum is: "<<d<<endl;
}

int Addition::geta() {
    return a;
}

void Addition::operator-() {
    a = -a;
    b = b;
    c = -c;
}

void Addition::operator+(Addition temp) {
    cout<<"my A "<<a<<endl;
    cout<<"their A "<<temp.geta()<<endl;
    cout<<"Teacher sum "<<a + temp.geta()<<endl;
}



int main () {
    Addition potter, lyerly;
    potter.input();
    lyerly.input();
    potter.display();
    lyerly.display();
    potter + lyerly;

    /*potter.input();
    potter.summ();
    potter.display();
    -potter;
    potter.display();
    */

    return 0;
}
