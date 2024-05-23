int calculateMinPatforms(int at[], int dt[], int n) {
    int pat = 1,maxi = 1;

    int i = 1,j = 0;
    sort(at,at+n);
    sort(dt,dt+n);

    while(i < n && j < n){
        if(at[i] <= dt[j]){
            pat ++;
            i++;
        }
        else if(at[i] > dt[j]){
            pat--;
            j++;
        }

        maxi = max(maxi,pat);
    }
    return maxi;
}