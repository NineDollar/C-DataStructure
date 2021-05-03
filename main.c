#include <stdio.h>
#include "predefined.h"
#include<stdlib.h>
#include<string.h>

typedef enum {
    Link, Thread
} PointerTag; //枚举类型；

typedef struct BiThrNode //创建结点；
{
    char data;
    struct BiThrNode *lchild, *rchild;
    PointerTag LTag, RTag;
} BiThrNode, *BiThTree;

BiThTree pre;

BiThTree CreatBiTree();

void InOrderThr(BiThTree *head, BiThTree T);

void InThreading(BiThTree p);

void InOrderTraverse(BiThTree T);

int main() {
    printf("Hello World");
    fflush(stdout);
    BiThTree BT;
    BT = CreatBiTree();
    BiThTree head;
    InOrderThr(&head, BT);
    InOrderTraverse(head);
    return 0;
}

BiThTree CreatBiTree() {
    BiThTree T;
    char ch;
    printf("请输入：");
    fflush(stdout);
    scanf("%c", &ch);
    rewind(stdin);
    if (ch ==' ')
    {
        T = NULL;
    }
    else
    {
        T = (BiThTree) malloc(sizeof(BiThrNode));
        T->data = ch;
        T->LTag = Link;
        T->RTag = Link;
        printf("请输入%c的左孩子：", ch);
        fflush(stdout);
        T->lchild = CreatBiTree();
        printf("请输入%c的右孩子：", ch);
        fflush(stdout);
        T->rchild = CreatBiTree();
    }
    return T;
}

//-----------------------------------------------------------
void InOrderThr(BiThTree *head, BiThTree T) //二叉树的线索化（中序线索二叉树）
{ //在遍历过程中，如果发现某个结点的左/右指针域为空，则将它们
    (*head) = (BiThTree) malloc(sizeof(BiThrNode)); //改为指向前驱/后继结点的线索；
    pre = *head;
    (*head)->rchild = *head;
    if (T == NULL) //若二叉树为空,只有一个头结点，lchild与rchild均指向本身；
    {
        (*head)->lchild = *head;
    } else {
        pre = *head;
        (*head)->lchild = T;
        InThreading(T);
        pre->rchild = *head; //(1)表示最后一个结点；
        pre->RTag = Thread; //(2)
        (*head)->rchild = pre; //(3)
    }
}

void InThreading(BiThTree p) {
    if (p != NULL) {
        InThreading(p->lchild);
        if (p->lchild==NULL) //无左孩子且是中序序列的第一个结点，即前驱为空；
        {
            p->LTag = Thread;
            p->lchild = pre;
        }
        if (pre->rchild==NULL) //无右孩子且是中序序列的最后一个结点，即后继为空；
        {
            pre->RTag = Thread;
            pre->rchild = p;
        }
        pre = p;
        InThreading(p->rchild);
    }
}

//---------------------------------------------------

void InOrderTraverse(BiThTree T) //遍历函数；
{
    BiThTree p = T->lchild;
    while (T != p) {
        while (p->LTag==Link) {
            p = p->lchild;
        }
        printf("%c ", p->data);
        while (p->RTag==Thread && p->rchild != T) {
            p = p->rchild;
            printf("%c ", p->data);
        }
        p = p->rchild;
    }
}
