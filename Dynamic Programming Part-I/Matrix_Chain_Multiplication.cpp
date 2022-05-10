// Question Name - Matrix Chain Multiplication 
// Question Link - https://practice.geeksforgeeks.org/problems/matrix-chain-multiplication0303/1


#include <bits/stdc++.h>
using namespace std;

int solve(int l, int r, int* arr, vector<vector<int>>&dp){
    if(l==r)return 0;
    if(dp[l][r]!=-1)return dp[l][r];
    dp[l][r] = 1e9;
    for(int k=l ; k<r ; k++){
        dp[l][r] = min(dp[l][r], solve(l, k, arr, dp) + solve(k+1, r, arr, dp) + arr[l-1]*arr[k]*arr[r]);
    }
    return dp[l][r];
}

int matrixMultiplication(int N, int arr[])
{
    vector<vector<int>>dp(N+1, vector<int>(N+1, -1));
    return solve(1, N-1, arr, dp);
}

int main(){
    int arr[] = {40, 20, 30, 10, 30};
    cout<<matrixMultiplication(5, arr)<<"\n";
    return 0;
}
