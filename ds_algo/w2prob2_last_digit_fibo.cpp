#include <iostream>

using namespace std;

int last_digit(int n) {
	if (n <= 1) return n;
	int fn, fn1, fn2;
	fn2=0;
	fn1=1;
	for (int i=2; i<=n; ++i) {
		fn = (fn1 + fn2) % 10; 
		fn2 = fn1;
		fn1 = fn;
	}
	return fn;
}

int main() {
	int n;
	cin >> n;
	cout << last_digit(n);
}
