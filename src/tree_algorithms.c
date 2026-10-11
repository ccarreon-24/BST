#include <stdio.h>
#include "tree_algorithms.h"

/*
 * Este archivo contiene los ejercicios de la practica.
 *
 * Complete cada funcion sin modificar su firma.
 * Las implementaciones iniciales permiten compilar el proyecto, pero
 * NO resuelven los ejercicios.
 */

size_t treeSize(const Node *root) {
    if(root == NULL) return 0;
    return 1 + treeSize(root->left) + treeSize(root->right);
}

int maxDepth(const Node *root) {
    if(root == NULL) return 0;
    int left = maxDepth(root->left);
    int right = maxDepth(root->right);

    return 1 + (left > right ? left : right);
}

int minValue(const Node *root) {
    if(root == NULL) return 0;
    if(root->left == NULL) return root->data;

    return minValue(root->left);
}

void printTree(const Node *root) {
    if(root == NULL)
        return;
    printTree(root->left);
    printf("%d ", root->data);
    printTree(root->right);
    
}

void printPostorder(const Node *root) {
    if(root == NULL)
        return;
    printPostorder(root->left);
    printPostorder(root->right);
    printf("%d ", root->data);
}

int hasPathSum(const Node *root, int sum) {
    if(root == NULL) return 0;

    if(root->left == NULL && root->right == NULL)
        return root->data == sum ? 1 : 0;

    return hasPathSum(root->left, sum - root->data) || hasPathSum(root->right, sum - root->data);
}

static void printPathsRecur(const Node* root, int path[], int pathLen){
    if(root == NULL) return ;

    path[pathLen] = root->data;

    if(root->left == NULL && root->right == NULL){
        printa(path, pathLen + 1);
        return ;
    }
        
    printPathsRecur(root->left, path, pathLen + 1);
    printPathsRecur(root->right, path, pathLen + 1);
}

void printPaths(const Node *root) {
    int path[length(root)];
    int pathLen = 0;
    printPathsRecur(root, path, 0);
}

void mirror(Node *root) {
  (void)root;
}

int sameTree(const Node *a, const Node *b) {
  (void)a;
  (void)b;
  return 0;
}

int isBST(const Node *root) {
  (void)root;
  return 0;
}
