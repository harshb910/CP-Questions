// Given the head of a linked list, remove the nth node from the end of the list and return its head.

 

// Example 1:


// Input: head = [1,2,3,4,5], n = 2
// Output: [1,2,3,5]
// Example 2:

// Input: head = [1], n = 1
// Output: []
// Example 3:

// Input: head = [1,2], n = 1
// Output: [1]
 

// Constraints:

// The number of nodes in the list is sz.
// 1 <= sz <= 30
// 0 <= Node.val <= 100
// 1 <= n <= sz
//Code:
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
//In O(n) + O(n) = O(2n)
//    |      |
// length   n=1(worst case)
int length(ListNode* head){
    int n=0;
    while(head!=NULL){
        n++;
        head = head->next;
    }
    return n;
}
ListNode* removeNthFromEnd(ListNode* head, int n) {
    int l = length(head);
    int k = l-n;
    if(k==0){
        ListNode*ans = head->next;
        delete(head);
        return ans;
    }
    else{
        ListNode*ans = head;
        for(int i=1;i<k;i++)head = head->next;
        ListNode*tmp = head->next;
        head->next = tmp->next;
        delete(tmp);
        return ans;
    }
}

// Follow up:-
//in one pass i.e. O(n)
ListNode* removeNthFromEnd(ListNode* head, int n) {
     //using slow and fast pointer concept
     ListNode *fast=head,*slow=NULL;
     for(int i=1;i<n;i++)fast = fast->next;
     int i=0;
     while(fast->next != NULL){
         //run only first time in loop
         if(i==0){
             fast = fast->next;
             slow = head;
             i++;
         }else{
             fast = fast->next;
             slow = slow->next;
         }
     }
     //Edge Case
     if(slow==NULL){
         ListNode *ans = head->next;
         delete(head);
         return ans;
     }else{
         ListNode* tmp = slow->next;
         slow->next = tmp->next;
         delete(tmp);
         return head;
     }
 }
//Here fast pointer takes O(n) time complexity
