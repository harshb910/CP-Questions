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
