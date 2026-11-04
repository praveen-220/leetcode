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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* temp=head;
        int n2=0;
        while(temp!=NULL)
        {
            n2++;
            temp=temp->next;
        }
        int n1=n2-n-1;
        ListNode* temp1=head;
        if(n1==-1)
        {
            ListNode* del=head;
            head=head->next;
            delete del;
        }
        else{
        int i=0;

        while(i<(n1)&&temp1!=NULL)
        {
            temp1=temp1->next;
            i++;
        }
        ListNode* dele=temp1->next;
        if(temp1->next!=NULL){
        temp1->next=temp1->next->next;
        delete dele;
        }
        else{
            return NULL;
        }
        }
        return head;
    }
};