///\file functions.c
///\brief Functions for main.
///
///
///
#include <stdio.h>
#include <malloc.h>
#include "head.h"


//function to generate random numbers
void generateNumbersToFile(FILE* f, unsigned int maxLines, unsigned int maxNumber)
{
    f = fopen ("f.in","w");
    ///\fn generateNumbersToFile()
    ///\brief generating random numbers to file
    ///@param maxLines is for telling the function how many numbers we want to generate
    ///@param maxNumber is the biggest number it can be found in that file.

    int i, numbers, counter = 0;

    for(numbers = 0; numbers < maxLines; numbers++){
            fprintf(f , "%d ", rand() % maxNumber + 1);
            counter++;
    }
    printf("\nNumbers have been generated.", counter, numbers);
    fclose(f);
}

//function to create a new node dynamically
nod *get_node()
{
   ///\fn *get_node()
   ///\brief allocate a new node
   ///
   ///\var aux is auxiliary value to create a new node
   nod *aux;
   aux = (nod *) malloc(sizeof(nod));
   aux->left_child = NULL;
   aux->right_child = NULL;
   return aux;
}

//function to find minimum in a tree
nod *min(nod* root)
{
    ///\fn *min(nod* root)
    ///\brief return address of root
    ///\param root the root of binary tree
    ///
	while(root->left_child != NULL)
        root = root->left_child; //change root to the left_child

	return root; //return address of root
}

//function to delete a value from tree
struct nod* Delete(struct nod *root, int data)
{

    ///\fn nod* Delete(struct nod *root, int data)
    ///\brief delete a node
    ///\param root is the root of the tree
    ///\param data is the item to be deleted
    ///
    ///\var aux used to traverse a tree in order to delete
    if (root == NULL) // empty tree
        return root;

    else if (data < root->data) //look to delete the node in left children
        root->left_child = Delete(root->left_child,data);
    else if (data > root->data) //look to delete the node in right children
        root->right_child = Delete(root->right_child,data);
    else
    {
        if(root->left_child == NULL && root->right_child == NULL) //no child
        {
            free(root); //delete the node
            root = NULL; //set root to null
        }
        //one child
        else if(root->left_child == NULL)
        {
            struct nod *aux = root; //store address of node we want to delete in a aux
            root = root->right_child; //set right_child the root of this subtree
            free(aux); //delete the node
        }
        else if(root->right_child == NULL)
        {
            struct nod *aux = root; //store address of node we want to delete in a aux
            root = root->left_child; //set left_child the root of this subtree
            free(aux); //delete the node
        }
        //2 children
        else
        {
            struct nod* aux = min(root->right_child); //min returns address of the node in aux searching for min in right subtree.
            root->data = aux->data; //set the root with min value
            root->right_child = Delete(root->right_child,aux->data); //delete min from the right subtree
        }
    }
    return root; //return adress of root
}

//insert data in BST
void insert(nod *root, nod *new_node)
{
   ///\fn insert(nod *root, nod *new_node)
   ///\brief insert a node in to the tree
   ///\param root is the root of the tree
   ///\param new_node is the node we want to add to the tree
   ///
   if (new_node->data < root->data) //call function with the left child as root
   {
      if (root->left_child == NULL)
         root->left_child = new_node;
      else
         insert(root->left_child, new_node);
   }

   if (new_node->data > root->data) //call function with the right child as root
   {
      if (root->right_child == NULL)
         root->right_child = new_node;
      else
         insert(root->right_child, new_node);
   }
}

//search an element in BST
void *search(nod *root, int lo, nod **parent)
{
    ///\fn *search(nod *root, int lo, nod **parent)
    ///\brief return the value we search for or it returns null if it does not find the value
    ///\param parent variable used to return by address the parent of node searched
    ///\param root is the root of the tree
    ///
    ///\var aux is used to search for specific value
    nod *aux;
    aux = root;
    int temp;
    while (aux != NULL)
        {
            if (aux->data == lo)
            {
                printf("\n Node %d is in the tree. ", aux->data);
                printf(" Parent of node %d is %d.\n", aux->data, temp);
                return;
            }

            *parent = aux;
            temp = aux->data;

            if (aux->data > lo)
                aux = aux->left_child; //if node we want to search is lower than actual root, it will be in left children
            else
                aux = aux->right_child; //if node we want to search is higher than actual root, it will be in right children
        }
        printf("\n The element you are searching for is not part of the tree.");
   return;
}

void rootLeftRight(nod *aux)
{
   ///\fn rootLeftRight(nod *aux)
   ///\brief print preorder traversal sequence
   ///\param aux variable used to traverse the tree
   ///
   if (aux != NULL) {
      printf("%d ", aux->data); //display the data part of the node
      rootLeftRight(aux->left_child); //traverse the left subtree by recursively calling the rootLeftRight function
      rootLeftRight(aux->right_child); //traverse the right subtree by recursively calling the rootLeftRight function
   }
}

void leftRootRight(nod *aux)
{
   ///\fn leftRootRight(nod *aux)
   ///\brief print inorder traversal sequence
   ///\param aux variable used to traverse the tree
   ///
   if (aux != NULL) {
      leftRootRight(aux->left_child); //traverse the left subtree by recursively calling the leftRootRight function
      printf("%d ", aux->data); //display the data part of the node
      leftRootRight(aux->right_child); //traverse the right subtree by recursively calling the leftRootRight function
   }
}

void leftRightRoot(nod *aux)
{
   ///\fn leftRightRoot(nod *aux)
   ///\brief print postorder traversal sequence
   ///\param aux variable used to traverse the tree
   ///
   if (aux != NULL) {
      leftRightRoot(aux->left_child); //traverse the left subtree by recursively calling the leftRightRoot function
      leftRightRoot(aux->right_child); //traverse the right subtree by recursively calling the leftRightRoot function
      printf("%d ", aux->data); //display the data part of the node
   }
}
