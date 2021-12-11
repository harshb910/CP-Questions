// Implement next permutation, which rearranges numbers into the lexicographically next greater permutation of numbers.

// If such an arrangement is not possible, it must rearrange it as the lowest possible order (i.e., sorted in ascending order).

// The replacement must be in place and use only constant extra memory.

 

// Example 1:

// Input: nums = [1,2,3]
// Output: [1,3,2]
// Example 2:

// Input: nums = [3,2,1]
// Output: [1,2,3]
// Example 3:

// Input: nums = [1,1,5]
// Output: [1,5,1]
// Example 4:

// Input: nums = [1]
// Output: [1]
 

// Constraints:

// 1 <= nums.length <= 100
// 0 <= nums[i] <= 100
//Approach:-
//     o First from last find first decreasing number's index. If no such number is found then just reverse the vector and return.
//     o Then find first just increasing number's index from end.
//     o swap these two numbers.
//     o Then reverse the right part of vector from right of first decreasing number's index.
//Code:-
void nextPermutation(vector<int>& nums) {
    int n = nums.size();
    int firstDecreasing,justIncreasing,i;
    for(i=n-2;i>=0;i--){
        if(nums[i]<nums[i+1]){
            firstDecreasing=i;
            break;
        }
    }
    if(i==-1){
        reverse(nums.begin(),nums.end());
        return ;
    }
    for(i=n-1;i>=0;i--){
        if(nums[i]>nums[firstDecreasing]){
            justIncreasing=i;
            break;
        }
    }
    swap(nums[firstDecreasing], nums[justIncreasing]);
    reverse(nums.begin()+firstDecreasing+1, nums.end());
    return ;
}
//using STL library function
void nextPermutation(vector<int>& nums) {
    next_permutation(nums.begin(),nums.end());
}
