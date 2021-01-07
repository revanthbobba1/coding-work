#include <iostream>

using namespace std;

int check1 = 0;
int check2 = 0;
int check3 = 0;
int check4 = 0;
int check5 = 0;

void Qsort(int arr[], int &b, int &e){

    check1++;

    if((e - b + 1) == 2){
            check2++;
        if(arr[b] > arr[e]){
                int temp = arr[b];
                arr[b] = arr[e];
                arr[e] = temp;
            }
    }

    else if((e - b + 1) > 2){

        int f = b + 1, l = e, P = b;
        int E = l, S = P + 1, temp2 = arr[P];

        while(f < l){

            while(arr[P] < arr[l] && l >= b){
                if(arr[P] < arr[l]){
                    l--;
                }
            }

            while(arr[P] > arr[f] && f <= E){
                if(arr[P] > arr[f]){
                        f++;
                }
            }

            if(f < l){
                int t = arr[f];
                    arr[f] = arr[l];
                    arr[l] = t;
            }

            else{
                int tem = arr[P];
                    arr[P] = arr[l];
                    arr[l]= tem;
            }
    }

        if(l == b){
            b++;
            check3++;
            return Qsort(arr, b, e);
        }

        else if(l == e){
            e--;
            check4++;
            return Qsort(arr, b, e);
        }

        else{
            int x = l + 1,y = l - 1;
            check5++;
            return Qsort(arr, x, e), Qsort(arr, b, y);
        }
    }
}

int main(){

    const int n = 10;
    int arr[n] = {1, 2, -1, -2, 3, 4, -3, -4, 5, 6};


    for(int i = 0; i <= (n - 1); i++){
        cout  <<  arr[i] << " ";
    }

    cout << endl << endl;

    int b = 0, en = n-1;

    Qsort(arr, b, en);

    for(int i = 0 ; i <= (n - 1); i++){
        cout  <<  arr[i]  <<  " ";
    }

    cout << endl << endl;

    cout << "check1 is : " << check1 << endl << endl;
    cout << "check2 is : " << check2 << endl << endl;
    cout << "check3 is : " << check3 << endl << endl;
    cout << "check4 is : " << check4 << endl << endl;
    cout << "check5 is : " << check5 << endl << endl;


return 0;
}

