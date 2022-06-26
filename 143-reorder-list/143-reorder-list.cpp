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
    void reorderList(ListNode* head) {
        deque<ListNode*> dq;
        ListNode* curr = head;
        while(curr!=NULL)
        {
            dq.push_front(curr);
            curr = curr->next;
        }
        ListNode* temp = dq.back();
        dq.pop_back();
        int i = 0;
        while(!dq.empty())
        {
            if(i%2 == 0)
            {
                temp->next = dq.front();
                dq.pop_front();
            }
            else
            {
                temp->next = dq.back();
                dq.pop_back();
            }
            temp = temp->next;
            i+=1;
        }
        temp->next = NULL;
    }
};