#include <bits/stdc++.h>

/****************************************************************

    Following is the class structure of the Node class:

        class Node
        {
        public:
	        int data;
	        Node *next;
	        Node(int data)
	        {
		        this->data = data;
		        this->next = NULL;
	        }
        };

*****************************************************************/

int getlen(Node* head){
	 int len  = 0;
     
	  Node* temp = head;

	 while(temp){
		 temp = temp->next;
		 len++;
	 }

	 return len;
}

Node* reverse(Node *head, int n, int b[],int i){
        int len = getlen(head);

		Node* curr = head, *prev = NULL, *next = NULL;

		while(b[i] == 0 && i <= n-1){
			i++;
		}

		if(head == NULL || i == n){
			return head;
		}

		int cnt = 0;

		while(curr != NULL && cnt < b[i] && i < n){
			next = curr->next;
			curr->next = prev;

			prev = curr;
			curr = next;
			cnt++;
		}

		if(next!= NULL){
			head->next = reverse(next,  n, b, ++i);
		}
	

		return prev;
}

Node *getListAfterReverseOperation(Node *head, int n, int b[]){
	

	return reverse(head,n,b,0);
}