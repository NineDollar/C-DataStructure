//
// Created by Nine_Dollar on 2021/4/14.
//

#ifndef DATASTRUCTURE_PREDEFINED_H
#define DATASTRUCTURE_PREDEFINED_H

#endif //DATASTRUCTURE_PREDEFINED_H

#define ElemType int
#define TRUE 1
#define FALSE 0
#define OK 1
#define ERROR 0
#define INFEASIBLE -1
#define OVERFLOW -2
//函数返回类型，函数结果状态代码
typedef int Status;

/**
 * @time 2021/4/16 19:52
 * @description 相等为1
 * @param
 * @return
 */
Status compare(ElemType a, ElemType b) {
    if (a == b) {
        return 1;
    }
    return 0;
}