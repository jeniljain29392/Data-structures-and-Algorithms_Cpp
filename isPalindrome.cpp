/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
private:
    ListNode* reverseList(ListNode* head) {
        ListNode* prev = NULL;
        ListNode* curr = head;
        ListNode* next;
        while(curr != NULL){
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        return prev;
    }
public:
    bool isPalindrome(ListNode* head) {
        if(head == NULL) return true;
        ListNode *fast = head;
        ListNode *slow = head, *revHalf;
        while(fast && fast->next){
            slow = slow->next;
            fast = fast->next->next;
        }
        revHalf = reverseList(slow);
        while(head != slow){
            if(head->val != revHalf->val) return false;
            head = head->next;
            revHalf = revHalf->next;
        }
        return true;
    }
};
