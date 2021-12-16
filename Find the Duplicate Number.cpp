// Given an array of integers nums containing n + 1 integers where each integer is in the range [1, n] inclusive.

// There is only one repeated number in nums, return this repeated number.

// You must solve the problem without modifying the array nums and uses only constant extra space.

 

// Example 1:

// Input: nums = [1,3,4,2,2]
// Output: 2
// Example 2:

// Input: nums = [3,1,3,4,2]
// Output: 3
// Example 3:

// Input: nums = [1,1]
// Output: 1
// Example 4:

// Input: nums = [1,1,2]
// Output: 1
 

// Constraints:

// 1 <= n <= 105
// nums.length == n + 1
// 1 <= nums[i] <= n
// All the integers in nums appear only once except for precisely one integer which appears two or more times.
 

// Follow up:

// How can we prove that at least one duplicate number must exist in nums?
// Can you solve the problem in linear runtime complexity?
//Approach:
//   o iterate through array. In each iteration repeate a loop till in ith position i+1 does not come or current number's position is already filled.
//   o again iterate and return the number which is not equal to iterator+1
//Code:
class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int n=nums.size();
        int a ;
        for(int i=0;i<n;i++){
            int correctPos = nums[i]-1;
            while(nums[i]!=(i+1) && nums[correctPos]!=correctPos+1){   
                swap(nums[i],nums[correctPos]);
                correctPos = nums[i]-1;
            }
        }
        for(int i=0;i<n;i++){
            if(nums[i]!= (i+1)){
                return nums[i];
            }
        }
        return n;
    }
};
//Or same cane be written as
class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int n=nums.size();
        int a ;
        for(int i=0;i<n;i++){
            int correctPos = nums[i]-1;
            while(nums[i]!=(i+1) && nums[correctPos]!=correctPos+1){   
                swap(nums[i],nums[correctPos]);
                correctPos = nums[i]-1;
                if(nums[correctPos]==correctPos+1 && correctPos!=i)return nums[i];
            }
        }
        for(int i=0;i<n;i++){
            if(nums[i]!= (i+1)){
                return nums[i];
            }
        }
        return n;
    }
};
//Or different approach is to use map but here complexity = O(n*logn)
class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int n=nums.size();
        vector<int>v(n+2,0);
        for(int i=0;i<n;i++){
            v[nums[i]]++;
        }
        for(int i=0;i<n+2;i++){
            if(v[i]>=2)return i;
        }
        return -1;
    }
};
//Or using slow and fast pointer approach  complexity = O(n)
class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int slow = nums[0],fast=nums[0];
        do{
            slow = nums[slow];
            fast = nums[nums[fast]];
        }while(slow!=fast);
        fast = nums[0];
        while(slow!=fast){
            slow = nums[slow];
            fast = nums[fast];
        }
        return slow;
    }
};
