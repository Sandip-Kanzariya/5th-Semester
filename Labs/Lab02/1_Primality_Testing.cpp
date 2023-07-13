#include <bits/stdc++.h>

using namespace std;

using USLLI = unsigned long long int;

// Generate Random number in between p and r :
USLLI getRandom(USLLI p, USLLI r)
{
    srand(time(0));
    return (rand() % (r - p + 1)) + p;
}

USLLI gcd(USLLI a, USLLI b)
{

    while (b != 0)
    {
        USLLI res = a % b;
        a = b;
        b = res;
    }

    return a;
}

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

// as k increases, probability of correct ans increases
int k = 100;

bool isPrime(USLLI n)
{

    if (n <= 1 || n == 4)
        return false;

    if (n <= 3)
        return true;

    while (k > 0)
    {

        USLLI a = getRandom(2, n - 2);

        if (gcd(n, a) != 1)
            return false;

        if (power(a, n - 1, n) != 1)
            return false;

        k--;
    }

    return true;
}
int main()
{

    USLLI n;
    cout << "Enter Number for Primality Testing : ";
    cin >> n;
    // 1000000007

    if (isPrime(n))
        cout << n << " is Prime";
    else
        cout << n << " is Composite";

    return 0;
}
