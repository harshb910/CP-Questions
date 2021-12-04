/*  Given an unsorted array of integers nums, return the length of the longest consecutive elements sequence.

You must write an algorithm that runs in O(n) time.

 

Example 1:

Input: nums = [100,4,200,1,3,2]
Output: 4
Explanation: The longest consecutive elements sequence is [1, 2, 3, 4]. Therefore its length is 4.
Example 2:

Input: nums = [0,3,7,2,5,8,4,6,0,1]
Output: 9
 

Constraints:

0 <= nums.length <= 105
-109 <= nums[i] <= 109   */
int longestConsecutive(vector<int>& nums) {
     set<int>s1;
     int n=nums.size();
     for(int i=0;i<n;i++){
         s1.insert(nums[i]);
     }
     int maxstreak=0;
     for(int i=0;i<n;i++){
         if(s1.find(nums[i]-1)==s1.end()){
             int currentnum = nums[i];
             int currentstreak=1;
             while(s1.find(currentnum+1) != s1.end()){
                 currentnum++;
                 currentstreak++;
             }

             maxstreak = max(maxstreak,currentstreak);
         }
     }
     return maxstreak;
 }
