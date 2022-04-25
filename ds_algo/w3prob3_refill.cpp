#include <iostream>

using namespace std;

int min_refill(int m, int n, int stop[]) {
	int count = 0, current = 0;
	while (current <= n) {
		int prev = current;
		while ((current<=n) && (stop[current+1]-stop[prev] <= m))
			++current;
		if (current==prev) return -1;
		if (current<=n) ++count;
	}
	return count;
}

int main() {
	int d, m, n, stop[500];
	cin >> d >> m >> n;
	for (int i=1; i<=n; ++i)
		cin >> stop[i];
	stop[0] = 0;
	stop[n+1] = d;
	cout << min_refill(m, n, stop);
}
