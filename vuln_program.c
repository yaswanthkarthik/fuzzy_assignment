#include <stdio.h>
#include <string.h>
void vulnerable_function(char *input) {
char buffer[50];
strcpy(buffer, input);
printf("Input: %s\n", buffer);
}
int main(int argc, char *argv[]) {
FILE *file;
char input[100];
file = fopen(argv[1], "r");
if (file == NULL) {
printf("Error opening file\n");
return 1;
}
fgets(input, sizeof(input), file);
fclose(file);
vulnerable_function(input);
return 0;
}
