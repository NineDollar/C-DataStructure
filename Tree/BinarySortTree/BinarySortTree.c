//
// Created by Nine_Dollar on 2021/4/27.
//
/**
 * p: 二叉排序树插入、生成、删除、查找
 */

#include "stdio.h"
#include "predefined.h"
#include "malloc.h"

typedef struct Node {
    int key;
    struct Node *lchild, *rchild;
} BSTNode;

/**
 * @time 2021/4/27 11:37
 * @description 二叉排序树中不存在关键字等于key的记录，插入该记录(递归)
 * @param  key：插入记录值
 * @return
 */
void InsertBst(BSTNode **bst, int key) {
    BSTNode *s;
    if (*bst == NULL) {
        s = (BSTNode *) malloc(sizeof(BSTNode));
        s->key = key;
        s->lchild = NULL;
        s->rchild = NULL;
        *bst = s;
    } else {
        if (key < (*bst)->key) {
            InsertBst(&((*bst)->lchild), key);
        } else {
            if (key > (*bst)->key) {
                InsertBst(&((*bst)->rchild), key);
            }
        }
    }
}

/**
 * @time 2021/4/27 11:43
 * @description 创建二叉排序树
 * @param
 * @return
 */
void CreateBST(BSTNode **bst) {
    int key;
    *bst = NULL;
    scanf("%d", &key);
    rewind(stdin);
    while (key != 0) {
        InsertBst(bst, key);
        printf("请输入序列（输入0结束）：");
        fflush(stdout);
        scanf("%d", &key);
        rewind(stdin);
    }
}

/**
 * @time 2021/4/27 11:49
 * @description 中序遍历
 * @param
 * @return
 */
void inOrder(BSTNode *root) {
    if (root != NULL) {
        inOrder(root->lchild);
        printf("%4d", root->key);
        inOrder(root->rchild);
    }
}

/**
 * @time 2021/4/27 11:51
 * @description 递归查找某关键子等于key的记录，若查找成功，返回指向该记录节点指针，否则返回空指针
 * @param key：查找的记录值
 * @return 返回指针
 */
BSTNode *SearchBST(BSTNode *bst, int key) {
    if (!bst) {
        return NULL;
    } else {
        if (bst->key == key) {
            return bst;
        } else {
            if (bst->key > key) {
                return SearchBST(bst->lchild, key);
            } else {
                return SearchBST(bst->rchild, key);
            }
        }
    }
}

/**
 * @time 2021/4/27 12:25
 * @description 删除关键字k的节点
 * @param
 * @return
 */
BSTNode *DelBST(BSTNode *t, int k) {
    BSTNode *p, *f, *s, *q;
    p = t;
    f = NULL;
    while (p) {
        if (p->key == k) {
            break;
        }
        f = p;
        if (p->key > k) {
            p = p->lchild;
        } else {
            p = p->rchild;
        }
    }
    if (p == NULL) {
        return t;
    }
    if (p->lchild == NULL) {
        if (f == NULL) {
            t = p->rchild;
        } else {
            if (f->lchild == p) {
                f->lchild = p->rchild;
            } else {
                f->rchild = p->rchild;
            }
        }
        free(p);
    } else {
        q = p;
        s = p->lchild;
        while (s->rchild) {
            q = s;
            s = s->rchild;
        }
        if (q == p) {
            q->lchild = s->lchild;
        } else {
            q->rchild = s->lchild;
        }
        p->key = s->key;
        free(s);
    }
    return t;
}

int main() {
    printf("二叉排序树插入、生成、删除、查找\n");

    BSTNode *T;
    int k, rec;
    BSTNode *result;
    printf("建立二叉排序树，请输入序列（输入0结束）：");
    fflush(stdout);
    CreateBST(&T);
    printf("二叉树排序树中序遍历为：\n");
    fflush(stdout);
    inOrder(T);
    printf("\n请输入要查找的记录:");
    fflush(stdout);
    scanf("%d", &k);
    result = SearchBST(T, k);
    if (result != NULL) {
        printf("要查找的记录值存在,值为:%d\n", result->key);
        result = DelBST(T, k);
        printf("查找到的记录被删除后的中序序列:\n");
        inOrder(result);
    } else {
        printf("该记录不存在!,只能进行插入\n");
    }
    printf("\n输入要插入的记录：");
    fflush(stdout);
    scanf("%d", &rec);
    rewind(stdin);
    InsertBst(&T, rec);
    printf("插入记录后二叉排序树的中序序列:\n");
    inOrder(T);
    return TRUE;
}
