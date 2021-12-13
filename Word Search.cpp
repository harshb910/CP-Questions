// Given an m x n grid of characters board and a string word, return true if word exists in the grid.

// The word can be constructed from letters of sequentially adjacent cells, where adjacent cells are horizontally or vertically neighboring. The same letter cell may not be used more than once.

 

// Example 1:


// Input: board = [["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]], word = "ABCCED"
// Output: true
// Example 2:


// Input: board = [["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]], word = "SEE"
// Output: true
// Example 3:


// Input: board = [["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]], word = "ABCB"
// Output: false
 

// Constraints:

// m == board.length
// n = board[i].length
// 1 <= m, n <= 6
// 1 <= word.length <= 15
// board and word consists of only lowercase and uppercase English letters.
// //Approach:-
//   o iterate through all cells for first letter in word.
//   o if found then run dfs through that cell and if result of dfs is true then return true.
//   o if by iterating all not found then return false.
//   o In dfs which takes parameter our board, our position{i,j}, count of letters match, our word to match; 
//     first check if count of letters match is equal to length of word if equal the return true.
//   o If not equal then check if we are within the limit constraint of our board or our cell does match current letter to match 
//     if true then proceed and if false then return false.
//   o Now we are sure that our current letter is matched and to proceed first declare a temp variable and set its value to current cell's value and set current cell's value to '_'
//     so that if proceed in all direction then we should not again match our current matched letter for eg BCB then in case of current letter C we should not count earlier counted B.
//   o make a variable(bool) and set its value to dfs of going right or left or down or up.
//   o before returning make sure reset the value of current cell with the help of temp variable and then return the value of variable(bool).
//code:
class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        for(int i=0;i<board.size();i++){
            for(int j=0;j<board[i].size();j++){
                if(board[i][j]==word[0] && dfs(board,i,j,0,word)){
                    return true;
                }
            }
        }
        return false;
    }
    bool dfs(vector<vector<char>> &board, int i, int j, int count, string word){
        if(count == word.length())
            return true;
        if(i<0 || i>=board.size() || j<0 || j>=board[i].size() || board[i][j]!=word[count])
            return false;
        char temp = board[i][j];
        board[i][j] = '_';
        bool isFound = dfs(board,i+1,j,count+1,word) || dfs(board,i-1,j,count+1,word) ||
                     dfs(board,i,j+1,count+1,word) || dfs(board,i,j-1,count+1,word);
        board[i][j] = temp;
        return isFound;
    }
};
    
