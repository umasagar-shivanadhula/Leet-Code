#include <queue>
#include <vector>
using namespace std;

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
    struct Compare {
        bool operator()(ListNode* a, ListNode* b) {
            return a->val > b->val;
        }
    };

    ListNode* mergeKLists(vector<ListNode*>& lists) {
        // Min-heap to store the node values
        priority_queue<ListNode*, vector<ListNode*>, Compare> minHeap;
        
        // Insert the first element from each list into the heap
        for (ListNode* list : lists) {
            if (list != nullptr) {
                minHeap.push(list);
            }
        }
        
        // Dummy node to simplify result list creation
        ListNode* dummy = new ListNode(0);
        ListNode* current = dummy;

        // Merge lists
        while (!minHeap.empty()) {
            // Get the smallest node from the heap
            ListNode* smallest = minHeap.top();
            minHeap.pop();
            
            // Append the smallest node to the merged list
            current->next = smallest;
            current = current->next;

            // If there is a next node in the same list, push it into the heap
            if (smallest->next != nullptr) {
                minHeap.push(smallest->next);
            }
        }

        return dummy->next;  // Return the next of the dummy node (the head of the merged list)
    }
};
