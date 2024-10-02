#include<bits/stdc++.h>
using namespace std;

class A{
    public:
    vector<int> flag(int V, vector<vector<int>>& mp){
        unordered_map<int,vector<int>> adj;
        vector<bool> visited(V,false);
        vector<int> result;
        for(int u=0; u<V; u++){
            for(auto v=mp[u].begin(); v!=mp[u].end(); v++) adj[u].push_back(*v);
        }
        dfs(adj,0,visited,result);
        return result;
    }
    void dfs(unordered_map<int,vector<int>>& adj, int u, vector<bool>& visited, vector<int>& result){
        if(visited[u]) return;
        visited[u]=true;
        result.push_back(u);
        for(auto v=adj[u].begin(); v!=adj[u].end(); v++){
            if(!visited[*v]) dfs(adj,*v,visited,result);
        }
    }
};

int main(){
    int V=10;
    vector<vector<int>> input={{2,3},{5},{0,4,5,6},{0,7},{2},{1,2},{2,8,9},{3,7},{6},{6,7}};
    A obj;
    vector<int> ans(V);
    ans=obj.flag(V,input);
    for(auto i=ans.begin(); i!=ans.end(); i++){
        cout<<*i<<" ";
    }
    return 0;
}