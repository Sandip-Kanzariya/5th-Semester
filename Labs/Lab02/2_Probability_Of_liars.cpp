#include <bits/stdc++.h>
using namespace std;
using USLLI = unsigned long long int;

USLLI power(USLLI a, USLLI x, USLLI n)
{
    USLLI res = 1;

    while (x > 0)
    {

        // Odd

        if (x % 2 == 1)
        {
            res = (res * a) % n;
        }

        x = x / 2;

        a = (a * a) % n;
    }

    return res;
}

int main()
{

    USLLI n;
    cout << "Enter Number : ";
    cin >> n;

    USLLI count = 0;

    for (USLLI i = 2; i <= n - 2; i++)
    {
        if (power(i, n - 1, n) == 1)
        {
            count++;
        }
    }
    
    cout << "Liars : " << count << "\n";
    cout << "Witness : " << n - 3 - count << "\n";

    cout << "Probability of Liars: " << (double)count / (n - 3);

    return 0;
}
