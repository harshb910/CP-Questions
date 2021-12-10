// We are given an array nums and need to return an array ans where ans[i] contains product of all elements in nums except nums[i].
// ✔️ Solution - I (Calculate product & divide by self)

// We can simply calculate product of the whole array and for each element in nums, divide the product by nums[i]. This effectively leaves us with 
// product of whole array except self at each index. We need to take care of zeros that may occur in the array -

// 1. If there are more than one 0s in nums, the result is an array consisting of all 0.
// 2. If there is a single 0 in nums, then the result is an array consisting of all 0 except at the index where there was 0 in nums, which will contain product of rest of array.
// 3. If there's no 0 in nums, then the result is an array ans where ans[i] = prod / nums[i] (prod = product of all elements in nums).
// Time Complexity : O(N)
// Space Complexity : O(1)

// ✔️ Solution - II (Prefix & Suffix Products)

// We are required to solve this problem without using the division operator. We can do this by calculating two arrays pre and suf where pre[i] contains product of all nums[j]
// such that j <= i, and suf[i] contains product of all nums[j] such that j >= i.

// Finally, the resulting array ans can be calculated as ans[i] = pre[i-1] * suf[i+1] which is product of all elements with index less than i multiplied by product of all 
// elements with index greater than i. This is essentially equal to product of array except self at each index.
//code:
 vector<int> productExceptSelf(vector<int>& nums) {
      int l = nums.size();
      vector<int>back(l),front(l);
      front[0]=1;
      back[l-1]=1;
      for(int i=0;i<l-1;i++){
          front[i+1]= front[i]*nums[i];
      }
      for(int i=l-1;i>0;i--){
          back[i-1] = back[i]*nums[i];
      }
      for(int i=0;i<l;i++){
          nums[i] = front[i]*back[i];
      }
      return nums;
//  }
// Time Complexity : O(N), calculating pre and suf arrays takes O(N) time and then another O(N) to compute ans. Total complexity comes out to be O(3*N) = O(N).
// Space Complexity : O(N), required to store pre and suf arrays
   
// ✔️ Solution - III (Space-Optimized Prefix & Suffix Products)

// We can calculate ans without maintaining two extra pre and suf arrays.

// We can initialize the result array ans of length equal to nums filled with 1.
// Then, for each i, we can calculate prefix product (without self), i.e, ans[i] = ans[i-1]*nums[i-1]. This is same as calculating pre in previous approach but this time 
//   we are storing it within our result array.
// Then we iterate from the last index with a variable suffixProd=1 denoting suffix product. For each i, we multiply ans[i] with suffixProd. Each time we will also update 
//   suffixProd = suffixProd * nums[i].
// The above again gives us product of array except self at each index. This is because, firstly we are storing prefix product (without self) in ans and then multiplying 
//   each ans[i] with suffix product which is the same that we did in the previous approach.
//code:
 vector<int> productExceptSelf(vector<int>& nums) {
    int l = nums.size();
    vector<int>op(l);
    op[0]=1;
    for(int i=0;i<l-1;i++){
        op[i+1]=op[i]*nums[i];
    }
    int R=nums[l-1];
    for(int i=l-2;i>=0;i--){
        op[i] = op[i]*R;
        R = R*nums[i];
    }

    return op;
}
// Time Complexity : O(N), one iteration is required to calculate prefix product for each index and another iteration to calculate suffix product. 
//                   Total time complexity comes out to be O(2*N) = O(N)
// Space Complexity : O(1), ignoring the output, we are only using constant extra space.

// ✔️ Solution - IV (Space-Optimized Prefix & Suffix Products in One-Pass)

// The above process can be done in single pass as well. We were first calculating prefix product in one loop and then multiplying it with suffix product in another loop.
// These two process are independent of each other and can be done in the same loop. We just need to keep another prefix product variable similar to suffix_prod in previous
//   approach.

// We iterate from start and keep calculating prefix product & update corresponding ans[i] & at the same time we can calculate keep calculating suffix product from the end & 
//   update ans[n-1-i].
   
//code:
vector<int> productExceptSelf(vector<int>& nums) {
    vector<int> ans(size(nums),1);
    for(int i = 0, suf = 1, pre = 1, n = size(nums); i < n; i++) {
        ans[i] *= pre;             // similar to prefix product being calculated in 1st loop of previous solution
        pre *= nums[i];			
        ans[n-1-i] *= suf;         // similar to suffix product being calculated in 2nd loop of previous solution
        suf *= nums[n-1-i];
    }
    return ans;
}

// Time Complexity : O(N)
// Space Complexity : O(1)
