#include <iostream>
using namespace std;

string vigenre(string text, string key, bool EncDec);

int main()
{
    string plaintext,ciphertext,key;
    char x;

    do{
        cout<<"Welcome to the encryption decryption station"<<endl;
        cout<<"Please choose one of the  following options"<<endl;
        cout<<"1.Encryption 2.Decryption 3.Exit"<<endl;
        int option;
        cin>>option;

        switch(option)
        {
            case 1:
                cout<<"Please enter a plain text"<<endl;
                cin>>plaintext;
                cout<<"Please enter a key"<<endl;
                cin>>key;
                ciphertext=vigenre(plaintext,key,0);
                cout<<"Cipher text:"<<ciphertext<<endl;
                cout<<"press Y/y to repeat the process or any key to exit"<<endl;
                cin>>x;
                break;
            case 2:
                cout<<"Please enter a cipher text"<<endl;
                cin>>plaintext;
                cout<<"Please enter a key"<<endl;
                cin>>key;
                ciphertext=vigenre(plaintext,key,1);
                cout<<"Plain text:"<<ciphertext<<endl;
                cout<<"press Y/y to repeat the process or any key to exit"<<endl;
                cin>>x;
                break;
            case 3:
            x='n';
            break;

        }
    }while(x=='Y'||x=='y');
    
}

string vigenre(string text, string key, bool EncDec)
{
    string newKey=key,newText;
    while(newKey.length()<text.length())
    {
        newKey+=key;
    }
    if(EncDec==0)
    {
        for(int i=0;i<text.length();i++)
        {
            newText+=(text[i]+newKey[i])%26+65;
    
        }
    }
    else
    {
        for(int i=0;i<text.length();i++)
        {
            newText+=(text[i]-newKey[i]+26)%26+65;
    
        }    
    }
    return newText;
}
