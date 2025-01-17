class Solution {
  public:
    Node* linkdelete(Node* head, int n, int m) {
        Node* temp = head;
        
        while (temp != NULL) {
            for (int i=1; i<m && temp != NULL; i++) {
                temp = temp->next;
            }
            
            if (temp == NULL) {
                return head;
            }
            
            Node* t = temp->next;
            for (int i=1; i<=n && t != NULL; i++) {
                t = t->next;
            }
            
            temp->next = t;
            temp = t;
        }
        
        return head;
    }
};
