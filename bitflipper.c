/* 
 * File:   bitflipper.c
 * Author: daniel
 *
 * Created on October 19, 2011, 10:46 PM
 */

#include <stdio.h>
#include <stdlib.h>
//#include <cstdlib>
#include <time.h>

/*
 * 
 */
int main(int argc, char** argv) {
    FILE* fos;   
    long fSize;
    int randNumBits, i, posi, maxBits;
    time_t seconds;
    
    fos = fopen("output.bin", "rb");
    fseek (fos , 0 , SEEK_END);
    fSize = ftell (fos);
    rewind (fos); 
    
    char buffer[fSize];
    fgets(buffer,fSize+1,fos);
    fclose(fos);
    
    time(&seconds);
    srand((unsigned int) seconds);
    maxBits = fSize/2000;
    if(maxBits<6){
        maxBits=6;
    }
    randNumBits = rand() % (maxBits - 2 + 1) + 2;
    
    for(i=0; i < randNumBits; i++){
        posi=rand()%(fSize-1+1);
        if(buffer[posi]=='1'){
            buffer[posi]='0';
        }else{
            buffer[posi]='1';   
        }
        printf("\nFlipped Bit Location is %d\n", posi);
        
    }
    
    printf("\n%d bits were flipped.\n Press enter to exit.", randNumBits);
    
    fos = fopen("output.bin", "wb");
    fputs(buffer,fos);
    fclose(fos);
    
    getchar();
    return (EXIT_SUCCESS);
}

