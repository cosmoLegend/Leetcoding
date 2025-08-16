class Solution {
public:
    void dfs (vector<vector<int>> & adj , vector<int>& vis , int node){
        queue <int > q ;
        vis [node] = 1 ;
        q.push(node) ;
        while (!q.empty()){
            int node = q.front () ;
            q.pop() ;
            for (auto &it : adj[node]){
                if (!vis[it])
                q.push(it) ;
            }
            vis[node] = 1 ;
        }
    }

    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size() ;
        int totalProvinces = 0 ; 

        vector<vector<int>>adj(n + 1) ;
        
        for (int i = 0 ; i < n ; i++){
            for (int j = 0 ; j < n ; j++){
                if(isConnected[i][j] == 1)
                adj[i + 1].push_back(j + 1) ;
            }
        }

        vector<int> vis (n + 1 , 0) ;

        for (int i = 1 ; i <= n ; i++){
            if (!vis[i]) dfs (adj , vis , i) , totalProvinces++ ;
            
        }

        return totalProvinces ;
    }
};