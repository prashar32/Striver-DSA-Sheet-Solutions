// Question Name - Ones and Zeroes
// Question Link - https://leetcode.com/problems/ones-and-zeroes/

// Solution Link - https://leetcode.com/submissions/detail/693999924/


#include <bits/stdc++.h>
using namespace std;

int findMaxForm(vector<string>& strs, int m, int n) {
    int sz = strs.size();
    vector<vector<int>>dp(n+1, vector<int>(m+1, 0));
    for(int i=0 ; i<sz ; i++){
        int zero = count(strs[i].begin(), strs[i].end(), '0');
        int one = strs[i].size() - zero;
        for(int z=m ; z>=zero ; z--){
            for(int o=n ; o>=one ; o--){
                dp[o][z] = max(dp[o][z], 1 + dp[o-one][z-zero]);
            }
        }
    }
    return dp[n][m];
}

int main(){
    vector<string>strs = {"10","0001","111001","1","0"};
    int m = 5, n = 3;
    cout<<findMaxForm(strs, m, n)<<"\n";
    return 0;
}
