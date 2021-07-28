//my solution also correct ****************************************


// class Solution {
// public:
//     void printB(vector<vector<string>> &board){
//         int k = board.size();
//         for(int i=0;i<k;i++){
//             for(int j=0;j<k;j++){
//                 if(board[i][j] == "Q") cout << "Q";
//                 else cout << ".";
//             }
//             cout << endl;
//         }
//     }
//     bool safe(vector<vector<string>> &board, int n, int i, int j){
//         //column
//         for(int row=0;row<i;row++){
//             if(board[row][j]=="Q"){
//                 return false;
//             }
//         }
//         //left diagonal
//         int x = i;
//         int y = j;
//         while(x>=0 && y>=0){
//             if(board[x][y]=="Q"){
//                 return false;
//             }
//             x--;
//             y--;
//         }
//         //right diagonal
//         x = i;
//         y = j;
//         while(x>=0 && y<n){
//             if(board[x][y]=="Q"){
//                 return false;
//             }
//             x--;
//             y++;
//         }
//         return true;
//     }
//     bool queenSet(vector<vector<string>> &board, int n, int i){
//         //if safe return true
//         if(i==n){
//             return true;
//         }
//         for(int j=0;j<n;j++){
//             if(safe(board,n,i,j)){
//                 board[i][j] = "Q";
//                 if(queenSet(board,n,i+1)) printB(board); 
//                 board[i][j] = ".";
//             }
//         }
//         //set queen
//         return true;
//     }
//     vector<vector<string>> solveNQueens(int n) {
//         vector<vector<string>> board(n,vector<string>(n,"."));
//         queenSet(board,n,0);
//         return board;
//     }
// };



class Solution {
public:
    vector<vector<string>> res;
    vector<vector<string>> solveNQueens(int n) {
        if(n==0 || n==2 || n==3)
        {
            //since it is not possible to place n queens
            return res;
        }
        vector<string> board(n,string(n,'.'));
        //initialize board 
        //if n=3 then  {...,...,...}
        findPlaces(board,0);
        return res;
    }
    void findPlaces(vector<string>& board,int row)
    {
        if(row==board.size())
        {
            res.push_back(board);
            return ;
        }
        for(int i=0;i<board.size();i++)
        {
            //if i can place queen in the row at some pos i
            if(canPlace(board,row,i)){
                board[row][i]='Q';
                //place queen in next row
                findPlaces(board,row+1);
                //back to normal to find other places
                board[row][i]='.';
            }
        }
    }
    
    bool canPlace(vector<string> board,int row, int ind)
    {
        //check up in the column;
        for(int i=row;i>=0;i--)
        {
            if(board[i][ind]=='Q')
                return false;
        }
        //check diagoanlly up left
        for(int i=row,j=ind;i>=0&&j>=0;i--,j--)
        {
            if(board[i][j]=='Q')
                return false;
        }
        //check diagonally up right
        for(int i=row,j=ind;i>=0&&j<board.size();i--,j++)
        {
            if(board[i][j]=='Q')
                return false;
        }
        //we wont check down because we are placing the queens from top to bottom
        //i.e first row to last row so we dont have any queens down the side
        //so if some queen is placed down afterwards it checks with this queen too
        return true;
    }
};


