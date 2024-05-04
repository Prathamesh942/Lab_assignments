// Implement depth first search algorithm and Breadth First Search algorithm, Use an undirected
// graph and develop a recursive algorithm for searching all the vertices of a graph or tree data
// structure. 

// PLAYGROUND - https://leetcode.com/playground/ifDRGA96

// I - implementing for graph data structure

#include<bits/stdc++.h>
using namespace std;

void recfun(vector<vector<int>> g, int c, vector<int>& vis){
    cout<<c<<" ";
    vis[c]=1;
    int n=g.size();
    for(int i=0; i<n; i++){
        if(g[c][i] && !vis[i]){
            recfun(g,i,vis);
        }
    }
}

class graph{
private:
    vector<vector<int>> g;
    int n;
public:
    graph(int n){
        this->n=n;
        for(int i=0; i<n; i++){
            g.push_back({});
            for(int j=0; j<n; j++){
                g[g.size()-1].push_back(0);
            }
        }
    }
    
    void addnode(int i, int j){
        g[i][j]=1;
        g[j][i]=1;
    }
    
    void print(){
        cout<<"  ";
        for(int i=0; i<n; i++){
            cout<<i<<" ";
        }
        cout<<"\n";
        for(int i=0; i<n; i++){
            cout<<i<<" ";
            for(int j=0; j<n; j++){
                cout<<g[i][j]<<" ";
            }
            cout<<"\n";
        }
    }
    
    void dfs(){
        vector<int> visited(n,0);
        recfun(g,0,visited);
        cout<<"\n";
    }
    
    void bfs(){
        vector<int> vis(n,0);
        queue<int> q;
        q.push(0);
        while(!q.empty()){
            int f = q.front();
            q.pop();
            cout<<f<<" ";
            vis[f]=1;
            for(int i=0; i<n; i++){
                if(g[f][i] && !vis[i]){
                    q.push(i);
                }
            }
        }
        cout<<"\n";
    }
};

// II implementing for tree data structure



class node{
public:
    int data;
    node* left;
    node* right;
    node(int data){
        this->data=data;
        this->left=NULL;
        this->right=NULL;
    }
};

void recfun2(node* root){
    if(root==NULL){
        return;
    }
    cout<<root->data<<" ";
    recfun2(root->left);
    recfun2(root->right);
}

class tree{
private:
    node* root;
public:
    tree(int data){
        root = new node(data);
    }
    
    void insert(int val){
        node* temp=root;
        while(temp->left!=NULL && temp->right!=NULL){
            if(rand()%2){
                temp=temp->left;
            }else{
                temp=temp->right;
            }
        }
        if(temp->left==NULL){
            temp->left=new node(val);
        }else{
            temp->right=new node(val);
        }
    }
    
    void bfs(){
        queue<node*> q;
        q.push(root);
        while(!q.empty()){
            int n=q.size();
            for(int i=0; i<n; i++){
                node* f=q.front();
                q.pop();
                cout<<f->data<<" ";
                if(f->left!=NULL){
                   q.push(f->left);
                }
                if(f->right!=NULL){
                    q.push(f->right);
                }
            }
            cout<<"\n";
        }
        cout<<"\n";
    }
    
    void dfs(){
        recfun2(root);
    }
};

int main(){
    tree t(1);
    t.insert(2);
    t.insert(3);
    t.insert(4);
    t.insert(5);
    t.insert(6);
    t.bfs();
    t.dfs();
    
    graph g(4);
    g.addnode(1,0);
    g.addnode(1,3);
    g.addnode(2,2);
    g.addnode(0,2);
    g.print();
    g.dfs();
    g.bfs();
}
