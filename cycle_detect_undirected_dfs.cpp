// class Solution{
//     public: 
//     bool isCycle(int V, vector<int> adj[]){
//         // unordered_map<int,vector<int>> adj;
//         // for(int i=0; i<V; i++){
//         //     for(auto v=mp[i].begin(); v!=mp[i].end(); v++) adj[i].push_back(*v);
//         // }
//         vector<bool> visited(V, false);
//         for(int i=0; i<V; i++){
//             if(!visited[i] && isCycleDFS(adj,i,visited,-1)) return true;
//         }
//         return false;
//     }
//     bool isCycleDFS(vector<int>& adj[], int u, vector<bool>& visited, int parent){
//         visited[u]=true;
//         for(int &v: adj[u]){
//             if(v==parent) continue;
//             if(visited[v]) return true;
//             if(isCycleDFS(adj,v,visited,u)) return true;
//         }
//         return false;
//     }
// }

#include<bits/stdc++.h>
using namespace std;
class solution{
    public:
    bool isCycle(int V, vector<vector<int>>& adj){
        vector<int> visited(V, false);
        for(int i=0; i<V; i++){
            if(!visited[i] && isCycleDFS(adj,i,visited,-1)) return true;
        }
        return false;
    }
    bool isCycleDFS(vector<vector<int>>& adj, int u, vector<int>& visited, int parent){
        visited[u]=true;
        for(int& v: adj[u]){
            if(v==parent) continue;
            if(visited[v]) return true;
            if(isCycleDFS(adj,v,visited,u)) return true;
        }
        return false;
    }
};

int main(){
    solution obj;
    // vector<vector<int>> input={{1,2,3},{0,5},{0,4,5,6},{0,7},{2,8},{1,2},{2,8,9},{3,7},{4,6},{6,7}};
    // bool ans=obj.isCycle(10,input);
    vector<vector<int>> input={{1},{0,2},{1}};
    bool ans=obj.isCycle(3,input);
    cout<<ans;
    return 0;
}