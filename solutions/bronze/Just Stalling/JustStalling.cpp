#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main()
{
    //fast io
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    vector<int> ch(n), fh(n);

    for(int i = 0; i < n; i++)
        cin >> ch[i];

    for(int i = 0; i < n; i++){
        int temp;
        cin >> temp;
        for(int j = 0; j < n; j++)
            if(ch[j] <= temp)
                fh[i]++;
    }

    sort(fh.begin(), fh.end());

    long f = fh[0];
    
    for(int i=1; i<n; i++)
        f *= (fh[i] - i);

    cout << f;

    return 0;
}
