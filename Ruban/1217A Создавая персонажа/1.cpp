#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
int main(){
int T;
cin >> T;
while(T--){
    int S, E, I, ch = 0, s = 0;
    cin >> S >> I >> E;
    s = max(0, ((E+I-S+2)/2));
    ch = max (0,E-s+1);
    cout<<ch<<endl;
}
}

