// Prim's Minimal Spanning Tree Algorithm

// PLAYGROUND - https://leetcode.com/playground/e4tmgp9i

#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;

vector<int> prims(vector<vector<pii>> g, int m, int n){
    vector<int> parent(n,-1);
    vector<int> key(n,INT_MAX);
    vector<bool> vis(n,false);
    
    priority_queue<pii, vector<pii>, greater<pii>>pq;
    pq.push(make_pair(0,0));
    key[0]=0;
    while(!pq.empty()){
        int u = pq.top().second;
        pq.pop();
        vis[u]=true;
        for(auto it:g[u]){
            int v=it.first;
            int wt=it.second;
            
            if(!vis[v] && key[v] > wt){
                key[v]=wt;
                parent[v]=u;
                pq.push(make_pair(key[v],v));
            }
        }   
    }
    return parent;
}

void print(vector<int> parent){
    for(int i=1; i<parent.size(); i++){
        cout<<parent[i]<<" "<<i<<"\n";
    }
}

int main(){
    vector<vector<pii>> g;
    int m,n;
    cout<<"Enter no of vertices and edges\n";
    cin>>n>>m;
    for(int i=0; i<n; i++){
        g.push_back({});
    }
    cout<<"Enter m edges (src,dest,wt)\n";
    for(int i=0; i<m; i++){
        int src,dest,wt;
        cin>>src>>dest>>wt;
        g[src].push_back(make_pair(dest,wt));
        g[dest].push_back(make_pair(src,wt));
    }
    vector<int> parent = prims(g,m,n);
    print(parent);
}
