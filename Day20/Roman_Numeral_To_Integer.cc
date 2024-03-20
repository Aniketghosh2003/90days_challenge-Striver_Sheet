int val(char ch){
     if(ch=='I'){

        return 1;

    }else if(ch=='V'){

        return 5;

    }else if(ch=='X'){

        return 10;

    }else if(ch=='L'){

        return 50;

    }else if(ch=='C'){

        return 100;

    }else if(ch=='D'){

        return 500;

    }else if(ch=='M'){

        return 1000;

    }   
}

int romanToInt(string s) {
    int ans = 0;
    int n = s.length();
    int prev  = 0;
    int curr = 0;
    for(int i =1;i < n;i++){
         prev = val(s[i-1]);
         curr = val(s[i]);

         if(prev < curr){
             ans -= prev;
         }else{
             ans += prev;
         }
    }


    ans += val(s[n-1]);
    return ans;
}