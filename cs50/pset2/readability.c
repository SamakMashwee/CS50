#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <math.h>

int main(void){
    string text = get_string("Text: ");

    int lettercount = 0;
    int wordcount = 0;
    int sentencecount = 0;

    for(int i = 0;i < strlen(text);i++){
        int letter = text[i];

        if((letter >= 'A' && letter <= 'Z') || (letter >= 'a' && letter <= 'z')){
            lettercount++;
        }

        else if(letter == 32){
            wordcount++;
        }

        else if(letter == 33 || letter == 46 || letter == 63){
            sentencecount++;
        }
    }

    float index = 0.0588 * (100 * (float) lettercount / (float) wordcount) - 0.296 * (100 * (float) sentencecount / (float) wordcount) - 15.8;

    if(index < 16 && index >= 1){
        printf("Grade %i", (int) index);
    }

    else if(index > 16){
        printf("Grade 16+\n");
    }

    else if(index < 8){
        printf("Before Grade 1\n");
    }
}