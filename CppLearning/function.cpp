/*
**@Brief: Quick Sort Algorithm.
**@param:int *a - input array of intarge.
**@param:int low/high - the doundary of array.
*/
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