#include <iostream>

using namespace std;

int last_digit_fibosum(long long m, long long n) {
	int i = 1;
	int fmod[100]; 
	fmod[0] = 0;
	fmod[1] = 1;
	
	// find pisano period or cycle length of fibo mod 10 (i)
	do {
		++i;
		fmod[i] = (fmod[i-1] + fmod[i-2]) % 10;
	} while (fmod[i] != 1 || fmod[i-1] != 0);
	int pp = i-1;
	
	//calculate last digit of sum
	long long sum = 0, sum_n = 0, sum_m = 0;
	for (int i=0; i<pp; ++i) {
		sum = (sum + fmod[i]) % 10;
	}
	sum_n = (sum * (n/pp)) % 10;
	sum_m = (sum * (m/pp)) % 10;
	for (int i=0; i <= n%pp; ++i) sum_n = (sum_n + fmod[i]) % 10;
	for (int i=0; i < m%pp; ++i) sum_m = (sum_m + fmod[i]) % 10;
	
	//cout << sum_m << " " << sum_n << endl;
	
	if (sum_n >= sum_m) return sum_n - sum_m;
	return sum_n + 10 - sum_m;
}

int main() {
	long long n, m;
	cin >> m >> n;
	cout << last_digit_fibosum(m, n);
}
