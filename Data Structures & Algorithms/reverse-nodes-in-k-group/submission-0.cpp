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
    ListNode* reverseKGroup(ListNode* head, int k) {
        if (head == NULL) {
            return head;
        }

        ListNode* temp = head;
        int count = 0;
        while (temp != NULL && count < k) {
            temp = temp->next;
            count++;
        }
        if (count < k) {
            return head;
        }

        int i = 1;
        ListNode* prev = NULL;
        ListNode* cur = head;

        while (i <= k && cur != NULL) {
            ListNode* nxt = cur->next;
            cur->next = prev;
            prev = cur;
            cur = nxt;
            i++;
        }

        ListNode* headFromMyFriend = reverseKGroup(cur, k);
        head->next = headFromMyFriend;

        return prev;
    }
};