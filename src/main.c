#include <stdio.h>
#include <stdlib.h>
#include "tree.h"
#include "tree_algorithms.h"

static Node *buildExample(void) {
  const int values[] = {5, 3, 9, 1, 4, 6};
  const size_t n = sizeof values / sizeof values[0];

  Node *root = NULL;

  for(size_t i = 0; i < n; ++i) {
    Node *newRoot = insert(root, values[i]);

    if(newRoot == NULL) {
      freeTree(root);
      return NULL;
    }

    root = newRoot;
  }

  return root;
}

static void Comparaciones(void){
    Node* vacio1 = NULL;
    Node* vacio2 = NULL;

    Node* p1 = newNode(3);

    Node* tree1 = insert(NULL, 6);
    tree1 = insert(tree1, 5);
    tree1 = insert(tree1, 9);

    Node* tree2 = insert(NULL, 6);
    tree2->left = newNode(9);
    tree2->right = newNode(5);

    Node* comp1 = insert(NULL, 6);
    comp1 = insert(comp1, 4);
    comp1 = insert(comp1, 9);

    Node* comp2 = insert(NULL, 6);
    comp2  = insert(comp2, 2);
    comp2 = insert(comp2, 9);

    Node* eq1 = insert(NULL, 10);
    eq1 = insert(eq1, 12);
    eq1 = insert(eq1, 1);
    eq1 = insert(eq1, 5);
    eq1 = insert(eq1, 23);

    Node* eq2 = insert(NULL, 10);
    eq2 = insert(eq2, 12);
    eq2 = insert(eq2, 1);
    eq2 = insert(eq2, 5);
    eq2 = insert(eq2, 23);

    printf("Ambos vacios: %d\n", sameTree(vacio1, vacio2));
    printf("Uno vacio el otro no: %d\n", sameTree(p1, vacio1));
    printf("Mismas claves diferentes estructuras: %d\n", sameTree(tree1, tree2));
    printf("Misma estructura pero diferentes datos : %d\n", sameTree(comp1, comp2));
    printf("Arboles iguales: %d\n", sameTree(eq1, eq2));

    freeTree(vacio1);
    freeTree(vacio2);
    freeTree(p1);
    freeTree(tree1);
    freeTree(tree2);
    freeTree(comp1);
    freeTree(comp2);
    freeTree(eq1);
    freeTree(eq2);
}


static Node* build123(void){
    Node* root = newNode(2);
    root->left = newNode(1);
    root->right = newNode(3);
    return root;
}

static Node* build1232(void){
    Node* root = NULL;
    root = insert(root, 2);
    root = insert(root, 1);
    root = insert(root, 3);
    return root;
}

int main(void) {
  Node *root = buildExample();

  if(root == NULL) {
    fprintf(stderr, "No se pudo construir el arbol.\n");
    return EXIT_FAILURE;
  }
    Node* p1 = build123();
    Node* p2 = build1232();
   printf("size = %zu\n", treeSize(root));
   printf("maxDepth = %d\n", maxDepth(root));
   printf("minValue = %d\n", minValue(root));
   
   printf("inorder: ");
   printTree(root);
   printf("\n");
   printf("inorder arboles de prueba: ");
   printTree(p1);
   printf("\n");
   printTree(p2);
   printf("\n");
   
   printf("postorder: ");
   printPostorder(root);
   printf("\n");
   printf("postorder otros arboles: ");
   printPostorder(p1);
   printf("\n");
   printPostorder(p2);
   printf("\n");
   

   Comparaciones();
  freeTree(root);
  return EXIT_SUCCESS;
}
