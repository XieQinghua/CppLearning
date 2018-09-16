/*
**@author:jason.lee
**@date:2018-8-19
*/

#include<iostream>
#include<string>
#include<algorithm>
#include<map>
#include"util.h"
#include"test.h"

using namespace std;

int main() {
	test_vector();
	cin.get();

	return 0;
}
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

//Util u;

