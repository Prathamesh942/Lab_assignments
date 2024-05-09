// https://leetcode.com/playground/3ut5Jaqd

#include<bits/stdc++.h>
using namespace std;

typedef pair<int,int> pii;

void dijkstra(vector<vector<pii>> g, vector<int>& dist,int src){
    int n=g.size();
    priority_queue<pii,vector<pii>,greater<pii>> pq;
    pq.push(make_pair(0,src));
    dist[src]=0;
    while(!pq.empty()){
        int u = pq.top().second;
        pq.pop();
        for(int i=0; i<g[u].size(); i++){
            int v=g[u][i].first;
            int w=g[u][i].second;
            if(dist[v] > dist[u]+w){
                dist[v]=dist[u]+w;
                pq.push(make_pair(dist[v],v));
            }
        }
    }
}

void print(vector<int> dist){
    for(int i=0; i<dist.size(); i++){
        cout<<i<<" "<<dist[i]<<'\n';
    }
}

int main(){
    vector<vector<pii>> g;
    int v,e;
    cin>>v>>e;
    for(int i=0; i<v; i++){
        g.push_back({});
    }
    vector<int> dist(v,INT_MAX);
    for(int i=0; i<e; i++){
        int src,dest,wt;
        cin>>src>>dest>>wt;
        g[src].push_back(make_pair(dest,wt));
        g[dest].push_back(make_pair(src,wt));
    }
    dijkstra(g,dist,0);
    print(dist);
}
