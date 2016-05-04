/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        if(head == NULL) return NULL;
        
        ListNode* prev = head;
        ListNode* curr = head->next;
        ListNode* temp;
        while(curr != NULL){
            if(curr->val == val){
                temp = curr;
                prev->next = curr->next;
                curr = curr->next;
                free(temp);
            }
            else{
                prev = prev->next;
                curr = curr->next;
            }
        }
        if(head->val == val) head = head->next;
        return head;
    }
};
