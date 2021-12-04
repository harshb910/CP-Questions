/*   Given an array having both positive and negative integers. The task is to compute the length of the largest subarray with sum 0.

Example 1:

Input:
N = 8
A[] = {15,-2,2,-8,1,7,10,23}
Output: 5
Explanation: The largest subarray with
sum 0 will be -2 2 -8 1 7.   */
int maxLen(vector<int>&A, int n)
{   
    unordered_map<int,int>umap;
    int cursum=0,maxlen=0;
    for(int i=0;i<n;i++){
        cursum += A[i];

        if(cursum==0){
            maxlen = i+1;
        }else{
            if(umap.find(cursum) != umap.end()){
                maxlen = max(i-umap[cursum],maxlen);
            }else{
                umap[cursum] = i;
            }
        }
    }
    return maxlen;
}
