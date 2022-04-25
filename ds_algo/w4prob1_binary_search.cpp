#include <iostream>
#include <vector>

using namespace std;

int bin_search(vector<int> a, int k, int l, int r) {
	while (l<=r) {
		int mid = (l+r) / 2;
		if (a[mid] == k) return mid;
		if (a[mid] < k) l = mid + 1;
		if (a[mid] > k) r = mid - 1;
	}
	return -1;
}

int main() {
	int n, k;
	cin >> n;
	vector<int> a(n);
	for (int i=0; i<n; ++i) cin >> a[i];
	cin >> k;
	vector<int> b(k);
	for (int i=0; i<k; ++i) cin >> b[i];
		
	for (int i=0; i<k; ++i)
		cout << bin_search(a, b[i], 0, n-1) << " ";
}
