#include<stdio.h>
#include<ctype.h>

#define MAX 100

typedef struct stack{
    char data[MAX];
    int top;
}stack;

//empty top=-1 full top=max-1

int priority(char x){
    if ( x=='(' )
        return 0;
    else if ( x=='+' || x=='-' )
        return 1;
    else if ( x=='*' || x=='/' || x=='%' )
        return 2;
    return 3;
}

int push(stack *s,char x){
    if (s->top==MAX-1) return 0;   //stack full
    s->data[++(s->top)] = x;
    return 1;
}

char pop(stack *s){
    char x;
    if (s->top==-1) return 0;
    x = s->data[(s->top)--];
    return x;
}

char top(stack *s){
    return s->data[s->top];
}

int main(){
    stack s;
    char x;
    int token;

    s.top=-1;

    printf("Enter infix expression:\n");
    while((token=getchar())!='\n'){
        if(isalnum(token))
            printf("%c",token);
        else //1
        {
            if(token == '(')
                push(&s,'(');
            else //2
            {
                if(token == ')')
                    while((x=pop(&s))!='(')
                        printf("%c",x);
                else //3
                {
                    while(priority(token) <= priority(top(&s)) && s.top!=-1)
                    {
                        x=pop(&s);
                        printf("%c",x);
                    }
                    push(&s,token);
                } //3 end
            } //2 end
        }  //1 end

    }//while ends

    while(s.top!=-1)
    {
        x=pop(&s);
        printf("%c",x);
    }

    return 0;
}