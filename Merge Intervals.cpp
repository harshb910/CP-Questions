// Given an array of intervals where intervals[i] = [starti, endi], merge all overlapping intervals, and return an array of the non-overlapping intervals that cover all the intervals in the input.

 

// Example 1:

// Input: intervals = [[1,3],[2,6],[8,10],[15,18]]
// Output: [[1,6],[8,10],[15,18]]
// Explanation: Since intervals [1,3] and [2,6] overlaps, merge them into [1,6].
// Example 2:

// Input: intervals = [[1,4],[4,5]]
// Output: [[1,5]]
// Explanation: Intervals [1,4] and [4,5] are considered overlapping.
 

// Constraints:

// 1 <= intervals.length <= 104
// intervals[i].length == 2
// 0 <= starti <= endi <= 104
//Code:
vector<vector<int>> merge(vector<vector<int>>& intervals) {
    vector< vector<int> >ans;
    sort(intervals.begin(),intervals.end());
    int start=intervals[0][0],end=intervals[0][1];
    ans.push_back({start,end});
    int k=0;
    int n = intervals.size();
    for(int i=1;i<n;i++){
        if(end >= intervals[i][0]){
            end = max(end,intervals[i][1]);
            ans[k][1]=end;
        }else{
            k++;
            start=intervals[i][0];
            end = intervals[i][1];
            ans.push_back({start,end});
        }
    }
    return ans;
}
