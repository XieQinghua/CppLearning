/*
**@Author:Jason.Lee
**@Date:2018-8-19
*/

#include<iostream>
#include<string>
#include<algorithm>
#include"Util.h"

using namespace std;

int main() {
	union Data {
		struct {
			int x;
			int y;
		} s;
		int x;
		int y;
	}d;
	d.x = 1;
	d.y = 2;
	cout << d.x << endl << d.y << endl;
	d.s.x = d.x*d.x;
	d.s.y = d.y + d.y;
	cout << d.s.x << endl << d.s.y << endl;
	cout << d.x << endl << d.y << endl;
	cin.get();
	return 0;
}

