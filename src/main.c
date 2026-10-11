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
    
    Node* bs = insert(NULL, 12);
    bs = insert(bs, 10);
    bs = insert(bs, 20);
    bs = insert(bs, 21);

    Node* bn = insert(NULL, 10);
    bn->right = newNode(12);
    bn->right->right = newNode(20);
    bn->right->right->right = newNode(21);

    printf("Ambos vacios: %d\n", sameTree(vacio1, vacio2));
    printf("Uno vacio el otro no: %d\n", sameTree(p1, vacio1));
    printf("Mismas claves diferentes estructuras: %d\n", sameTree(tree1, tree2));
    printf("Misma estructura pero diferentes datos : %d\n", sameTree(comp1, comp2));
    printf("Arboles iguales: %d\n", sameTree(eq1, eq2));
    
    printf("Recorrido inorder: ");
    printTree(bs);
    printf("\n");
    printTree(bn);
    printf("\n");

    printf("comparando: %d\n", sameTree(bs, bn));
    freeTree(vacio1);
    freeTree(vacio2);
    freeTree(p1);
    freeTree(tree1);
    freeTree(tree2);
    freeTree(comp1);
    freeTree(comp2);
    freeTree(eq1);
    freeTree(eq2);

    freeTree(bs);
    freeTree(bn);
}

void GeneralTrees(void){
    Node* vo = NULL;
    Node* one = newNode(1);

    Node* t1 = newNode(2);
    t1 = insert(t1, 1);

    Node* t2 = newNode(7);
    t2 = insert(t2, 9);


    Node* r1 = newNode(1);
    r1 = insert(r1, 2);
    r1 = insert(r1, 3);
    r1 = insert(r1, 4);
    r1 = insert(r1, 5);

    Node* r2 = newNode(5);
    r2 = insert(r2, 4);
    r2 = insert(r2, 3);
    r2 = insert(r2, 2);
    r2 = insert(r2, 1);

    Node* r3 = newNode(3);
    r3 = insert(r3, 2);
    r3 = insert(r3, 5);
    r3 = insert(r3, 1);
    r3 = insert(r3, 4);

    Node* n1 = newNode(10);
    n1 = insert(n1, 10);
    n1 = insert(n1, 27);
    n1 = insert(n1, 2);
    n1 = insert(n1, 29);
    n1 = insert(n1, 5);

    Node* balanced = newNode(3);
    balanced = insert(balanced, 2);
    balanced = insert(balanced, 5);
    balanced = insert(balanced, 1);
    balanced = insert(balanced, 6);
    balanced = insert(balanced, 7);
    balanced = insert(balanced, 4);

    printf("Arboles generales: \n");
    printf("Nodos y profundidad(n1): %zu %d \n", treeSize(n1), maxDepth(n1));
    printf("Inorder, postorder: ");
    printTree(r3);
    printf("\n");
    printPostorder(r3);
    printf("\n");

    printf("Suma 6 en balanced: %d\n",hasPathSum(balanced, 6));
    printf("Caminos hasta las hojas en balanced: \n");
    printPaths(balanced);
    printf("\n");
    printf("Arbol degenerado izquierdo r2: ");
    printTree(r2);
    printf("\n");
    mirror(r2);
    printf("Mirror a r2: ");
    printTree(r2);
    printf("\n");
    printf("Comparando arboles degenerados r1, r2: %d\n", sameTree(r1, r2));

    mirror(r2);
    
    printf("Aplicar mirror 2 veces al balanceado \n");
    printf("Arbol balanceado: ");
    printTree(balanced);
    printf("\n");
    mirror(balanced);
    printf("Mirror 1 vez: ");
    printTree(balanced);
    printf("\n");
    printf("Mirror 2 vez: ");
    mirror(balanced);
    printTree(balanced);
    printf("\n");



    freeTree(vo);
    freeTree(one);
    freeTree(t1);
    freeTree(t2);
    freeTree(r1);
    freeTree(r2);
    freeTree(r3);
    freeTree(n1);
    freeTree(balanced);
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
   GeneralTrees();
  freeTree(root);
  return EXIT_SUCCESS;
}
