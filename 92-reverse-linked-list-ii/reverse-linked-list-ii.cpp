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
    ListNode* reversebet(ListNode* rhead, int n)
    {
        ListNode* prev = NULL;
        ListNode* curr = rhead;

        while(curr != NULL && n--)
        {
            ListNode* nextnode = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nextnode;
        }

        rhead->next = curr;
        return prev;
    }

    ListNode* reverseBetween(ListNode* head, int left, int right) {

        if(left == right) return head;

        ListNode* temp = head;
        ListNode* before = NULL;
        int i = 1;

        while(i < left)
        {
            before = temp;
            temp = temp->next;
            i++;
        }

        ListNode* rhead = temp;

        ListNode* newhead = reversebet(rhead, right-left+1);

        if(before != NULL)
            before->next = newhead;
        else
            head = newhead;

        return head;
    }
};
