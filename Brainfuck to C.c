#include <stdio.h>
#define MAX_LEN 1500000
#include <string.h>

int main() {
    char code[]="+++++++++++++++++++++++++++++++++++++++++++++ +++++++++++++++++++++++++++.+++++++++++++++++ ++++++++++++.+++++++..+++.------------------- --------------------------------------------- ---------------.+++++++++++++++++++++++++++++ ++++++++++++++++++++++++++.++++++++++++++++++ ++++++.+++.------.--------.------------------ --------------------------------------------- ----.-----------------------.";
    int i = 0;
    int pars = 0;
    int size =sizeof(code) / sizeof(char);
    char arr[30000];
    char *output_file="int i = 0; char arr[30000]; memset(arr, 0, sizeof(arr));";
    memset(arr, 0, sizeof(arr)); 
    printf("Size of code = %d\n", size);
    while (
            pars!=size
            ){
        switch(code[pars]){
            case '>': strncat(output_file,"i++;",MAX_LEN); pars++;
            case '<': strncat(output_file,"i--;",MAX_LEN);pars++;
            case '+': strncat(output_file,"arr[i]++;",MAX_LEN);pars++;
            case '-': strncat(output_file,"arr[i]--;",MAX_LEN);pars++;
            case '.': strncat(output_file,"putchar(arr[i]);",MAX_LEN);pars++;
            case ',': strncat(output_file,"arr[i] = getchar();",MAX_LEN); pars++;
            case '[': strncat(output_file,"while(arr[i]){",MAX_LEN); pars++;
            case ']': strncat(output_file,"}",MAX_LEN); pars++;
            default: pars++;

        }

    }
    printf("%s",output_file);
    FILE *fin;
    fin = fopen("output.c", "w");
    fprintf (fin, "%s",output_file);
    fclose(fin);
    return pars;

}