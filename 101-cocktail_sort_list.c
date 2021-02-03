#include "sort.h"
/**
 * swap_back - Function that swap two nodes
 *
 * @head: double pointer to the head of a doubly linked list.
 * @node: pointer to the current node
 *
 * Return: Nothing.
 */

int swap_back(listint_t **head, listint_t *node)
{
	listint_t *prev_node = NULL;
	int flag;

	prev_node = node->next;
	node->next = node->prev;
	node->prev = node->prev->prev;
	if (node->prev != NULL)
	{
		node->prev->next = node;
		flag = 1;
	}
	else
	{
		*head = node;
		flag = 0;
	}
	node->next->next = prev_node;
	prev_node->prev = node->next;
	node->next->prev = node;
	print_list(*head);
	return (flag);
}

/**
 * swap_forward - Function that swap two nodes
 *
 * @head: double pointer to the head of a doubly linked list.
 * @node: pointer to the current node
 *
 * Return: Nothing.
 */

int swap_forward(listint_t **head, listint_t *node)
{
	listint_t *prev_node = NULL;
	int flag;

	prev_node = node->prev;
	prev_node->next = node->next;
	if (node->next != NULL)
	{
		node->next->prev = node->prev;
		flag = 0;
	}
	else
		flag = 1;
	node->next = prev_node;
	node->prev = prev_node->prev;
	prev_node->prev = node;
	if (node->prev == NULL)
		*head = node;
	else
		node->prev->next = node;
	print_list(*head);
	return (flag);
}

/**
 * cocktail_sort_list - function that sorts a doubly linked list of integers
 * in ascending order using the Cocktail shaker sort algorithm
 *
 * @list: double pointer to a doubly linked list.
 *
 * Return: Nothing.
 */
void cocktail_sort_list(listint_t **list)
{
	listint_t *node = NULL, *next_node = NULL, *prev_node = NULL;
	int flag = 0;

	if (list == NULL || *list == NULL)
		return;
	node = (*list)->next;
	while (node)
	{
		next_node = node->next;
		while (node->prev != NULL && node->prev->n > node->n)
		{
			prev_node = node->prev;
			flag = swap_forward(list, node);
			if (prev_node->n > node->n)
			{
				break;
			}
		}
		if (flag == 1)
		{
			while (node->prev != NULL && node->n < node->prev->n)
			{
				flag = swap_back(list, node);
			}
			next_node = node->next;
		}
		node = next_node;
	}
}
