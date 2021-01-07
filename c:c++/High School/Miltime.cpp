#include <iostream>

using namespace std;

class Time {
    private:
        int hour;
        int min;
        int ampm;
    public:
        Time();
        void setTime(int, int, int);
        int military(int);
        int getHour();
        void print();

};

Time::Time() {
    hour = 12;
    min = 0;
    ampm = 0;
}

void Time::setTime(int h, int m, int a) {
    hour = h;
    min = m;
    ampm = a;
}

int Time::military(int h2) {
    return (12 + h2);
}

int Time::getHour() {
    return hour;
}

void Time::print() {
    cout<<"The time is ";
    if(ampm == 1)
        hour = military(hour);
    cout<<hour<<" "<<min;
}

int main () {
    Time d;
    d.print();
    cout<<endl;
    int h1, m1, a1;
    cout<<"Hour?"<<endl;
    cin>>h1;
    cout<<"Minute?"<<endl;
    cin>>m1;
    cout<<"ampm?"<<endl;
    cin>>a1;

    d.setTime(h1, m1, a1); //Send h1 m1 and a1 to the class
    d.print();
    char x = d.military(h1);
    cout<<x;

    return 0;
}

