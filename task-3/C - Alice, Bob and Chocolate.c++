#include<bits/stdc++.h>
#define Iamfast ios_base::sync_with_stdio(false); cin.tie(NULL);

using namespace std;

void solve()
{
    int n ;
    cin >> n ;
    int arr[n];
    for(int i = 0 ; i < n ; i ++)
        cin >> arr[i];
    int Acnt = 0 , Bcnt = 0 ;
    int A = 0 , B = n-1 ;
    int Asum = arr[A] , Bsum = arr[B];
    while( A <= B)
    {
        if(Asum <= Bsum)
        {
            Asum += arr[++A];
            Acnt ++ ;
        }
        else
        {
            Bsum += arr[--B];
            Bcnt ++ ;
        }
    }

    cout << Acnt << " " << Bcnt << endl;
}

int main()
{



    Iamfast;
    solve();
}