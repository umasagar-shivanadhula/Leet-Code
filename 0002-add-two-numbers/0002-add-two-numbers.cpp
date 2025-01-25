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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        // Initialize dummy head for result
        ListNode dummy(0);
        ListNode* current = &dummy; // Pointer for constructing output
        int carry = 0; // To handle sums greater than 9
        
        while (l1 != nullptr || l2 != nullptr || carry != 0) {
            int sum = carry; // Start with carrying over value
            
            if (l1 != nullptr) { // Add value from first number if available
                sum += l1->val;
                l1 = l1->next; // Move to next node
            }
            
            if (l2 != nullptr) { // Add value from second number if available
                sum += l2->val;
                l2 = l2->next; // Move to next node
            }

            current->next = new ListNode(sum % 10); // Create new node with digit 
            current = current->next;                  // Move current pointer ahead
            
            carry = sum / 10;                          // Update carry for future additions
        }
        
        return dummy.next;                            // Return head of constructed list excluding dummy head 
    }
};
