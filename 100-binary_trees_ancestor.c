#include "binary_trees.h"

/**
 * binary_trees_ancestor - Finds the lowest common ancestor of two nodes
 * @first: Pointer to the first node
 * @second: Pointer to the second node
 *
 * Return: Pointer to the lowest common ancestor, or NULL if non-existant
 */
binary_tree_t *binary_trees_ancestor(const binary_tree_t *first,
									const binary_tree_t *second)
{
	const binary_tree_t *first_a = first, *second_a = second;

	if (first == NULL || second == NULL)
		return (NULL);

	while (first_a != second_a)
	{
		first_a = (first_a == NULL) ? second : first_a->parent;
		second_a = (second_a == NULL) ? first : second_a->parent;
	}
	return ((binary_tree_t *)first_a);
}
