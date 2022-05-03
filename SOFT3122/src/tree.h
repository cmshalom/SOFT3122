/*
 * tree.h
 *
 *  Created on: 3 May 2022
 *      Author: cmshalom
 */

#ifndef TREE_H_
#define TREE_H_

struct tree_node;
typedef struct tree_node TREE;

extern TREE *tree_create(int i); // Creates a tree with a single value i
extern TREE *tree_add(TREE *t, int i); // Returns a pointer to the newly added node
extern TREE *tree_find(TREE *t, int i); // Returns NULL if not found
extern int tree_value(TREE *t); // Returns the value in the root node of t
extern void tree_print_inorder(TREE *t);
extern void tree_print_postorder(TREE *t);
extern void tree_delete(TREE *t); // Deletes the entire tree and frees-up memory

#endif /* TREE_H_ */
