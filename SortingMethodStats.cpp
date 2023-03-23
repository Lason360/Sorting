#include<iostream>
#include<vector>
#include <chrono>
using namespace std::chrono;
using namespace std;

//Insertion Sort Function
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

//Bubble Sort Function
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

//Optimized Bubble Sort Function
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

//Selection Sort Function
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

//Random vector generator
vector <vector <int> > arrayGen (){
    vector<vector<int>> mainVec;
    for(int x=0;x<10;x++){
        vector<int> vec;
        int numberOfElements = (rand() % (20000-100)) + 5000;
        for(int y = 0; y<numberOfElements;y++){
            vec.push_back((rand() % 10000)+0);}
        mainVec.push_back(vec);
    }
    return mainVec;
}

int main(){

    // Generating a vector set to be sorted
    vector<vector<int>> vec = arrayGen();
    
    // Taking runtime for insertion sort
    cout<<"========================"<<endl<<"Insertion Sort"<<endl;
    for(int x = 0; x<10; x++){

        auto start = high_resolution_clock::now();
        insertionSort(vec[x]);
        auto stop = high_resolution_clock::now();
        auto duration = duration_cast<microseconds>(stop - start);
        cout<<x+1<<". Total elements in array: "<<vec[x].size()<<endl;
        cout<<"Time taken in miliseconds: "<<(duration.count())/1000<<endl<<endl;
    
    }
    cout<<endl;

    cout<<"========================"<<endl<<"Bubble Sort"<<endl;
    for(int x = 0; x<10; x++){

        auto start = high_resolution_clock::now();
        bubbleSort(vec[x]);
        auto stop = high_resolution_clock::now();
        auto duration = duration_cast<microseconds>(stop - start);
        cout<<x+1<<". Total elements in array: "<<vec[x].size()<<endl;
        cout<<"Time taken in miliseconds: "<<(duration.count())/1000<<endl<<endl;
    
    }
    cout<<endl;

    cout<<"========================"<<endl<<"Optimized Bubble Sort"<<endl;
    for(int x = 0; x<10; x++){

        auto start = high_resolution_clock::now();
        bubbleSortOpti(vec[x]);
        auto stop = high_resolution_clock::now();
        auto duration = duration_cast<microseconds>(stop - start);
        cout<<x+1<<". Total elements in array: "<<vec[x].size()<<endl;
        cout<<"Time taken in miliseconds: "<<(duration.count())/1000<<endl<<endl;
    
    }
    cout<<endl;

    cout<<"========================"<<endl<<"Selection Sort"<<endl;
    for(int x = 0; x<10; x++){

        auto start = high_resolution_clock::now();
        selectionSort(vec[x]);
        auto stop = high_resolution_clock::now();
        auto duration = duration_cast<microseconds>(stop - start);
        cout<<x+1<<". Total elements in array: "<<vec[x].size()<<endl;
        cout<<"Time taken in miliseconds: "<<(duration.count())/1000<<endl<<endl;
    
    }
    cout<<endl;
}