#include<iostream>
#include<vector>
using namespace std;

vector <int> insertionSort(vector <int> vec){
    int n = vec.size();
    int pos,temp;
    for(int i = 1; i<n; i++){
        pos = i;
        temp = vec[i];
        while(pos>0 && temp<vec[pos-1]){
            vec[pos] = vec[pos-1];
            pos--;
        }
        vec[pos] = temp;
    }
    return vec;
}

int main(){
    vector <int> a = {4,5,6,2,3,6};
    vector <int> b = insertionSort(a);
    for(int x=0;x<6;x++){
        cout<<b[x]<<endl;
    }
}
