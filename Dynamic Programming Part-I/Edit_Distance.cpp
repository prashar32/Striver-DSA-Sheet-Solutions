// Question Name - Edit Distance
// Question Link - https://leetcode.com/problems/edit-distance/

// Solution Link - https://leetcode.com/submissions/detail/694799418/
//                 https://leetcode.com/submissions/detail/694785467/ 


#include <bits/stdc++.h>
using namespace std;

// N*M Time   N*M space
int minDistance(string word1, string word2) {
    int n = word1.size();
    int m = word2.size();
    vector<vector<int>>dp(n+1, vector<int>(m+1));
    for(int i=0 ; i<=n ; i++){
        for(int j=0 ; j<=m ; j++){
            if(!i || !j)
                dp[i][j] = max(i, j);
            else
                dp[i][j] = (word1[i-1] == word2[j-1]) ? dp[i-1][j-1] : min({dp[i-1][j-1], dp[i-1][j], dp[i][j-1]}) + 1;
        }
    }
    return dp[n][m];
}

// N*M*N Time    N*M Space 
int minDistance(string word1, string word2) {
    // changing word2 to word1
    swap(word1, word2);
    int n = word1.size();
    int m = word2.size();
    vector<vector<int>>dp(n+1, vector<int>(m+1, 5000));
    dp[0][0] = 0;       
    for(int i=0 ; i<=n ; i++){
        for(int j=0 ; j<=m ; j++){
            if(i==0 && j==0)continue;
            else if(i==0){
                dp[i][j] = j;
                continue;
            }
            else if(j==0){
                dp[i][j] = i;
                continue;
            }
            dp[i][j] = dp[i][j-1] + 1;
            bool have = false;
            for(int k=i-1 ; k>=0 ; k--){
                if(word1[k]==word2[j-1])have = true;
                have ? dp[i][j] = min(dp[i][j], dp[k][j-1] + i-k-1) : dp[i][j] = min(dp[i][j], dp[k][j-1] + 1 + i-k-1);
            }
        }
    }
    return dp[n][m];
} 


int main(){
    cout<<minDistance("horse", "ros")<<"\n";
    return 0;
}
