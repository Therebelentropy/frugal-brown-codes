#include <bits/stdc++.h>

using namespace std;
int main()
{
	int n,k;
	cin>>n>>k;
	int modulus[k];
	for(int i=0;i<k;i++)
	{
		modulus[i]=0;
	}
	for(int i=0;i<n;i++)
	{
		int temp;
		cin>>temp;
		temp=temp%k;
		modulus[temp]++;
	}
	int sum=0;
	for(int i=0;i<=k/2;i++)
	{
		if(i==0)
		{
			if(modulus[i]>0)
			{
				sum++;
			}
			continue;
		}
		if(k%2==0 && i==k/2)
			if(modulus[i]>0)
			{
				sum++;
				continue;
			}
		sum+=max(modulus[i],modulus[k-i]);
	}
	printf("%d",sum);
	return 0;
}