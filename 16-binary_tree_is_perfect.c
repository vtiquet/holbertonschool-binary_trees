#include "binary_trees.h"
/**
* get_tree_height_recursive - a function that measures the height
* of a binary tree recursively.
* @tree: is a pointer to the root node of the tree to measure the height.
* Return: the height of the tree, or 0 if tree is NULL.
*/
static size_t get_tree_height_recursive(const binary_tree_t *tree)
{
	size_t lh = 0;
	size_t rh = 0;

	if (tree == NULL)
		return (0);
	if ((*tree).left == NULL && (*tree).right == NULL)
		return (0);
	lh = get_tree_height_recursive((*tree).left);
	rh = get_tree_height_recursive((*tree).right);
	if (lh >= rh)
		return (1 + lh);
	else
		return (1 + rh);
}
/**
* get_tree_size_recursive - a function that measures the size
* of a binary tree recursively.
* @tree: is a pointer to the root node of the tree to measure the size.
* Return: the size of the tree, or 0 if tree is NULL.
*/
static size_t get_tree_size_recursive(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);
	return (1 + get_tree_size_recursive((*tree).left)
			+ get_tree_size_recursive((*tree).right));
}
/**
* binary_tree_is_perfect - a function that checks if a binary tree is perfect.
* @tree: is a pointer to the root node of the tree to check.
* Return: 0 if tree is null, 1 otherwise.
*/
int binary_tree_is_perfect(const binary_tree_t *tree)
{
	size_t height;
	size_t size;
	size_t expected_size = 1;
	size_t i = 0;

	if (tree == NULL)
	{
		return (0);
	}
	height = get_tree_height_recursive(tree);
	size = get_tree_size_recursive(tree);
	while (i < (height + 1))
	{
		expected_size = expected_size * 2;
		i++;
	}
	expected_size = expected_size - 1;
	return (size == expected_size);
}
