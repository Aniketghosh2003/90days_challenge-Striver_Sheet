#include <bits/stdc++.h> 
int countdays(vector<int> &time,int sec){
     int days = 1;
	 int secperdays = 0;
	 for(int i  =0; i < time.size();i++){
		 if(secperdays + time[i] <= sec){
			 secperdays += time[i];
		 }
		 else{
			 days++;
			 secperdays = time[i];
		 }
	 }
	 return days;
}

long long ayushGivesNinjatest(int n, int m, vector<int> time) 
{	
    long long low = *max_element(time.begin(),time.end());
	long long high = accumulate(time.begin(),time.end(),0);
	while(low <= high){
		long long mid  = low + (high - low) / 2;
		int days = countdays(time, mid);
		if(days  > n){
           low = mid + 1;
		}
		else{
			high = mid - 1;
		}
	}
    return low;
}