#include <bits/stdc++.h>
using namespace std;
void swap(int* arr, int i, int j){
    int temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
}
int part(int* arr, int l, int h){
    int pivot_ele = arr[h],i=l;
    for(int j=l; j <=h ; j++){
        if(arr[j]<pivot_ele){
            i++;
            swap(arr,j,i);
        }
    }
    swap(arr,h,i);
    return i;
}
int kthSmallest(int* arr, int l,int h, int k){
    int p = part(arr,l,h);
    if(p == k-1)
        return arr[p];
    else if(p<k-1)
        return kthSmallest(arr,p+1,h,k);
    else
        return kthSmallest(arr,l,p-1,k);
    return INT_MIN;
}
int main()
{
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int arr[n];
        for(int i=0; i<n; i++)
            cin>>arr[i];
        int k;
        cin>>k;
        int ans = kthSmallest(arr,0,n-1,k);
        if(k<n)
            cout<<ans<<endl;
        else
            cout<<"Not present"<<endl;
    }
    return 0;
}
