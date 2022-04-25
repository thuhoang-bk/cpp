#include <iostream>
#include <vector>

using namespace std;

// +1 x2 x3
int min_op(int n) {
	vector<int> a(n+1);
	a[0] = 0;
	a[1] = 0;
	for (int i=2; i<=n; ++i)
		if (i%2==0 && i%3==0)
			a[i] = min(a[i-1], min(a[i/2], a[i/3])) + 1;
		else if (i%2==0)
			a[i] = min(a[i-1], a[i/2]) + 1;
		else if (i%3==0)
			a[i] = min(a[i-1], a[i/3]) + 1;
		else a[i] = a[i-1] + 1;
	return a[n];
}

int main() {
	int n;
	cin >> n;
	cout << min_op(n);
}
