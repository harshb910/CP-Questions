// Given an integer array nums of unique elements, return all possible subsets (the power set).

// The solution set must not contain duplicate subsets. Return the solution in any order.

 

// Example 1:

// Input: nums = [1,2,3]
// Output: [[],[1],[2],[1,2],[3],[1,3],[2,3],[1,2,3]]
// Example 2:

// Input: nums = [0]
// Output: [[],[0]]
 

// Constraints:

// 1 <= nums.length <= 10
// -10 <= nums[i] <= 10
// All the numbers of nums are unique.
//Code:
class Solution {
private:
    void powerSet(vector<vector<int>>&ans, vector<int>subans, vector<int>nums, int ind){
        ans.push_back(subans);
        for(int j=ind;j<nums.size();j++){
            if(j>ind && nums[j]==nums[j-1])continue;
            subans.push_back(nums[j]);
            powerSet(ans,subans,nums,j+1);
            subans.pop_back();
        }
    }
    
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>>ans;
        vector<int>subans;
        sort(nums.begin(),nums.end());
        powerSet(ans,subans,nums,0);
        return ans;
    }
};
