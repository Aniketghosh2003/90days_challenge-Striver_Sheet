#include <bits/stdc++.h> 
/*
	This is signature of helper function 'knows'.
	You should not implement it, or speculate about its implementation.

	bool knows(int A, int B); 
	Function 'knows(A, B)' will returns "true" if the person having
	id 'A' know the person having id 'B' in the party, "false" otherwise.
*/

int findCelebrity(int n) {
	stack<int> s;
	for(int i =0 ;i<n;i++){
		s.push(i);
	}

	while(s.size() > 1){
		int a = s.top();
		s.pop();
		int b = s.top();
		s.pop();

		if(knows(a,b) == true){
			s.push(b);
		}
		else{
			s.push(a);
		}
	}

	int candidate = s.top();

	bool rowcheck = false;
	int kcnt = 0;
	for(int i = 0;i<n;i++){
        if(knows(candidate,i) == false)  kcnt++;
	}

	if(kcnt == n) rowcheck = true;

    bool colcheck = false;
	kcnt = 0;
	for(int i = 0;i<n;i++){
        if(knows(i,candidate) == true)  kcnt++;
	}

	if(kcnt == n-1) colcheck = true;
	if(rowcheck && colcheck) return candidate;
	else return -1;
}