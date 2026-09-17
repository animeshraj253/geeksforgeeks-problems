class Solution {
  public:
  
    void dfs( int node , vector<bool> &visited, stack<int> &s, vector<vector<int>> &adj ){
        visited[node] = true;
        
        for( auto neigh : adj[node]){
            if( !visited[neigh]){
                dfs(neigh, visited,s,adj);
            }
        }
        s.push(node);
    }
    vector<int> topoSort(int V, vector<vector<int>>& edges) {
        
        vector<vector<int>> adj(V);
        for( int i = 0; i < edges.size(); i++){
            int u = edges[i][0];
            int v = edges[i][1];
            
            adj[u].push_back(v);
        }
        
        
        vector<bool> visited(V, false);
        stack <int> s;
        for( int i= 0 ; i < V; i++){
            if( !visited[i] ){
                dfs(i,visited,s,adj);
            }
        }
        
        vector<int> ans;
        while(!s.empty()){
            ans.push_back(s.top());
            s.pop();
        }
        
        return ans;
        
    }
};