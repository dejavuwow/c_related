//
%{
#include <stdio.h>
#include <stdlib.h>

// 定义符号值类型为字符
typedef char YYSTYPE;
#define YYSTYPE_IS_DECLARED 1

int yylex();
void yyerror(const char *s);
void print_char(char c);
%}

%token CHAR LPAREN RPAREN COMMA

%%

// 文法规则
start:
    S { printf("\n"); }  // 解析完成后换行
    ;

S:
    LPAREN L RPAREN  // (L)
    | CHAR           // 单个字符
    ;

L:
    L COMMA S        // L,S → 递归展开列表
    | S              // 单个元素
    ;

%%

// 词法分析器（Lexer）
int yylex() {
    int c = getchar();
    switch (c) {
        case '(': return LPAREN;
        case ')': return RPAREN;
        case ',': return COMMA;
        case ' ': case '\t': case '\n':  // 忽略空白字符
            return yylex();
        case EOF: return 0;  // 输入结束
        default:
            if (c >= 'a' && c <= 'z' || c >= 'A' && c <= 'Z') {
                yylval = c;  // 存储字符值
                return CHAR;
            } else {
                yyerror("Invalid character");
                exit(1);
            }
    }
}

// 打印字符（忽略括号和逗号）
void print_char(char c) {
    if (c != '(' && c != ')' && c != ',') {
        printf("%c ", c);
    }
}

void yyerror(const char *s) {
    fprintf(stderr, "Error: %s\n", s);
    exit(1);
}

int main() {
    printf("Enter a list (e.g., '(a,(b,c),d)'): ");
    yyparse();
    return 0;
}
