// Given the head of a singly linked list, return the middle node of the linked list.

// If there are two middle nodes, return the second middle node.

 

// Example 1:


// Input: head = [1,2,3,4,5]
// Output: [3,4,5]
// Explanation: The middle node of the list is node 3.
// Example 2:


// Input: head = [1,2,3,4,5,6]
// Output: [4,5,6]
// Explanation: Since the list has two middle nodes with values 3 and 4, we return the second one.
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
ListNode* middleNode(ListNode* head) {
    if(head==NULL || head->next==NULL)return head;
    int l = length(head);
    int n = floor(l/2)+1;
    for(int i=1;i<n;i++){
        head = head->next;
    }
    return head;
}
