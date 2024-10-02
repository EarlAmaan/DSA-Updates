// #include<bits/stdc++.h>
// using namespace std;
// // class solution{
// //     bool isCycle(int V, vector<int> adj[]){
// //         vector<bool> visited(V, false);
// //         vector<bool> inRecursion(V,false);
// //         for(int i=0; i<V; i++){
// //             if(!visited[i] && isCycleDFS(adj,i,visited,inRecursion)) return true;
// //         }
// //         return false
// //     }
// //     bool isCycleDFS(vector<int> adj[], int u, vector<bool>& visited, vector<bool>& inRecursion){
// //         visited[u]=true;
// //         inRecursion[u]=true;
// //         for(int& v: adj[u]){
// //             if(!visited[v] && isCycleDFS(adj,v,visited,inRecursion)) return true;
// //             else if(inRecursion[v]==true) return true;  
// //         }
// //         inRecursion[u]=false;
// //         return false;
// //     }
// // };
// class solution{
//     public:
//     bool isCycle(int V, vector<int> adj[]){
//         vector<bool> visited(V,false);
//         vector<bool> inRecursion(V,false);
//         for(int i=0; i<V; i++){
//             if(!visited[i] && isCycleDFS(adj,i,visited,inRecursion)) return true;
//         }
//         return false;
//     }
//     bool isCycleDFS(vector<int> adj[], int u, vector<bool>& visited, vector<bool>& inRecursion){
//         visited[u]=true;
//         inRecursion[u]=true;
//         for(int& v: adj[u]){
//             if(!visited[v] && isCycleDFS(adj,v,visited,inRecursion)) return true;
//             else if(inRecursion[v]) return true; 
//         }
//         inRecursion[u]=false;
//         return false;
//     }
// };

// int main(){
//     solution obj;
//     // Input 1 with cycle
//     // vector<int> input[]={{1},{2},{3},{4},{1}};
//     // bool ans=obj.isCycle(5,input);

//     // Input 2 without cycle
//     vector<int> input[]={{1},{},{1}};
//     bool ans=obj.isCycle(3,input);
//     cout<<ans;
//     return 0;
// }

class Solution {
  public:
    bool isCyclic(int V, vector<int> adj[]) {
        vetor<bool> visited(V, false);
        vetor<bool> inRecursion(V, false);
        for(int i=0; i<V; i++){
            if(!visited[i] && isCycleDFS(adj,i,visited,inRecursion)) return true;
        }
        return false;
    }
    bool isCycleDFS(vector<int> adj[], int u, vector<bool>& visited, vector<bool>& inRecursion){
        visited[u]=true;
        inRecursion[u]=true;
        for(int& v: adj[u]){
            if(!visited[v] && isCycleDFS(adj,i,visited,inRecursion)) return true;;
            else if(inRecursion[v]) return true;
        }
        inRecursion[u]=false;
        return false;
    }
};