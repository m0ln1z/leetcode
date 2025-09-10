class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if (!head || left == right) return head;

        ListNode dummy(0, head);
        ListNode* prev = &dummy;

        for (int i = 1; i < left; i++) {
            prev = prev->next;
        }

        ListNode* curr = prev->next;  
        ListNode* nextNode = nullptr;

        for (int i = 0; i < right - left; i++) {
            nextNode = curr->next;       
            curr->next = nextNode->next; 
            nextNode->next = prev->next; 
            prev->next = nextNode;       
        }

        return dummy.next;
    }
};