## https://leetcode.com/problems/max-area-of-island/
class Solution {
public:
    bool isSafe(int i,int j,vector<vector<bool>> &visited,vector<vector<int>>& grid){
        return (i>-1 && j>-1 && i<visited.size() && j<visited[0].size() && !visited[i][j] && grid[i][j]);
    }
    int bfs(int i,int j,vector<vector<bool>> &visited,vector<vector<int>>& grid){
        queue<pair<int,int>> q;
        q.push(make_pair(i,j));
        visited[i][j] = true;
        int area=0;
        int x[] = {-1,0,1,0};
        int y[] = {0,-1,0,1};
        while(!q.empty()){
            pair<int,int> curr = q.front();
            q.pop();
            area++;
            for(int k=0;k<4;k++){
                int newx = curr.first+x[k];
                int newy = curr.second+y[k];
                if(isSafe(newx,newy,visited,grid)){
                    q.push(make_pair(newx,newy));
                    visited[newx][newy] = true;
                }
            }
        }
        return area;
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int m = grid.size(),n = grid[0].size();
        vector<vector<bool>> visited(m,vector<bool>(n,false));
        int maxArea = 0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(isSafe(i,j,visited,grid)){
                    maxArea = max(maxArea,bfs(i,j,visited,grid));
                }
            }
        }
        return maxArea;
    }
};