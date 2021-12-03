/*  Given an array nums of n integers, return an array of all the unique quadruplets [nums[a], nums[b], nums[c], nums[d]] such that:

0 <= a, b, c, d < n
a, b, c, and d are distinct.
nums[a] + nums[b] + nums[c] + nums[d] == target
You may return the answer in any order.

 

Example 1:

Input: nums = [1,0,-1,0,-2,2], target = 0
Output: [[-2,-1,1,2],[-2,0,0,2],[-1,0,0,1]]
Example 2:

Input: nums = [2,2,2,2,2], target = 8
Output: [[2,2,2,2]]
 

Constraints:

1 <= nums.length <= 200
-109 <= nums[i] <= 109
-109 <= target <= 109   */
vector<vector<int>> fourSum(vector<int>& nums, int target) {
    vector<vector<int> >ans;
    int n=nums.size();
    sort(nums.begin(),nums.end());
    if(n<4)return {};
    int i=0,j;
    for(i=0;i<n-3;i++){

        for(j=i+1;j<n-2;j++){
            int target2 = target - nums[i] - nums[j];
            int left=j+1;
            int right = n-1;
            while(left<right){
                if((nums[left]+nums[right])==target2){
                    vector<int>a(4);
                    a[0]=nums[i]; a[1]=nums[j]; a[2]=nums[left]; a[3]=nums[right];
                    ans.push_back(a);

                    while(nums[left]==a[2] && left<right)left++;
                    while(nums[right]==a[3] && right>left)right--;
                }else if((nums[left]+nums[right])<target2)
                    left++;
                else 
                    right--;
            }

            while(nums[j]==nums[j+1] && j+1<n-1)j++;
        }

        while(nums[i]==nums[i+1] && i+1<n-2)i++;
    }
    return ans;
}
