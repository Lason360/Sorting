#include<iostream>
#include<vector>
using namespace std;

vector <int> bubbleSortOpti(vector <int> vec){
    int n = vec.size();
    int temp;
    bool swapped;
    for (int x =n ;x>0;x--){
        swapped = false;
        for (int y = 0; y<x-1;y++){
            
            if (vec[y]>vec[y+1]){
                temp = vec[y];
                vec[y] = vec[y+1];
                vec[y+1] = temp;
                swapped = true;
            }
            else{
                continue;
            }
        }
        if (!swapped){
            break;
        }
    }
    return vec;
}

int main(){
    vector <int> a = {23,42,64,232,64,23};
    vector <int> b = bubbleSortOpti(a);
    for(int x=0;x<b.size();x++){
       cout<<b[x]<<endl;
    }
}
