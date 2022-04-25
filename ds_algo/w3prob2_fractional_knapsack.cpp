#include <iostream>
#include <iomanip>

using namespace std;

#define MAXN 1001

//exp: phai ep kieu float(int/int); == chu khong phai =;

double max_value(int n, int W, int v[], int w[]) {
	//sort accord to net value
	double net_value[MAXN];
	for (int i=1; i<=n; ++i) {
		net_value[i] = double(v[i]) / w[i];
	}
	for (int i=1; i<n; ++i)
		for (int j=i+1; j<=n; ++j)
			if (net_value[i] < net_value[j]) {
				swap(net_value[i], net_value[j]);
				swap(v[i], v[j]);
				swap(w[i], w[j]);
			}
	double V = 0.;
	
	//choose from highest net_value		
	for (int i=1; i<=n; ++i) {
		if (W==0) 
			return V;
		int a = min(w[i], W);
		V = V + a*net_value[i];
		W = W - a;
	}
	return V;
}

int main() {
	int n, W;
	int v[MAXN], w[MAXN];
	cin >> n >> W;
	for (int i=1; i<=n; ++i) {
		cin >> v[i] >> w[i];
	}
	cout << setprecision(4) << fixed << max_value(n, W, v, w);
}
