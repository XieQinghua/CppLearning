#include<iostream>

using namespace std;

int sort(int*a, int low, int high) {
	int key = a[low];
	while (low < high) {
		while (low < high&&key <= a[high]) {
			high--;
		}
		a[low] = a[high];
		while (low < high&&key >= a[low]) {
			low++;
		}
		a[high] = a[low];
	}
	a[low] = key;
	return low;
}
void quick_sort(int*a, int low, int high) {
	if (low >= high) {
		return;
	}
	int part = sort(a, low, high);
	quick_sort(a, low, part - 1);
	quick_sort(a, part + 1, high);
}

int main() {
	int a[] = { 12,45,78,97,65,46,456,147,135,648,31,1,22 };
	int length = sizeof(a) / sizeof(int);
	quick_sort(a, 0, length - 1);
	for (int i = 0; i < length; i++) {
		cout << a[i] << " ";
	}
	cin.get();
	return 0;
}