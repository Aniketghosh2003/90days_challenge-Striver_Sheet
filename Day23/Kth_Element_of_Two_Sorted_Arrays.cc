int ninjaAndLadoos(vector<int> &row1, vector<int> &row2, int m, int n, int k) {
    int i = 0;
    int j = 0;
    int l = 1;
    while(  i < m && j  < n){
        if(row1[i] > row2[j]){
            if(l == k) return row2[j];
            j++;
        } else {
            if(l == k) return row1[i];
            i++;
        }
        l++;
    }
    
    while(i < m){
         if(l == k) return row1[i];
        i++;
        l++;
    }
    while(j < n){
        if(l == k) return row2[j];
        j++;
        l++;
    }
       
}