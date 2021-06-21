#include<iostream>
using namespace std;
#include<string.h>
#include<algorithm>
void encryption(int key,string plaintext){
    cout<<plaintext;
    transform(plaintext.begin(), plaintext.end(), plaintext.begin(), ::tolower); // Changing to lowercase
    string cipherText;
    char base;
    string encrypt;
    int len=plaintext.length();
    int i=0;
    while(plaintext[i]!='\0'){
    if(plaintext[i]>='a' && plaintext[i]<='z'){
        base='a';
    }
    if (plaintext[i]==' '){
        cipherText=cipherText+' ';
    }
    else{
        encrypt= char((int(plaintext[i])-int(base)+key)%26 +int(base));
        cipherText=cipherText+encrypt;
    }
    i++;
    }
    cout<<cipherText;
}

void decryption(int key,string cipherText){
    transform(cipherText.begin(), cipherText.end(), cipherText.begin(), ::tolower); // Changing to lowercase
    string plainText;
    char base;
    string decrypt;
    int i=0;
    while(cipherText[i]!='\0'){
    if(cipherText[i]>='a' && cipherText[i]<='z'){
        base='a';
    }
    if (cipherText[i]==' '){
        cipherText=cipherText+' ';
    }
    else{
        decrypt= char((int(cipherText[i])-int(base)-key)%26 +int(base));
        plainText=plainText+decrypt;
    }
    i++;
    }
    cout<<plainText;
}
int main(){
    string plaintext,cipherText;
    int choice;
    cout<<"\nEnter your choice:\n1. Encrypt\n2. Decrypt\n3. Exit\n";
    cin>>choice;
    switch(choice){
        case 1 :{
            cout<<"\nEnter plain Text:";
           
            cin>>plaintext;
            //getline(cin,plaintext);
            encryption(3,plaintext);
            break;
        }
        case 2:{
            cout<<"\nEnter cipher Text: ";
            cin>>cipherText;
            //getline(cin,cipherText);
            decryption(3,cipherText);
        }
        case 3:
            exit(0);
        default:
            cout<<"Enter a correct choice";

    }
    

}