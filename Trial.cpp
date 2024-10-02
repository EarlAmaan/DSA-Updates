#include<bits/stdc++.h>
using namespace std;

class solution{
    public:
    void dfs(vector<int> adj[], int u, vector<bool>& visited, vector<int>& result){
        if(visited[u]) return ;
        visited[u]=true;
        result.push_back(u);
        for(int &v: adj[u]){
            if(!visited[v]) dfs(adj,v,visited,result);
        }
    }
    void kahn_algo(vector<int> adj[], int V, vector<int>& result){
        vector<int> indegree(V,0);
        for(int u=0; u<V; u++){
            for(int &v: adj[u]) indegree[v]++;
        }
        queue<int> q;
        for(int i=0; i<V; i++) { 
            if(indegree[i]==0) {
                q.push(i); 
                result.push_back(i);
            }
        }
        while(!q.empty()){
            int u=q.front();
            q.pop();
            for(int &v: adj[u]){
                indegree[v]--;
                if(indegree[v]==0){
                    q.push(v);
                    result.push_back(v);
                }
            }
        }
        
    }

};

int main(){
    int V=6;
    vector<int> adj[]={{3,2},{4},{3,1},{1},{},{1,4}};
    // vector<bool> visited(V,false);
    solution obj;
    vector<int> result;
    // obj.dfs(adj,0,visited,result);
    obj.kahn_algo(adj,V,result);
    for(int i=0;i<V;i++) cout<<result[i]<<" ";
    return 0;
}