#include<iostream>
using namespace std;
#include<math.h>
//changing key to 3*3 matrix
void getKeyMatrix(string key,int mat_key[3][3]){

    int i,j,k =0;
    for(i=0;i<3;i++){
        for(j=0;j<3;j++){
            mat_key[i][j]=key[k++]%97;
        }
    }
}

//changing text to 3*1 matrix
void getKeyText(string text,int mat_Text[3][1]){
    int i;
    for(i=0;i<3;i++){
            mat_Text[i][0]=text[i]%97;
    }
}

int determinant(int key[3][3]){
    int det=0;
    int det_inv;
    int  i,k=1;

    //calculating determinant
    for(i=0;i<3;i++)
        det+=key[0][i]*((key[1][(i+1)%3]*key[2][(i+2)%3])-(key[2][(i+1)%3]*key[1][(i+2)%3]));

    // finding d^-1
    while(((det*k)%26)!=1){ //(determinant* determinat^-1 ) mod 26 ==1
        k++;

    }
    det_inv=k;
    return det_inv;
}

void adjacent(int key[3][3],int adj_mat[3][3]){
    int i,j;

    //calculation adancency matrix of  key
    for(i=0;i<3;i++){
        for(j=0;j<3;j++){
            adj_mat[i][j]=(key[(j+1)%3][(i+1)%3]*key[(j+2)%3][(i+2)%3])-(key[(j+2)%3][(i+1)%3]*key[(j+1)%3][(i+2)%3]);
        }
    }
}

void encryption(int key[3][3],int text[3][1]){
    char cipherText[3][1];
    string cipher;
    int i,j,k,sum;

    //matrix multiplication of ciphertext and key
    for(i=0;i<3;i++){
        for(j=0;j<1;j++){
            sum=0;
            for(k=0;k<3;k++){
                sum+=key[i][k]*text[k][j];
            }

            cipherText[i][j]=(sum%26)+97;
        }
    }

    for(int i=0;i<3;i++){
        cipher+=cipherText[i][0];
    }
    cout<<"Cipher Text: "<<cipher;

}

void decryption(int adj_mat[3][3],int inv_det,int text[3][1]){
    int inv_mat[3][3],i,j,k,sum;
    string cipherText,plain;
    char plainText[3][1];

    //Finding inverse of key
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
           inv_mat[i][j]=((adj_mat[i][j]*inv_det))%26;
        }
    }
    
    //changing -ve no to +ve no
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            if(inv_mat[i][j]<0){
                inv_mat[i][j]+=26;
            }
        }
    }   
    //matrix multiplication of inverse matrix and cipherText
    for(i=0;i<3;i++){
        for(j=0;j<1;j++){
            sum=0;
            for(k=0;k<3;k++){
                sum+=inv_mat[i][k]*text[k][j];
            }
            plainText[i][j]=(sum%26)+97;
        }
    }

    for(int i=0;i<3;i++){
        plain+=plainText[i][0];
    }
    cout<<"Plain Text: "<<plain;

}

int main(){
    char key[9];
    int mat_key[3][3],mat_plainText[3][1],adj_mat[3][3],mat_cipherText[3][1];
    char plainText[3];
    char cipherText[3];
    int inv_det,choice;

    cout<<"\nEnter your key of 9 letter: ";
    cin>>key;
    getKeyMatrix(key,mat_key);//change key to 3*3 matrix

    cout<<"\nEnter your choice:\n1. Encrypt\n2. Decrypt\n3. Exit\n";
    cin>>choice;

    switch (choice)
    {
    case 1:
        cout<<"Enter plainText of 3 letter: ";
        cin>>plainText;
        getKeyText(plainText,mat_plainText);//change string plainText to matrix form
        encryption(mat_key,mat_plainText);//encryption
        break;
    case 2:
        cout<<"\n"<<"Enter Cipher Text: ";
        cin>>cipherText;
        getKeyText(cipherText,mat_cipherText); //change string cipherText to matrix form
        inv_det=determinant(mat_key); //return inverse of determinant (d^-1)
        adjacent(mat_key,adj_mat); //returns adjacent matrix of key.
        decryption(adj_mat,inv_det,mat_cipherText); //decryption
    case 3:
        exit(0);
    default:
        break;
    }

}