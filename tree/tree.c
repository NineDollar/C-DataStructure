//
// Created by Nine_Dollar on 2021/4/20.
//
/**
 * p: 二叉链表树
 */

#include "stdio.h"
#include "stdlib.h"
#include "predefined.h"

typedef char TElemType;

typedef struct BiTNode {
    TElemType data;
    struct BiTNode *lchild, *rchild;
} BiTNode, *BiTree;

typedef struct SNode {
    BiTree tnodedata;
    struct SNode *next;
} SNode, *StackPtr;

typedef struct {
    StackPtr top;
} LinkStack;

/**
 * @time 2021/4/20 21:17
 * @description 初始化栈
 * @param
 * @return
 */
Status InitStack(LinkStack *s) {
    s->top = (StackPtr) malloc(sizeof(SNode));
    if (!s->top) {
        exit(OVERFLOW);
    }
    s->top->next = NULL;
    return OK;
}

/**
 * @time 2021/4/20 19:10
 * @description 入栈
 * @param
 * @return
 */
Status Push(LinkStack *s, BiTree st) {
    StackPtr p;
    p = (StackPtr) malloc(sizeof(SNode));
    p->tnodedata = st;
    p->next = s->top;
    s->top = p;
    return OK;
}

/**
 * @time 2021/4/20 19:16
 * @description 出栈
 * @param
 * @return
 */
Status Pop(LinkStack *s, BiTree *st) {
    StackPtr q;
    if (!s->top) {
        printf("空表\n");
        return ERROR;
    }
    q = s->top;
    *st = q->tnodedata;
    s->top = q->next;
    free(q);
    return OK;
}

/**
 * @time 2021/4/20 19:19
 * @description 获取栈顶元素
 * @param
 * @return
 */
Status GetTop(LinkStack *s, BiTree *st) {
    if (!s->top) {
        printf("空栈");
        return ERROR;
    }
    *st = s->top->tnodedata;
    return OK;
}

Status PrintElement(TElemType e) {
    printf("%c", e);
    return OK;
}

/**
 * @time 2021/4/20 12:02
 * @description 先序遍历
 * @param
 * @return
 */
Status PreOrderTraverse(BiTree t, Status(*Visit)(TElemType e)) {
    if (t) {
        if (Visit(t->data)) {
            if (PreOrderTraverse(t->lchild, Visit)) {
                if (PreOrderTraverse(t->rchild, Visit)) {
                    return OK;
                }
            }
        }
        return ERROR;
    } else {
        return OK;
    }
}

/**
 * @time 2021/4/20 21:17
 * @description 创建
 * @param
 * @return
 */
Status CreateBiTree(BiTree *t) {
    TElemType ch;
    fflush(stdout);
    scanf("%c", &ch);
    rewind(stdin);
    if (ch == ' ') {
        *t = NULL;
    } else {
        if (!((*t) = (BiTNode *) malloc(sizeof(BiTNode)))) {
            printf("内存分配失败");
            exit(OVERFLOW);
        }
        (*t)->data = ch;
        printf("请输入%c的左孩子：", ch);
        CreateBiTree(&(*t)->lchild);
        printf("请输入%c的右孩子：", ch);
        CreateBiTree(&(*t)->rchild);
    }
    return OK;
}

/**
 * @time 2021/4/20 19:26
 * @description 判断是否空链栈
 * @param
 * @return
 */
Status StackEmpty(LinkStack *s) {
    if (!s->top->next) {
        return TRUE;
    }
    return FALSE;
}

/**
 * @time 2021/4/20 15:09
 * @description 中序遍历
 * @param
 * @return
 */
Status InOrderTraverse(BiTree t, Status (*Visit)(TElemType e)) {
    BiTree p;
    LinkStack s;
    printf("中序遍历:");
    InitStack(&s);//初始化栈
    Push(&s, t);//放入跟节点
    while (!StackEmpty(&s)) {
        while (GetTop(&s,&p) && p){//中序遍历，先把所有节点左子树放入栈中
            Push(&s, p->lchild);
        } //此时p位置在叶子的左孩子
        Pop(&s, &p);//p1,开始退栈,叶子节点孩子为NULL指针,所以空指针退栈,此时p位置在叶子节点的左孩子
        if(!StackEmpty(&s)){  //访问节点向右走一步
            Pop(&s, &p);//p2,退的tnodedata放入p,p此时位置在叶子节点的双亲
            if(!Visit(p->data)){//访问p的data值
                return ERROR;
            }
            Push(&s, p->rchild);
        }
    }
    printf("\n");
    return OK;
}

/**
 * @time 2021/4/20 21:32
 * @description 中序遍历
 * @param
 * @return
 */
Status InOrderTraverse1(BiTree t,Status(*Visit)(TElemType elemType)){
    BiTree p;
    LinkStack s;
    InitStack(&s);
    p = t;
    while (p||!StackEmpty(&s)){
        if(p){
            Push(&s,p);
            p = p->lchild;
        } else{
            Pop(&s, &p);
            if(!Visit(p->data)){
                return ERROR;
            }
            p = p->rchild;
        }
    }
    return OK;
}

int main() {
    BiTree t;
    printf("请输入第一个节点的值,' '表示没有叶节点：");

    /*先序遍历二叉树：A B C D E F G
    中序遍历二叉树：C D B A F G E
    后续遍历二叉树：D C B G F E A*/
    CreateBiTree(&t);
/*//    先序遍历
    printf("先序遍历:");
    PreOrderTraverse(t, PrintElement);
    printf("\n");

//    中序遍历
    InOrderTraverse(t, PrintElement);*/

//    中序遍历
//    InOrderTraverse1(t, PrintElement);

    return TRUE;
}