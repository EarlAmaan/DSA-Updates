#include<bits/stdc++.h>
using namespace std;
class A{
    protected:
    vector<int> flag(int V, vector<vector<int>>& mp){
        unordered_map<int,vector<int>> adj;
        vector<int> result;
        vector<bool> visited(V, false);
        for(int u=0; u<V; u++){
            for(auto v=mp[u].begin(); v!=mp[u].end(); v++){
                adj[u].push_back(*v);
            }
        }
        bfs(adj,0,visited,result);
        return result;
    }
    // void bfs(unordered_map<int,vector<int>>& adj, int u, vector<bool>& visited, vector<int>& result){
    //     queue<int> q;
    //     result.push_back(u);
    //     visited[u]=true;
    //     q.push(u);
    //     while(!q.empty()){
    //         int u=q.front();
    //         q.pop();
    //         for(auto v=adj[u].begin(); v!=adj[u].end(); v++){
    //             if(!visited[*v]){
    //                 q.push(*v);
    //                 visited[*v]=true;
    //                 result.push_back(*v);
    //             }
    //         }
    //     }
    // }
    void bfs(unordered_map<int,vector<int>>& adj, int u, vector<bool>& visited, vector<int>& result){
        queue<int> q;
        visited[u]=true;
        q.push(u);
        result.push_back(u);
        while(!q.empty()){
            int u=q.front();
            q.pop();
            for(int& v: adj[u]){
                if(!visited[v]){
                    visited[v]=true;
                    q.push(v);
                    result.push_back(v);
                }
            }
        }
    }
};
class B: public A{
    public:
    vector<int> send(int V, vector<vector<int>>& mp){
        vector<int> result;
        result=flag(V,mp);
        return result;
    }
    void print(vector<int>& result){
        for(auto i=result.begin(); i!=result.end(); i++) cout<<*i<<" ";
    }
};
int main(){
B obj;
vector<vector<int>> input={{1,2,3},{0,5},{0,4,5,6},{0,7},{2,8},{1,2},{2,8,9},{3,7},{4,6},{6,7}};
// vector<vector<int>> input={{1,4},{0},{3,4,6},{2},{0,2,7},{2,8},{2,7},{4,6,8},{5,7}};
vector<int> result=obj.send(10,input);
// vector<int> result=obj.send(9,input);
obj.print(result);
return 0;
}