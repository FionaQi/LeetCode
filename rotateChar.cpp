#include<iostream>
using namespace std;

void main()
{
	char src[] = "ABCD";
	//char *p = src;
	char *dp = new char(2*sizeof(src));
	for( int i = 0; i < sizeof(src) -1; ++i  )
	{
		dp[i] = src[i];
	}
	for( int i = 0; i < sizeof(src) -1; ++i  )
	{
		dp[i+sizeof(src)-1] = src[i];
	}
	cout<<dp<<endl;
	if( strstr(dp,"DAB") == 0 )
		puts("0");
	char str[] ="This is a simple string";
	char * pch;
	pch = strstr (str,"simple");  
	//Returns a pointer to the first occurrence of str2 in str1, or a null pointer if str2 is not part of str1.
	strncpy (pch,"sample",6);
	puts (str);
}