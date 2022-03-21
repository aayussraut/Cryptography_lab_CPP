#include<iostream>
using namespace std;
#include<string.h>
class VigeneCipher{
    public:
        string key;
        string plainText;

    public:
        VigeneCipher(string key, string plainText){
            this->key=key;
            this->plainText=plainText;
        }
    //Generate the key as the length of plaintext
    void keyGen(){
        string newKey =key;
        if(key.length()<plainText.length()){
            for(int i=key.length();i<plainText.length();i++){
                newKey += newKey.at(i%key.length());
            }

        }
        else if(key.length()>plainText.length()){
            cout<<"The key length is greater than plaiantext";
        }
        else{

        }
        key=newKey;

    }
    int * keyNumbering(string key){
    	int numberKey[key.length()];
    	for(int i=0;i<key.length();i++){
        	numberKey[i]=(int)(key.at(i))-97;
    	}
    	return numberKey;
	}

	int * plainTextNumbering(string plainText){
    	int plainNumber[plainText.length()];
    	for(int i=0;i<plainText.length();i++){
        	plainNumber[i]=(int)(plainText.at(i))-97;
    	}
    	return plainNumber;
	}

	
    

};



int main(){
    VigeneCipher vc("hello","monoalphabetic");
    vc.keyGen();
}
