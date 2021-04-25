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
    Link, Thread
} PointerTag;  //Link ==0:指针，Thread == 1:线索

typedef struct BiThrNode {
    TElemType data;
    struct BiThrNode *lchild, *rchild;
    PointerTag LTag, RTag;  //左右标志
} BiThrNode, *BiThrTree;

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
        while (p->LTag == Link) {
            p = p->lchild;
        }
        if (!Visit(p->data)) {
            return ERROR;
        }
        while (p->RTag == Thread && p->lchild != t) {
            p = p->rchild;
            Visit(p->data);
        }
        p = p->rchild;
    }
    return OK;
}

/**
 * @time 2021/4/21 10:43
 * @description 中序遍历二叉树，并将其中
 * @param 
 * @return 
 */
Status InOrderThreading(BiThrTree thrt, BiThrTree t) {

    return OK;
}

int main() {

    return TRUE;
}

