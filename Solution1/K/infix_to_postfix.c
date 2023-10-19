#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_SIZE 100

typedef struct {
    char data[MAX_SIZE];
    int top;
} Stack;

void init_stack(Stack* s) {
    s->top = -1;
}

int is_empty(Stack* s) {
    return s->top == -1;
}

int is_operator(char c) {
    return (c == '+' || c == '-' || c == '*' || c == '/');
}

int precedence(char c) {
    if (c == '+' || c == '-') {
        return 1;
    }
    else if (c == '*' || c == '/') {
        return 2;
    }
    else {
        return 0;
    }
}

void push(Stack* s, char c) {
    s->data[++s->top] = c;
}

char pop(Stack* s) {
    return s->data[s->top--];
}

void infix_to_postfix(char* infix, char* postfix) {
    Stack s;
    init_stack(&s);
    int i, j = 0;

    for (i = 0; infix[i]; i++) {
        if (isalnum(infix[i])) {
            postfix[j++] = infix[i];
        }
        else if (infix[i] == '(') {
            push(&s, infix[i]);
        }
        else if (infix[i] == ')') {
            while (!is_empty(&s) && s.data[s.top] != '(') {
                postfix[j++] = pop(&s);
            }
            pop(&s);
        }
        else if (is_operator(infix[i])) {
            while (!is_empty(&s) && precedence(s.data[s.top]) >= precedence(infix[i])) {
                postfix[j++] = pop(&s);
            }
            push(&s, infix[i]);
        }
    }

    while (!is_empty(&s)) {
        postfix[j++] = pop(&s);
    }
    postfix[j] = '\0';
}

int main() {
    char infix[MAX_SIZE], postfix[MAX_SIZE];
    printf("请输入中缀表达式：");
    scanf("%s", infix);
    infix_to_postfix(infix, postfix);
    printf("对应的后缀表达式为：%s", postfix);
    return 0;
}
