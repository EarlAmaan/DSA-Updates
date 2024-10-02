#include<bits/stdc++.h> //Result: Unsuccessful
using namespace std;
class solutions{
    public:
    void find_dfs(int V, vector<int> adj[]){
        vector<bool> visited(V,false);
        vector<int> result;
        for(int i=0; i<V; i++){
            if(!visited[i]) dfs(adj,i,visited,result);
        }
        cout<<"DFS result: ";
        for(int i=0; i<result.size(); i++) cout<<result[i]<<" ";
        cout<<endl;
    }
    void dfs(vector<int> adj[], int u, vector<bool>& visited, vector<int>& result){
        visited[u]=true;
        result.push_back(u);
        for(int &v: adj[u]){
            if(!visited[v]) dfs(adj,v,visited,result);
        }
    }

    void find_bfs(int V, vector<int> adj[]){
        vector<bool> visited(V,false);
        vector<int> result;
        for(int i=0; i<V; i++){
            if(!visited[i]) bfs(adj,i,visited,result);
        }
        cout<<"BFS result: ";
        for(int i=0; i<result.size(); i++) cout<<result[i]<<" ";
        cout<<endl;
    }
    void bfs(vector<int> adj[], int u, vector<bool>& visited, vector<int>& result){
        visited[u]=true;
        result.push_back(u);
        queue<int> q;
        q.push(u);
        while(!q.empty()){
            int u=q.front();
            q.pop();
            for(int &v: adj[u]){
                if(!visited[v]){
                    visited[v]=true;
                    result.push_back(v);
                    q.push(v);
                }
            }
        }
    }

    bool undirectedCycleDFS(int V, vector<int> adj[]){
        vector<bool> visited(V,false);
        for(int i=0; i<V; i++){
            if(!visited[i] && undirectedIsCycleDFS(adj,i,visited,-1)) return true;
        }
        return false;
    }
    bool undirectedIsCycleDFS(vector<int> adj[], int u, vector<bool>& visited, int parent){
        visited[u]=true;
        for(int &v: adj[u]){
            if(v==parent) continue;
            if(visited[v]) return true;
            if(undirectedIsCycleDFS(adj,v,visited,u)) return true;
        }
        return false;
    }

    bool undirectedCycleBFS(int V, vector<int> adj[]){
        vector<bool> visited(V,false);
        for(int i=0; i<V; i++){
            if(!visited[i] && undirectedIsCycleBFS(adj,i,visited)) return true;
        }
        return false;
    }
    bool undirectedIsCycleBFS(vector<int> adj[], int u, vector<bool>& visited){
        queue<pair<int,int>> q;
        visited[u]=true;
        q.push({u,-1});
        while(!q.empty()){
            pair<int,int> p=q.front();
            int source=p.first;
            int parent=p.second;
            for(int& v: adj[source]){
                if(!visited[v]){
                    visited[v]=true;
                    q.push({v,source});
                }
                else if(v==parent) continue;
                else return false;
            }
        }
    }

    bool directedCycleDFS(int V, vector<int> adj[]){
        vector<bool> visited(V, false);
        vector<bool> inRecursion(V,false);
        for(int i=0; i<V; i++){
            if(!visited[i] &&directedIsCycleDFS(adj,i,visited,inRecursion)) return true;
        }
        return false;
    }
    bool directedIsCycleDFS(vector<int> adj[], int u, vector<bool>& visited, vector<bool>& inRecursion){
        visited[u]=true;
        inRecursion[u]=true;
        for(int &v: adj[u]){
            if(!visited[v] && directedIsCycleDFS(adj,v,visited,inRecursion)) return true;
            else if(inRecursion[v]) return true; 
        }
        inRecursion[u]=false;
        return false;
    }

    bool directedCycleBFS(int V, vector<int> adj[]){ //Kahn's ALgorithm
        vector<int>indegree (V,0);
        for(int i=0; i<V; i++){
            for(int &j: adj[i]){
                indegree[j]++;
            }
        }
        queue<int> q;
        int count=0;
        for(int i=0; i<V; i++){
            if(indegree[i]==0) {q.push(i); count++;}
        }
        while(!q.empty()){
            int u=q.front();
            q.pop();
            for(int &v: adj[u]){
                indegree[v]--;
                if(indegree[v]==0){
                    count++;
                    q.push(v);
                }
            }
        }
        if(count==V) return false;
        return true;
    }
};
int main(){
    int V=10;
    vector<int> input[]={{2,3},{5},{0,4,5,6},{0,7},{2},{1,2},{2,8,9},{3,7},{6},{6,7}};
    solutions obj;
    vector<int> input1[]={{1},{0,2},{1}};
    vector<int> input2[]={{1},{2},{3},{4},{1}};
    obj.find_dfs(V,input);
    obj.find_bfs(V,input);
    cout<<"DFS Undirected Cycle: "<<obj.undirectedCycleDFS(3,input1)<<endl;
    cout<<"BFS Undirected Cycle: "<<obj.undirectedCycleBFS(3,input1)<<endl;
    cout<<"DFS Directed Cycle: "<<obj.directedCycleDFS(5,input2)<<endl;
    cout<<"DFS Undirected Cycle: "<<obj.directedCycleBFS(5,input2)<<endl;
    return 0;
}