#include <bits/stdc++.h> 
// Implement class for minStack.
class minStack
{
	stack<long long> st;
	int mini;
	
	public:
		
		// Constructor
		minStack() 
		{ 
			mini = INT_MAX;
		}
		
		// Function to add another element equal to num at the top of stack.
		void push(int num)
		{
		     if(st.empty()){
				 mini = num;
				 st.push(num);
			 }
			 else{
				 if(mini > num){
					 st.push(2*num - mini);
					 mini = num;
				 }
				 else{
					 st.push(num);
				 }
			 }
		}
		
		// Function to remove the top element of the stack.
		int pop()
		{
			if(st.empty()){
                return -1;
			}

			int curr = st.top();
			st.pop();

			if(mini > curr){
					int prev = mini;
					mini = 2*mini - curr;
					return prev;

				}
				else{
					return curr;
				}
		}
		
		// Function to return the top element of stack if it is present. Otherwise return -1.
		int top()
		{
			if(st.empty()){
                return -1;
			}
            int curr = st.top();
			if(mini > curr){
					return mini;
				}
				else{
					return curr;
				}
		}
		
		// Function to return minimum element of stack if it is present. Otherwise return -1.
		int getMin()
		{
			if(st.empty()){
				return -1;
			}
			return mini;
		}
};