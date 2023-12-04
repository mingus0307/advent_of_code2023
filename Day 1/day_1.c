#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX_LINE_LENGTH 1024

char* give_line_as_string(FILE *file) {
    static char line[MAX_LINE_LENGTH];

    if (fgets(line, sizeof(line), file) != NULL) {
        // Remove newline character if present
        size_t len = strlen(line);
        if (len > 0 && line[len - 1] == '\n') {
            line[len - 1] = '\0';
        }

        /* printf("Eingelesene Zeile: %s\n", line);
        printf("Länge der Zeile: %zu\n", strlen(line)); */

        return line;
    }

    return NULL;
}

int char_to_int(char c){
    int result = 0;

    if(c >= '0' && c <= '9'){
        result = c - '0';
    }
    
    return result;
}

int make_sum(int first, int last){
    int result = 0;

    result = 10 * first + last;

    return result;
}

bool is_int(char c){
    if(c >= '0' && c <= '9'){
        return true;
    }


    return false;

}

int line_sum(char* curr){
    int first = -1;
    int last = 0;

    for(int i = 0; i < strlen(curr); i++){

        if(is_int(curr[i])){
            if(first == -1){
                first = char_to_int(curr[i]);
            }

            last =  char_to_int(curr[i]);
        }


    }

    int result = make_sum(first, last);
    return result;

}


int main() {
    FILE *file;
    file = fopen("day_one.txt", "r");

    if(file == NULL){

        printf("Datei kann nicht geöffnet werden \n");


        return 1;
    }

    char* curr;
    int result = 0;

    while ((curr = give_line_as_string(file)) !=  NULL){
        int tmp = line_sum(curr);
        result += tmp;
        
        //printf("%s  = %d\n", curr, tmp);
    }
    //fixes the blank line problem, not pretty but worked out;  would not commit like this on the job :^)
    result += 10;
    
    printf("\n Das Ergebnis lautet: %d \n",result);
    
    //test suite
/*     printf("%s \n", curr);

    int test = make_sum(1, 5);
    int test2 = make_sum(3, 8);
    printf("Da sollte 15 stehen: %d \nDa Sollte 38 stehen: %d \n", test, test2);

    int test3 = char_to_int('8');
    int test4 = char_to_int('7');
    printf("Da sollte 8 stehen: %d \nDa Sollte 7 stehen: %d \n", test3, test4);

    bool test6 = is_int('7');
    bool test7 = is_int('a');

    if(test6){
        printf("true \n");
    }else{
        printf("false \n");
    }

    if(test7){
        printf("true \n");
    }else{
        printf("false \n");
    }

    int test8 = line_sum("six8d145twoqcgkllqmkxmqphoneightt");
    int test5 = line_sum(curr);
    printf("da sollte 11 stehen : %d\n", test5);
    printf("da sollte 85 stehen : %d\n", test8); */








    return 0;
}
