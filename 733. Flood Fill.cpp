## https://leetcode.com/problems/flood-fill/
class Solution {
public:
    bool isSafe(int x,int y,vector<vector<bool>>& visited){
        return (x<visited.size() && y < visited[0].size() && !visited[x][y]);
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        int m = image.size(),n = image[0].size(),oldColor=image[sr][sc];
        vector<vector<bool>> visited(m,vector<bool>(n,false));
        queue<pair<int,int>> q;
        q.push(make_pair(sr,sc));
        int x[] = {-1,0,1,0};
        int y[] = {0,-1,0,1};
        while(!q.empty()){
            pair<int,int> curr = q.front();
            q.pop();
            visited[curr.first][curr.second]=true;
            image[curr.first][curr.second]=newColor;
            for(int i=0;i<4;i++){
                int newx = curr.first+x[i];
                int newy = curr.second+y[i];
                if(isSafe(newx,newy,visited) && image[newx][newy]==oldColor)
                    q.push(make_pair(newx,newy));
            }
        }
        return image;
    }
};