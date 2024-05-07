int maximumXor(vector<int> A)
{
      int maxi = INT_MIN;
      for(int i = 0;i < A.size();i++){
          for(int j = 0;j < A.size();j++){
               int curr = A[i] ^ A[j];
               if(curr > maxi)
                    maxi = curr;
          }
      }   
      if(maxi < 0)
          return 0;

      return maxi;
}