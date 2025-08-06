#include "binary_trees.h"
/**
* binary_tree_uncle - a function that finds the uncle of a node.
* @node: is a pointer to the node to find the uncle.
* Return: a pointer to the uncle node.
*/
binary_tree_t *binary_tree_uncle(binary_tree_t *node)
{
	if (node == NULL || (*node).parent == NULL)
	{
		return (NULL);
	}
	return (binary_tree_sibling((*node).parent));
}
