#include <bits/stdc++.h>
int rq,cq;
using namespace std;
 int main()
 {
 	int n,k,c_q,r_q;
	cin>>n>>k;
	cin>>c_q>>r_q;
	cq=c_q;
	rq=r_q;
	vector<int> row (n+2,0);
	//vector<vector<int>> grid;
	vector<vector<int>> grid (n+2, row);
	/*for(int i=0;i<n;i++)
	{
		grid.push_back(row);
		printf("pushed %d\n",i);
	}*/
	int dis_dir[]={0,0,0,0,0,0,0,0};

	for(int i=0; i<k; i++)
	{
		int r,c;
		cin>>c>>r;
		//printf("%d %d\n",c,r);
		grid[c][r]=1;
	}
	//printf("Data taken\n");
	int dc[8]={-1,-1,0,+1,+1,+1,0,-1};
	int dr[8]={0,+1,+1,+1,0,-1,-1,-1};
	int sum=0;
	for(int i=0; i<8;i++)
	{
		int mc=cq;
		int mr=rq;
		while(true)
		{
			mc+=dc[i];
			mr+=dr[i];
			if(mc==0 || mr==0 || mc==n+1 || mr==n+1)
				break;
			if(grid[mc][mr]==1)
				break;
			dis_dir[i]++;
		}
		sum+=dis_dir[i];
		//printf("dis_dir %d = %d\n",i,dis_dir[i] );
	}
	printf(%d \n",sum);

 }