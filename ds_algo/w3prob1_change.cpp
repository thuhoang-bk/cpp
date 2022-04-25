#include <iostream>

using namespace std;

int bill_num(int m) {
	int count = 0;
	count += m/10 + (m%10)/5 + m%5;
	return count;
}

int main() {
	int m;
	cin >> m;
	cout << bill_num(m);
}


