bool checkpalindrome(string str){
	int n = str.length();
	int i = 0;
	int  j = n-1;

	while(i  <= j){
          if (str[i] != str[j]) {
            return false;
          }
          i++;
          j--;
        }
		return true;
}

int minCharsforPalindrome(string str) {
	int add = 0;
	int n = str.length();
	while(n > 0){
        if(checkpalindrome(str.substr(0,n-add))){
			break;
		}
		else{
			add++;
		}
	}
	return add;
}
