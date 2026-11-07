#include <stdio.h> 
#include <string.h> 
#include <assert.h> 
FILE *input; 
char preord[30],inord[30]; // Strings storing preorder traversal and inorder traversal of the tree
int read_case() //Input preorder traversal and inorder traversal of the tree 
{ 
 fscanf(input,"%s %s",preord,inord);
 if (feof(input)) return 0; 
 return 1;
} 
void recover (int preleft, int preright, int inleft, int inright) // produce the tree's postorder traversal based on preorder traversal and inorder traversal of the tree 
{ 
 int root,leftsize,rightsize;
 assert(preleft<=preright && inleft<=inright); 
 for (root=inleft; root<=inright; root++) //Calculate the root’s position 
 if (preord[preleft]==inord[root]) break;
 leftsize = root-inleft; //sizes of left subtree and right subtree
 rightsize = inright-root;
 if(leftsize>0) //left subtree 
recover(preleft+1,preleft+leftsize,inleft,root-1); 
 if(rightsize>0) //right subtree 
recover(preleft+leftsize+1,preright,root+1,inright); 
 printf("%c",inord[root]); //Output the root
} 
void solve_case() 
{ 
 int n = strlen(preord); // number of nodes 
 recover(0,n-1,0,n-1); //Output the tree's postorder traversal
 printf("\n");
} 
int main() 
{ 
 input = fopen("tree.in","r"); 
 assert(input!=NULL); 
 while (read_case()) solve_case(); 
 fclose(input); 
 return 0;
}