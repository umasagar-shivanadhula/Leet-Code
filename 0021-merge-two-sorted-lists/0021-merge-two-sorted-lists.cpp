/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode* next) : val(x), next(next) {}
 * };
 */

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        // Create a dummy node
        ListNode dummy(0);
        // Pointer for constructing new list
        ListNode* current = &dummy;

        // While either l1 or l2 has nodes left
        while (l1 != nullptr && l2 != nullptr) {
            if (l1->val < l2->val) {
                current->next = l1;    // Link current node with l1's node
                l1 = l1->next;         // Advance in lst 1 
            } else {
                current->next = l2;    // Link current with lst 2's node
                l2 = l2->next;         // Advance in lst 2 
            }
            current = current->next;    // Move forwards on newly appended Sorting Queue!
        }

        // Attach whichever remains from either lst  after exiting loop above!
        if (l1 != nullptr)
            current->next = l1;
        
        if (l2 != nullptr)
            current->next = l2;

        
       return dummy.next;             // Return resulting head right after Dummy Node! 
    }
};
