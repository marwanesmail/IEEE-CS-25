#include <iostream>
using namespace std;
#define FastInput ios_base::sync_with_stdio(false); cin.tie(NULL);
#include <bits/stdc++.h>
#define ll long long
//"


int main() {

    FastInput

   int n;
   cin>>n;

   vector<int>Arry(n);
   for(int i=0;i<n;i++)
        cin>>Arry[i];

   sort(Arry.begin(),Arry.end());

    int m,x;
    cin>>m;

    while(m--){

        cin>>x;
        int low=0,high=n-1;
        
        int ans=-1;

        while(low<=high){
            int mid=(low+high)/2;
            if(Arry[mid]<=x){
                low=mid+1;
                ans=low;
            }else
               high=mid-1;
        }

        if(ans==-1)
          cout<<"0\n";
        else
         cout<<ans<<"\n";

  }
}
