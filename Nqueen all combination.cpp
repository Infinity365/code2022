#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> result;
class Solution{
public:
bool isSafe(vector<vector<int>> &board ,int row,int col){
    //left row
 int i, j;
	int N = board.size();

	/* Check this row on left side */
	for (i = 0; i < col; i++)
		if (board[row][i])
			return false;

	/* Check upper diagonal on left side */
	for (i = row, j = col; i >= 0 && j >= 0; i--, j--)
		if (board[i][j])
			return false;

	/* Check lower diagonal on left side */
	for (i = row, j = col; j >= 0 && i < N; i++, j--)
		if (board[i][j])
			return false;

	return true;
}
bool solveQueen(vector<vector<int>> &board,int col){
    int N=board.size();
    if(col>=N){
        vector<int> v;
        for(int i=0;i<N;i++){
            for(int j=0;j<N;j++){
                if(board[i][j]==1)
                v.push_back(j+1);
            }
        }
        result.push_back(v);
        return true;
        
        
    }
    
    for(int i=0;i<N;i++){
        
        if(isSafe(board,i,col)==true){
            board[i][col]=1;
            solveQueen(board,col+1);  
            board[i][col]=0;
            
        }
    }
    
}
    vector<vector<int>> nQueen(int n) {
        
        result.clear();
        vector<vector<int> > board(n, vector<int>(n, 0));
        
        solveQueen(board,0);
        sort(result.begin(),result.end());
        return result;

    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        
        Solution ob;
        vector<vector<int>> ans = ob.nQueen(n);
        if(ans.size() == 0)
            cout<<-1<<"\n";
        else {
            for(int i = 0;i < ans.size();i++){
                cout<<"[";
                for(int u: ans[i])
                    cout<<u<<" ";
                cout<<"] ";
            }
            cout<<endl;
        }
    }
    return 0;
}  // } Driver Code Ends