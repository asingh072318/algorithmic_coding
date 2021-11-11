## https://leetcode.com/problems/number-of-islands/

class Solution {
public:
    bool isSafe(int i,int j,vector<vector<bool>>& visited,vector<vector<char>>& grid){
        return (i>-1 && j>-1 && i<grid.size() && j<grid[0].size() && !visited[i][j] && grid[i][j] == '1');
    }
    void dfsRec(int i,int j,vector<vector<bool>>& visited,vector<vector<char>>& grid){
        visited[i][j] = true;
        int adji[] = {-1,1,0,0};
        int adjj[] = {0,0,-1,1};
        for(int k=0;k<4;k++){
            int inew = i + adji[k];
            int jnew = j + adjj[k];
            if(isSafe(inew,jnew,visited,grid))
                dfsRec(inew,jnew,visited,grid);
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        int mrow = grid.size(), mcol = grid[0].size(),response=0;
        vector<vector<bool>> visited(mrow,vector<bool> (mcol,false));
        for(int i=0;i<mrow;i++){
            for(int j=0;j<mcol;j++){
                if(!visited[i][j] && grid[i][j]=='1'){
                    dfsRec(i,j,visited,grid);
                    response++;
                }
            }
        }
        return response;
    }
};