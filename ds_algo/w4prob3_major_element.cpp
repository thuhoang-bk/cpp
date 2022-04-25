#include <iostream>
#include <vector>

#define MAXN 100001

using namespace std;

void merge(int a[], int l, int mid, int r) {
	int l1 = mid - l + 1, l2 = r - mid;
	vector<int> b(l1), c(l2);
	for (int i=0; i<l1; ++i) b[i] = a[l+i];
	for (int i=0; i<l2; ++i) c[i] = a[mid+1+i];
	int cs1=0, cs2=0, count=0;
	while ((cs1<l1) && (cs2<l2)) {
		if (b[cs1] < c[cs2]) {
			a[l+count] = b[cs1];
			++cs1;
		}
		else {
			a[l+count] = c[cs2];
			++cs2;
		}
		++count;
	}
	while (cs1<l1) {
		a[l+count] = b[cs1];
		++cs1;
		++count;
	}
	while (cs2<l2) {
		a[l+count] = c[cs2];
		++cs2;
		++count;
	}
}

void merge_sort(int a[], int l, int r) {
	if (l >= r) return;
	int mid = (l + r) / 2;
	merge_sort(a, l, mid);
	merge_sort(a, mid+1, r);
	merge(a, l, mid, r);
}

int check_major(int n, int a[]) {
	a[n+1] = -1;
	int i=0;
	while (i<n) {
		int count = 1;
		while (a[i] == a[i+1]) {
			++i;
			++count;
		}
		if (count > n/2) return 1;
		++i;
	}
	return 0;
}

int main() {
	int n;
	int a[MAXN];
	cin >> n;
	for (int i=0; i<n; ++i) cin >> a[i];
	merge_sort(a, 0, n-1);
	cout << check_major(n, a);
}
