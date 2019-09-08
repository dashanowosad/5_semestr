#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main(){
int T;
cin >> T;
while(T--){
    int n, X;
    cin >> n >> X;
    ll Max = -1, MaxD = -1;
    while(n--){
        ll d,h;
        cin >> d >> h;
        Max = max(Max, d-h);
        MaxD = max(d,MaxD);
    }
    int c = 0;
    if (X <= MaxD) cout<<1<<endl;
    else if (Max <= 0) cout <<-1<<endl;
    else{
        ++c;
        //X-=MaxD;
        //c+=ceil(X/Max);
        c += ceil((X - MaxD)/Max);
        cout<<c<<endl;
    }


}
return 0;
}
