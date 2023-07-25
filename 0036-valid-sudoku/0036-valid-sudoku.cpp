class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        map<int,int> row[9],col[9],blk[9];
        char c;
        for(int i = 0;i<9;i++){
        for(int j =0;j<9;j++){
            c = board[i][j];
            if(c!='.'){
                if(row[i][c] == 1 || col[j][c] == 1 || blk[i/3*3+j/3][c] == 1)
                    return false;
                row[i][c]=col[j][c]=blk[i/3*3+j/3][c]=1;

            }
        }
    }
    return true;
        
    }
};


/*
row[1]={
    3:1
    5:2
}
row[3]={

}
row = {row[1],row[2]     } 



*/