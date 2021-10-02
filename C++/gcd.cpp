#include <bits/stdc++.h>
using namespace std;
long long int gcd(long long int a,long long int b)
{
    if(b==0)
    {
        return a;
    }
    else
    {
        return gcd(b,a%b);
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    long long int a,b;
    cin>>a>>b;
    cout<<gcd(a,b)<<endl;
    return 0;
}
