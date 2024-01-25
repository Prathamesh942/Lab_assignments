#include<iostream>
using namespace std;


void print(vector<vector<int>> board){
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if(board[i][j]){
                cout<<board[i][j]<<" ";
            }else{
                cout<<"  ";
            }
        }
        cout<<"\n";
    }
}

int geth(vector<vector<int>> board){
    int h=0;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if(board[i][j]==0){
                continue;
            }
            if((i*3)+j+1 != board[i][j]){
                h++;
            }
        }
    }
    return h;
}

bool validpos(int n, int i, int j){
    if(i<0 || j<0 || i>=n || j>=n){
        return false;
    }
    return true;
}

bool validstate(vector<vector<int>> board){
    vector<vector<int>> invalid;
    for(int i=0; i<n; i++){
        invalid.push_back(vector<int> (n,-1));
    }
    return invalid!=board;   
}

vector<vector<int>> move(vector<vector<int>> board, char direction){
    int p,q;
    int n=board.size();
    vector<vector<int>> invalid;
    for(int i=0; i<n; i++){
        invalid.push_back(vector<int> (n,-1));
    }
    if(direction=='U'){
        if(validpos(n,p-1,q)){
            board[p][q] = board[p-1][q];
            board[p-1][q] = 0;
            return board;
        }
        return invalid;
    }
    if(direction=='D'){
        if(validpos(n,p+1,q)){
            board[p][q] = board[p+1][q];
            board[p+1][q] = 0;
            return board;
        }
        return invalid;
    }
    if(direction=='R'){
        if(validpos(n,p,q+1)){
            board[p][q] = board[p][q+1];
            board[p][q+1] = 0;
            return board;
        }
        return invalid;
    }
    if(direction=='L'){
        if(validpos(n,p,q-1)){
            board[p][q] = board[p][q-1];
            board[p][q-1] = 0;
            return board;
        }
        return invalid;
    }
}

void play(vector<vector<int>> state1,vector<vector<int>> state2){
    int h = geth(state1);
    vector<vector<int>> r1,r2,r3,r4;
    int h1=999,h2=999,h3=999,h4=999;
    r1=move(board,'U');
    r2=move(board,'D');
    r3=move(board,'R');
    r4=move(board,'L');
    if(validstate(r1)){
        h1=geth(r1);
    }
    if(validstate(r2)){
        h2=geth(r2);
    }
    if(validstate(r3)){
        h3=geth(r3);
    }
    if(validstate(r4)){
        h4=geth(r4);
    }
    
}

class game{
private:
    vector<vector<int>> state1;
    vector<vector<int>> state2;
    int n;
public:
    game(vector<vector<int>> state1){
        this->state1 = state1;
        for(int i=0; i<n; i++){
            state2.push_back({});
            for(int j=0; j<n; j++){
                state[state.size()-1].push_back((i*3)+j+1);
            }
        }
        state2[n-1][n-1] = 0;
    }
    void printstates(){
        print(state1);
        print(state2);
    }
    void solution(){
        void play(state1,state2,0);
    }
};
