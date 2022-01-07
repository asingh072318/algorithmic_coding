## https://leetcode.com/problems/rotting-oranges/
class Solution {
public:
    bool isSafe(int i,int j,vector<vector<int>>& grid,vector<vector<bool>>& visited){
        return (i>-1 && j>-1 && i<grid.size() && j<grid[0].size() && !visited[i][j]);
    }
    int orangesRotting(vector<vector<int>>& grid) {
        vector<vector<bool>> visited(grid.size(),vector<bool>(grid[0].size(),false));
        vector<vector<int>> time(grid.size(),vector<int>(grid[0].size(),-1));
        int maxTime=-1;
        bool executed = false;
        queue<pair<int,int>> q;
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                if(grid[i][j]==2){
                    time[i][j]=0;
                    q.push(make_pair(i,j));
                    executed = true;
                }
            }
        }
        while(!q.empty()){
            int xadj[] = {-1,0,1,0};
            int yadj[] = {0,1,0,-1};
            pair<int,int> cell = q.front();
            q.pop();
            for(int p = 0;p<4;p++){
                int newi = cell.first+xadj[p];
                int newj = cell.second+yadj[p];
                if(isSafe(newi,newj,grid,visited) && grid[newi][newj]==1){
                    q.push(make_pair(newi,newj));
                    visited[newi][newj]=true;
                    time[newi][newj]=time[cell.first][cell.second]+1;
                }
            }
        }
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                if(grid[i][j]==1 && time[i][j]==-1)
                    return -1;
                else
                    time[i][j]>maxTime?maxTime=time[i][j]:NULL;
            }
        }
        if(!executed)
            return 0;
        return maxTime;
    }
};