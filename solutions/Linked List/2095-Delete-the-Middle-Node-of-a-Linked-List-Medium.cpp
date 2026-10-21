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
class Solution{
public:
    ListNode* deleteMiddle(ListNode* head){
        if(head->next == nullptr) return nullptr;

        ListNode* n = head;
        ListNode* m = head->next->next;

        while(m != nullptr && m->next != nullptr){
            n = n->next;
            m = m->next->next;
        }

        ListNode* mid = n->next;
        n->next = mid->next;

        delete mid;
        return head;
    }
};