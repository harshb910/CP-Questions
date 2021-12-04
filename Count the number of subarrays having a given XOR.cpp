/* Given an array of integers arr[] and a number m, count the number of subarrays having XOR of their elements as m.
Examples: 

Input : arr[] = {4, 2, 2, 6, 4}, m = 6
Output : 4
Explanation : The subarrays having XOR of 
              their elements as 6 are {4, 2}, 
              {4, 2, 2, 6, 4}, {2, 2, 6},
               and {6}

Input : arr[] = {5, 6, 7, 8, 9}, m = 5
Output : 2
Explanation : The subarrays having XOR of
              their elements as 5 are {5}
              and {5, 6, 7, 8, 9}
*/
int solution(vector<int>&A, int B){
    //umap store currentxor^B and frequency
  unordered_map<int,int>umap;
  int curxor=0;
  int count=0;
  for(auto i:A){
      curxor = curxor^i;
      if(curxor==B)count++;

      if(umap.find(curxor^B)!=umap.end()){
          count+= umap[curxor^B];
      }

      umap[curxor]++;
  }
  return count;
}
