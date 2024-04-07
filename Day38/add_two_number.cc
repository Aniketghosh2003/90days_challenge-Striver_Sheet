void insertattail(Node* &head,Node*&tail,int val){
    Node* ans = new Node(val);

    if(head == NULL){
        head = ans;
        tail = ans;
        return;
    }
    else{
        tail->next = ans;
        tail = ans;
    }
}

Node* add(Node *num1, Node *num2){
    int carry = 0;

    Node *anshead = NULL;
    Node* anstail = NULL;

    while(num1 != NULL || num2 != NULL || carry != 0){
           
           int v1 = 0;
           if(num1 != NULL)
              v1 = num1 ->data;

            int v2 = 0;
            if(num2 !=NULL ){
                v2 = num2->data;
            }  

            int sum = v1+v2+carry;

            int digit = sum%10;

            insertattail(anshead,anstail,digit);

           carry = sum/10;
           if(num1 != NULL){
               num1 = num1->next;
           }
           if(num2 != NULL){
             num2 = num2->next;
           }
    }
    return anshead;
}
Node *addTwoNumbers(Node *num1, Node *num2)
{

    Node* ans = add(num1,num2);
    return ans;

}