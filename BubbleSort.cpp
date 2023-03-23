#include<iostream>
#include<vector>
using namespace std;
//this is Bubble Sort
vector <int> bubbleSort(vector <int> vec){
    int n = vec.size();
    int temp;
    for (int x =n ;x>0;x--){
        for (int y = 0; y<x-1;y++){
            
            if (vec[y]>vec[y+1]){
                temp = vec[y];
                vec[y] = vec[y+1];
                vec[y+1] = temp;
            }
            else{
                continue;
            }

        }
    }
    return vec;
}

int main(){
    vector <int> a = {123123,1344,123,2334,12,3412};
    vector <int> b = bubbleSort(a);
    for(int x=0;x<b.size();x++){
       cout<<b[x]<<endl;
    }
}
