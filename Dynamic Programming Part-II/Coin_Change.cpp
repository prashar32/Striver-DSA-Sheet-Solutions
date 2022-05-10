// Question Name - Coin Change
// Question Link - https://leetcode.com/problems/coin-change/

// Solution Link - https://leetcode.com/submissions/detail/696559284/


#include <bits/stdc++.h>
using namespace std;

int coinChange(vector<int>& coins, int amount) {
    vector<int>dp(amount+1, INT_MAX);
    dp[0] = 0;
    for(int i=0 ; i<=amount ; i++){
        for(auto x : coins){
            if(dp[i]!=INT_MAX && i <= amount-x)
                dp[i+x] = min(dp[i+x], dp[i] + 1);
        }
    }
    return dp[amount] == INT_MAX ? -1 : dp[amount];
}


int main(){
    vector<int>coins = {1,2,5};
    int amount = 11;
    cout<<coinChange(coins, amount)<<"\n";
    return 0;
}