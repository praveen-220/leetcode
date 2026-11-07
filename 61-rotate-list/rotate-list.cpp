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
    ListNode* operations(ListNode* head) {
        if(head == NULL || head->next == NULL)
            return head;

        ListNode* temp = head;

        while(temp->next->next != NULL) {
            temp = temp->next;
        }

        ListNode* newnode = temp->next;
        temp->next = NULL;
        newnode->next = head;

        return newnode;
    }

    ListNode* rotateRight(ListNode* head, int k) {
        if(head == NULL || head->next == NULL)
            return head;

        int len = 0;
        ListNode* temp = head;

        while(temp != NULL) {
            len++;
            temp = temp->next;
        }

        k = k % len;

        for(int i = 0; i < k; i++) {
            head = operations(head);
        }

        return head;
    }
};