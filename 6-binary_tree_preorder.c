#include "binary_trees.h"
/**
 * binary_tree_preorder - Traverses a binary tree in pre-order
 * @tree: Pointer to the root node of the tree
 * @func: Pointer to a function that prints a number
 */
void binary_tree_preorder(const binary_tree_t *tree, void (*func)(int))
{
    if (tree == NULL || func == NULL)
        return;

    func(tree->n);
    binary_tree_preorder(tree->left, func);
    binary_tree_preorder(tree->right, func);
}