#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main(int argc, string argv[]){

    if(argc != 2){
        printf("Usage: ./substitution key\n");
        return 0;
    }

    if(strlen(argv[1]) != 26){
        printf("Key must contain exactly 26 characters.\n");
        return 0;
    }

    char tmp[26];

    for(int i = 0;i < 26;i++){
        tmp[i] = argv[1][i];
    }

    for(int i = 0;i < 26;i++){

        for(int j = i + 1;j < 26;j++){

            if(argv[1][i] == tmp[j]){
                printf("Key must not contain duplicate characters.\n");
                return 0;
            }
        }
    }

    string plaintext = get_string("plaintext:\t");
    char ciphertext[strlen(plaintext)];

    string abc = "abcdefghijklmnopqrstuvwxyz";

    printf("ciphertext:\t");

    int counter;
    for(int i = 0;i < strlen(plaintext);i++){
        counter = 0;

        for(int j = 0;j < strlen(abc);j++){

            if(tolower(plaintext[i]) != abc[j]){
                continue;
            }

            else{
                counter = j;
            }
        }

        if(isupper(plaintext[i]) != 0){
            printf("%c", toupper(argv[1][counter]));
        }

        else{
            printf("%c", tolower(argv[1][counter]));
        }
    }
    printf("\n");
}