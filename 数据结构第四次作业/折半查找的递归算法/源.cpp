#include <iostream>
using namespace std;


int find(int data[], int start, int end, int k) {
	if (start < end) {
		int mid = (start + end) / 2;
		if (data[mid] == k) {
			return mid;
		}
		else if (k < data[mid]) {
			return find(data, start, mid - 1, k);
		}
		else {
			return find(data, mid + 1, end, k);
		}
	}
	return -1;
}



int main() {
	int data[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
	cout << find(data, 0, 10, 3) << endl;
	cout << find(data, 0, 10, 10) << endl;
	cout << find(data, 0, 10, 1) << endl;
	cout << find(data, 0, 10, 11) << endl;
	return 0;
}
