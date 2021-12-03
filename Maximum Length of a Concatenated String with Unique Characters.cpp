//Maximum Length of a Concatenated String with Unique Characters
//You are given an array of strings arr. A string s is formed by the concatenation of a subsequence of arr that has unique characters.

//Return the maximum possible length of s.

//A subsequence is an array that can be derived from another array by deleting some or no elements without changing the order of the remaining elements.
/*Input: arr = ["cha","r","act","ers"]
Output: 6
Explanation: Possible longest valid concatenations are "chaers" ("cha" + "ers") and "acters" ("act" + "ers").
Input: arr = ["un","iq","ue"]
Output: 4
Explanation: All the valid concatenations are:
- ""
- "un"
- "iq"
- "ue"
- "uniq" ("un" + "iq")
- "ique" ("iq" + "ue")
Maximum length is 4.
Input: arr = ["aa","bb"]
Output: 0
Explanation: Both strings in arr do not have unique characters, thus there are no valid concatenations.*/
//Code:- 
int func(vector<string>str,int i,string s){
      if(i==str.size()){
          int freq[26]={0};
          for(auto itr:s){
              if(freq[itr-'a']==1)return 0;
              freq[itr-'a']++;
          }
          return s.length();
      }
      int op1=0, op2=0;
      if((s.length()+str[i].length())<=26){
          op1 = func(str,i+1,s+str[i]);
      }
      op2 = func(str,i+1,s);
      return max(op1,op2);
  }
  int maxLength(vector<string>& arr) {
      string s="";
      return func(arr,0,s);
  }
