string longestPalinSubstring(string str) {
    int cnt = 1;
    int s = 0,e = 0;

    for(int i = 0;i < str.length() - 1;i++){
        int l = i,r = i;
        while(l >= 0 && r < str.length() ){
                 if(str[l] == str[r]){
                    l--; r++;
                 }
                 else{
                     break;
                 }
        }
        int len = r- l - 1;
        if(len > cnt){
            cnt = len;
            s = l+1;
            e = r - 1;
        }
        
    }

    for(int i = 0;i < str.length() - 1;i++){
        int l = i,r = i+1;
        while(l >= 0 && r < str.length() ){
                 if(str[l] == str[r]){
                    l--; r++;
                 }
                 else{
                     break;
                 }
        }
        int len = r- l - 1;
        if(len > cnt){
            cnt = len;
            s = l+1;
            e = r - 1;
        }
        
    }

    return str.substr(s,cnt);

}