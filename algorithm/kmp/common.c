#include <stdio.h>
#include <string.h>
int sel(char * S,char *T){
    int i=0,j=0;
    while (i<strlen(S) && j<strlen(T)) {//循环开始
        if (S[i]==T[j]) {//首字符对比
            i++;
            j++;
        }else{
            i=i-j+1;//匹配失败，回到上次匹配的下一位
            j=0;//从T的首字符和S的下一位字符再继续匹配
        }
    }

    if (j==strlen(T)) {//当j等于T的长度时说明匹配成功返回位置
        return i-strlen(T)+1;
    }
    return 0;
}
int main(void) {
    int add=sel("12351234", "1234");
    printf("%d",add);
    return 0;
}


