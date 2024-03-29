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
    ListNode* rotateRight(ListNode* head, int k) {
        if(!head) return head;
        ListNode *newH,*newT;
        newH = newT = head;
        int count = 1;
        while(newT->next!=NULL)
        {
            newT = newT->next;
            count++;
            
        }
        newT->next = head;
        if(k%=count)
        {
            for(int i = 0; i < count-k;i++) newT = newT->next;
        }
        newH = newT->next;
        newT->next = NULL;
        return newH;
    }
};