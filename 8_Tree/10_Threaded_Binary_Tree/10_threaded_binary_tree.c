//
// Created by Nine_Dollar on 2021/4/21.
//
/**
 * p: 线索二叉树,134页
 */
#include "stdio.h"
#include "stdlib.h"
#include "predefined.h"

typedef char TElemType;
typedef enum PointerTag {
    Link, Thread //Link ==0:指针，Thread == 1:线索
} PointerTag;

typedef struct BiThrNode {
    TElemType data;
    struct BiThrNode *lchild, *rchild;
    PointerTag LTag, RTag;  //左右标志
} BiThrNode, *BiThrTree;
BiThrTree pre;

/**
 * @time 2021/5/3 14:38
 * @description 创建线索二叉树，初始标志与设置为指针
 * @param
 * @return
 */
BiThrTree CreatBiTree() {
    BiThrTree T;
    char ch;
    scanf("%c", &ch);
    rewind(stdin);
    if (ch == ' ') {
        T = NULL;
    } else {
        T = (BiThrTree) malloc(sizeof(BiThrNode));
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

/**
 * @time 2021/4/21 10:40
 * @description 非递归中序遍历线索二叉树
 * @param 
 * @return
 */
Status InorderTraverse_Thr(BiThrTree t, Status(*Visit)(TElemType e)) {
    BiThrTree p;
    p = t->lchild;
    while (p != t) {
        while (p->LTag == Link) {  //指针,表示指向左孩子
            p = p->lchild;
        }
        if (!Visit(p->data)) {  //输出左孩子
            return ERROR;
        }
        while (p->RTag == Thread && p->rchild != t) {  //线索,便是后继,即为最左边孩子的双亲结点,如果是指针,说明有孩子
            p = p->rchild;  //中间节点
            Visit(p->data); //访问后继节点
        }
        p = p->rchild;
    }
    return OK;
}

/**
 * @time 2021/5/3 14:37
 * @description 线索化
 * @param
 * @return
 */
void InThreading(BiThrTree p) {
    if (p) {
        InThreading(p->lchild);
        if (!p->lchild) {
            p->LTag = Thread;
            p->lchild = pre;
        }
        if (!pre->rchild) {
            pre->RTag = Thread;
            pre->rchild = p;
        }
        pre = p;
        InThreading(p->rchild);
    }
}

/**
 * @time 2021/4/21 10:43
 * @description 中序遍历二叉树，并将其中中序线索化，thrt指向头节点
 * @param 
 * @return 
 */
Status InOrderThreading(BiThrTree *thrt, BiThrTree t) {
    if (!(*thrt = (BiThrTree) malloc(sizeof(BiThrNode)))) {
        exit(OVERFLOW);
    }
    (*thrt)->LTag = Link;
    (*thrt)->RTag = Thread;
    (*thrt)->rchild = *thrt;
    if (!t) {
        (*thrt)->lchild = *thrt;
    } else {
        (*thrt)->lchild = t;
        pre = *thrt;
        InThreading(t);
        pre->rchild = *thrt;
        pre->RTag = Thread;
        (*thrt)->rchild = pre;
    }
    return OK;
}

Status PrintElement(TElemType e) {
    printf("%c\t", e);
    return OK;
}

int main() {
    BiThrTree BT;
    BiThrTree head;
    printf("请输入：");
    fflush(stdout);
    BT = CreatBiTree();
    InOrderThreading(&head, BT);
    InorderTraverse_Thr(head, PrintElement);
    return TRUE;
}

