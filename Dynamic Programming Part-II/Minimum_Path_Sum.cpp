// Question Name - Minimum Path Sum
// Question Link - https://leetcode.com/problems/minimum-path-sum/

// Solution Link - https://leetcode.com/submissions/detail/695514746/


#include <bits/stdc++.h>
using namespace std;

int minPathSum(vector<vector<int>>& grid) {
    int m = grid.size();
    int n = grid[0].size();
    for(int i=0 ; i<m ; i++){
        for(int j=0 ; j<n ; j++){
            if(i==0 && j==0)continue;
            else if(i==0)grid[i][j] += grid[i][j-1];
            else if(j==0)grid[i][j] += grid[i-1][j];
            else grid[i][j] += min(grid[i-1][j], grid[i][j-1]);
        }
    }
    return grid[m-1][n-1];
}


int main(){
    vector<vector<int>>grid = {{1,3,1},{1,5,1},{4,2,1}};
    cout<<minPathSum(grid)<<"\n";
    return 0;
}