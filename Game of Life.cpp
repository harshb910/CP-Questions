// According to Wikipedia's article: "The Game of Life, also known simply as Life, is a cellular automaton devised by the British mathematician John Horton Conway in 1970."

// The board is made up of an m x n grid of cells, where each cell has an initial state: live (represented by a 1) or dead (represented by a 0). Each cell interacts with its eight neighbors (horizontal, vertical, diagonal) using the following four rules (taken from the above Wikipedia article):

// Any live cell with fewer than two live neighbors dies as if caused by under-population.
// Any live cell with two or three live neighbors lives on to the next generation.
// Any live cell with more than three live neighbors dies, as if by over-population.
// Any dead cell with exactly three live neighbors becomes a live cell, as if by reproduction.
// The next state is created by applying the above rules simultaneously to every cell in the current state, where births and deaths occur simultaneously. Given the current state of the m x n grid board, return the next state.

 

// Example 1:


// Input: board = [[0,1,0],[0,0,1],[1,1,1],[0,0,0]]
// Output: [[0,0,0],[1,0,1],[0,1,1],[0,1,0]]
// Example 2:


// Input: board = [[1,1],[1,0]]
// Output: [[1,1],[1,1]]
 

// Constraints:

// m == board.length
// n == board[i].length
// 1 <= m, n <= 25
// board[i][j] is 0 or 1.
 

// Follow up:

// Could you solve it in-place? Remember that the board needs to be updated simultaneously: You cannot update some cells first and then use their updated values to update other cells.
//Approach:
//   o for counting current surrounding live cells mark the transitioned live cell as something eg. -1, or count*10+borad[i][j] which help in determiningthe current live cell even after transition
//   o similarly for dead cells eg. 2 which indicate 0->1.
//   o after this again traverse through matrix and make necessary changes.
//code:
class Solution {
public:
    bool isSafe(int i,int j,int r,int c){
        if(i<0 || i>=r || j<0 || j>=c)
            return false;
        return true;
    }
    void gameOfLife(vector<vector<int>>& board) {
        int r = board.size(),c = board[0].size();
        // 0->1 => 2, 1->0 => -1
        vector<vector<int>>d = {{1,0},{-1,0},{0,1},{0,-1},{1,1},{-1,1},{1,-1},{-1,-1}};
        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){
                int count=0;
                for(int k=0;k<8;k++){
                    if(isSafe(i+d[k][0], j+d[k][1], r, c) && abs(board[i+d[k][0]][j+d[k][1]])==1){
                        count++;
                    }
                }
                if((count<2 || count>3) && (board[i][j]==1)){
                    board[i][j]=-1;//dead i.e 1->0
                }else if(count==3 && board[i][j]==0){
                    board[i][j]=2;//live i.e. 0->1
                }
            }
        }
        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){
                if(board[i][j]==-1){
                    board[i][j]=0;
                }else if(board[i][j]==2){
                    board[i][j]=1;
                }
            }
        }
    }
};

//Or


void gameOfLife(vector<vector<int>>& board) {
        
    int n = board.size();
    int m = board[0].size();
    for(int i =0; i < n ; i++)
    {
        for(int j = 0; j< m ; j++)
        {
            int cnt = 0;
            // Checking if neighbour is live or not
            if(  ((i - 1) >=0 && (i-1)<n) && board[i-1][j]%10 == 1)
            {
                cnt++;
            }
            if(  ((i + 1) < n && (i+1)>=0) && board[i+1][j]%10 == 1)
            {
                cnt++;
            }
            if(  ((j - 1) >=0 && (j-1) < m) && board[i][j-1]%10 == 1)
            {
                cnt++;
            }
            if(  ((j+1) >=0 && (j + 1) < m) && board[i][j+1]%10 == 1)
            {
                cnt++;
            }
            if(  ((i - 1) >=0 && (j-1) >=0 && (i-1) <n && (j-1) < m) && board[i-1][j-1]%10 == 1)
            {
                cnt++;
            }
            if(  ((i - 1) >=0 && (i-1) <n && (j+1) >=0 && (j+1) < m) && board[i-1][j+1]%10 == 1)
            {
                cnt++;
            }
            if(  ((i+1)>=0 && (i + 1) < n && (j-1) >=0 &&(j-1) < m) && board[i+1][j-1]%10 == 1)
            {
                cnt++;
            }
            if(  ((i+1) >=0 && (i + 1) <n && (j+1) >= 0 && (j + 1) < m) && board[i+1][j+1]%10 == 1)
            {
                cnt++;
            }
            // updating the board value to keep track of live neighbours
            int s = cnt*10 + board[i][j];
            board[i][j] = s;
        }
    }
    for(int i = 0 ; i< n ; i++)
    {
        for(int j = 0; j < m ; j++)
        {
            // Here count is the no of live neighbours
            int cnt = board[i][j]/10;
            // Here val is the original value of the cell
            int val = board[i][j]%10;

            // Checking according to the condition provided and updating the cell with final value

            if(val ==1 && cnt < 2)
            {
                board[i][j] = 0;
                continue;
            }
            if(val == 1 && (cnt == 2 || cnt == 3))
            {
                board[i][j] = 1;
                continue;
            }
            if(val == 1 && cnt > 3)
            {
                board[i][j] = 0;
                continue;
            }
            if( val == 0 && cnt !=3)
            {
                board[i][j] = 0;
                continue;
            }
            if(val == 0 && cnt == 3)
            {
                board[i][j] = 1;
                continue;
            }
        }
    }  
}
