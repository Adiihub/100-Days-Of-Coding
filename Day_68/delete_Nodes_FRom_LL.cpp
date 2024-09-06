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
    ListNode* modifiedList(vector<int>& nums, ListNode* head) {
        vector<int> freq(1e5+1,0);
        for(int i=0;i<nums.size();i++){
            freq[nums[i]]=1;
        }

        ListNode* dummy=new ListNode(-1);
        ListNode* ans=dummy;

        ListNode* temp=head;
        while(temp!=NULL){
            int val=temp->val;
            if(freq[val]==0){
                dummy->next=temp;
                dummy=dummy->next;
            }
            temp=temp->next;
        }

        dummy->next=NULL;
        return ans->next;
    }

};