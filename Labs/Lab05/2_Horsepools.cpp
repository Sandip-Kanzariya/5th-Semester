#include <bits/stdc++.h>
using namespace std;
int comp = 0;

/*
Time : O(n)
WorstCase-Time : O(n * m)
*/

int main()
{

    string text, pattern;
    // T= “JIM SAW ME IN A BOOK SHOP” P= “SHOP”
    cout << "Enter Text : ";
    cin >> text;
    cout << "Enter Pattern : ";
    cin >> pattern;

    int n = text.size();
    int m = pattern.size();

    // Pre-Processing
    map<char, int> shift;
    for (int i = 0; i < n; i++)
    {
        shift[text[i]] = m;
    }
    for (int i = 0; i < m - 1; i++)
    {
        shift[pattern[i]] = m - 1 - i;
    }

    // Print Shift Table
    // for(auto k : shift){
    //     cout << k.first << " " << k.second << "\n";
    // }
    

   cout << "Shifts : ";
    int j = 0;
    while (j + m <= n)
    {
        //
        if (text[j + m - 1] == pattern[m - 1])
        {
            int i = m - 2; // Second Last

            while (i >= 0 && text[j + i] == pattern[i])
            {
                i--;
                comp++;
            }
            if (i == -1)
            {
                cout << j << " | ";
            }
        }

        if (isalpha(text[j + m - 1]))
            j += shift[text[j + m - 1]];
        else
            j += m - 1;
    }

    cout << "\nComparisions : " << comp;

    return 0;
}