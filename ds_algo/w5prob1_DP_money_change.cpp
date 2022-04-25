#include <iostream>

#define MAXN 1000
using namespace std;

//n<=1000; denominations 1, 3, 4;
//return min number of bill
int DP_change(int n) {
	int a[MAXN];
	a[0] = 0;
	a[1] = 1;
	a[2] = 2;
	a[3] = 1;
	a[4] = 1;
	for (int i=5; i<=1000; ++i) {
		a[i] = min(a[i-1], min(a[i-3], a[i-4]))+ 1;
	}
	return a[n];
}

int main() {
	int n;
	cin >> n;
	cout << DP_change(n);
}
