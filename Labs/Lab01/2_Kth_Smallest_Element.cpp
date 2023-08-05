#include <bits/stdc++.h>
using namespace std;


int getRandom(int p, int r) {    
    srand(time(0));
    return (rand() % (r - p + 1)) + p;
}


int partition(vector <int> &v, int l, int h){


    // Take last element as pivot
    int pivot = v[h];


    int i = l;
    for(int j = l; j < h;j++){


        if(v[j] <= pivot){
            
            swap(v[i], v[j]);
            i++;
        }
    }
   
    swap(v[i], v[h]);


    return i;
}


int  find(vector <int> &v, int l, int h, int k){


    if(l < h){
        int random = getRandom(l, h);
        swap(v[random], v[h]);
        int q = partition(v, l, h);


        if(k - 1 == q) return v[q];


        if(k - 1 < q){
            return find(v, l, q - 1, k);
        }
        else{
            return find(v, q + 1, h, k - q - 1); //
        }
    }
    return 0;
}




int main(){
   


    vector <int> v = {10, 9, 1, 2, 6, 99, 11};

    int k = 4;
    int n = v.size();
       
    cout << find(v, 0, n - 1, k);
       
    return 0;
}
