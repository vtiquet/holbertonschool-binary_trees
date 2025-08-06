#include "binary_trees.h"
/**
* binary_tree_height - a function that measures the height of a binary tree.
* @tree: is a pointer to the root node of the tree to measure the height.
* Return: the height of the tree, or 0 if tree is NULL.
*/
size_t binary_tree_height(const binary_tree_t *tree)
{
	size_t lh;
	size_t rh;

	if (tree == NULL)
	{
		return (0);
	}
	if ((*tree).left == NULL && (*tree).right == NULL)
	{
		return (0);
	}
	lh = binary_tree_height((*tree).left);
	rh = binary_tree_height((*tree).right);
	if (lh >= rh)
	{
		return (1 + lh);
	}
	else
	{
		return (1 + rh);
	}
}
/**
* binary_tree_balance - a function that measures the balance factor
* of a binary tree.
* @tree: is a pointer to the root node of the tree to measure
* the balance factor.
* Return: the balance factor, or 0 if tree is NULL.
*/
int binary_tree_balance(const binary_tree_t *tree)
{
	int lsh;
	int rsh;

	if (tree == NULL)
	{
		return (0);
	}
	if ((*tree).left != NULL)
	{
		lsh = (int)binary_tree_height((*tree).left);
	}
	else
	{
		lsh = -1;
	}
	if ((*tree).right != NULL)
	{
		rsh = (int)binary_tree_height((*tree).right);
	}
	else
	{
		rsh = -1;
	}
	return (lsh - rsh);
}
