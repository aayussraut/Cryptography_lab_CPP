#include<iostream>
using namespace std;
#include<string.h>
#include<cstdio>
string encryption(string plainText){
    int i;
    string newplainText;
    string railfence1,railfence2,cipherText;
    for(i=0;i<plainText.length();i++){
        if(plainText[i]==' '){

        }
        else{
            newplainText+=plainText[i];
        }
            
   }
    for(i=0;i<newplainText.length();i++){
        if(i%2==0)
            railfence1+=newplainText[i];
        else
            railfence2+=newplainText[i];
    }
    cipherText=railfence1+railfence2;
    return cipherText;
}

string decryption(string cipherText){
    int mid,i;
    string plainText;
    if(cipherText.length()%2==0){
        mid = cipherText.length()/2;
    }
    else
        mid=cipherText.length()/2 + 1;
    for(i=0;i<mid;i++){
        plainText+=cipherText[i];
        plainText+=cipherText[mid+i];

    }
    return plainText;

}

int main(){
    string cipherText1,cipherText2,plainText1,plainText2,cipherText;
    char plainText[50];
    int choice;
    cout<<"\nEnter your choice:\n1. Encrypt\n2. Decrypt\n3. Exit\n";
    cin>>choice;
    switch(choice){
        case 1 :{
            cout<<"\nEnter plain Text:";
            gets(plainText);
            cipherText1=encryption(plainText);
            cipherText2=encryption(cipherText1);
            cout<<cipherText2;
            break;
        }
        case 2:{
            cout<<"\nEnter cipher Text: ";
            cin>>cipherText;
            plainText1=decryption(cipherText);
            plainText2=decryption(plainText1);
            cout<<plainText2;
        }
        case 3:
            exit(0);
        default:
            cout<<"Enter a correct choice";
    }
    
    

}

