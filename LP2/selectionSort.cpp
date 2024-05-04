//Selection Sort

//PLAYGROUND - https://leetcode.com/playground/KQqcSm5G

#include<bits/stdc++.h>
using namespace std;

void selsort(vector<int>& arr){
    int n=arr.size();
    for(int i=0; i<n-1; i++){
        for(int j=i+1; j<n; j++){
            if(arr[i]>arr[j]){
                int temp=arr[i];
                arr[i]=arr[j];
                arr[j]=temp;
            }
        }
    }
}

int main(){
    vector<int> arr={6,5,3,4,2,1};
    selsort(arr);
    for(int i=0; i<6; i++){
        cout<<arr[i]<<" ";
    }
}
