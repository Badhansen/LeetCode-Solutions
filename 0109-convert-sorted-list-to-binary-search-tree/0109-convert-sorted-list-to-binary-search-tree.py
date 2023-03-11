# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def sortedListToBST(self, head: Optional[ListNode]) -> Optional[TreeNode]:
        """
        ListNode* getMid(ListNode* head){
            ListNode* prev = NULL, *slow = head, *fast = head;
            while(fast && fast->next){
                prev = slow;
                slow = slow->next;
                fast = fast->next->next;
            }
            if(prev != NULL)
                prev->next = NULL;
            return slow;
        }
        TreeNode* go(ListNode* head){
            if(!head)
                return NULL;
            ListNode* mid = getMid(head); 
            TreeNode *root = new TreeNode(mid->val);
            if(mid == head)
                return root;
            root->left = go(head);
            root->right = go(mid->next);
            return root;
        }
        TreeNode* sortedListToBST(ListNode* head) {
            if(head == NULL)
                return NULL;
            return go(head);
        }
        """
        def getMid(head):
            prev, slow, fast = None, head, head
            while fast and fast.next:
                prev = slow
                slow = slow.next
                fast = fast.next.next
            if prev:
                prev.next = None
            return slow
        
        
        def create(head):
            if not head:
                return None
            mid = getMid(head)
            root = TreeNode(mid.val)
            if mid == head:
                return root
            root.left = create(head)
            root.right = create(mid.next)
            return root
        
        if not head:
            return None
        return create(head)
    