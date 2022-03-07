class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* head;
        ListNode* sorted;
        //if any list is empty then return the other list as a resulrt
        if(list1==NULL)
            return list2;
        if(list2==NULL)
            return list1;
        // find the first element which is smaller
        if(list1->val<list2->val){
            sorted=list1;
            list1=list1->next;
        }
        else{
            sorted=list2;
            list2=list2->next;
        }
        
        head=sorted;
        while(list1 && list2){
            if(list1->val<list2->val){
                sorted->next=list1;
                list1=list1->next;
                sorted=sorted->next;
            }
            else if(list1->val>list2->val){
                sorted->next=list2;
                list2=list2->next;
                sorted=sorted->next;
            }
            else{
                sorted->next=list1;
                list1=list1->next;
                sorted=sorted->next;
                sorted->next=list2;
                sorted=sorted->next;
                list2=list2->next;
                
            }
        }
        
        if(list1==NULL)
            sorted->next=list2;
        else
            sorted->next=list1;
        
        return head;
        
    }
};