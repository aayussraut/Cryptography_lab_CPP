def keyGen(key,Text):
    newKey=key[:]
    if(len(key)>len(Text)):
        print("The key length is greater than Text")
    else:
        for i in range(len(key),len(Text)):
            newKey+=key[i%len(key)]
    return newKey

def encryption(key,plaintext):
    plaintext=plaintext.lower()
    
    cipherText=''
    for i in range(len(plaintext)):
        if plaintext[i]>='a' and plaintext[i]<='z':
            base='a'
        if plaintext[i] ==' ':
            cipherText=cipherText+plaintext[i]
        else:
            encrypt= chr((ord(plaintext[i])-ord(base)+ord(key[i])-ord(base))%26 +ord(base))
            cipherText=cipherText+ (encrypt)
       
    print("\nCipher Text: "+cipherText);


def decryption(key,cipherText):
    cipherText=cipherText.lower()
    plainText=''
    for i in range(len(cipherText)):
        if cipherText[i]>='a' and cipherText[i]<='z':
            base='a'
        if cipherText[i] ==' ':
            plainText=plainText+cipherText[i]
        else:
            if ord(cipherText[i])-ord(base)-ord(key[i])-ord(base)<0:
                decrypt= chr((ord(cipherText[i])-ord(key[i])+26)%26 +ord(base))
                plainText= plainText+ decrypt
            else:
                decrypt= chr((ord(cipherText[i])-ord(key[i]))%26 +ord(base))
                plainText= plainText+ decrypt

       
    print("\nPlain Text: "+plainText);


choice = int(input("\nEnter your choice:\n1. Encrypt\n2. Decrypt\n3. Exit\n"))
if choice == 1:
    key=input("\nEnter your key: ")
    plainText=input("\nEnter plain text: ")
    newKey=keyGen(key,plainText)
    encryption(newKey,plainText)
elif choice == 2:
    key=input("\nEnter your key: ")
    cipherText=input("\nEnter cipher text: ")
    newKey=keyGen(key,cipherText)
    decryption(newKey,cipherText)
elif choice == 3:
    exit()
else:
    print("Choose a correct Number.")


