#include <iostream>
using namespace std;


// Consider arr as weigth 

bool isSubsetsum(int arr[], int n, int sum){
    bool dp[n + 1][sum + 1];

    for (int j = 0; j < sum + 1; j++)
    {
        dp[0][j] = 0;
    }

    // dp[0][0] is 1

    for (int i = 0; i < n + 1; i++)
    {
        dp[i][0] = 1;
    }
    
    for (int i = 1; i < n + 1; i++)
    {
        for (int j = 1; j < sum + 1; j++)
        {
            if(arr[i - 1] <= j){
                dp[i][j] = dp[i - 1][j] || dp[i - 1][j - arr[i - 1]];
            }
            else{
                dp[i][j] = dp[i - 1][j];
            }
        }
    }

    return dp[n][sum];    
}
int main(){

    int n, sum;
    cout << "Enter number of elements in set and sum : ";
    cin >> n >> sum;

    int arr[n];
    cout << "Enter " << n << " elements : ";
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    
    cout << isSubsetsum(arr, n, sum);
    
    return 0;
}