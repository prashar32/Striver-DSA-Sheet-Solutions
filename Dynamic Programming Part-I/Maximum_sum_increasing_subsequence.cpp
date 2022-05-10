// Question Name - Maximum sum increasing subsequence 
// Question Link - https://practice.geeksforgeeks.org/problems/maximum-sum-increasing-subsequence4749/1

#include <bits/stdc++.h>
using namespace std;

int maxSumIS(int arr[], int n)  {  
   int ans = 0;
   vector<pair<int,int>>dp(n+1, {0, 0});
   for(int i=1 ; i<=n ; i++){
       dp[i] = make_pair(arr[i-1], arr[i-1]);
       for(int j=i-1 ; j>=0 ; j--){
           if(dp[j].second < arr[i-1] && arr[i-1] + dp[j].first > dp[i].first){
               dp[i].first = arr[i-1] + dp[j].first;
           }
       }
       ans = max(ans, dp[i].first);
   }
   return ans;
} 


int main(){
    int arr[] = {1, 101, 2, 3, 100}; 
    cout<<maxSumIS(arr, 5)<<"\n";
    return 0;
}



