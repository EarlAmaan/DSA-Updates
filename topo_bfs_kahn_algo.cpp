#include<bits/stdc++.h>
using namespace std;
class solution{
    public:
    vector<int> topoSort(int V, vector<int> adj[]){
        vector<int> indegree(V, 0);
        for(int u=0; u<V; u++){
            for(int& v: adj[u]){
                indegree[v]++;
            }
        }
        queue<int> q;
        for(int i=0; i<V; i++){
            if(indegree[i]==0) q.push(i);
        }
        vector<int> result;
        while(!q.empty()){
            int u=q.front();
            result.push_back(u);
            q.pop();
            for(int& v: adj[u]){
                indegree[v]--;
                if(indegree[v]==0) q.push(v);
            }
        }
        return result;
    }
};
int main(){
    solution obj;
    vector<int> adj[]={{3,2},{4},{3,1},{1},{},{1,4}};
    int V=6;
    vector<int> result=obj.topoSort(V,adj);
    for(int i=0; i<result.size(); i++) cout<<result[i]<<" ";
    return 0;
}