#include <iostream>

using namespace std;

int GCD(int a, int b) {
	int r;
	while (b != 0) {
		r = a % b;
		a = b;
		b = r;
	}
	return a;
}

long long LCM(int a, int b) {
	return ((long long) a) * b / GCD(a, b);
}

int main() {
	int a, b;
	cin >> a >> b;
	cout << LCM(a, b);
}
