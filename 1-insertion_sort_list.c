#include "sort.h"
/**
 * swap_nodes - Function that swap two nodes
 *
 * @head: double pointer to the head of a doubly linked list.
 * @node: pointer to the current node
 * @next_node: current next node
 *
 * Return: Nothing.
 */

void swap_nodes(listint_t **head, listint_t *node, listint_t *next_node)
{
	listint_t *prev_node = NULL;

	prev_node = node->prev;
	/*el next del nueve apunta al dos */
	prev_node->next = next_node;
	/*el prev del 2 apunta al 9 */
	if (next_node != NULL)
		next_node->prev = prev_node;
	/*el prev del 8 apunta al prev del 9, sea lo que sea */
	node->prev = prev_node->prev;
	/*el prev del nodo apunta al prev del 9 */
	node->prev = prev_node->prev;
	/* chequear si es le primero */
	if (prev_node->prev == NULL)
		*head = node;
	/*el prev del nueve apunta al 8 */
	prev_node->prev = node;
	/*el next del ocho lo apunto al nueve */
	node->next = prev_node;
}

/**
 * insertion_sort_list - Function that sorts a doubly linked list of integers
 * in ascending order using the Insertion sort algorithm.
 *
 * @list: double pointer to a doubly linked list.
 *
 * Return: Nothing.
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *node = NULL, *next_node = NULL, *prev_node = NULL;

	if (list == NULL || *list == NULL)
		return;
	node = (*list)->next;
	while (node)
	{
		next_node = node->next;
		while (node->prev != NULL && node->prev->n > node->n)
		{
			/* No toquen el next_node !!!!! */
			prev_node = node->prev;
			/*el next del nueve apunta al dos */
			prev_node->next = node->next;
			if (node->next != NULL)
				node->next->prev = node->prev;
			/* el siguiente del 8 al nueve */
			node->next = prev_node;
			/*el prev del 8 apunta al prev del 9, sea lo que sea */
			node->prev = prev_node->prev;
			/* chequear si es le primero */
			prev_node->prev = node;
			if (node->prev == NULL)
				*list = node;
			else
				/*el prev del nueve apunta al 8 */
				node->prev->next = node;
			/* swap_nodes(list, node, next_node); */
			print_list(*list);
		}
		node = next_node;
	}
}
