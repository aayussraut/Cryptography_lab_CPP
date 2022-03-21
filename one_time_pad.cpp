#include<iostream>
using namespace std;
#include<string.h>
#include<time.h>
#include<stdlib.h>
class One_Time_Pad{

    public:

        string key;
        string Text;
        string cipherText;
        string encrypt;
        string decrypt;
        char base='a';
        One_Time_Pad(string key,string Text){
            this->key=key;
            this->Text=Text;
        }
        void keyGen(){
            string newKey;
            string plainText=Text;
            srand(time(0));
            for(int i=0;i<plainText.length();i++){
                newKey += char((rand()%(97-122+1))+97);
            }
            key=newKey;
            cout<<"\nKey: "<<key<<"\n";
        }


        void encryption(){
            string plainText=Text;
    	    for(int i=0;i<key.length();i++){
        	    encrypt= char((int(plainText[i])-97+key[i]-97)%26 +97);
                cipherText=cipherText+encrypt;
    	    }
            cout<<"\nCipherText: "<<cipherText;
	    }

        void decryption(){
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
    string plaintext,key;
    cout<<"\nEnter plain Text:";
    cin>>plaintext;
    One_Time_Pad otp(key,plaintext);
    otp.keyGen();
    otp.encryption();
    otp.decryption();
}