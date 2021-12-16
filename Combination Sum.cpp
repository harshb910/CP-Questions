// Given an array of distinct integers candidates and a target integer target, return a list of all unique combinations of candidates where the chosen numbers sum to target. You may return the combinations in any order.

// The same number may be chosen from candidates an unlimited number of times. Two combinations are unique if the frequency of at least one of the chosen numbers is different.

// It is guaranteed that the number of unique combinations that sum up to target is less than 150 combinations for the given input.

 

// Example 1:

// Input: candidates = [2,3,6,7], target = 7
// Output: [[2,2,3],[7]]
// Explanation:
// 2 and 3 are candidates, and 2 + 2 + 3 = 7. Note that 2 can be used multiple times.
// 7 is a candidate, and 7 = 7.
// These are the only two combinations.
// Example 2:

// Input: candidates = [2,3,5], target = 8
// Output: [[2,2,2,2],[2,3,3],[3,5]]
// Example 3:

// Input: candidates = [2], target = 1
// Output: []
 

// Constraints:

// 1 <= candidates.length <= 30
// 1 <= candidates[i] <= 200
// All elements of candidates are distinct.
// 1 <= target <= 500
//Approach:
//                                                                           [2,3,6,7],target=7
//                                           |                     |                             |                           |
//                                          [2], 5               [3], 4                        [6], 1                      [7], 0 => add in result
//                       |         |       |       |           |       |                         |     
//                    [2,2],3   [2,3],2  [2,6],-1 [2,7],-2   [3,6],-2  [3,7],-3                [6,7],-5
//              |       |          ->[2,3,3],-1
//      [2,2,2],1 [2,2,3],0=>add in result
//       |
//       [2,2,2,2],-1
//Code:
class Solution {
private:
    void combinations(vector<vector<int>> &combs,vector<int>&comb,int start,vector<int>nums,int target){
        if(target<0)return;
        if(target==0){
            combs.push_back(comb);
            return;
        }
        for(int i=start;i<nums.size();i++){
            comb.push_back(nums[i]);
            combinations(combs,comb,i,nums,target-nums[i]);
            comb.erase(comb.begin()+comb.size()-1);
        }
    }
public:
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
        vector<vector<int>>combs;
        vector<int>comb;
        combinations(combs,comb,0,nums,target);
        return combs;
    }
};
