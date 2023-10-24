#include <bits/stdc++.h>
using namespace std;

/*
Time : O(n + m)
*/
int main(){
    
    string T, P;
    cout << "Enter Text : ";
    cin >> T;
    cout << "Enter Pattern : ";
    cin >> P;

    int n = T.size();
    int m = P.size();

    // Preprocessing Step : Pi Table 

    vector <int> pi(m + 1, 0);
    pi[0] = -1;
    int k = -1;

    for (int i = 1; i <= m; i++)
    {
        while(k >= 0 && P[k] != P[i - 1])
        {
            k = pi[k];
        }
        pi[i] = ++k;
    }
    
    // PI Table 
    // for(auto y : pi){
    //     cout << y << " ";
    // }
    

    int q = 0;

    for (int i = 0; i < n; i++)
    {
        while(q > 0 && P[q] != T[i]){
            q = pi[q];
        }        

        if(P[q] == T[i]){
            q++;
        }

        if(q == m){
            cout << i - m + 1 << " | ";
            q = pi[q];
        }
    }
    
    
    
    return 0;
}