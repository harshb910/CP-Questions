// You are given the heads of two sorted linked lists list1 and list2.

// Merge the two lists in a one sorted list. The list should be made by splicing together the nodes of the first two lists.

// Return the head of the merged linked list.

 

// Example 1:


// Input: list1 = [1,2,4], list2 = [1,3,4]
// Output: [1,1,2,3,4,4]
// Example 2:

// Input: list1 = [], list2 = []
// Output: []
// Example 3:

// Input: list1 = [], list2 = [0]
// Output: [0]
 

// Constraints:

// The number of nodes in both lists is in the range [0, 50].
// -100 <= Node.val <= 100
// Both list1 and list2 are sorted in non-decreasing order.
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
ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
    ListNode *head1,*head2;
    if(list1==NULL){return list2;}
    if(list2==NULL)return list1;
    if(list1->val <= list2->val){
        head1 = list1;
        head2 = list2;
    }
    else {
        head1 = list2;
        head2 = list1;
    }
    ListNode*ans = head1;
    ListNode *prev1=NULL,*prev2=NULL;
    while(head1!=NULL && head2!=NULL){
        if(head1->val <= head2->val){
            prev1 = head1;
            head1 = head1->next;
        }else{
            prev2 = head2;
            head2 = head2->next;
            prev1->next = prev2;
            prev2->next = head1;
            prev1 = prev2;
        }
    }
    if(head1==NULL)prev1->next = head2;
    return ans;
}
