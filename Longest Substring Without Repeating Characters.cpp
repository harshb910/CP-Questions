/* Given a string s, find the length of the longest substring without repeating characters.

 

Example 1:

Input: s = "abcabcbb"
Output: 3
Explanation: The answer is "abc", with the length of 3.
Example 2:

Input: s = "bbbbb"
Output: 1
Explanation: The answer is "b", with the length of 1.
Example 3:

Input: s = "pwwkew"
Output: 3
Explanation: The answer is "wke", with the length of 3.
Notice that the answer must be a substring, "pwke" is a subsequence and not a substring.  */
int lengthOfLongestSubstring(string s) {
    unordered_map<char,int>umap;
    int l=s.length();
    int curlen=0,maxlen=0,isprev=-1;
    for(int i=0;i<l;i++){
        if(umap.find(s[i])==umap.end()){
            curlen++;
            maxlen = max(curlen,maxlen);
            umap[s[i]] = i;
        }else{
            if(umap[s[i]]<isprev){
                curlen++;
            }else{
                curlen = i - umap[s[i]];
                isprev = umap[s[i]];
            }

            maxlen = max(curlen,maxlen);
            umap[s[i]] = i;
        }
    }
    return maxlen;
}
