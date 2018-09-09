#include <iostream>
#include <cassert>
#include <stack>
#include <math.h>
#include<algorithm>
 
using namespace std ;
 
bool cmp(int a,int b){
	return a<b;
}
 float EvaluateMedian(int a[], int n)
{
	sort(a,a+n,cmp);
 
	if(n % 2 !=0)
	{
		return a[n / 2];
	}
	else
	{
		return ((float)a[n / 2] + a[n / 2 - 1]) / 2;
	}
}
 
int main()
{
	int num ;
	cin>>num;
	int a[101];  
	for(int i=0;i<num;i++){
		cin>>a[i];
	}
    float test=EvaluateMedian(a, num);
    cout<<test<<endl;
        
	return 0;
}

