#include<bits/stdc++.h>
using namespace std;
class solution{
    public:
    bool isCycle(int V, vector<int> adj[]){
        vector<bool> visited(V,false);
        for(int i=0; i<V; i++){
            if(!visited[i] && isCycleBFS(adj,i,visited)) return true;
        }
        return false;
    }
    bool isCycleBFS(vector<int> adj[], int u, vector<bool>& visited){
        queue<pair<int,int>> q;
        q.push({u,-1});
        visited[u]=true;
        while(!q.empty()){
            pair<int,int> P=q.front();
            q.pop();
            int source=P.first;
            int parent=P.second;
            for(int& v: adj[source]){
                if(visited[v]==false){
                    visited[v]=true;
                    q.push({v,source});
                }
                else if(v==parent) continue;
                else return true;
            }
        }
        return false;
    }
};
int main(){
    solution obj;
    vector<int> input[]={{1,2,3},{0,5},{0,4,5,6},{0,7},{2,8},{1,2},{2,8,9},{3,7},{4,6},{6,7}};
    bool ans=obj.isCycle(10,input);
    cout<<ans;
    return 0;
}