#include <cs50.h>
#include <stdio.h>

int main(void){
    int height = get_int("Height: ");
    while(height > 8 || height < 0){
        height = get_int("Height: ");
    }
    int spaces = height - 1;
    int hashes = height - (height - 1);
    
    for(int x = 0;x < height;x++){
        for(int i = 0;i < spaces;i++){
            printf(" ");
        }
        for(int j = 0;j < hashes;j++){
            printf("#");
        }
        printf("  ");
        for(int k = 0;k < hashes;k++){
            printf("#");
        }
        printf("\n");
        spaces--;
        hashes++;
    }
}