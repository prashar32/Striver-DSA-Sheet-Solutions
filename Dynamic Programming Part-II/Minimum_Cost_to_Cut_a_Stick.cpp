// Question Name - Minimum Cost to Cut a Stick
// Question Link - https://leetcode.com/problems/minimum-cost-to-cut-a-stick/

// Solution Link - https://leetcode.com/submissions/detail/697401893/


#include <bits/stdc++.h>
using namespace std;

int dp[103][103] = {};
int MemoDP(vector<int>&cuts, int i, int j){
    if(j-i <= 1)return dp[i][j] = 0;
    if(!dp[i][j]){
        dp[i][j] = INT_MAX;
        for(int k=i+1 ; k<j ; k++){
            dp[i][j] = min(dp[i][j], MemoDP(cuts, i, k) + MemoDP(cuts, k, j) + cuts[j] - cuts[i]);
        }
    }
    return dp[i][j];
}
int minCost(int n, vector<int>& cuts) {
    cuts.push_back(0);
    cuts.push_back(n);
    sort(cuts.begin(), cuts.end());
    return MemoDP(cuts, 0, cuts.size()-1);
}


int main(){
    vector<int>cuts = {5,6,1,4,2};
    cout<<minCost(9, cuts)<<"\n";
    return 0;
}



