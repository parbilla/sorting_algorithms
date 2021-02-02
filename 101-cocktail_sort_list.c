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
void cocktail_sort_list(listint_t **list)
{
	listint_t *node = NULL, *next_node = NULL, *prev_node = NULL;
	int flag = 0;

	if (list == NULL || *list == NULL)
		return;
	node = (*list)->next;
	while (node)
	{
		if (node->next != NULL)
			next_node = node->next;
		else
		{
			flag = 1;
			next_node = node->prev;
		}
		/*printf("node: %i\nprev: %i\nnext: %i\n", node->n, node->prev->n, next_node->n);*/
		while (node->prev != NULL && node->prev->n > node->n)
		{
			prev_node = node->prev;
			prev_node->next = node->next;
			if (node->next != NULL)
				node->next->prev = node->prev;
			else
				flag = 1;
			node->next = prev_node;
			node->prev = prev_node->prev;
			prev_node->prev = node;
			if (node->prev == NULL)
				*list = node;
			else
				node->prev->next = node;
			/* swap_nodes(list, node, next_node); */
			/*printf("sigo en el while\n");*/
			print_list(*list);
			if (prev_node->n > node->n)
				break;
		}
		if (flag == 1)
		{
			while (node->prev != NULL && node->n < node->prev->n)
			{
				/*printf("estoy en el tercer while");*/
				prev_node = node->next;
				node->next = node->prev;
				node->prev = node->prev->prev;
				if (node->prev != NULL)
					node->prev->next = node;
				else
				{
					*list = node;
					flag = 0;
				}
				node->next->next = prev_node;
				prev_node->prev = node->next;
				node->next->prev = node;
				print_list(*list);
			}
			next_node = node->next;
		}
		node = next_node;
	}

}
