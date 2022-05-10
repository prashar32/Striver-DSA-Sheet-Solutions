// Question Name - Longest Increasing Subsequence
// Question Link - https://leetcode.com/problems/longest-increasing-subsequence/

// Solution Link - https://leetcode.com/submissions/detail/693859796/
                // https://leetcode.com/submissions/detail/693864082/


#include <bits/stdc++.h>
using namespace std;

// N^2 Tabulation
int lengthOfLIS_DP(vector<int>& nums) {
    int n = nums.size();
    vector<int>dp(n, 1);
    int MaxiLen = 0;
    for(int i=0 ; i<n ; i++){
        for(int j=i-1 ; j>=0 ; j--){
            if(nums[j] < nums[i])
                dp[i] = max(dp[i], dp[j] + 1);
        }
        MaxiLen = max(MaxiLen, dp[i]);
    }
    return MaxiLen;
}

// Nlog(N) Binary Search
int lengthOfLIS_BinarySearch(vector<int>& nums) {
    int n = nums.size();
    int currLen = 0;
    for(auto x : nums){
        if(!currLen || nums[currLen-1] < x)
            nums[currLen++] = x;
        else{
            int idx = lower_bound(nums.begin(), nums.begin()+currLen, x) - nums.begin();
            nums[idx] = x;
        }
    }
    return currLen;
}

int main(){
    vector<int>nums = {10,9,2,5,3,7,101,18};
    cout<<lengthOfLIS_DP(nums)<<"\n";
    cout<<lengthOfLIS_BinarySearch(nums)<<"\n";
    return 0;
}
