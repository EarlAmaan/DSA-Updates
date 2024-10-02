#include<bits/stdc++.h>
using namespace std;
class solution{
    public:
    vector<int> topoSort(int V, vector<int> adj[]){
        vector<bool> visited(V, false);
        stack<int> st;
        for(int i=0; i<V; i++){
            if(!visited[i]) dfs(adj,i,visited,st);
        }
        vector<int> result;
        while(!st.empty()){
            result.push_back(st.top());
            st.pop();
        }
        return result;
    }
    void dfs(vector<int> adj[], int u, vector<bool>& visited, stack<int>& st){
        visited[u]=true;
        for(int& v: adj[u]){
            if(!visited[v]) dfs(adj,v,visited,st);
        }
        st.push(u);
    }
    void print_stack(vector<int>& result){
        for(int i=0; i<result.size(); i++) cout<<result[i]<<" ";
    }
};
int main(){
    solution obj;
    int V=6;
    vector<int> adj[]={{3,2},{4},{3,1},{1},{},{1,4}};
    vector<int> result;
    result=obj.topoSort(V,adj);
    obj.print_stack(result);
    return 0;
}