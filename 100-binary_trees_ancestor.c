#include "binary_trees.h"

/**
 * binary_trees_ancestor - Finds the lowest common ancestor of two nodes
 * @first: Pointer to the first node
 * @second: Pointer to the second node
 *
 * Return: Pointer to the lowest common ancestor, or NULL if non-existant
 */
binary_tree_t *binary_trees_ancestor(const binary_tree_t *first, const binary_tree_t *second)
{
    const binary_tree_t *first_ancestor = first, *second_ancestor = second;
    
    if (first == NULL || second == NULL)
        return (NULL);

    while (first_ancestor != second_ancestor)
    {
        first_ancestor = (first_ancestor == NULL) ? second : first_ancestor->parent;
        second_ancestor = (second_ancestor == NULL) ? first : second_ancestor->parent;
    }
    return ((binary_tree_t *)first_ancestor);
}