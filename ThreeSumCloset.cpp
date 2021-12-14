// Given an integer array nums of length n and an integer target, find three integers in nums such that the sum is closest to target.

// Return the sum of the three integers.

// You may assume that each input would have exactly one solution.

 

// Example 1:

// Input: nums = [-1,2,1,-4], target = 1
// Output: 2
// Explanation: The sum that is closest to the target is 2. (-1 + 2 + 1 = 2).
// Example 2:

// Input: nums = [0,0,0], target = 1
// Output: 0
 

// Constraints:

// 3 <= nums.length <= 1000
// -1000 <= nums[i] <= 1000
// -104 <= target <= 104
//Approach:
//   o Creating a variable closetSum to store sum closest to target and store maximum value 
//     in this we have considered maximum to be 1e7 (max(nums[i])=e4 * max(nums.size()=1e3)) and not INT_MAX as to avoid integer overflow.
//   o then iterate over the array and in each iteration consider two pointer approach to create sum variable equal to sum of iterate pointer and two pointers of two pointer approach.
//   o Now consider two cases if this sum is equal to target return target as closest to target is target itself and if absolute value of difference of target and closest sum uptill
//     now is greater than current difference of target sum then update the closest sum.
//Code:
class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
        int n = nums.size();
        int closetSum = 1e7;
        for(int k=0;k<n-1;k++){ 
            int i = k+1;
            int j = n-1;
            while(i<j){
                int sum = nums[i] + nums[j] + nums[k];
                if(sum==target)
                    return target;
                if((long long)abs(target-closetSum)>(long long)abs(target-sum))
                    closetSum = sum;
                if(sum < target)
                    i++;
                else
                    j--;
            }
        }
        return closetSum;
    }
};
