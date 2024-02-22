#include <stdio.h>
#include <time.h>

static inline int count_vowel(char *str) {
    int count = 0;
    while (*str) {
        if (*str == 'a' || *str == 'e' || *str == 'i' || *str == 'o' || *str == 'u' || *str == 'A' || *str == 'E' || *str == 'I' || *str == 'O' || *str == 'U') {
            count++;
        }
        str++;
    }
    return count;
}

void call_inline_function(char *str) {
    count_vowel(str);
}

void call_function(char *str) {
    count_vowel(str);
}
int main() {
    char input[100];
    printf("Enter a string-: ");
    fgets(input, sizeof(input), stdin);
    
    int result;
    clock_t start_time, end_time;
    printf("Using inline function:-\n");
    result = count_vowel(input);
    printf("Number of vowels: %d\n", result);
    start_time = clock();
    for (int i = 0; i < 10; i++) {
        call_inline_function(input);
    }
    end_time = clock();
    
    double time_taken_inline = ((double) (end_time - start_time)) / CLOCKS_PER_SEC;
    printf("System time taken: %f seconds\n", time_taken_inline);
    
    
    printf("\nWithout using inline function:\n");
    result = count_vowel(input);
    printf("Number of vowels: %d\n", result);
    
    start_time = clock();
    for (int i = 0; i < 10; i++) {
        call_function(input);
    }
    end_time = clock();
    
    double time_taken = ((double) (end_time - start_time)) / CLOCKS_PER_SEC;
    printf("System time taken: %f seconds\n", time_taken);
    
    FILE *file = fopen("program", "r");
    fseek(file, 0, SEEK_END);
    long int size = ftell(file);
    fclose(file);
    
    printf("\nComparison Table:\n");
    printf("\n");
    printf("Inline Function | Without Inline Function |\n");
    printf("\n");
    printf("Size%ld bytes %ld bytes\n", size, size);
    printf("Time%f sec%f sec\n", time_taken_inline, time_taken);
    printf("\n");

    return 0;
}
