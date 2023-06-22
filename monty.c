#include <stdio.h>
#include <stdlib.h>
#include "monty.h"

int main(int argc, char *argv[]) {
	 // Check if the file argument is provided
	 if (argc != 2) {
		  fprintf(stderr, "USAGE: monty file\n");
		  exit(EXIT_FAILURE);
	 }

	 // Open the file
	 FILE *file = fopen(argv[1], "r");
	 if (file == NULL) {
		  fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		  exit(EXIT_FAILURE);
	 }

	 // Initialize the stack
	 stack_t *stack = NULL;

	 // Read and execute instructions from the file
	 char *line = NULL;
	 size_t len = 0;
	 ssize_t nread;
	 unsigned int line_number = 1;

	 while ((nread = getline(&line, &len, file)) != -1) {
		  execute_instruction(line, line_number, &stack);
		  line_number++;
	 }

	 free(line);
	 fclose(file);
	 free_stack(stack);

	 return 0;
}

