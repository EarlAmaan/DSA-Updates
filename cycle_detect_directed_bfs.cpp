#include<bits/stdc++.h>
using namespace std;
class solution{
    public:
    bool topoSort(int V, vector<int> adj[]){
        int count=0;
        vector<int> indegree(V,0);
        for(int i=0; i<V; i++){
            for(int& v: adj[i]) indegree[v]++;
        }
        queue<int> q;
        for(int i=0; i<V; i++){
            if(indegree[i]==0) {
                q.push(i);
                count++;
            }
        }
        while(!q.empty()){
            int u=q.front();
            q.pop();
            for(int& v: adj[u]){
                indegree[v]--;
                if(indegree[v]==0){
                    q.push(v);
                    count++;
                }
            }
        }
        if(count==V) return false;
        return true;
    }
};
int main(){
    solution obj;
    vector<int> adj[]={{3,2},{4},{3,1},{1},{},{1,4}};
    int V=6;
    bool result=obj.topoSort(V,adj);
    cout<<result;
    return 0;
}