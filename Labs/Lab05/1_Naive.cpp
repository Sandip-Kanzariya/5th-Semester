#include <bits/stdc++.h>
using namespace std;

int comp = 0;

/*

Average Time : O((n - m + 1) * m)
// T = JIM_SAW_ME_IN_A_BOOK_SHOP | P = SHOP
// T = JIMY_HAILED_THE_LEADER_TO_STOP | P = LEADER
--------------------------------------------------------------
Worst Time : O(n * m)
Comparision : (n - m + 1) * m 
// T = AAAAAAAAAA | P = AA
*/

bool check(string p, string s)
{

    for (int i = 0; i < s.size(); i++)
    {
        comp++;
        if (p[i] != s[i])
        {
            return false;
        }
    }

    return true;
}

int main()
{

    
    string text, pattern;
    cout << "Enter Text : ";
    cin >> text;

    cout << "Enter Pattern : ";
    cin >> pattern;

    int n = text.size();
    int m = pattern.size();

    cout << "Shifts : ";
    for (int s = 0; s <= n - m; s++)
    {
        string str = text.substr(s, m);

        if (check(pattern, str))
        {
            cout << s << " | ";
        }
    }
    
    cout << "\nComparisions : " << comp;
    return 0;
}