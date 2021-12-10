// Given an array of integers nums and an integer k, return the total number of continuous subarrays whose sum equals to k.

 

// Example 1:

// Input: nums = [1,1,1], k = 2
// Output: 2
// Example 2:

// Input: nums = [1,2,3], k = 3
// Output: 2
 

// Constraints:

// 1 <= nums.length <= 2 * 104
// -1000 <= nums[i] <= 1000
// -107 <= k <= 107

// Explanation:
// ->The HashMap will store with the key being any particular sum, and the value being the number of times it has happened till the current iteration of the loop as we 
//   traverse the array from left to right.
// ->For example:
//   o k = 26.
//   o If a sub-array sums up to k, then the sum at the end of this sub-array will be sumEnd = sumStart + k. That implies: sumStart = sumEnd - k.
//   o Suppose, at index 10, sum = 50, and the next 6 numbers are 8,-5,-3,10,15,1.
//   o At index 13, sum will be 50 again (the numbers from indexes 11 to 13 add up to 0).
//   o Then at index 16, sum = 76.
//   o Now, when we reach index 16, sum - k = 76 - 26 = 50. So, if this is the end index of a sub-array(s) which sums up to k, then before this, just before the 
//     start of the sub-array, the sum should be 50.
//   o As we found sum = 50 at two places before reaching index 16, we indeed have two sub-arrays which sum up to k (26): from indexes 14 to 16 and from indexes 11 to 16.

//Code:
int subarraySum(vector<int>& nums, int k) {
    int n=nums.size();
    int sum=0;
    int count=0;
    map<int,int>m;
    m[0]=1;
  
    for(int i=0;i<n;i++){
        sum+=nums[i];
        if(m.find(sum-k)!=m.end()){
            count+=m[sum-k];
        }
        m[sum]++;
    }


    return count;
}
