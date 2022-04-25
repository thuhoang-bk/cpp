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
	int n;  // n<=100
	
	//tim cac cap (i,j) co tong 100
	//vd n=4 1 2 98 100
	cin >> n;
	vector<int> a(n); // a[i] <= 1000
	for (int i=0; i<n; ++i)
		cin >> a[i];
		
	//sort < < <
	for (int i=0; i<n-1; ++i)
		for (int j=i+1; j<n; ++j)
			if (a[i]>a[j])
				swap(a[i], a[j]); 
	//find
	for (int i=0; i<n; ++i) {
		int key = a[i];
		int idx = bin_search(a, 100 - key, 0, n-1);
		if ((key<=100) && (idx!=-1))
			cout << i << " " << idx << endl;
	} 
}
