LinkedListNode<int> *reverseLinkedList(LinkedListNode<int> *head) 
{
    LinkedListNode<int> *curr = head;
    LinkedListNode<int> *prev = NULL;
    LinkedListNode<int> *next = NULL;

    while(curr != NULL){
          next = curr->next;
          curr->next = prev;
          prev = curr;
          curr = next;
    }

    return prev;
}