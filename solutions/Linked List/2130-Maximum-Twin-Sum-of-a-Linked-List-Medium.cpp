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
    int pairSum(ListNode* head) {
        int ans = 0;

        vector<int> v;
        ListNode* p = head;

        while(p != nullptr){
            v.push_back(p->val);
            p = p->next;
        }

        for(int i=0; i<v.size(); i++){
            ans = max(ans, v[i]+v[v.size()-1-i]);
        }

        return ans;
    }
};