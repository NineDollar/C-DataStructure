//
// Created by Nine_Dollar on 2021/5/20.
//
/**
 * p: 文件
 */
#include "stdio.h"
#include "predefined.h"

int main() {
    printf("文件\n");
    fflush(stdout);
    int i = 0;
    char str[255], *p = str;
    char ch;
    FILE *fp;
    printf("请输入字符,回车结束:");
    fflush(stdout);
    while ((ch = (char) getchar()) != '\n') {
        str[i++] = ch;
    }
//    gets(str);  //输入字符串
    printf("printf:%s\n", str);
    printf("puts:");
    puts(str);

    printf("对文件操作\n");
    fflush(stdout);
//  写入
    printf("写入\n");
    fflush(stdout);
    fp = fopen("fputs.txt", "w+");
    fputs(str, fp);

    fp = fopen("fprintf.txt", "w+");
    fprintf(fp, "%s", str);
    rewind(fp);

//    读取
    printf("读取\n");
    fflush(stdout);
    fp = fopen("fgets.txt", "r");
    fgets(str, 255, fp);
    printf("fgets:");
    puts(str);

    fp = fopen("fscanf.txt","r");
    fscanf(fp, "%s", str);
    puts(str);

    fp = fopen("D:\\Users\\Nine_Dollar\\Documents\\CLionProjects\\DataStructure\\my.txt","r");
    fscanf(fp, "%s", str);
    puts(str);

    clearerr(fp);
    return TRUE;
}

