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
class Solution {
public:
    ListNode* temp;
    bool solve(ListNode* head)
    {
        if(head == NULL) return true;
        
        bool check = solve(head->next) and temp->val == head->val;
        temp = temp->next;
        return check;
    }
    bool isPalindrome(ListNode* head) {
        temp = head;
        return solve(head);
    }
};