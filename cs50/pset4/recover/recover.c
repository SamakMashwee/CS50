#include <stdio.h>
#include <stdlib.h>

#define JAR 512
#define NAME 8

typedef unsigned char BYTE;

int main(int argc, char *argv[]){

    if(argc != 2){
        fprintf(stderr, "Usage: ./recover image\n");
        return 1;
    }
    
    char *card = argv[1];

    FILE *raw = fopen(card, "r");
    BYTE buffer[JAR];
    
    if(raw == NULL){
        fprintf(stderr, "Could not open %s\n", card);
    }
    
    char *name = malloc(NAME);
    
    int counter = 0;
    
    FILE *outfile;
    
    while(fread(buffer, sizeof(buffer), 1, raw) == 1){
        
        if(buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff && (buffer[3] & 0xf0) == 0xe0){
            
            if(counter > 0){
                fclose(outfile);
                
                sprintf(name, "%03i.jpg", counter);
                counter++;
            
                outfile = fopen(name, "w");
            
                fwrite(buffer, sizeof(buffer), 1, outfile);
            }
            
            else{
                sprintf(name, "%03i.jpg", counter);
                counter++;
                
                outfile = fopen(name, "w");
                
                fwrite(buffer, sizeof(buffer), 1, outfile);
            }
        }
        
        else if(counter > 0){
            fwrite(buffer, sizeof(buffer), 1, outfile);
        }
    }
    
    fclose(raw);
}