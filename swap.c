#include "monty.h"

/**
 * f_swap - swaps the top two elements of the stack.
 * @head: double pointer to the stack head
 * @counter: line number
 * Return: no return value
 */
void f_swap(stack_t **head, unsigned int counter)
{
    if (*head == NULL || (*head)->next == NULL)
    {
        fprintf(stderr, "L%d: can't swap, stack too short\n", counter);
        fclose(bus.file);
        free(bus.content);
        free_stack(*head);
        exit(EXIT_FAILURE);
    }

    int temp = (*head)->n;
    (*head)->n = (*head)->next->n;
    (*head)->next->n = temp;
}

