#include <bits/stdc++.h>

using namespace std;

#define endl '\n'
#define READ_SPEED cin.tie(0)->sync_with_stdio(0);
#define MOD 1000000007
#define MAXN 100000
#define INF 0x3f3f3f3f

int main(){
    int n, r, l;

    cin >> n;

    int vet[n], prefix_sum[n + 1];

    // Inicializando prefix sum
    prefix_sum[0] = 0;

    for(int i = 0; i < n; ++i){
        cin >> vet[i];
        prefix_sum[i + 1] = prefix_sum[i] + vet[i];
    }

    for(auto x : prefix_sum) 
        cout << x << " ";
    cout << endl;

    cout << "Entre com index left e right:" << endl;

    cin >> l >> r;

    // Soma do index l até r
    cout << prefix_sum[r + 1] - prefix_sum[l] << endl;

    return 0;
}