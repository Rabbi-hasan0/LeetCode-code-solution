
// Just provided solution in a function;

class Solution{
public:
  ListNode* removeElements(ListNode* head, int val) {
    if(!head) return head;
    ListNode *prev = nullptr, *curr = head;
    while(curr) {
      if(curr->val == val) {
        if(!prev) {
          head = curr->next;
        }else {
          prev->next = curr->next;
        }
      }else {
        prev = curr;
      }
      curr = curr->next;
    }
    return head;
  }
};
