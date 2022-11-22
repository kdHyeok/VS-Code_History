#include <stdio.h>
#include <stdlib.h>

typedef struct TreeNode {
    int data;
    struct TreeNode *left, *right;
} TNode;

int calc_size(TNode *n){
    if (n == NULL) return 0;
    return n->data + calc_size(n->left) + calc_size(n->right);
}

void main()
{
    TNode m4 = { 200,  NULL, NULL };
    TNode m5 = { 500,  NULL,  NULL };
    TNode m3 = { 100,  &m4,  &m5 };
    TNode m2 = { 50, NULL, NULL };
    TNode root = { 0, &m2, &m3 };
    TNode *fs = &root;
    printf("폴더 용량 = %d KB\n",calc_size(fs));
}
