#include <algorithm>
#include <cstdio>
#include <vector>
#include <iostream>

using namespace std;

int main() {
	freopen("shuffle.in", "r", stdin);

	int N;
	scanf("%d", &N);

	vector<int> shuffle(N);
	for (int& i : shuffle) { cin >> i; }
	vector<int> ids(N);
	for (int& i : ids) { cin >> i; }

	for (int i = 0; i < 3; i++) {
		vector<int> temp(N);
		for (int j = 0; j < N; j++) {
			temp[j] = ids[shuffle[j] - 1];
		}

		ids = temp;
	}

	freopen("shuffle.out", "w", stdout);
	for (int i : ids) {
		printf("%d\n", i);
	}
}
