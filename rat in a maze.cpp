#include<bits/stdc++.h>
using namespace std;
int isSafe(vector<vector<int>> &maze,vector<vector<int>> visites,int x,int y,int n){
  if(x>=0 && y>=0 && x<=n-1 && y<=n-1 && visites[x][y]!=1&& maze[x][y]==1)
    return 1;
  else
    return 0;
}
void ratMaze(vector<vector<int>> &maze,vector<vector<int>> &visited, vector<string> &ans, string move, int x,int y,int n){
  if(x==n-1 &&y==n-1){
    ans.push_back(move);
    return;
  }

  //check downward
  if(isSafe(maze,visited,x+1,y,n)==1){
    visited[x][y]=1;
    ratMaze(maze,visited,ans,move+'D',x+1,y,n);
    visited[x][y]=0;
  }

   if(isSafe(maze,visited,x,y+1,n)==1){
    visited[x][y]=1;
    ratMaze(maze,visited,ans,move+'R',x,y+1,n);
    visited[x][y]=0;
  }
}
 
int main(){
  int n;
  cin>>n;
  //declare of the maze
  vector<vector<int>> maze={{1,0,0,0},{1,1,0,1},{1,1,0,0},{0,1,1,1}};
  vector<vector<int>> visited(n,vector<int>(n,0));
  vector<string> ans;
  if(maze[0][0]==1){
    ratMaze(maze,visited,ans,"",0,0,n);
  }
  int si=ans.size();
  if(si==0){
    cout<<"nothing";
  }
  else{
    for(int i=0;i<si;i++){
      cout<<ans[i]<<endl;
    }
  }

}