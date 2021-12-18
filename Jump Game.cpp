// You are given an integer array nums. You are initially positioned at the array's first index, and each element in the array represents your maximum jump length at that position.

// Return true if you can reach the last index, or false otherwise.

 

// Example 1:

// Input: nums = [2,3,1,1,4]
// Output: true
// Explanation: Jump 1 step from index 0 to 1, then 3 steps to the last index.
// Example 2:

// Input: nums = [3,2,1,0,4]
// Output: false
// Explanation: You will always arrive at index 3 no matter what. Its maximum jump length is 0, which makes it impossible to reach the last index.
 

// Constraints:

// 1 <= nums.length <= 104
// 0 <= nums[i] <= 105
//Approach:
//   o iterate through all indices and update a maximum reachable index in each iteration.
//   o if this maximum reachable index is small than current index means it is not possible 
//     to reach current index then return false and if maximum reachable index is last index or greated then return true.
//   o if oup loop run through each iteration means it is possible to just reach last index so return true.
//Code:
class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size();
        int maxn = 0;
        for(int i=0;i<n;i++){
            if(maxn<i)return false;
            maxn = max(maxn, i+nums[i]);
            if(maxn>=(n-1))return true;
        }
        return true;
    }
};
