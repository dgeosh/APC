#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

/*
  does not pass sample case
  author: Alessandro
  date: 9/22/23
  todo: fix
*/

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N, K;
    cin >> N;
    vector<int> metalunits(N);

    for (int i = 0; i < N; i++) {
        cin >> metalunits[i];
    }

    cin >> K;
    unordered_map<int, vector<int>> recipes; // this is ok
    vector<vector<int>> rps = vector<vector<int>>(K);

    for (int i = 0; i < K; i++) {
        int L, M;
        cin >> L >> M;
        vector<int> constituents(M);

        for(int j = 0; j < M; j++) {
            cin >> constituents[j];
        }

        recipes[L] = constituents;
    }

    vector<int> dp(N + 1, -1);

    for(int i = 1; i <= N; i++) {
        dp[i] = metalunits[i-1];
    }

    for(int metal = 1; metal <= N; metal++) {
        if(recipes.find(metal) != recipes.end()) {
            vector<int> constituents = recipes[metal];
            bool transformable = true;

            for(int constituent : constituents) {
                if(dp[constituent] == -1) {
                    transformable = false;
                    break;
                }
            }

            if(transformable) {
                dp[metal] = max(dp[metal], 1 + *min_element(dp.begin(), dp.end() - N + metal));
            }
        }
    }

    cout << dp[N] << endl;
}
