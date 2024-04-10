/**
 * Definition for singly-linked list.
 * class Node {
 * public:
 *     int data;
 *     Node *next;
 *     Node() : data(0), next(nullptr) {}
 *     Node(int x) : data(x), next(nullptr) {}
 *     Node(int x, Node *next) : data(x), next(next) {}
 * };
 */

Node *rotate(Node *head, int k) {
     if(head == NULL || k == 0){
          return head;
     }

     Node* temp = head;
     Node* curr = head;
     Node* head1 = NULL;
     int len = 1;

     while(temp->next != NULL){
         temp = temp->next;
         len++;
     }
    
    k = k%len;
    int n = len - k - 1;
    if(k % len == 0) return head;

    for(int i = 0;i < n;i++){
        curr = curr->next;
    }
    
    head1 = curr->next;
    curr->next = NULL;
    temp->next = head;
    
    return head1;
}