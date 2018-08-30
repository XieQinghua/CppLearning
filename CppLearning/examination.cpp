#include<iostream>
#include<string>
#include<algorithm>

using namespace std;

struct coefficient {
	int real;// Êµ²¿ 
	int ima;// Ðé²¿ 
};

coefficient coef_a[5], coef_b[5], coef_c[9];

int test002() {
	//coefficient temp{0,0,0};
	int real;
	int ima;
	int rank = 5;
	while (rank--) {
		cin >> real >> ima;
		coef_a[rank].real = real;
		coef_a[rank].ima = ima;
	}
	rank = 5;
	while (rank--) {
		cin >> real >> ima;
		coef_b[rank].real = real;
		coef_b[rank].ima = ima;
	}
	coefficient temp{ 0,0 };
	fill(coef_c, coef_c + 9, temp);
	for (int i = 0; i<5; i++) {
		for (int j = 0; j<5; j++) {
			coef_c[i + j].real += coef_a[i].real*coef_b[j].real - coef_a[i].ima*coef_b[j].ima;
			coef_c[i + j].ima += coef_a[i].real*coef_b[j].ima + coef_a[i].ima*coef_b[j].real;
		}
	}
	for (int i = 8; i >= 0; i--) {
		cout << coef_c[i].real << endl << coef_c[i].ima << endl;
	}
	cin.get();
	cin.get();
	return 0;
}