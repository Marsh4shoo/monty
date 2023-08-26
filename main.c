#include "monty.h"

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "USAGE: monty file\n");
        return EXIT_FAILURE;
    }

    FILE *file = fopen(argv[1], "r");
    if (!file) {
        fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
        return EXIT_FAILURE;
    }
    
    bus_t bus = {file, NULL, NULL, 0};
    stack_t *stack = NULL;
    unsigned int counter = 0;
    
    char *content = NULL;
    size_t size = 0;
    ssize_t read_line;

    while ((read_line = getline(&content, &size, file)) != -1) {
        bus.content = content;
        counter++;
        
        if (read_line > 0) {
            execute(content, &stack, counter, file);
        }
        
        free(content);
        content = NULL;
    }

    free_stack(stack);
    fclose(file);

    return EXIT_SUCCESS;
}
