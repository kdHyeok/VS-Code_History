#include <stdio.h>
#include <stdlib.h>

typedef struct TreeNode {
    int data;
    struct TreeNode *left, *right;
} TreeNode;
//             +
//         *         -
//    3       2   5     6
TreeNode n1 = { 3,  NULL, NULL };
TreeNode n2 = { 2,  NULL,  NULL };
TreeNode n3 = { '*',  &n1,  &n2 };
TreeNode n4 = { 5, NULL, NULL };
TreeNode n5 = { 6, NULL, NULL };
TreeNode n6 = { '-', &n4,  &n5 };
TreeNode n7 = { '+', &n3,  &n6 };
TreeNode *ex = &n7;

// 수식 계산 함수
int evaluate(TreeNode *root)
{
    if (root == NULL)
        return 0;
    if (root->left == NULL && root->right == NULL)
        return root->data;
    else {
        int op1 = evaluate(root->left);
        int op2 = evaluate(root->right);
        switch (root->data) {
            case '+':
                return op1 + op2;
            case '-':
                return op1 - op2;
            case '*':
                return op1 * op2;
            case '/':
                return op1 / op2;
        }
    }
    return 0;
}

int calc_height(TreeNode *root){
    int hLeft, hRight;
    if(root == NULL)
        return 0;
    hLeft = calc_height(root -> left);
    hRight = calc_height(root -> right);
    return (hLeft > hRight) ? hLeft + 1 : hRight + 1;
}

int count_node(TreeNode *root){
    if(root == NULL)
        return 0;
    return 1 + count_node(root -> left) + count_node(root -> right);
}

int count_leaf(TreeNode *root){
    if(root = NULL)
        return 0;
    if(root -> left == NULL && root -> right == NULL)
        return 1;
    else return count_leaf(root -> left) + count_leaf(root -> right);
}
//
int main()
{
    printf("수식 계산 결과 = %d\n", evaluate(ex));
    printf("트리의 높이 = %d\n", calc_height(ex));
    printf("노드의 수 = %d\n", count_node(ex));
    printf("단말 노드의 수 = %d\n", count_leaf(ex));
    return 0;
}