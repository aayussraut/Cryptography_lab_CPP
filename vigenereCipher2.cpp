#include<iostream>
using namespace std;
#include<string.h>
class VigenereCipher{

    public:

        string key;
        string Text;
        string encrypt;
        string decrypt;
        char base='a';
        VigenereCipher(string key,string Text){
            this->key=key;
            this->Text=Text;
        }
        void keyGen(){
            string newKey =key;
            string plainText=Text;
            if(key.length()<plainText.length()){
                for(int i=key.length();i<plainText.length();i++){
                    newKey += key[i%key.length()];
                }
            }
            else if(key.length()>plainText.length()){
                cout<<"The key length is greater than plaiantext";
            }
            else{

            }
            key=newKey;
            // cout<<key<<"\n";
        }


        void vignereCipherEncryption(){
            string plainText=Text;
            string cipherText;
    	    for(int i=0;i<key.length();i++){
        	    encrypt= char((int(plainText[i])-97+key[i]-97)%26 +97);
                cipherText=cipherText+encrypt;
    	    }
            cout<<"\nCipherText: "<<cipherText;
	    }

        void vignereCipherDecryption(){
            string cipherText=Text;
            string plainText;
    	    for(int i=0;i<key.length();i++){
                if((cipherText[i]-97-key[i]-97)<0){
                    decrypt= char((int(cipherText[i])-key[i]+26)%26 +int(base));
                    plainText=plainText+decrypt;
                }
                else{
                    decrypt= char((int(cipherText[i])-key[i])%26 +int(base));
                plainText=plainText+decrypt;
                }
        	    
    	    }
            cout<<"\nPlainText: "<<plainText;
	    }
};

int main(){
    string plaintext,cipherText,key;
    cout<<"\nEnter your key: ";
    cin>>key;
    int choice;
    cout<<"\nEnter your choice:\n1. Encrypt\n2. Decrypt\n3. Exit\n";
    cin>>choice;
    switch(choice){
        case 1 :{
            cout<<"\nEnter plain Text:";
            cin>>plaintext;
            VigenereCipher vc(key,plaintext);
            vc.keyGen();
            vc.vignereCipherEncryption();
            break;
        }
        case 2:{
            cout<<"\nEnter cipher Text: ";
            cin>>cipherText;
            VigenereCipher vc(key,cipherText);
            vc.keyGen();
            vc.vignereCipherDecryption();
        }
        case 3:
            exit(0);
        default:
            cout<<"Enter a correct choice";
    }
}