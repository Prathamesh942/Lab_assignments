// Kruskal's Minimal Spanning Tree Algorithm
//PLAYGROUND - https://leetcode.com/playground/jTmYFBHk

#include<bits/stdc++.h>
using namespace std;

class Edge{
public:
    int src;
    int dest;
    int wt;
    Edge(int src,int dest, int wt){
        this->src=src;
        this->dest=dest;
        this->wt=wt;
    }
};

class graph{
public:
    vector<Edge> edges;
    int v,e;
    vector<Edge> res;
    
    graph(int v, int e){
        this->v=v;
        this->e=e;
    }
    
    void addedge(int src,int dest, int wt){
        Edge newedge(src,dest,wt);
        edges.push_back(newedge);
    }
    
    int find(vector<int> parent,int i){
        if(parent[i]==-1){
            return i;
        }
        return find(parent,parent[i]);
    }
    
    void kruskal(){
        vector<int> parent(v,-1);
    
    sort(edges.begin(),edges.end(), [](Edge a, Edge b){return a.wt<b.wt;});
    
    int ec=0;
    int i=0;
    while(ec<v-1 && i<e){
        Edge next=edges[i++];
        
        int x=find(parent, next.src);
        int y=find(parent, next.dest);
        
        if(x!=y){
            res.push_back(next);
            parent[x]=y;
            ec++;
        }
    }
    
    cout<<"MST\n";
    for(auto it:res){
        cout<<it.src<<" "<<it.dest<<" "<<it.wt<<"\n";
    }
    }
};

int main(){
    graph g(6,9);
    g.addedge(0,1,1);
    g.addedge(0,2,1);
    g.addedge(0,3,2);
    g.addedge(1,5,2);
    g.addedge(2,5,1);
    g.addedge(2,3,2);
    g.addedge(3,4,2);
    g.addedge(3,5,1);
    g.addedge(4,5,2);
    g.kruskal();
}
