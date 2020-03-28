#include <iostream>
#include <string>
#include <cstring>
#include <cstdio>
#include <stdlib.h>
#include <windows.h>

using namespace std;

char tapcode[5][5] = {{'a','b','c','d','e'},{'f','g','h','i','j'},{'l','m','n','o','p'},{'q','r','s','t','u'},{'v','w','x','y','z'}};

string returntaps(int n, int tap)
{
    string subtap = "";
    for(int i=1; i <= (n*tap); i++){
        subtap = subtap + ".";
    }
    return subtap;
}

string convertfortap(char c, int ntap)
{
    char letra = tolower(c);
    string tap = "";
    for(int i=0; i < 5; i++){
        for(int j=0; j < 5; j++){
            if(tapcode[i][j] == letra)
            {
                tap = returntaps(i+1, ntap) + " " + returntaps(j+1, ntap) + " ";
            }
        }
    }
    return tap;
}

int main(int argc, char*argv[]){

   SetConsoleTitle("ds");
   
   if(argv[1][0] == 'c'){

    if (argv[2][0] == 'e'){
        // encryption
        string msg = argv[3];


        int key = atoi(argv[4]);


        string encryptedText = msg;

        for (int i = 0; i < msg.size(); i ++){

            if(msg[i]==32){
                continue; 
            } else {

                if((msg[i]+key) > 122) {
                   
                    int temp = (msg[i] + key) - 122;
                    encryptedText[i] = 96 + temp;
                } else if (msg[i] + key > 90 && msg[i] <= 96){
                    
                    int temp = (msg[i] + key) - 90;
                    encryptedText[i] = 64 + temp;
                } else {
                    
                    encryptedText[i] += key;
                }

            } 
        }
        cout << endl;
        cout << "Mesazhi i enkriptuar: " << encryptedText;

    } else if (argv[2][0] == 'd'){
        

        string encpMsg = argv[3];


        int dcyptKey = atoi(argv[4]);


        string decryptedText = encpMsg;

        for (int i = 0; i < encpMsg.size(); i++){
            if(encpMsg[i]==32){
                continue;
            } else {
                if((encpMsg[i] - dcyptKey) < 97 && (encpMsg[i] - dcyptKey) > 90){
                    int temp = (encpMsg[i] - dcyptKey) + 26;
                    decryptedText[i] = temp;
                } else if((encpMsg[i] - dcyptKey) < 65){
                    int temp = (encpMsg[i] - dcyptKey) + 26;
                    decryptedText[i] = temp;
                } else {
                    decryptedText[i] = encpMsg[i] - dcyptKey;
                }
            }
        }
        cout << endl;
        cout << "Mesazhi i dekriptuar: " << decryptedText << endl;

    } else {
        cout << "Zgjedhje e gabuar";
    }

    }
  


return 0;
}
