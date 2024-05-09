// https://leetcode.com/playground/jfYQX8iB

#include<bits/stdc++.h>
using namespace std;

bool validcolor(vector<vector<int>> g, int node, int i,vector<int> color){
    for(int j=0; j<g[node].size(); j++){
            int v = g[node][j];
        if(color[v]==i){
            return false;
        }
    }
    return true;
}

bool recfun(vector<vector<int>> g, int node, vector<int>& vis, vector<int>& color,int m){
    for(int i=1; i<=m; i++){
        if(!validcolor(g,node,i,color)){
            continue;
        }
        color[node]=i;
        bool flag=true;
        vis[node]=1;
        for(int j=0; j<g[node].size(); j++){
            int v = g[node][j];
            if(vis[v]){
                continue;
            }
            if(!recfun(g,v,vis,color,m)){
                flag=false;
                break;
            }
        }
        if(flag==true){
            return true;
        }
    }
    vis[node]=0;
    color[node]=0;
    return false;
}

void print(vector<int> color,vector<string> clrs){
    for(int i=0; i<color.size(); i++){
        cout<<i<<"-"<<clrs[color[i]-1]<<"\n";
    }
    cout<<"\n";
}

class graph{
public:
    vector<vector<int>> g;
    vector<string> clrs{"Red","Green","Blue","Yellow","Black","White","Orange","Brown"};
    vector<int> color;
    vector<int> vis;
    int n;
    int m=3;
    
    graph(int n){
        for(int i=0; i<n; i++){
            g.push_back({});
            color.push_back(0);
            vis.push_back(0);
        }
    }
    
    void addedge(int u,int v){
        g[u].push_back(v);
        g[v].push_back(u);
    }
    
    void colorgraph(){
        bool possible = recfun(g,0,vis,color,4);
        if(possible){
            print(color,clrs);
        }else{
            cout<<"Impossible to color graph using "<<m<<" colors\n";
        }
    }
};

int main(){
    graph g(6);
    g.addedge(0,1);
    g.addedge(0,5);
    g.addedge(1,2);
    g.addedge(1,5);
    g.addedge(2,3);
    g.addedge(2,4);
    g.addedge(2,5);
    g.addedge(3,4);
    g.addedge(4,5);
    g.colorgraph();
}
