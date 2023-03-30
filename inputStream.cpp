#include<iostream>
#include<vector>
using namespace std;

vector<int> insertInput( vector <int> vec,int input){
    for(int x = 0;x<vec.size();x++){
        if(vec[x]>input){
            vec.insert(vec.begin()+x,input);
            return vec;
        }
    }
    vec.push_back(input);
    return vec;
}
int main(){
    int inputNum,numElements;
    vector<int> a;
    cout<<"How many elements: ";
    cin>>numElements;
    cout<<endl;
    cout<<"Start inputing numbers";

    for(int x = 0; x<numElements ; x=x+1){
        cin>>inputNum;
        a = insertInput(a,inputNum);
        cout<<"[ ";
        for (int y : a){
            cout<<y<<" ";
        }
        cout<<"] ";
        int n = a.size();
        if ( n % 2 == 0){
            int c = n/2;
            double M = ((double)a[c-1]+(double)a[c])/2;
            cout<<"Median is "<<M<<endl;
        }
        else{
            int c = n/2+1;
            double M = a[c-1];
            cout<<"Median is "<<M<<endl;
        }
        

    }
}