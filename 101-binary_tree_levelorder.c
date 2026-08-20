#include "binary_trees.h"

/**
 * tree_height - Measures the height of a binary tree
 * @tree: Pointer to the root node of the tree to measure
 *
 * Return: Height of the tree, or 0 if tree is NULL
 */
static size_t tree_height(const binary_tree_t *tree)
{
	size_t left_h, right_h;

	if (tree == NULL)
		return (0);

	left_h = tree_height(tree->left);
	right_h = tree_height(tree->right);

	return ((left_h > right_h ? left_h : right_h) + 1);
}

/**
 * execute_at_level - Calls func on nodes at a specific level
 * @tree: Pointer to the root node of the tree
 * @func: Pointer to the function to call for each node
 * @level: Targeted level to execute func on
 */
static void execute_at_level(const binary_tree_t *tree,
				 void (*func)(int), size_t level)
{
	if (tree == NULL)
		return;

	if (level == 1)
		func(tree->n);
	else if (level > 1)
	{
		execute_at_level(tree->left, func, level - 1);
		execute_at_level(tree->right, func, level - 1);
	}
}

/**
 * binary_tree_levelorder - Goes through a binary tree using level-order
 * @tree: Pointer to the root node of the tree to traverse
 * @func: Pointer to a function to call for each node
 */
void binary_tree_levelorder(const binary_tree_t *tree, void (*func)(int))
{
	size_t height, level;

	if (tree == NULL || func == NULL)
		return;

	height = tree_height(tree);

	for (level = 1; level <= height; level++)
		execute_at_level(tree, func, level);
}
