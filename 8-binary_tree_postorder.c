#include "binary_trees.h"
/**
 * binary_tree_inorder - Traverses a binary tree in in-order
 * @tree: Pointer to the root node of the tree
 * @func: Pointer to a function that prints a number
 */
void binary_tree_postorder(const binary_tree_t *tree, void (*func)(int))
{
	if (tree == NULL || func == NULL)
		return;

	binary_tree_postorder(tree->left, func);
	binary_tree_postorder(tree->right, func);
	func(tree->n);
}
    