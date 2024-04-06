LinkedListNode<int>* reverse(LinkedListNode<int>* head){

    LinkedListNode<int>* curr = head;

    LinkedListNode<int>* prev = NULL;

    LinkedListNode<int>* next = NULL;


    while(curr != NULL){

        next = curr -> next;

        curr -> next = prev;

        prev = curr;

        curr = next;

    }

 

    return prev;

}

 

LinkedListNode<int>* mid(LinkedListNode<int>* head){

    LinkedListNode<int>* slow = head;

    LinkedListNode<int>* fast = head->next;

    while (fast != NULL && fast->next != NULL) {

        fast = fast->next->next;

        slow = slow->next;
    }

    return slow;
}

bool isPalindrome(LinkedListNode<int> *head) {


    if(head==NULL || head->next==NULL){

        return true;

    }

    LinkedListNode<int>* middle = mid(head);

 

    LinkedListNode<int>* temp = middle -> next;

    middle -> next = reverse(temp);

    

    LinkedListNode<int>* head1 = head;

    LinkedListNode<int>* head2 = middle->next;

 

    while(head2!=NULL){

        if(head1->data != head2->data){

            return false;

        }

        head1 = head1 -> next;

        head2 = head2 -> next;

    }

 

    return true;

}