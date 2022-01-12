#include<stdio.h>
#include<stdlib.h>

typedef struct {
int key;
} TItem;
typedef struct Node* BST;
typedef struct Node {
TItem Item;
BST left, right;
} Node;

BST BST_search(BST No, int x);
int BST_insert(BST *pRaiz, TItem x);
int BST_remove(BST *pRaiz, int x);
void BST_predecessor(BST *q, BST *r);
void BST_sucessor(BST *q, BST *r);
BST BST_create();
BST BST_createNode(TItem x, BST left, BST right);
void preOrder(BST No);

int main()
{
    int n,i;
    TItem k;
    int search;
    BST raiz;
    raiz = BST_create();

    scanf("%d", &n);

    scanf("%d", &k);
    raiz = BST_createNode(k, NULL, NULL);

    for(i=0; i<n-1; i++)
    {
        scanf("%d", &k);

        BST_insert(&raiz, k);

    }
    scanf("%d", &search);
    if(BST_remove(&raiz, search)==1) preOrder(raiz);
    else{
        k.key = search;
        BST_insert(&raiz, k);
        preOrder(raiz);
    }
    return 0;
}

BST BST_create()
{
return NULL;
}

BST BST_createNode(TItem x, BST left, BST right)
{
BST No;
No = (BST) malloc(sizeof(Node));
No->Item = x;
No->left = left;
No->right = right;
return No;
}

BST BST_search(BST root, int x)
{
    BST No;
    No = root;
    while ((No != NULL) && (x != No->Item.key))
    {
        if (x < No->Item.key) No = No->left;
        else if (x > No->Item.key) No = No->right;
    }
    return No;
}

int BST_insert(BST *pr, TItem x)
{
    BST *pNo;
    pNo = pr;

    while ((*pNo != NULL) && (x.key != (*pNo)->Item.key))
    {
    if (x.key < (*pNo)->Item.key) pNo = &(*pNo)->left;
    else if (x.key > (*pNo)->Item.key) pNo = &(*pNo)->right;
    }
    if (*pNo == NULL)
    {
    *pNo = BST_createNode(x, BST_create(), BST_create());
    return 1;
    }
    return 0;
}

int BST_remove(BST *pr, int x)
{
    BST *p, q;
    p = pr;
    while ((*p != NULL) && (x != (*p)->Item.key))
    {
    if (x < (*p)->Item.key) p = &(*p)->left;
    else if (x > (*p)->Item.key) p = &(*p)->right;
    }
    if (*p != NULL)
    {
        q = *p;
        if (q->left == NULL){
            *p = q->right;
            return 1;
        }
        else if (q->right == NULL){
            *p = q->left;
            return 1;
        }
        else
        {
            BST_sucessor(&q, &q->right);
            free(q);
            return 1;
        }
    }
    return 0;
}

void BST_predecessor(BST *q, BST *r)
{
    if ((*r)->right != NULL) BST_predecessor(q, &(*r)->right);
    else
    {
        (*q)->Item = (*r)->Item;
        *q = *r;
        *r = (*r)->left;
    }
}

void BST_sucessor(BST *q, BST *r)
{
    if ((*r)->left != NULL) BST_sucessor(q, &(*r)->left);
    else
    {
        (*q)->Item = (*r)->Item;
        *q = *r;
        *r = (*r)->right;
    }
}

void preOrder(BST No)
{
    if (No != NULL)
    {
    printf("(%d",No->Item.key);
    preOrder(No->left);
    preOrder(No->right);
    printf(")");
    }
    else printf("()");
}

