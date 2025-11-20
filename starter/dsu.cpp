#include <bits/stdc++.h>
using namespace std;

vector<int> parent, sz;

int findSet(int v) {
    // TODO: implement path compression
    if(v==parent[v]){
        return v;
    }

    else{
        return parent[v]=findSet(parent[v]);
    }
}

void unionSet(int a, int b) {
    // TODO: implement union by size/rank
    a=findSet(a)
    b=findSet(b)

    if(a==b){
    }

    else{
        if(sz[a]<sz[b]){
            parent[a]=b;
            sz[b]+=sz[a];
        }

        else{
            parent[b]=a;
            sz[a]+=sz[b];
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, q;
    cin >> n >> q;

    parent.resize(n + 1);
    sz.resize(n + 1, 1);

    for (int i = 1; i <= n; i++) {
        parent[i] = i;
    }

    while (q--) {
        char type;
        int a, b;
        cin >> type >> a >> b;

        if (type == '+') {
            unionSet(a, b);
        } else if (type == '?') {
            if (findSet(a) == findSet(b)) cout << "YES\n";
            else cout << "NO\n";
        }
    }

    return 0;
}
