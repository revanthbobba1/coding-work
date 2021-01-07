#include <iostream>
#include <fstream>
#include <limits.h>

using namespace std;

class Stats
{
    private:
        // ...
        int total;
        int count;
        int max;
        int min;
    public:
        // ...
        Stats();
        int fcount ();
        int ftotal ();
        int fmin ();
        int fmax ();
        float faverage ();
        void fupdate ( int value );
};

Stats::Stats () {
    // ...
    total = 0;
    count = 0;
    min = INT_MAX;
    max = INT_MIN;
}

int Stats::fcount () { /* ... */ return count; }

int Stats::ftotal () { /* ... */ return total; }

int Stats::fmin () { /* ... */ return min; }

int Stats::fmax () { /* ... */ return max; }

float Stats::faverage () { /* ... */ return ((float) total) / ((float) count); }

void Stats::fupdate ( int value ) {
    // ...
    if (value < min)
        min = value;
    else if (value > max)
        max = value;
    
    count++;
    total += value;
}

int main()
{

    Stats s;

    // ...
    
    ifstream input( "numbers.txt" );
  
    int val = 0;
    while (input >> val)
        s.fupdate(val);
    
    if (s.fcount() == 0)
        cout << "No numbers in input file" << endl;
    else
        cout << "Total: " << s.ftotal() << ", count: " << s.fcount() << ", average: " << s.faverage() << ", min: " << s.fmin() << ", max: " << s.fmax() << endl;
}
