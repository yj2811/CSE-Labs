#include <stdio.h>
#include <stdlib.h>
#include "bt.h"

int diameter=-1;

int max(int a, int b){
  return a>b?a:b;
}


int getDiameter(node* root){
    if (root == NULL) {
        return 0;
    }

    int left_height = getDiameter(root->left);
    int right_height = getDiameter(root->right);

    int max_diameter = left_height + right_height + 1;
    diameter = max(diameter, max_diameter);


    return max(left_height, right_height) + 1;
}

int Diameter(node* root)
{
    getDiameter(root);

    return diameter;
}



int main(){
  bt();
  printf("The diameter of the tree is %d. \n", Diameter(root));
  return 0;
}
