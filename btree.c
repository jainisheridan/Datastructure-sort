#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

typedef struct treeNode_def{
    int number;
    struct treeNode_def *left, *right;
} treeNode;

typedef struct {
    treeNode *root;
    int nodeCount;
} BinaryTree;

void visitNode(treeNode* node) {
    printf("%d ", node->number);
}

treeNode* createNode(int num) {
    treeNode *newNode = (treeNode*)malloc(sizeof(treeNode));
    assert(newNode);
    newNode->number = num;
    newNode->left = newNode->right = NULL;
    return newNode;
}

void preOrderTraversal(treeNode *node) {
    if (node == NULL)
        return;
    visitNode(node);
    preOrderTraversal(node->left);
    preOrderTraversal(node->right);
}

void inOrderTraversal(treeNode *node) {
    if (node == NULL)
        return;
    inOrderTraversal(node->left);
    visitNode(node);
    inOrderTraversal(node->right);
}

void postOrderTraversal(treeNode *node) {
    if (node == NULL)
        return;
    postOrderTraversal(node->left);
    postOrderTraversal(node->right);
    visitNode(node);
}

void init(BinaryTree *btree) {
    btree->root = NULL;
    btree->nodeCount = 0;
}

int main(int argc, char* argv[]) {
    BinaryTree btree;
    init(&btree);

    btree.root = createNode(10);
    btree.root->left = createNode(4);
    btree.root->right = createNode(5);
    btree.root->left->left = createNode(12);
    btree.root->left->right = createNode(8);
    btree.root->right->left = createNode(1);
    btree.root->right->right = createNode(3);
    btree.nodeCount = 7;

    printf("Pre-order Traversal:\n");
    preOrderTraversal(btree.root);
    printf("\n");

    printf("In-order Traversal:\n");
    inOrderTraversal(btree.root);
    printf("\n");

    printf("Post-order Traversal:\n");
    postOrderTraversal(btree.root);
    printf("\n");

    return 0;
}

