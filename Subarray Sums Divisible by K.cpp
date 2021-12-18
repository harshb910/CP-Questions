// Given an integer array nums and an integer k, return the number of non-empty subarrays that have a sum divisible by k.

// A subarray is a contiguous part of an array.

 

// Example 1:

// Input: nums = [4,5,0,-2,-3,1], k = 5
// Output: 7
// Explanation: There are 7 subarrays with a sum divisible by k = 5:
// [4, 5, 0, -2, -3, 1], [5], [5, 0], [5, 0, -2, -3], [0], [0, -2, -3], [-2, -3]
// Example 2:

// Input: nums = [5], k = 9
// Output: 0
 

// Constraints:

// 1 <= nums.length <= 3 * 104
// -104 <= nums[i] <= 104
// 2 <= k <= 104
//apprach:
//   o create a varibale sum to store prefix sum and update it in each iteration.
//   o create a unordered map to store temp = sum%k as key and freq as value (to handle negative prefix sum do (sum%k + k)%k).
//   o now if temp is equal to 0 increment count by 1 .
//   o if there already present temp as key in unordered map means a certain prefix sum%k has ocurred so increment count by frequency(value) of temp as key.=> ---15----15----15(cur) then umap[15](cur)=2 so count increment by 2 i.e previous ocurring frequency of 15 and then umap[15]++. 
//   o now increment the frequency of temp as key in unordered map.
//code:
class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        unordered_map<int,int>umap;
        int sum=0;
        int count=0;
        for(int i=0;i<nums.size();i++){
            sum+=nums[i];
            int temp = ((sum%k)+k)%k; // handle negative sum
            if(temp==0)count++;
            if(umap.find(temp)!=umap.end()){
                count+=umap[temp];
            }
            umap[temp]++;
        }
        
        return count;
        
    }
};
