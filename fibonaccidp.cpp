#include <iostream>
#include <vector>
 
using namespace std;
 
int fibonacci(vector <int> &dp, int n)
{
        // base case
        if(n == 0)
                return 0;
 
        if(dp[n] != 0)
                return dp[n];
 
        // otherwise
        // calculate the solution and store it
        dp[n] = fibonacci(dp, n - 1) + fibonacci(dp, n - 2);
 
        // finally return the solution
        return dp[n];
}
 
int main()
{
        cout << "Enter the highest order term you want to evaluate" << endl;
        int n;
        cin >> n;
 
        // declare the dynamic programming vector
        vector <int> dp(n, 0);
        dp[1] = 1;
 
        cout << "Term " << n << " of the Fibonacci Series is: " << fibonacci(dp, n - 1) << endl;
}