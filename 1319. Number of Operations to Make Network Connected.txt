## https://leetcode.com/problems/number-of-operations-to-make-network-connected/
class Solution {
public:
    void dfsRec(int v,vector<bool>& visited,vector<int> adj[]){
        visited[v] = true;
        for(int i=0;i<adj[v].size();i++){
            if(!visited[adj[v][i]])
                dfsRec(adj[v][i],visited,adj);
        }
    }
    int makeConnected(int n, vector<vector<int>>& connections) {
        vector<bool> visited(n,false);
        vector<int> adj[n];
        for(int i=0;i<connections.size();i++){
            adj[connections[i][0]].push_back(connections[i][1]);
            adj[connections[i][1]].push_back(connections[i][0]);
        }
        int components = 0;
        for(int i=0;i<n;i++){
            if(!visited[i]){
                dfsRec(i,visited,adj);
                components++;
            }
        }
        int wiresRequired = components-1;
        int alreadyWiredComponents = n - wiresRequired;
        int extraWires = connections.size() - (alreadyWiredComponents - 1);
        if(wiresRequired > extraWires)
            return -1;
        else
            return wiresRequired;
    }
};