#include <iostream>
#include <vector>

using namespace std;

int last_digit_sum(long long n) {
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
	long long sum = 0, sum_n = 0;
	for (int i=0; i<pp; ++i) {
		sum = (sum + fmod[i]) % 10;
	}
	sum_n = (sum * (n/pp)) % 10;
	for (int i=0; i <= n%pp; ++i) sum_n = (sum_n + fmod[i]) % 10;
	//cout << pp << " HEHE \n";
	return sum_n;
}

int main() {
	long long n;
	cin >> n;
	cout << last_digit_sum(n);
}
