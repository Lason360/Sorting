#include<iostream>
#include<vector>
using namespace std;

vector <int> selectionSort(vector <int> vec){
    int n = vec.size();
    for (int x = 0; x<n ;x++){
        int min = vec[x];
        int loc = x;
        for (int y = x+1; y<n ; y++){
            if(vec[y]<min){
                min = vec[y];
                loc = y;
            }
        }
        int temp = vec[x];
        vec[x] = min;
        vec[loc] = temp;
    }
    return vec;
}    

int main(){
    vector <int> a = {10,9,8,7,6,5,4,3,2,1};
    vector <int> b = selectionSort(a);
    for(int x=0;x<a.size();x++){
       cout<<b[x]<<endl;
    }
}
