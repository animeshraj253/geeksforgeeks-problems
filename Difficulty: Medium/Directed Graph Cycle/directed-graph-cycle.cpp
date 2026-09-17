class Solution {
  public:
  bool isCyclicDFS(int node, vector<bool> &visited, vector<bool> &dfsCall, vector<vector<int>> &adj){

      visited[node] = true;
      dfsCall[node] = true;

      for( auto neighbour : adj[node]){
          if(!visited [ neighbour ] ){
              bool isPresent = isCyclicDFS(neighbour, visited, dfsCall, adj);
              if( isPresent) return true;
          }

          else if ( dfsCall[neighbour] == true ){
              return true;
          }
      }

      dfsCall[node] = false;
        return false;
    }
    bool isCyclic(int V, vector<vector<int>> &edges) {
        vector<vector<int>> adj(V);
        for( int i = 0 ; i<edges.size(); i++){
            int u = edges[i][0];
            int v = edges[i][1];

            adj[u].push_back(v);
        }

        vector<bool> visited(V,false);
        vector<bool> dfsCall(V,false);

        for( int i = 0; i < V ; i++ ){
            if(!visited[i]){
                bool isCyclicPresent = isCyclicDFS(i, visited, dfsCall, adj);
                if( isCyclicPresent ) 
                    return true;
            }
        }

        return false;
        
    }
};