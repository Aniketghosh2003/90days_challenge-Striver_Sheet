void solve(vector<vector<int>> &image, int i, int j, int newColor,int oldcol,int n ,int m){
       if(i < 0 || j < 0 || i == n || j == m || image[i][j] != oldcol) return ;

       image[i][j] = newColor;
       solve(image,i+1,j,newColor,oldcol,n,m);
       solve(image,i,j-1,newColor,oldcol,n,m);
       solve(image,i-1,j,newColor,oldcol,n,m);
       solve(image,i,j+1,newColor,oldcol,n,m);


}

vector<vector<int>> floodFill(vector<vector<int>> &image, int x, int y, int newColor)
{
    int oldcol = image[x][y];
    if(oldcol == newColor) return image;

    int n = image.size();
    int m = image[0].size();

     solve(image,x,y,newColor,oldcol,n,m);
     return image;
    }