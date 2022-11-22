#include <stdio.h>
#include <stdlib.h>

typedef struct TreeNode {
    int data;
    struct TreeNode *left, *right;
} TNode;


TNode n1 = { 3,  NULL, NULL };
TNode n2 = { 2,  NULL,  NULL };
TNode n3 = { '*',  &n1,  &n2 };
TNode n4 = { 5, NULL, NULL };
TNode n5 = { 6, NULL, NULL };
TNode n6 = { '-', &n4,  &n5 };
TNode n7 = { '+', &n3,  &n6 };
TNode *ex = &n7;

int evaluate(TNode *root)
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
int count_node(TNode *n)
{
    if (n == NULL)
        return 0;
    return 1 + count_node(n->left) + count_node(n->right);
}

int count_leaf(TNode *n)
{
    if (n == NULL)
        return 0;
    if (n->left == NULL && n->right == NULL)
        return 1;
    else
        return count_leaf(n->left) + count_leaf(n->right);
}

int calc_height(TNode *n)
{
    int hLeft, hRight;
    if (n == NULL)
        return 0;
    hLeft = calc_height(n->left);
    hRight = calc_height(n->right);
    return (hLeft > hRight) ? hLeft + 1 : hRight + 1;
}

int main(void)
{

    // 최종 트리 정보 출력
    printf("수식 계산 결과 = %d\n", evaluate(ex));
    printf("트리의 높이 = %d\n", calc_height(ex));
    printf("노드의 수 = %d\n", count_node(ex));
    printf("단말 노드의 수 = %d\n", count_leaf(ex));

    return 0;
}