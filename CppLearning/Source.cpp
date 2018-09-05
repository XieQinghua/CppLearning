/*
**@author:jason.lee
**@date:2018-8-19
*/

#include<iostream>
#include<string>
#include<algorithm>
#include"util.h"
#include"test.h"

using namespace std;
//
//int main(int agc,char** args) {
//	test_scanf_format();
//	/*for (int i = 0; i < agc; i++) {
//		cout << args[i] << endl;
//	}*/
//	cin.get();
//	return 0;
//}
//
//#include<iostream>
//
//using namespace std;
//int function2(int a[], int b, int e)
//{
//	if (e - b <= 1) return abs(a[b] - a[e]) >= 3 ? a[b] : a[e];
//	int l = 0, r = 0;
//	l = function2(a, b, b + (e - b) / 2);
//	if (l % 2 == 0)
//		r = function2(a, b + (e - b) / 2 + 1, e);
//	else
//		return l;
//	if (l | r)
//		return l | r;
//	else
//		return r;
//}
//
//int main()
//{
//	int a[] = { 10,5,8,4,5,20,2,3 };
//	cout << function2(a, 0, sizeof(a) / sizeof(1)) << endl;
//	int b[] = { 3,5,8,4,8,30,2,3 };
//	cout << function2(b, 0, sizeof(b) / sizeof(1)) << endl;
//	return 0;
//}

//int main()
//{
//	int
//		a[4][4] = { { 1,2,3.1,4 },{ 5,6,7,8 },{ 11,12,13,14 },{ 15,16,17,18 } };
//	int
//		i = 0, j = 0, s = 0;
//
//	while (i++<4)
//	{
//
//		if (i == 2 || i == 4) continue;
//
//		j = 0;
//
//		do { s += a[i][j]; j++; } while (j<4);
//	}
//
//	printf("%d\n", s);
//	cin.get();
//}

//#include<iostream>
//using namespace std;
//int main()
//{
//	char c[2][5] = { "6938" , "8254" }, *p[2];
//	int s = 0;
//	for (int i = 0; i < 2; i++)
//		p[i] = c[i];
//	for (int i = 0, j = 0; i <4; i++, j += 2)
//	{
//		if (j>3)
//		{
//			j = 0;
//		}
//		s = 10 * s + (p[i / 2][j] - '0');
//	}
//	cout << s << endl;
//	cin.get();
//	return 0;
//}

int main() {

	int a = 1;
	int b = 100;
	int c = 1;
	c = (a++, b++);
	printf("%d",c);

	cin.get();

	return 0;
}