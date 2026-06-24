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
    ListNode* reverseEvenLengthGroups(ListNode* head) {
        ListNode dummy(0);
        dummy.next = head;
        ListNode* prevGroupEnd = &dummy;
        ListNode* curr = head;
        int groupSize = 1;
        while (curr) {
            // Find actual length of current group
            ListNode* temp = curr;
            int len = 0;
            while (temp && len < groupSize) {
                temp = temp->next;
                len++;
            }
            ListNode* nextGroupStart = temp;

            if (len % 2 == 0) {
                // Reverse current group
                ListNode* prev = nextGroupStart;
                ListNode* node = curr;

                for (int i = 0; i < len; i++) {
                    ListNode* nxt = node->next;
                    node->next = prev;
                    prev = node;
                    node = nxt;
                }

                prevGroupEnd->next = prev;
                prevGroupEnd = curr;
                curr = nextGroupStart;
            } else {
                // Skip current group
                for (int i = 0; i < len; i++) {
                    prevGroupEnd = curr;
                    curr = curr->next;
                }
            }
            groupSize++;
        }
        return dummy.next;
    }
};
