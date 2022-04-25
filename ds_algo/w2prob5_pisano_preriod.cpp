#include <iostream>
#include <vector>

using namespace std;

//can get rid of array to save memory
int fn_mod_m(long long n, int m) {
	if (n <= 1) return n;
	
	//cycle is m^2 at most
	vector<int> fmod(m*m);
	fmod[0]=0;
	fmod[1]=1;
	int i = 1;
	
	// find pisano period or cycle length
	do {
		++i;
		fmod[i] = (fmod[i-1] + fmod[i-2]) % m;
	} while (fmod[i] != 1 || fmod[i-1] != 0);
	
	// f[n] mod m = f[n mod pp] mod m
	return fmod[n % (i-1)];
}

int main() {
	long long n;
	int m;
	cin >> n >> m;
	cout << fn_mod_m(n, m);
}
