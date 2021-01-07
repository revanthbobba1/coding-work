#include "H://MyHeader.h"

#include<iostream>
#include<vector>
#include<string>

using namespace std;


void output (vector<string> &vs) {
    int vecsize = vs.size();
    for(int c = 0; c < vecsize; c++) {
        cout<<"word # "<<c+1<<" - "<<"size: "<<vs[c].size()<<" - "<<vs[c]<<endl;
}

}

using namespace std;

void bsort(vector<string> &vs) {

for(int a = 0; a < vs.size(); a++) {
        for(int b = a ; b < vs.size(); b++) {
            if (vs[a].size() > vs[b].size()) {
                    string temp = vs[a];
                    vs[a] = vs[b];
                    vs[b] = temp;
            }
        }
}
}


int main () {
    char ask;
    string tempstring;
    vector <string> vs;

    while(ask != 'n') {
        cout<<"Enter a string"<<endl;
        cin>>tempstring;
        vs.push_back(tempstring);

        cout<<endl;

        cout<<"continue? y/n"<<endl;
        cin>>ask;

        cout<<endl;
}


    cout<<"Unsorted Array: "<<endl;
    output(vs);

    bsort(vs);

    cout<<endl;

    cout<<"Sorted Array :"<<endl;
    output(vs);

return 0;
}



