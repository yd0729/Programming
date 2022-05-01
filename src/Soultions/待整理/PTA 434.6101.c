// https://pintia.cn/problem-sets/434/problems/6101

#include <stdio.h>
#include <stdlib.h>

#define MAXN 30
typedef int ElementType;

typedef struct TNode *Position;
typedef Position BinTree; /* 二叉树类型 */
struct TNode {            /* 树结点定义 */
    ElementType Data;     /* 结点数据 */
    BinTree Left;         /* 指向左子树 */
    BinTree Right;        /* 指向右子树 */
};

BinTree BuildTree(int Inorder[], int Postorder[], int N);
void PreorderTraversal(BinTree BT);
void freeTree(BinTree T);

int main() {
    BinTree T;
    int Inorder[MAXN] = {0}, Postorder[MAXN] = {0}, N, i;

    scanf("%d", &N);
    for (i = 0; i < N; i++)
        scanf("%d", &Postorder[i]);
    for (i = 0; i < N; i++)
        scanf("%d", &Inorder[i]);
    T = BuildTree(Inorder, Postorder, N);
    printf("Preorder:");
    PreorderTraversal(T);
    printf("\n");

    freeTree(T);
    return 0;
}

BinTree BuildTree(int Inorder[], int Postorder[],
                  int N) { /* 根据中序和后序数组中的 N 个结点建树 */
    BinTree T;
    int p;

    if (!N)
        return NULL; /* 递归终止条件：空树 */

    T = (BinTree)malloc(sizeof(struct TNode));
    T->Data = Postorder[N - 1]; /* 根结点是后序最后一个 */
    T->Left = T->Right = NULL;

    for (p = 0; p < N; p++) /* 在中序里找根结点 */
        if (Inorder[p] == Postorder[N - 1])
            break;

    T->Left = BuildTree(Inorder, Postorder, p);
    T->Right = BuildTree(Inorder + p + 1, Postorder + p, N - p - 1);

    return T;
}

void PreorderTraversal(BinTree T) {
    if (T) {
        printf(" %d", T->Data);
        PreorderTraversal(T->Left);
        PreorderTraversal(T->Right);
    }
}

void freeTree(BinTree T) {
    if (T == NULL) {
        return;
    }
    freeTree(T->Left);
    freeTree(T->Right);
    free(T);
}