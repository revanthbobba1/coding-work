#include <iostream>
#include <vector>

using namespace std;

int main () {
    int f = 0, s = 0;
    bool check = true;
    int check2 = -1;
    int fnumcheck = 1;

    vector<int> fnumvec;
    vector<int> svec;

    cout<<"Enter number: "<<endl;
    cin>>f;
   // cout<<f<<endl;
    cout<<"Enter second number: "<<endl;
    cin>>s;
    //cout<<s<<endl;
    int see = s;

    while (check) {
//int i = 0;
        cout<<fnumcheck<<"   "<<s<<endl<<endl;

        fnumcheck = fnumcheck * 2;
        s = s * 2;

        if (fnumcheck < f) {

        }
        else{
            fnumcheck = fnumcheck / 2;
            s = s / 2;
            check = false;
        }
    check2++;

    int ary[check2];

    //fnumvec.push_back(fnumcheck);
    //cout<<endl;
    //svec.push_back(s);

   // cout<<fnumvec[i];
    //cout<<endl;
    //cout<<svec[i];
    //i++;
    }
//cout<<check2<<endl;

            cout<<endl<<endl<<endl<<endl;

//cout<<f<<endl;
//<<fnumcheck<<endl;

for(int i = 0; i < check2 + 1; i++) {
        if(f >= fnumcheck) {
            f = f - fnumcheck;
            //cout<<f<<endl;
            cout<<fnumcheck<<" ";
            see = fnumcheck * see;
            cout<<see<<" ";
            see = see / fnumcheck;
            fnumcheck = fnumcheck / 2;
            cout<<"   ";
        }
        else if (f == 0) {
            check2 = false;
        }

        else{
            cout<<endl;

                cout<<"casted away  ";
            cout<<fnumcheck<<" ";
            see = fnumcheck * see;
            cout<<see<<" ";
            see = see / fnumcheck;

            fnumcheck = fnumcheck / 2;
        }

                    cout<<endl<<endl;

}

//cout<<"   1   "<<see;



return 0;
}
