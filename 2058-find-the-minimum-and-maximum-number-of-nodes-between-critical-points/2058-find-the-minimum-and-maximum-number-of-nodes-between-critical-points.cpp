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
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        vector<int>criti;
        ListNode* p=head;
        ListNode* c=head->next;
        ListNode* n=head->next->next;
        int i=0;
        while(n){
            if(c->val>p->val&&c->val>n->val)criti.push_back(i);
            else if(c->val<p->val&&c->val<n->val)criti.push_back(i);
            i++;
            p=c;
            c=n;
            n=n->next;
        }
        if(criti.size()<2)return {-1,-1};
        int mini=criti[1]-criti[0];
        for(int i=2;i<criti.size();i++)mini=min(mini,criti[i]-criti[i-1]);
        int maxi=criti.back()-criti[0];
        return {mini,maxi};
    }
};