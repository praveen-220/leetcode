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
    bool isPalindrome(ListNode* head) {
        vector<int> num;

        while (head != NULL) {
            num.push_back(head->val);
            head = head->next;
        }

        int left = 0;
        int right = num.size() - 1;

        while (left < right) {
            if (num[left] != num[right]) {
                return false;
            }

            left++;
            right--;
        }

        return true;
    }
};