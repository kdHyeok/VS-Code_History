#include <stdio.h>
#include <stdlib.h>

typedef int TElement;

typedef struct BinTrNode {
    TElement     data;
    struct BinTrNode* left;
    struct BinTrNode* right;
} TNode;
TNode*    root;

void init_tree() { root = NULL; }
int is_empty_tree() { return root == NULL; }
TNode* get_root() { return root; }

TNode* create_tree(TElement val, TNode* l, TNode* r)
{
    TNode* n = (TNode*)malloc(sizeof(TNode));
    n->data = val;
    n->left = l;
    n->right = r;
    return n;
}

//================================================================
void Preorder(TNode *n)
{
    if (n != NULL) {
        printf("[%d] ", n->data);
        Preorder(n->left);
        Preorder(n->right);
    }
}
void inorder(TNode *n)
{
    if (n != NULL) {
        inorder(n->left);
        printf("[%d] ", n->data);
        inorder(n->right);
    }
}
void Postorder(TNode *n)
{
    if (n != NULL) {
        Postorder(n->left);
        Postorder(n->right);
        printf("[%d] ", n->data);
    }
}

//================================================================
#define MAX_QUEUE_SIZE    100
typedef TNode* Element;

Element data[MAX_QUEUE_SIZE];
int    front;
int    rear;

void error(char str[])
{
    printf("%s\n", str);
    exit(1);
}
void init_queue() { front = rear = 0; ; }
int is_empty() { return front == rear; }
int is_full() { return front == (rear + 1) % MAX_QUEUE_SIZE; }
int size() { return(rear - front + MAX_QUEUE_SIZE) % MAX_QUEUE_SIZE; }

void enqueue(Element val)
{
    if (is_full())
        error("  큐 포화 에러");
    rear = (rear + 1) % MAX_QUEUE_SIZE;
    data[rear] = val;
}
Element dequeue()
{
    if (is_empty())
        error("  큐 공백 에러");
    front = (front + 1) % MAX_QUEUE_SIZE;
    return data[front];
}
Element peek()
{
    if (is_empty())
        error("  큐 공백 에러");
    return data[(front + 1) % MAX_QUEUE_SIZE];
}

void levelorder(TNode *root)
{
    TNode* n;
    
    if (root == NULL) return;
    init_queue();
    enqueue(root);
    while (!is_empty()) {
        n = dequeue();
        if (n != NULL) {
            printf("[%d] ", n->data);
            enqueue(n->left);
            enqueue(n->right);
        }
    }
}

int count_node(TNode *n)
{
    if (n == NULL) return 0;
    return 1 + count_node(n->left) + count_node(n->right);
}

int count_leaf(TNode *n)
{
    if (n == NULL) return 0;
    if (n->left == NULL && n->right == NULL) return 1;
    else return count_leaf(n->left) + count_leaf(n->right);
}

int calc_height(TNode *n)
{
    int hLeft, hRight;
    if (n == NULL) return 0;
    hLeft = calc_height(n->left);
    hRight = calc_height(n->right);
    return (hLeft>hRight) ? hLeft + 1 : hRight + 1;
}

TNode* search(TNode *n, int key)
{
    if (n == NULL) return NULL;
    else if (key == n->data) return n;
    else if (key < n->data) return search(n->left, key);
    else return search(n->right, key);
}

void search_BST(int key)
{
    TNode* n = search(root, key);
    if (n != NULL)
        printf("[탐색 연산] : 성공 [%d] = 0x%x\n", n->data, n);
    else
        printf("[탐색 연산] : 실패: No %d!\n", key);
}

int insert(TNode* r, TNode* n)
{
    if (n->data == r->data) return 0;
    else if (n->data < r->data) {
        if (r->left == NULL) r->left = n;
        else insert(r->left, n);
    }
    else {
        if (r->right == NULL) r->right = n;
        else insert(r->right, n);
    }
    return 1;
}

void insert_BST(int key)
{
    TNode* n = create_tree(key, NULL, NULL);
    if (is_empty_tree())
        root = n;
    else if (insert(root, n) == 0)
        free(n);
}

