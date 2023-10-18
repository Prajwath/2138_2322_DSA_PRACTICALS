#ifndef BINARY_TREE_H
#define BINARY_TREE_H

typedef struct TreeNode {
    int data;
    struct TreeNode* left;
    struct TreeNode* right;
} TreeNode;

typedef struct {
    TreeNode* root;
} BinaryTree;

void initBinaryTree(BinaryTree* tree);
void insertNode(BinaryTree* tree, int value);
void deleteNode(BinaryTree* tree, int value);
void preorderTraversal(TreeNode* root);
void inorderTraversal(TreeNode* root);
void postorderTraversal(TreeNode* root);

#endif
