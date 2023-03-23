#include<iostream>
using namespace std;

void merge(int arr[], int l, int m, int r){
    int nl = m - l +1;
    int nr = r - m;
    int L[nl];
    int R[nr];

    //seperate the array from the midpoint
    for(int x = 0; x<nl;x++){
        L[x] = arr[l+x];
    }
    for(int y = 0; y<nr;y++){
        R[y] = arr[m+1+y];
    }    
    int i1 = 0;
    int i2 = 0;
    int k = l;

    while(i1<nl && i2<nr){
        if (L[i1]<=R[i2]){
            arr[k] = L[i1];
            i1++;  
        }
        else{
            arr[k] = R[i2];
            i2++;
        }
        k++;
    }

    if(i1<nl){
        for(int z=i1;z<nl;z++){
            arr[k] = L[z];
            k++;
        }
    }

    if(i2<nr){
        for(int z=i2;z<nr;z++){
            arr[k] = R[z];
            k++;
        }
    }
}

void mergesort(int arr[], int l, int r){
    if(l<r){
        int m = (l+r)/2;

        mergesort(arr, l, m);
        
        mergesort(arr,m+1,r);

        merge(arr,l,m,r);
    }
    
}


int main(){
    int a[] = {1,5,4,4,2,7,23,53};
    
    int l = 7;
    mergesort(a,0,l);
    for(int x = 0;x< 8 ;x++){
        cout<<a[x]<<" ";//
    }
}