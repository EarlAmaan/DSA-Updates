#include<bits/stdc++.h>
using namespace std;
class solution{
    public:
    stack<int> topo_sort(int V, vector<int> adj[]){
        vector<bool> visited(V,false);
        stack<int> st;
        for(int i=0; i<V; i++){
            if(!visited[i]) dfs(adj,i,visited,st);
        }
        return st;
    }
    void dfs(vector<int> adj[], int u, vector<bool>& visited, stack<int>& st){
        visited[u]=true;
        for(int& v: adj[u]){
            if(!visited[v]) dfs(adj,v,visited,st);
        }
        st.push(u);
    }
};
int main(){
    solution obj;
    vector<int> adj[]={{2,3},{4},{1,3},{1},{},{4,1}};
    int V=6;
    stack<int> result;
    result=obj.topo_sort(V,adj);
    while(!result.empty()){
        cout<<result.top()<<" ";
        result.pop();
    }
    return 0;
}