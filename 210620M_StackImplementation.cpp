#include<iostream>
#include<cstdlib>
#include <chrono>
using namespace std::chrono;
using namespace std;

//LinkedList implementation
class node{
    public:
        int data;
        node * next;

        node(int value){
            data = value;
        }

};

class linkedList{
    public:
        node* head;
        
        linkedList(){
            head =NULL;
        }

        void append(int value){
            node* newNode = new node(value);
            if(head == NULL){
                head = newNode;
                return;
            }
            else{
                node* currentNode = head;
                while(currentNode->next != NULL){
                    currentNode = currentNode->next;
                }
                currentNode->next = newNode;
            }

        }

        int popEnd(){
            if(head == NULL){
                throw "No elements in the stack";
            }
            else{
                node* currentNode = head;
                while(currentNode->next->next != NULL){
                    currentNode = currentNode->next;
                }
                int value = currentNode->next->data;
                currentNode->next = NULL;
                return value;
            }
        }

        void display(){
            if(head == NULL){
                return;
            }
            else{
                node * currentNode = head;
                int x = 0;
                while(currentNode != NULL){
                    x++;
                    //cout<<x;
                    cout<<currentNode->data<<" ";
                    currentNode = currentNode->next;
                }
                cout<<endl;
            }
        }
};

class stackLinkedList{
    public:
    linkedList stackList;
    void push(int value){
        stackList.append(value);
    }
    int pop(){
        return stackList.popEnd();
    }
    void display(){
        stackList.display();
    }
};

//Array Implementation

const int maxSize = 1000;

class stackArr{
    public:
        int stackArray[maxSize] ;
        int top;

    stackArr(){
        top = -1;
    }
    
    bool isEmpty(){
        if(top == -1){
            return true;
        }
        else{
            return false;
        }
    }

    bool isFull(){
        if(top == maxSize-1){
            return true;
        }
        else{
            return false;
        }
    }

    bool push(int value){ 
        if(isFull()){
            cout<<"Error: Stack is full. Can't push "<<value<<endl;
            return false;
        }
        top++;
        stackArray[top] = value;
        return true;
        
    }
    int pop(){
        if (isEmpty()){
            cout<<"Error: Stack is empty. Can't pop";
            return 0;
        }

        int value = stackArray[top];
        top--;
        return value;
    }
    int stackTop(){
        if (isEmpty()){
            throw "Error: Stack is empty. Can't pop";
        }
        return stackArray[top];
    }
    void display(){
        for(int x=0;x<top+1;x++){
            cout<<stackArray[x]<<" ";
        }
        cout<<endl;
    }

    
};
void testArray(int * num){
    
    
    stackArr s;
    
    auto start1 = high_resolution_clock::now();
    for(int x = 0;x<10;x++){
        s.push(num[x]);
    }
    s.display();
    for(int x = 0;x<5;x++){
        s.pop();
    }
    s.display();
    for(int x = 10;x<15;x++){
        s.push(num[x]);
    }
    s.display();
    auto stop1 = high_resolution_clock::now();
    auto duration1 = duration_cast<microseconds>(stop1 - start1);
    cout<<"Time taken in miliseconds for the array implimentation: "<<(duration1.count())<<endl;
    
}

void testLinkedList(int * num){
    
    stackLinkedList s2;
    
    auto start2 = high_resolution_clock::now();
    for(int x = 0;x<10;x++){
        s2.push(num[x]);
    }
    s2.display();
    for(int x = 0;x<5;x++){
        s2.pop();
    }
    s2.display();
    for(int x = 10;x<15;x++){
        s2.push(num[x]);
    }
    s2.display();
    auto stop2 = high_resolution_clock::now();
    auto duration2 = duration_cast<microseconds>(stop2 - start2);
    cout<<"Time taken in miliseconds for the Linked list implimentation: "<<(duration2.count())<<endl;
    
}


int main(){
    
    for(int y=0;y<5;y++){
        int num[15];
        for(int x = 0;x<15;x++){
            num[x] = rand()%100000;
        }
        cout<<endl;
        cout<<"=================="<<y+1<<"==================";
        cout<<endl;
        cout<<"Array Implementation"<<endl;
        testArray(num);
        cout<<endl<<endl;
        cout<<"Linked List Implementation"<<endl;
        testLinkedList(num);
    }
}

