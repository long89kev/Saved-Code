#include<bits/stdc++.h>

using namespace std;

int getFirstEle(int x){
    while(x > 0){
        x /= 10;
    }
    return x;
}

bool cmp(pair<int, int> &a, pair<int, int> &b){
    return a.first > b.first;
}

int main(){
    int x;
    cin >> x;

    vector<pair<int, int>> m;

    for(int i = 2; i <= x; i++){
        while(x % i == 0){
            if(i < 10) m.push_back({i, i});
                else m.push_back({getFirstEle(i), i});
            x /= i;
        }     
    }
    sort(m.begin(), m.end(), cmp);
    for(auto i : m){
        cout << i.second;
    }
}
