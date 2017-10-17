///\file main.c
///\brief Main function of the program.
///
#include <stdio.h>///> printf() , scanf()
#include "head.h"///> insert() , Delete() , search() , rootLeftRight() , leftRootRight() , leftRightRoot()

int main() {
    ///\fn int main()
    ///\brief Main function.
    /// Function calls of insert, Delete, search, rootLeftRight, leftRootRight and leftRightRoot imported from head.h
    ///\var lo element that i want to search
    ///\var del element that i want to delete
    ///\var c variable to choose a operation
    int lo, del, c;
    int biggestNumber, maxNumbers;

    nod *new_node, *root, *tmp, *parent;
    nod *get_node();

    root = NULL;

    printf("\n\tBinary search trees (BST)\n");
    //selecting an option
    do {
      printf("\n 1. Create a BST from the file");
      printf("\n 2. Delete a node");
      printf("\n 3. Search for a node");
      printf("\n 4. Recursive traversals");
      printf("\n 5. Generate random numbers to file");
      printf("\n 6. Exit\n");
      printf("\n Enter your choice : ");
      scanf("%d", &c);
      FILE *fi;
      fi = fopen ("f.in","r+");

      switch (c) {
      //in case 1 we call function insert
      case 1:

         while(!feof(fi))
         {
            new_node = get_node();
            fscanf(fi,"%d", &new_node->data);

            if (!feof(fi))
            {
                if (root == NULL)
                    root = new_node;
                else
                    insert(root, new_node);
            }
         }
         printf("\n The BST has been created!\n");
         break;

      //in case 2 we call function Delete
      case 2:

        if (root == NULL)
            printf("\n No tree found.\n");
        else
        {
        printf("\n Enter element to be deleted : ");
        scanf("%d", &del);

        Delete(root,del);

        printf("\n The node has been deleted!\n");
        }
        break;

      //in case 3 we call function search
      case 3:

         if (root == NULL)
            printf("\n No tree found.\n");
         else
         {
         printf("\n Enter element to be searched : ");
         scanf("%d", &lo);

         tmp = search(root, lo, &parent);
         }
         break;

      //in case 4 we call function rootLeftRight, leftRootRight, leftRightRoot
      case 4:
         if (root == NULL)
            printf("\n No tree found.\n");
         else
         {
            printf("\n The preorder (Root-Left-Right) display : ");
            rootLeftRight(root);
            printf("\n The inorder (Left-Root-Right) display : ");
            leftRootRight(root);
            printf("\n The postorder (Left-Right-Root) display : ");
            leftRightRoot(root);
            printf("\n");
         }
         break;
      case 5:
            printf("\nHow many numbers do you want to generate: ");
            scanf("%d", &maxNumbers);
            printf("\nWhich is the largest number you want to generate: ");
            scanf("%d", &biggestNumber);
            generateNumbersToFile(fi, maxNumbers, biggestNumber);
      }
      fclose(fi);
   } while (c != 6);

   return 0;
}
