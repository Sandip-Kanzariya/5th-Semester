#include <bits/stdc++.h>

using namespace std;

int getRandom(int p, int r)
{
    srand(time(0));
    return (rand() % (r - p + 1)) + p;
}
    
int c = 0, sw = 0;
int partition(vector<int> &v, int l, int h)
{

    // Take last element as pivot
    int pivot = v[h];

    int i = l;
    for (int j = l; j < h; j++)
    {

        c++;
        //
        if (v[j] <= pivot)
        {
            sw++;
            swap(v[i], v[j]);
            i++;
        }
    }
    sw++;
    swap(v[i], v[h]);

    return i;
}

void quickSort(vector<int> &v, int l, int h)
{

    if (l < h)
    {
        int random = getRandom(l, h);
        swap(v[random], v[h]);

        int q = partition(v, l, h);
        quickSort(v, l, q - 1);
        quickSort(v, q + 1, h);
    }

    return;
}

int main()
{

    // vector <int> v = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    // vector <int> v = {10, 9, 8, 7, 6, 5, 4, 3, 2, 1};
    // vector <int> v = {7, 5, 6, 10, 9, 2, 1, 8, 4, 3};
    // vector <int> v = {4, 3, 6, 8, 5, 9, 20, 50, 12, 30, 432, 12, 69, 29, 40, 50, 10, 4, 23, 34, 45, 45, 24,  89, 799, 45, 80, 50, 10, 30, 43,54,65,76,87, 98, 21, 32, 43, 78, 98, 57, 29, 91, 34,  54, 64, 19, 82, 87, 65};

    // vector <int> v = {1, 2, 3, 4, 5, 6};

    int n;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++)
    {
        v[i] = i;
    }

    quickSort(v, 0, n - 1);
    cout << "Sorted : ";
    for (auto k : v)
        cout << k << " ";

    cout << "\nComparisions : " << c << "\n";
    cout << "Swaps : " << sw << "\n";

    return 0;
}
