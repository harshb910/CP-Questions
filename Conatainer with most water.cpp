// Given n non-negative integers a1, a2, ..., an , where each represents a point at coordinate (i, ai). n vertical lines are drawn such that the two endpoints of the line i is at (i, ai) and (i, 0). Find two lines, which, together with the x-axis forms a container, such that the container contains the most water.

// Notice that you may not slant the container.

 

// Example 1:


// Input: height = [1,8,6,2,5,4,8,3,7]
// Output: 49
// Explanation: The above vertical lines are represented by array [1,8,6,2,5,4,8,3,7]. In this case, the max area of water (blue section) the container can contain is 49.
// Example 2:

// Input: height = [1,1]
// Output: 1
// Example 3:

// Input: height = [4,3,2,1,4]
// Output: 16
// Example 4:

// Input: height = [1,2,1]
// Output: 2
 

// Constraints:

// n == height.length
// 2 <= n <= 105
// 0 <= height[i] <= 104
//Approach:
//   o by using two pointer method, setting i to 0 and j to last index.
//   o calculating area based on these two i.e. minimum of the two*(j-i)
//   o creating a variable which track the max area obtained.
//   o moving the lower height pointer towards centre till i<j .
//code: 
class Solution {
public:
    int maxArea(vector<int>& height) {
        int n = height.size();
        int maxarea=0;
        int i=0,j=n-1;
        while(i<j){
            int minheight = min(height[i],height[j]);
            maxarea = max(maxarea, minheight*(j-i));
            //moving lower height pointer towards centre
            if(height[i]<=height[j])i++;
            else
                j--;
        }
        return maxarea;
    }
};
