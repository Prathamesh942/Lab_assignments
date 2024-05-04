// . Implement A star Algorithm for any game search problem.

// PLAYGROUND - https://leetcode.com/playground/new/empty

#include<bits/stdc++.h>
using namespace std;

class cell{
public:
    int row,col;
    int f,g,h;
    cell* parent;
    
    cell(int row, int col){
        this->row=row;
        this->col=col;
        f=0;
        g=0;
        h=0;
        parent=NULL;
    }
    
    void calculateh(cell* dest){
        h=abs(row - dest->row)+abs(col - dest->col);
    }
    
    void calculatef(){
        f=g+h;
    }
};

bool isvalid(int row, int col, vector<vector<int>> grid){
    int m = grid.size();
    int n=grid[0].size();
    return (row>=0 && row<m && col>=0 && col<n && grid[row][col]==0);
}

vector<cell*> aStar(vector<vector<int>> maze, cell* src, cell* dest){
    vector<int> dr = {-1,1,0,0};
    vector<int> dc = {0,0,-1,1};
    
    priority_queue<cell*, vector<cell*>, function<bool(cell*,cell*)>> pq([](cell* a, cell* b){return a->f > b->f;});
    
    vector<vector<bool>> visited(maze.size(), vector<bool>(maze[0].size(), false));
    
    src->g=0;
    src->calculateh(dest);
    src->calculatef();
    
    pq.push(src);
    
    while(!pq.empty()){
        cell* curr = pq.top();
        pq.pop();
        
        visited[curr->row][curr->col] = true;
        
        if(curr->row == dest->row && curr->col == dest->col){
            vector<cell*> path;
            while(curr!=NULL){
                path.push_back(curr);
                curr=curr->parent;
            }
            return path;
        }
        
        for(int i=0; i<4; i++){
            int newr = curr->row+dr[i];
            int newc = curr->col+dc[i];
            
            if(isvalid(newr,newc,maze) && !visited[newr][newc]){
                cell* nbr = new cell(newr,newc);
                nbr->parent=curr;
                nbr->g=curr->g+1;
                nbr->calculateh(dest);
                nbr->calculatef();
                pq.push(nbr);
            }
        }
    }
    return {};
}

void print(vector<cell*> path){
    if(path.empty()){
        cout<<"No path found!"<<"\n";
        return;
    }
    cout<<"Path found";
    for(int i=path.size()-1; i>=0; i--){
        cout<<"("<<path[i]->row<<","<<path[i]->col<<") ";
    }
    cout<<"\n";
}

int main(){
    vector<vector<int>> maze = {
        {0, 1, 0, 0, 0, 0},
        {0, 0, 1, 1, 0, 0},
        {0, 0, 0, 0, 0, 0},
        {0, 0, 1, 0, 1, 0},
        {0, 0, 0, 0, 1, 0}
    };
    cell* src = new cell(0,0);
    cell* dest = new cell(4,5);
    
    vector<cell*> path = aStar(maze,src,dest);
    print(path);
}
