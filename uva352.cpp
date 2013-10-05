#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

int dr[] = {1,1,0,-1,-1,-1, 0, 1};
int dc[] = {0,1,1, 1, 0,-1,-1,-1};
char grid[150][150];
int R,C;

int floodfill(int r, int c, char c1, char c2) {
    if (r < 0 || r >= R || c < 0 || c >= C) return 0;
    if (grid[r][c] != c1) return 0;
    int ans = 1;
    grid[r][c] = c2;
    for (int d = 0; d < 8; d++)
        ans += floodfill(r + dr[d], c + dc[d], c1, c2);
    return ans;
}

int main(){
   int cas=0;
   while(scanf("%d",&R)==1){
       scanf("\n");
       for(int i=0;i<R;i++) gets(grid[i]);
       C=strlen(grid[0]);
       int counts=0;
       for(int i=0;i<R;i++) for(int j=0;j<C;j++)
        if(grid[i][j]=='1') counts++,floodfill(i,j,'1','.');
       printf("Image number %d contains %d war eagles.\n",++cas,counts);
   }
   return 0;
}
