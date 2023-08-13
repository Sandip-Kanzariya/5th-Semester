#include <bits/stdc++.h>
using namespace std;

int comp = 0;

/*
Time : O((n - m + 1) * m)
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

    // T = JIM_SAW_ME_IN_A_BOOK_SHOP | P = SHOP
    // T = JIMY_HAILED_THE_LEADER_TO_STOP | P = LEADER
    // T = AAAAAAAAAA | P = AA
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