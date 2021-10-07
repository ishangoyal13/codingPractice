class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.size()==0) return NULL;
        vector<int> nums;
        for(int i=0;i<lists.size();i++){
            ListNode* temp = lists[i];
            
            while(temp!=NULL){
                nums.push_back(temp->val);
                temp = temp->next;
            }
            
        }
        
        sort(nums.begin(), nums.end());
        
        int j = 0;
        for(int i=0;i<lists.size();i++){
            ListNode* temp = lists[i];
            ListNode* prev;
            
            while(temp!=NULL){
                prev = temp;
                temp->val = nums[j++];
                temp = temp->next;
            }
            
            if(i+1<lists.size() && prev!=NULL) prev->next = lists[i+1];
            
        }
        
        
        
        for(int i=0;i<lists.size();i++){
            if(lists[i]!=NULL) return lists[i];
        }
        
        
        return NULL;
        
        
    }
};
