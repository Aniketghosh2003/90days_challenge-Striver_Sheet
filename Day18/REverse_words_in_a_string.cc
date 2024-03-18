#include<bits/stdc++.h>
string reverseString(string &str){
	// int n = str.length();
	// string ans = "";
	// int i =  0;

	// while(i < n){
    //     while( i < n && str[i] == ' '){
	// 		i++;
	// 	}
	// 	if(i >= n) break;
	// 	int j = i+1;
	// 	while(j < n && str[j] != ' ' ){
    //         j++;
	// 	}

	// 	string sub = str.substr(i,j-i);
	// 	if(ans.length() ==0 ) ans = sub;

	// 	else{
	// 		ans = sub +" " + ans ;
	// 	}

	// 	j = i+ 1;
    // return ans;


	string ans = "";
	string  temp = "";
	for(int i = 0;i < str.length();i++){
		char x = str[i];
         if(x != ' '){
              temp += x;
		 }
		 else if(x == ' '){
             if(ans == ""){
				 ans = temp;
             } else {
                   if(temp != ""){
					    ans = temp + " " + ans;
				   }
             }
             temp = "";
        }
        }
		if(temp != ""){
			ans = temp + " " + ans;
		}
		return ans;
}