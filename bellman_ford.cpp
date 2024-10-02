// Bellman Ford's Algorithm
#include<bits/stdc++.h>
#define max INT_MAX
using namespace std;
class Solution{
    public:
    vector<int> bellman_Ford(int V, vector<vector<int>>& edges, int S){
        vector<int> dis(V,max);
        dis[S]=0;
        for(int i=0; i<V-1; i++){
            for(auto it:edges){
                int u=it[0];
                int v=it[1];
                int wt=it[2];

                if(dis[u]!=max && dis[u]+wt<dis[v]){
                    dis[v]=dis[u]+wt;
                }
            }
        }
        return dis;
    }
    void print(vector<int>& result){
        for(int i=0; i<result.size(); i++){
            cout<<result[i]<<" ";
        }
    }
};
int main(){
    Solution obj;
    int V=5;
    vector<vector<int>> input={
        {0,1,-1},
        {0,2,4},
        {1,2,3},
        {1,3,2},
        {1,4,2},
        {3,1,1},
        {3,2,5},
        {4,3,-3}
    };
    vector<int> result=obj.bellman_Ford(V,input,0);
    obj.print(result);
    return 0;
}