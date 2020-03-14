#include <bits/stdc++.h>

using namespace std;
long int dist(long int c,long int r);
long int getDir(long int dc ,long int dr);

long int cq,rq;

int main()
{
	long int n,k,c_q,r_q;
	cin>>n>>k;
	cin>>c_q>>r_q;
	cq=c_q;
	rq=r_q;
	long int D[8][2];
	D[0][0]=0;
	D[0][1]=rq;
	D[4][0]=n+1;
	D[4][1]=rq;
	D[2][0]=cq;
	D[2][1]=n+1;
	D[6][0]=cq;
	D[6][1]=0;
	long int a = cq-1;
	long int b =	n-rq;
	long int c = n -cq;
	long int d = rq-1;
	if(a<b)
	{
		D[1][0]=0;
		D[1][1]=rq+a+1;
	}
	else
	{
		D[1][0]=cq-b-1;
		D[1][1]=n+1;
	}
	if(b<c)
	{
		D[3][0]=cq+b+1;
		D[3][1]=n+1;
	}
	else
	{
		D[3][0]=n+1;
		D[3][1]=rq+c+1;
	}
	if(c<d)
	{
		D[5][0]=n+1;
		D[5][1]=rq-c-1;
	}
	else
	{
		D[5][0]=cq+d+1;
		D[5][1]=0;
	}
	if(d<a)
	{
		D[7][0]=cq-d-1;
		D[7][1]=0;
	}
	else
	{
		D[7][0]=0;
		D[7][1]=rq-a-1;
	}

	for (long int i=0;i<k;i++)
	{
		long int c,r;
		cin>>c>>r;
		long int dc=c-c_q;
		long int dr=r-r_q;
		long int dir = getDir(dc,dr);
		if (dir<0)
			continue;
		else 
		{
			D[dir][0]=(dist(c,r)<dist(D[dir][0],D[dir][1]))?c:D[dir][0];
			D[dir][1]=(dist(c,r)<dist(D[dir][0],D[dir][1]))?r:D[dir][1];
		}
	}
	long int dis=0;
	for (long int i=0;i<8;i++)
	{
		dis=dis+dist(D[i][0],D[i][1]);
	}
	printf("%ld",dis);
}

long int getDir(long int dc,long int dr)
{
	if(abs(dc)!=abs(dr) && abs(dc*dr)!=0)
		return -1; //Invalid
	if(dc<0 && dc==dr)
		return 7;
	if(dc>0 && dc==dr)
		return 3;
	if(dc<0 && dr>0)
		return 1;
	if(dc>0 && dr<0)
		return 5;
	if(dc==0 && dr>0)
		return 2;
	if(dc==0 && dr<0)
		return 6;
	if(dr==0 && dc>0)
		return 4;
	if(dr==0 && dc<0)
		return 0;
	return -100;

}

long int dist(long int c,long int r)
{
	return max(abs(c-cq), abs(r-rq))-1; //Actual number of available steps}
}