#include <iostream>

using namespace std;

int last_digit_f(long long n) {
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
	
	return fmod[n % pp];
}

int main() {
	long long n;
	cin >> n;
	cout << (last_digit_f(n) * last_digit_f(n+1)) % 10;
}
