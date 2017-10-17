///\file head.h
///\brief This is the header file.
///
#ifndef HEAD_H_INCLUDED
#define HEAD_H_INCLUDED

//defining the node in bst
typedef struct nod {
   int data;
   struct nod *left_child;
   struct nod *right_child; //defining the node in bst
} nod;


void generateNumbersToFile(FILE* f, unsigned int maxLines, unsigned int maxNumber);
void insert(nod *root, nod *new_nod);
nod *Delete(nod *root, int);
nod *min(nod* root);
void *search(nod *root, int lo, nod **parent);
void rootLeftRight(nod *aux);
void leftRootRight(nod *aux);
void leftRightRoot(nod *aux);

#endif // HEAD_H_INCLUDED
