#include <bits/stdc++.h>

using namespace std;

// Complete the encryption function below.
void encryption(string s) {
	int l=s.length();
	int x=ceil(sqrt(l));
	int r=x;
	int c= x*(x-1)>=l?x-1:x;
	int m=0;
	for(int i=0;i<l;i++)
	{
		printf("%c",s[m]);
		m+=r;
		if(m>=l)
		{
			m=m%r;
			m++;
			printf(" ");
		}
	}

}

int main()
{
    string s;
    getline(cin, s);

    encryption(s);
    return 0;
}
