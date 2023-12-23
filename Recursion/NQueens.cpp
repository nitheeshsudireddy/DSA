class Solution {
public:
    bool isSafe(int row,int col, int n, vector<string>board){
        //column check
        for(int i=0;i<n;i++){
            if(board[i][col] == 'Q') return false;
        }
        int row1 = row;
        int col1 = col;
        //Check for diagonals . Since we are traversing row wise, just check for top diagonals only.
        while(row1>=0 && col1>=0){
            if(board[row1][col1] == 'Q') return false;
            row1--;
            col1--;
        }
        //Diagonal check
        while(row>=0 && col<n){
            if(board[row][col] == 'Q') return false;
            row--;
            col++;
        }
        return true;
    }
    void compute(int row, int n, vector<string> &board, vector<vector<string>>&res){
        if(row == n){
            res.push_back(board);
            return;
        }
        for(int i=0;i<n;i++){
            if(isSafe(row,i,n,board)){
                board[row][i] = 'Q';
                compute(row+1,n,board,res);
                board[row][i] = '.';
            }
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        string s(n,'.');
        vector<string> board;
        for(int i=0;i<n;i++) board.push_back(s);
        vector<vector<string>> res;
        compute(0,n,board,res);
        return res;
    }
};
