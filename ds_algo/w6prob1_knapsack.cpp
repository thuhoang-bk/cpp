#include <iostream>
#include <vector>

#define MAXN 301
#define MAXW 10001
using namespace std;

int max_gold(int Wm, int n, long w[]) {
  vector<vector<int>> value(MAXW, vector<int> (MAXN));
  int i, j, weight, val;
  for (i=0; i<=Wm; ++i) value[i][0] = 0;
  for (j=0; j<=n; ++j) value[0][j] = 0;
  for (i=1; i<=n; ++i)
    for (weight=1; weight<=Wm; ++weight) {
      value[weight][i] = value[weight][i-1];
      if (w[i] <= weight) {
        val = value[weight-w[i]][i-1] + w[i];
        if (value[weight][i] < val)
          value[weight][i] = val;
      }
    }
  return value[Wm][n];
}

int main() {
  int Wm, n;
  long w[MAXN];
  cin >> Wm >> n;
  for (int i=1; i<=n; ++i)
    cin >> w[i];
  cout << max_gold(Wm, n, w) << endl;
}
