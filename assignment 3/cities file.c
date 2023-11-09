#include<stdio.h>

int main(){
    FILE *file;

    file = fopen("cities.txt","w+");

    if (file == NULL){
        printf("Error opening the file.\n");
        return 1;
    }
    
    fprintf(file,"Pune\n");
    fprintf(file,"Mumbai\n");
    fprintf(file,"nashik");
    

    fclose(file);
    
    printf("data has been written\n");
    return 0;
}
