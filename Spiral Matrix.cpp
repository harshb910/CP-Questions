// Given an m x n matrix, return all elements of the matrix in spiral order.

 

// Example 1:


// Input: matrix = [[1,2,3],[4,5,6],[7,8,9]]
// Output: [1,2,3,6,9,8,7,4,5]
// Example 2:


// Input: matrix = [[1,2,3,4],[5,6,7,8],[9,10,11,12]]
// Output: [1,2,3,4,8,12,11,10,9,5,6,7]
 

// Constraints:

// m == matrix.length
// n == matrix[i].length
// 1 <= m, n <= 10
// -100 <= matrix[i][j] <= 100
class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> ans;
        int l=0,t=0,b=matrix.size()-1,r=matrix[0].size()-1,f=0;
        while(t<=b && l<=r){
            if(f==0){
                for(int i=l;i<=r;i++){
                    ans.push_back(matrix[t][i]);
                }
                f=1;
                t++;
            }
            else if(f==1){
                for(int i=t;i<=b;i++){
                    ans.push_back(matrix[i][r]);
                }
                f=2;
                r--;
            }
            else if(f==2){
                for(int i=r;i>=l;i--){
                    ans.push_back(matrix[b][i]);
                }
                f=3;
                b--;
            }
            else if(f==3){
                for(int i=b;i>=t;i--){
                    ans.push_back(matrix[i][l]);
                }
                l++;
                f=0;
            }
        }
        return ans;
    }
};
