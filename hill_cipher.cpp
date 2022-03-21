#include<iostream>
using namespace std;
#include<math.h>
int getKeyMatrix(string key,int mat_key[3][3]){

    int i,j,k =0;
    for(i=0;i<3;i++){
        for(j=0;j<3;j++){
            mat_key[i][j]=key[k++]%97;
        }
    }
}

int getKeyText(string text,int mat_Text[3][1]){
    int i;
    for(i=0;i<3;i++){
            mat_Text[i][0]=text[i]%97;
    }

}

int determinant(int key[3][3]){
    int det=0;
    int det_inv;
    int  i,k=1;
    for(i=0;i<3;i++)
        det+=key[0][i]*((key[1][(i+1)%3]*key[2][(i+2)%3])-(key[2][(i+1)%3]*key[1][(i+2)%3]));
    while(((det*k)%26)!=1){
        k++;
        //cout<<k;
    }
    det_inv=k;

    //     if((det*i%26)==1){
    //         det_inv=i;
    //         break;
    //     }
    // }
    return det_inv;
}

int adjacent(int key[3][3],int adj_mat[3][3]){
    int i,j;
    for(i=0;i<3;i++){
        for(j=0;j<3;j++){
            adj_mat[i][j]=(key[(j+1)%3][(i+1)%3]*key[(j+2)%3][(i+2)%3])-(key[(j+2)%3][(i+1)%3]*key[(j+1)%3][(i+2)%3]);
            //adj_mat[i][j]=(key[(i+1)%3][(j+1)%3]*key[(i+2)%3][(j+2)%3])-(key[(i+2)%3][(j+1)%3]*key[(i+1)%3][(j+2)%3]);
        }
    }
}

void encryption(int key[3][3],int text[3][1]){
    char cipherText[3][1];
    string cipher;
    int i,j,k,sum;
    // for(int i=0;i<3;i++){

    //         cout<<"\t"<<text[i][0];
    // }
    for(i=0;i<3;i++){
        for(j=0;j<1;j++){
            sum=0;
            for(k=0;k<3;k++){
                sum+=key[i][k]*text[k][j];
                // cout<<"\n"<<(cipherText[i][j]%26)+97;
            }
            //cout<<"\n"<<(cipherText[i][j]%26)+97;
            cipherText[i][j]=(sum%26)+97;
        }
    }
    // for(i=0;i<3;i++){
    //     for(j=0;j<1;j++){
    //         cout<<"\n"<<cipherText[i][j]+97;
    //     }
    // }
    for(int i=0;i<3;i++){
        cipher+=cipherText[i][0];
    }
    cout<<cipher;

}

void decryption(int adj_mat[3][3],int inv_det){
    int inv_mat[3][3];
    string cipherText;
    int text[3][1];
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
           inv_mat[i][j]=((adj_mat[i][j]*inv_det))%26;
        }
    }
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            if(inv_mat[i][j]<0){
                inv_mat[i][j]+=26;
            }
            // cout<<inv_mat[i][j]<<" ";
        }
        // cout<<"\n";
    }
    cout<<"\n"<<"Enter Cipher Text";
    cin>>cipherText;
    getKeyText(cipherText,text);
    char plainText[3][1];
    string plain;
    int i,j,k,sum;
    //cout<<"\t"<<text[i][0];
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
    cout<<plain;

}

int main(){
    char key[9];
    int mat_key[3][3],mat_plainText[3][1],adj_mat[3][3];
    char plainText[3];
    char cipherText[3];
    int inv_det;
    cout<<"\nEnter your key of 9 words: ";
    cin>>key;
    cout<<"Enter plainText of 3 words: ";
    cin>>plainText;
    getKeyMatrix(key,mat_key);
    getKeyText(plainText,mat_plainText);
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            cout<<"\t"<<mat_key[i][j];
        }
    }
    cout<<"\n";

    encryption(mat_key,mat_plainText);
    inv_det=determinant(mat_key);
    // cout<<"\n"<<det;
    adjacent(mat_key,adj_mat);
    // for(int i=0;i<3;i++){
    //     for(int j=0;j<3;j++){
    //         cout<<"\t"<<adj_mat[j][i];
    //     }
    //     cout<<"\n";
    // }
    decryption(adj_mat,inv_det);

}