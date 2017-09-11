//
//  main.cpp
//  BinaryTree
//
//  Created by Nicholas on 5/4/17.
//  Copyright © 2017 Nicholas. All rights reserved.
//

#include <iostream>
using namespace std;

class Bnode{
private:
    int data;
    Bnode *left;
    Bnode *right;
public:
    Bnode(char d, Bnode *l, Bnode *r){data=d,left=l,right=r;}
    char getData(){return(data);}
    Bnode *getLeft(){return(left);}
    Bnode *getRight(){return(right);}
    void setLeft(Bnode *l){left=l;}
    void setRight(Bnode *r){right=r;}
};

class List{
private:
    Bnode *first;
public:
    List(){first=NULL;}
    void print(Bnode *f);
    void insert(string);
};

void List::insert(string input){
    Bnode *current;
    char data;
    int size=input.size();
    cout << "String: "<<input<<endl;
    for(int i=0;i<size;i++){
        data=input[i];
    
        Bnode *newbie=new Bnode(data,NULL,NULL);
        
        //if there is nothing in TREE
        if(first==NULL){
            first=newbie;
            current=first;

        }
        //if there is anything in TREE
        else{
            current=first;
            
            do{
                if( (newbie->getData() <= current->getData()) && (current->getLeft() != NULL )){
                    current=current->getLeft();
                }
                else if ((newbie->getData() > current->getData()) && (current->getRight() != NULL)){
                    current=current->getRight();
                    
                }
            
            
            }while( (current->getLeft()!=NULL && newbie->getData() <= current->getData()) || (current->getRight()!=NULL && newbie->getData() > current->getData()));
            
            
            if(newbie->getData()>current->getData()){
                current->setRight(newbie);
                cout<<"## "<<current->getData()<<" "<<current<<" || "<<newbie->getData()<<" "<<newbie<<endl;
            }
            else{
                current->setLeft(newbie);
                cout<<"$$"<<current->getData()<<" "<<current<<" || "<<newbie->getData()<<" "<<newbie<<endl;
            }
        }

        
        
    }
    cout<<"Sorted string: ";
    print(first);
    cout<<endl;
}

void List::print(Bnode *first){
    cout<<first->getData()<<",";
    if(first->getLeft() != NULL){
        print(first->getLeft());
    }
    if(first->getRight() != NULL){
        print(first->getRight());
    }
}




int main() {
    List l;
    string input;
    cout << "Input string: \n";
    cin >> input;
    l.insert(input);
    return 0;
}
