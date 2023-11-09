/*This code for writing the data from files*/

#include<stdio.h>

int main(){
    FILE *file;

    file = fopen("person.txt","w+");

    if (file == NULL){
        printf("Error opening the file.\n");
        return 1;
    }
    
    fprintf(file,"1 25\n");
    fprintf(file,"2 30\n");
    fprintf(file,"3 23 \n");
    

    fclose(file);
    
    printf("data has been written\n");
    return 0;
}

