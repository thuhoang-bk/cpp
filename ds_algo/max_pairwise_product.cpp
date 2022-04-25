#include <iostream>
#include <vector>

using namespace std;

long long MaxPairwiseProduct(vector<int>& numbers) {
	int n = numbers.size();
	int max1 = -1, max2 = -1;
	int index1, index2;
	for (int i=0; i<n; ++i)
		if (numbers[i] > max1) {
			max1 = numbers[i];
			index1 = i;
		}
	for (int i=0; i<n; ++i)
		if ((numbers[i] > max2) && (i != index1)){
			max2 = numbers[i];
			index2 = i;
		}
	return ((long long) max1) * max2;
}

int main() {
	int n;
	cin >> n;
	vector<int> numbers(n);
	for (int i=0; i<n; ++i) cin >> numbers[i];
	cout << MaxPairwiseProduct(numbers);
}
