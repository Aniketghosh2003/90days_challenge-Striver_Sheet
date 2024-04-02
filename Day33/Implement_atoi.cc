long atoi(string s,int sign,int i , long ans){

    if(sign*ans >= INT_MAX){
        return INT_MAX;
    }
    if(sign*ans <= INT_MIN){
        return INT_MIN;
    }

    if(i >= s.size()|| s[i] < '0' || s[i] > '9'){
        return sign*ans;
    }
     
     ans =  atoi(s, sign, i+1,(ans*10+(s[i] - '0')));
    return ans;
}

int createAtoi(string s) {
     int i = 0;
     int sign = 1;
     int n = s.size();

     while(i < n && s[i] == ' '){
         ++i;
     }

     if(s[i] == '-'){
         sign = -1,++i;
     }
     else if(s[i] == '+'){
        ++i;
     }

     return atoi(s,sign,i,0);
}