// Given an integer array nums, return all the triplets [nums[i], nums[j], nums[k]] such that i != j, i != k, and j != k, and nums[i] + nums[j] + nums[k] == 0.

// Notice that the solution set must not contain duplicate triplets.

 

// Example 1:

// Input: nums = [-1,0,1,2,-1,-4]
// Output: [[-1,-1,2],[-1,0,1]]
// Example 2:

// Input: nums = []
// Output: []
// Example 3:

// Input: nums = [0]
// Output: []
 

// Constraints:

// 0 <= nums.length <= 3000
// -105 <= nums[i] <= 105
//code:
vector<vector<int>> threeSum(vector<int>& nums) {
    vector<vector<int>> ans;
    sort(nums.begin(),nums.end());
    int n = nums.size();
    for(int i=0;i<n;i++){
        int a = nums[i];
        int target = -a;
        //now two sum approach
        int s = i+1;
        int e = n-1;
        while(s<e){
            if(nums[s]+nums[e]==target){
                ans.push_back({nums[i],nums[s],nums[e]});
                //to avoid repetation
                while(s<e && nums[s]==nums[s+1])s++;
                while(s<e && nums[e]==nums[e-1])e--;
                s++;
                e--;
            }else if(nums[s]+nums[e]<target) 
                s++;
            else 
                e--;

        }
        while(i+1<n && nums[i]==nums[i+1])i++;
    }
    return ans;
}
