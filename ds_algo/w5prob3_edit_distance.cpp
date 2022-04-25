#include <iostream>

#define MAXN 101
using namespace std;

int min_edit(string s1, string s2) {
	int l1 = s1.size(), l2 = s2.size();
	int D[MAXN][MAXN];
	for (int i=0; i<=l1; ++i)
		D[i][0] = i;
	for (int j=0; j<=l2; ++j)
		D[0][j] = j;
	for (int i=1; i<=l1; ++i)
		for (int j=1; j<=l2; ++j)
			if (s1[i-1] == s2[j-1])
				D[i][j] = D[i-1][j-1];
			else
				D[i][j] = min(min(D[i-1][j], D[i][j-1]), D[i-1][j-1]) + 1;
	return D[l1][l2];
}

int main() {
	string s1, s2;
	cin >> s1 >> s2;
	cout << min_edit(s1, s2);
}
