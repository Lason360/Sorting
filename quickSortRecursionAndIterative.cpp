#include <iostream>
#include <stack>
#include<chrono>
using namespace std::chrono;
using namespace std;

void swap(int arr[],int p, int q){
    int temp;
    temp = arr[p];
    arr[p] = arr[q];
    //cout<<p<<" "<<q;
    arr[q] = temp;
}

int partition(int array [], int start, int end){
    int i=start-1; 
    int j=start;
    while(j < end){
        if(array[j]<array[end]){
            i = i+1;
            swap(array,i,j);
        }
        j=j+1;
    }
    swap(array,i+1,end);
    return i+1;
    
}

void quickSortRecur(int array[], int start, int end){
    if(start < end){
        int pivotIndex = partition(array, start, end);
        quickSortRecur(array, start,pivotIndex-1);
        quickSortRecur(array, pivotIndex+1, end);
    }
}


void quickSortIter(int array[], int start, int end) {
    stack<int> s;
    s.push(start);
    s.push(end);

    while (!s.empty()) {
        int end = s.top();
        s.pop();
        int start = s.top();
        s.pop();

        int pivotIndex = partition(array, start, end);

        if (pivotIndex - 1 > start) {
            s.push(start);
            s.push(pivotIndex - 1);
        }

        if (pivotIndex + 1 < end) {
            s.push(pivotIndex + 1);
            s.push(end);
        }
    }
}

int main(){
    for(int x = 5000; x<50000; x=x+5000){
        int a[x];
        int b[x];
        for(int y = 0; y<x; y++){
            a[y] = (rand() % 40000);
            b[y] = a[y];
        }

        cout<<"======================================"<<endl<<"Considering an array with "<<x<<" elements"<<endl;
        auto start = high_resolution_clock::now();
        quickSortIter(a,0,x-1);
        auto stop = high_resolution_clock::now();
        auto duration = duration_cast<microseconds>(stop - start);
        cout<<"Time taken by iterative algorithm "<<(duration.count())<<endl;
        auto start2 = high_resolution_clock::now();
        quickSortRecur(b,0,x-1);
        auto stop2 = high_resolution_clock::now();
        auto duration2 = duration_cast<microseconds>(stop2 - start2);
        cout<<"Time taken by recursive algorithm "<<(duration2.count())<<endl<<endl;
        
    }
}