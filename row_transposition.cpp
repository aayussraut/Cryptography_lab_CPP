#include<iostream>
using namespace std;

void rowColumnEncryption(int key,string message){
    int remainingNumLetter =0;
    char matrixMessage[7][7];
    int count=0,totalRow=0;
    string cipherText;

    //checked the length of message
    if(message.length()%7!=0){
        remainingNumLetter=7-message.length()%7;
        for(int i=0;i<remainingNumLetter;i++)
            message+='x';
    }

    totalRow=message.length()/7;

    //converting to matrix according to the size of key
    for(int i=0;i<7;i++){
        for(int j=0;j<7;j++){
            matrixMessage[i][j]=message[count];

        }
        if(count==message.length()){
            break;
        }
    }

    //finding the postion of key
    int keypostion[7];
    count=0;

    for(int i = 1;i<=7;i++){
		for(int j = 0;j<7;j++) {
			if(i == key[j])
			{
				keyposition[count] = j;
				break;
			}
					
		}
		count++;
	}

    // cipher text generation
	for(int i =0;i<keyposition.length();i++) {
		for(int j=0;j<totalRow;j++) {
			cipherText += matirxMessage[j][keyposition[i]];
		}
	}

    cout<<"Cipher Text: "<<cipherText;
}

int main(){
    int key[7]={4,3,1,2,5,6,7};
    rowColumnEncryption(key,"attackpostponeduntiltwoam");
}