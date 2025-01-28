# Definition for singly-linked list.
class ListNode(object):
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next

class Solution(object):
    def swapPairs(self, head):
        """
        :type head: Optional[ListNode]
        :rtype: Optional[ListNode]
        """
        # Create a dummy node to simplify edge case handling
        dummy = ListNode(0)
        dummy.next = head
        prev_node = dummy
        
        while head and head.next:
            # Identify the two nodes to swap
            first_node = head
            second_node = head.next
            
            # Swap the nodes by adjusting the pointers
            prev_node.next = second_node
            first_node.next = second_node.next
            second_node.next = first_node
            
            # Move the pointers two steps forward
            prev_node = first_node
            head = first_node.next
            
        return dummy.next