void delete (TNode *parent, TNode *node)
{
    TNode *child, *succ, *succp;
    
    // case 1
    if ((node->left == NULL && node->right == NULL)) {
        if (parent == NULL) root = NULL;
        else {
            if (parent->left == node)
                parent->left = NULL;
            else parent->right = NULL;
        }
    }
    // case 2
    else if (node->left == NULL || node->right == NULL) {
        child = (node->left != NULL) ? node->left : node->right;
        if (node == root) root = child;
        else {
            if (parent->left == node)
                parent->left = child;
            else parent->right = child;
        }
    }
    // case 3
    else {
        succp = node;
        succ = node->right;
        while (succ->left != NULL) {
            succp = succ;
            succ = succ->left;
        }
        if (succp->left == succ)
            succp->left = succ->right;
        else succp->right = succ->right;
        
        node->data = succ->data;
        node = succ;
    }
    free(node);
}

void delete_BST(int key)
{
    TNode *parent = NULL;
    TNode *node = root;
    
    if (node == NULL) return;
    while (node != NULL && node->data != key) {
        parent = node;
        node = (key < node->data) ? node->left : node->right;
    }
    if (node == NULL)
        printf(" Error: key is not in the tree!\n");
    else delete (parent, node);
}

//=================================================================
#define max(a,b)    (((a) > (b)) ? (a) : (b))

TNode* rotate_LL(TNode *parent) {
    TNode *child = parent -> left;
    parent -> left = child -> right;
    child -> right = parent;
    return child;
}

TNode* rotate_RR(TNode *parent) {
    TNode *child = parent->right;
    parent -> right = child -> left;
    child -> left = parent;
    return child;
}

TNode* rotate_RL(TNode *parent) {
    TNode *child = parent -> right;
    parent -> right = rotate_LL(child);
    return rotate_RR(parent);
}

TNode* rotate_LR(TNode *parent) {
    TNode *child = parent -> left;
    parent -> left = rotate_RR(child);
    return rotate_LL(parent);
}

int get_height(TNode *node) {
    int height = 0;
    if(node != NULL)
        height = 1+max(get_height(node -> left),get_height(node -> right));
    return height;
}

int get_balance(TNode *node) {
    if(node == NULL) return 0;
    return get_height(node -> left) - get_height(node -> right);
}

TNode* balance_tree(TNode **node) {
    int height_diff= get_balance(*node);
     
    if(height_diff > 1) // 왼쪽 서브트리의 균형을 맞춘다
    {
        if(get_balance((*node) -> left) > 0)
            *node = rotate_LL(*node);
        else
            *node = rotate_LR(*node);
    }
    else if(height_diff < -1) // 오른쪽 서브트리의 균형을 맞춘다
    {
        if(get_balance((*node) -> right) < 0)
            *node = rotate_RR(*node);
        else
            *node = rotate_RL(*node);
    }
    return *node;
}

TNode* insert_node_AVL(TNode **root,int key) {
    if(*root == NULL)
    {
        *root = (TNode*)malloc(sizeof(TNode));
        if(*root == NULL)
        {
            printf("메모리 할당 실패\n");
            exit(-1);
        }

        (*root) -> data = key;
        (*root) -> left = (*root) -> right = NULL;
    }
    else if(key < (*root) -> data)
    {
        (*root) -> left = insert_node_AVL(&((*root) -> left),key);
        (*root) = balance_tree(root);
    }
    else if(key > (*root) -> data)
    {
        (*root) -> right = insert_node_AVL(&((*root) -> right), key);
        (*root) = balance_tree(root);
    }
    else
    {
        printf("중복 키로 인한 삽입 실패\n");
        exit(-1);
    }
    return *root;
}

int main() {
    
    TNode* root;
    printf("202052016 김동혁\n\n");

    root = create_tree(30, NULL, NULL); printf("\nAVL(30) : ");  levelorder(root);
    root = insert_node_AVL(&root, 40);   printf("\nAVL(40) : ");  levelorder(root);
    root = insert_node_AVL(&root, 100);  printf("\nAVL(100) : "); levelorder(root);
    root = insert_node_AVL(&root, 20);   printf("\nAVL(20) : ");  levelorder(root);
    root = insert_node_AVL(&root, 10);   printf("\nAVL(10) : ");  levelorder(root);
    root = insert_node_AVL(&root, 60);   printf("\nAVL(60) : ");  levelorder(root);
    root = insert_node_AVL(&root, 70);   printf("\nAVL(70) : ");  levelorder(root);
    root = insert_node_AVL(&root, 120);  printf("\nAVL(120) : "); levelorder(root);
    root = insert_node_AVL(&root, 110);  printf("\nAVL(110) : "); levelorder(root);
    
    printf("\n 노 드 의  개 수 = %d\n", count_node(root));
    printf(" 단 말 의  개 수 = %d\n", count_leaf(root));
    printf(" 트 리 의  노 드 = %d\n", calc_height(root));
    return 0;
}