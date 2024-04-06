LinkedListNode<int> *cloneRandomList(LinkedListNode<int> *head)
{
     LinkedListNode<int> *clone = new LinkedListNode<int>(0);
     LinkedListNode<int> *temp1 = clone;
     LinkedListNode<int> *temp2  = head;

     while(temp2){
         temp1->next = new LinkedListNode<int>(temp2->data);
         temp1 = temp1->next;
         temp2 = temp2->next;
     } 

     temp1 = clone;
     temp1 = temp1->next;
      temp2 = head;

      while(temp2){
          temp1->random = temp2->random;
          temp1 = temp1->next;
         temp2 = temp2->next;
      }

      return clone->next;
      

}
