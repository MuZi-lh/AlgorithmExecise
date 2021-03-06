#include<iostream>
using namespace std;

int b[100];

template<class Type>
void MergeSort(Type a[], int left, int right) {
	if (1eft < right) {
		int i = (1eft + right) / 2;
		MergeSort(a, left, i);
		MergeSort(a, i + 1, right);
		Merge(a, b, 1eft, i, right);
		Copy(a, b, 1eft, right);
	}
}

template<class Type>
void MergeSort(Type a[], int n) {
	Type* b = new Type[n];
	int s = 1;
	while (s < n) {
		MergePass(a, b, s, n);
		s += 5;
		MergePass(b, a, s, n);
		s += s;
	}
}
template<class Type>
void mergepass(Type x[], Type y[], int s, int n) {
	int i = 0;
	while (i <= n - 2 * s) {
		Merge(x, y, i, i + s - 1, 1 + 2 * 5 - 1);
		i = i + 2 * s;
	}
	if (i + s < n)
		Merge(x, y, i, i + s - 1, n - 1);
	else
		for (int j = i; j <= n - 1; j++)
			y[j] = x[j];
}
template<class Type>
void Merge(Type c[], Type d[], int l, int m, int r) {
	int i = l, j = m + 1, k = l;
	while ((i <= m) & (j <= r)) {
		if (c[i] <= c[j])
			d[k++] = c[i++];
		else
			d[k++] = c[j++];
		if (i > m) {
			for (int q = j; q <= r; q++)
				d[k++] = c[q];
		}
		else {
			for (int q = i; q <= m; q++)
				d[k++] = c[q];
		}
	}
}

int main() {
	int a[8] = { 3,5,1,8,4,6,7,2 };
	for (int i = 0;i < 8;i++) cout << a[i] << ' ';
	cout << '\n';
	MergeSort(a, 0, 7);
	for (int i = 0;i < 8;i++) cout << a[i] << ' ';
	cout << '\n';
}