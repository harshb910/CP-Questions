// Given an array of non-negative integers nums, you are initially positioned at the first index of the array.

// Each element in the array represents your maximum jump length at that position.

// Your goal is to reach the last index in the minimum number of jumps.

// You can assume that you can always reach the last index.

 

// Example 1:

// Input: nums = [2,3,1,1,4]
// Output: 2
// Explanation: The minimum number of jumps to reach the last index is 2. Jump 1 step from index 0 to 1, then 3 steps to the last index.
// Example 2:

// Input: nums = [2,3,0,1,4]
// Output: 2
 

// Constraints:

// 1 <= nums.length <= 104
// 0 <= nums[i] <= 1000
//Approach:
//   o by creating a vector to store min number of steps to reach that point ans store 0 at 0th position as we are starting from first index.
//Code:
class Solution {
public:
    int jump(vector<int>& nums) {
        int n = nums.size();
        vector<int>v(n,1e5);
        v[0] = 0;
        for(int i=0;i<n;i++){
            for(int j=1;j<=nums[i];j++){
                if(i+j < n)
                    v[i+j] = min(v[i+j],v[i]+1);
            }
        }
        return v[n-1];
    }
};
