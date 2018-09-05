////#include<stdio.h>
////#include<stdlib.h>
////
////int main() {
////	char *str = "123";
////	char a[10];
////	printf("%c%c%c\n", a[0],a[1],a[2]);
////	getchar();
////	return 0;
////}
//
//
//#include<stdio.h>
//#define N 4
//void fun(int a[][N], int *p)
//{
//	int i;
//	for (i = 0; i<N; i++) {
//		if (i<3) p[i] += a[i][i] - a[i][N - i - 2];
//		else p[i] += a[i][i] - a[i][N - i];
//	}
//}
//main()
//{
//	int x[N][N] = { { 3,6,2,0 },{ 2,8,7,9 },{ 5,1,7,3 },{ 9,5,3,7 } }, y[N] = { 3,5,8,6 }, i;
//	fun(x, y);
//	for (i = 0; i<N; i++)
//		printf("%d ", y[i]);
//	printf("\n");
//	getchar();
//}

//#include <stdio.h>
//int fun(int x)
//{
//	int p;
//	if (x == 0 || x == 1)
//		return(3);
//	p = x - fun(x - 2);
//	return(p);
//}
//
//void	main() {
//		printf("%d\n", fun(9));
//		getchar();
//	}