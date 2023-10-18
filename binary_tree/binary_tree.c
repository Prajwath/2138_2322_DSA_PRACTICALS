#include "binary_tree.h"
#include <stdio.h>
#include <stdlib.h>

void initBinaryTree(BinaryTree* tree) {
    tree->root = NULL;
}

TreeNode* createNode(int value) {
    TreeNode* node = (TreeNode*)malloc(sizeof(TreeNode));
    node->data = value;
    node->left = NULL;
    node->right = NULL;
    return node;
}

void insertNode(BinaryTree* tree, int value) {
    TreeNode* newNode = createNode(value);
    if (tree->root == NULL) {
        tree->root = newNode;
    } else {
        TreeNode* current = tree->root;
        TreeNode* parent;
        while (1) {
            parent = current;
            if (value < current->data) {
                current = current->left;
                if (current == NULL) {
                    parent->left = newNode;
                    return;
                }
            } else {
                current = current->right;
                if (current == NULL) {
                    parent->right = newNode;
                    return;
                }
            }
        }
    }
}

TreeNode* findMin(TreeNode* node) {
    while (node->left != NULL) {
        node = node->left;
    }
    return node;
}

TreeNode* deleteNodeRecursively(TreeNode* root, int value) {
    if (root == NULL) {
        return root;
    }
    if (value < root->data) {
        root->left = deleteNodeRecursively(root->left, value);
    } else if (value > root->data) {
        root->right = deleteNodeRecursively(root->right, value);
    } else {
        if (root->left == NULL) {
            TreeNode* temp = root->right;
            free(root);
            return temp;
        } else if (root->right == NULL) {
            TreeNode* temp = root->left;
            free(root);
            return temp;
        }
        TreeNode* temp = findMin(root->right);
        root->data = temp->data;
        root->right = deleteNodeRecursively(root->right, temp->data);
    }
    return root;
}

void deleteNode(BinaryTree* tree, int value) {
    tree->root = deleteNodeRecursively(tree->root, value);
}

void preorderTraversal(TreeNode* root) {
    if (root != NULL) {
        printf("%d ", root->data);
        preorderTraversal(root->left);
        preorderTraversal(root->right);
    }
}

void inorderTraversal(TreeNode* root) {
    if (root != NULL) {
        inorderTraversal(root->left);
        printf("%d ", root->data);
        inorderTraversal(root->right);
    }
}

void postorderTraversal(TreeNode* root) {
    if (root != NULL) {
        postorderTraversal(root->left);
        postorderTraversal(root->right);
        printf("%d ", root->data);
    }
}
