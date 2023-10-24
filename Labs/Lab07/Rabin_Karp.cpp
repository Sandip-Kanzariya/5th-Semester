#include <bits/stdc++.h>
using namespace std;

using USLLI = unsigned long long int;

USLLI pow(USLLI a, USLLI x, USLLI n){
    USLLI res = 1;
    while(x > 0){

        if(x % 2 == 1){ // Odd
            res = (res * a) % n;
        }

        x /= 2;

        a = (a * a) % n;
    }
    return res;
}

/*
Time : O((n - m + 1) * m) = O(n + m)
*/
int main(){
    
    cout << "Enter Numerice String Only : \n";

    string T, P;
    cout << "Enter Text : ";
    cin >> T;
    cout << "Enter Pattern : ";
    cin >> P;
    // Radix of Number System x
    int d = 10;
    int q;
    cout << "Enter Prime Number : ";
    cin >> q;

    
    int n = T.size();
    int m = P.size();

    // Preprocessing Step : Make Hash Table [ H(x) = x % q ]
    int p = 0, t = 0;
    for(int i = 0;i < m;i++){
        p = (p * d + (P[i] - '0')) % q;
        t = (t * d + (T[i] - '0')) % q;
    }

    int h = pow(d, m - 1, q); // d ^ (m - 1)
    
    cout << "Shift : ";
    for(int s = 0;s <= n - m;s++){
        
        // Check Pattern is Found or not 
        if(p == t){
            bool match = 1;
            for (int i = 0; i < m; i++)
            {
                if(P[i] != T[s + i]){
                    match = 0;
                    break;
                }
            }

            if(match)
            {
                cout << s << " | ";
            }
        }
        
        t = ( (t - (T[s] - '0') * h) * d + (T[s + m] - '0')) % q;

        while(t < 0){
            t += q;
        }
    }

    return 0;
}