#include <bits/stdc++.h>
using namespace std;

void print(vector<vector <int> > board) {
  int n = board.size();
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      if (board[i][j]) {
        cout << board[i][j] << " ";
      } else {
        cout << "  ";
      }
    }
    cout << "\n";
  }
  cout<<"\n";
}



int geth(vector<vector <int> > board) {
  int h = 0;
  int n = board.size();
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      if (board[i][j] == 0) {
        continue;
      }
      if ((i * 3) + j + 1 != board[i][j]) {
        h++;
      }
    }
  }
  return h;
}

bool validpos(int n, int i, int j) {
  if (i < 0 || j < 0 || i >= n || j >= n) {
    return false;
  }
  return true;
}

bool validstate(vector<vector <int> > board) {
  int n = board.size();
  vector<vector <int> > invalid;
  for (int i = 0; i < n; i++) {
    invalid.push_back(vector<int>(n, -1));
  }
  return invalid != board;
}

vector<vector <int> > move(vector<vector <int> > board, char direction) {
  int p, q;
  int n = board.size();
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      if (board[i][j] == 0) {
        p = i;
        q = j;
        break;
      }
    }
  }
  vector<vector <int> > invalid;
  for (int i = 0; i < n; i++) {
    invalid.push_back(vector<int>(n, -1));
  }
  if (direction == 'U') {
    if (validpos(n, p - 1, q)) {
      board[p][q] = board[p - 1][q];
      board[p - 1][q] = 0;
      return board;
    }
    return invalid;
  }
  if (direction == 'D') {
    if (validpos(n, p + 1, q)) {
      board[p][q] = board[p + 1][q];
      board[p + 1][q] = 0;
      return board;
    }
    return invalid;
  }
  if (direction == 'R') {
    if (validpos(n, p, q + 1)) {
      board[p][q] = board[p][q + 1];
      board[p][q + 1] = 0;
      return board;
    }
    return invalid;
  }
  if (direction == 'L') {
    if (validpos(n, p, q - 1)) {
      board[p][q] = board[p][q - 1];
      board[p][q - 1] = 0;
      return board;
    }
    return invalid;
  }
  return board;
}

string code(vector<vector <int> > state){
    string cd="";
    for(int i=0; i<3; i++){
        for(int j=0; j<3; j++){
            cd+=(state[i][j] - 'a');
        }
    }
    return cd;
}

int play(vector<vector <int> > state1, vector<vector <int> > state2,map<string,int>& mp) {
  print(state1);
  if(!validstate(state1) || mp[code(state1)]){
    return -1;
  }
  mp[code(state1)]++;
  int h = geth(state1);
  if (h == 0) {
    return 1;
  }
  vector<vector <int> > r1, r2, r3, r4;
  vector<int> arrh(4, 999);
  r1 = move(state1, 'U');
  r2 = move(state1, 'D');
  r3 = move(state1, 'R');
  r4 = move(state1, 'L');
  if(play(r1,state2,mp)==-1){
    if(play(r2,state2,mp)==-1){
        if(play(r3,state2,mp)==-1){
           if(play(r4,state2,mp)==-1){
            return -1;
           }else{
            return 1;
           }
        }else{
            return 1;
        }
    }else{
        return 1;
    }
  }
  return 1;
}

class game {
private:
  vector<vector <int> > state1;
  vector<vector <int> > state2;
  int n;

public: 
  game(vector<vector <int> > state1, int n) {
    this->n=n;
    this->state1 = state1;
    for (int i = 0; i < n; i++) {
      vector<int> empty;
      state2.push_back(empty);
      for (int j = 0; j < n; j++) {
        state2[state2.size() - 1].push_back((i * 3) + j + 1);
      }
    }
    state2[n - 1][n - 1] = 0;
  }
  void printstates() {
    print(state1);
    print(state2);
  }
  map< string , int > mp;
  void solution() { play(state1, state2,mp); }
};

int main() {
  //vector< vector<int> > ss = {{0,1,3}, {4,2,5}, {7,8,6}};
  //0 3 1 2 4 5 7 8 6
  vector< vector<int> > ss(3, vector<int> (3,0));
  for(int i=0; i<3; i++){
    for(int j=0; j<3; j++){
        cin>>ss[i][j];
    }
  }
  game g(ss, 4);
  g.solution();
}
