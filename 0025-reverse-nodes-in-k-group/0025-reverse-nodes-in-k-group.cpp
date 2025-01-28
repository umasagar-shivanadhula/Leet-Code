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
        // Helper to reverse the linked list in a range
        auto reverse = [](ListNode* start, ListNode* end) -> ListNode* {
            ListNode *prev = nullptr, *curr = start, *next = nullptr;
            while (curr != end) {
                next = curr->next;
                curr->next = prev;
                prev = curr;
                curr = next;
            }
            return prev;
        };

        // Dummy node for easy handling of the head
        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        ListNode* groupPrev = dummy;

        while (true) {
            // Find the kth node in the group
            ListNode* kth = groupPrev;
            for (int i = 0; i < k && kth; ++i) {
                kth = kth->next;
            }
            if (!kth) break; // If less than k nodes are left, stop

            // Mark the next group's starting node
            ListNode* groupNext = kth->next;

            // Reverse the current k-group
            ListNode* groupStart = groupPrev->next;
            ListNode* groupEnd = kth->next;

            reverse(groupStart, groupEnd);

            // Reconnect the reversed group with the rest of the list
            groupPrev->next = kth;
            groupStart->next = groupNext;

            // Move groupPrev to the end of the reversed group
            groupPrev = groupStart;
        }

        return dummy->next;
    }
};
