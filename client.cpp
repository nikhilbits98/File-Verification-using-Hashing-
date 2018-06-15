#include<iostream>
#include<stdlib.h>
#include<string.h>
#include<fstream>
#include"sha1.cpp"

using namespace std;
int main(){
    
    string name;
    cout<<"Enter filename to test: ";
    cin>>name;

    fstream orignal;
    orignal.open("text.txt",ios::in);
    if(!orignal){
        cout<<"Orignal File Not Found. Try Again"<<endl;
        return 2;
    }
    
    SHA1 sha1;
    string data;
    while(!orignal.eof()){
        orignal >> data;
        sha1.add(data.c_str(),data.length());
    }
    orignal.close();
    cout<<"Hash Of Orignal file is:  "<<sha1.getHash()<<endl;

    fstream testfile;
    testfile.open(name.c_str(),ios::in);
    if(!testfile){
        cout<<"Test File Not Found. Try Again"<<endl;
        return 3;
    }
    
    SHA1 sha2;
    string data1;
    while(!testfile.eof()){
        testfile >> data1;
        sha2.add(data1.c_str(),data1.length());
    }
    testfile.close();
    cout<<"Hash Of Test file is   :  "<<sha2.getHash()<<endl;

    if(sha1.getHash() == sha2.getHash()){
        cout<<"Files are same"<<endl;
    }
    else{
        cout<<"File has been tampered with"<<endl;
    }
    return 0;
}