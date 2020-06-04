#include <stdio.h>
#include <stdlib.h>

struct stack
{
    int size;
    int top;
    int *s;
};

void create(struct stack *st)
{
    printf("Enter size");
    scanf("%d",&st->size);
    st->top=-1;
    st->s=(int *)malloc(st->size*sizeof(int));
}

void display(struct stack st)
{
    int i;
    for(i=st.top;i>=0;i--)
    {
        printf("%d ",st.s[i]);
    }
    printf("\n");
}

void push(struct stack *st,int x)
{
    if(st->top == st->size-1)
    {
        printf("Stack overflow\n");
    }
    else
    {
        st->top++;
        st->s[st->top]=x;
    }
}

int pop(struct stack *st)
{
    int x=-1;
    if(st->top==-1)
    {
        printf("Stack underflow\n");
    }
    else
    {
        x=st->s[st->top--];
    }
    return x;
}

int peep(struct stack st,int pos)
{
    int x=-1;
    if(st.top-pos+1 < 0)
    {
        printf("Invalid Index\n");
    }
    else
    {
        x=st.s[st.top-pos+1];
    }
    return x;
}
int isempty(struct stack st)
{
    if(st.top==-1)
    {
        return 1;
    }
    else
        return 0;
}
int isfull(struct stack st)
{
    if(st.top==st.size -1)
    {
        return 1;
    }
    else
        return 0;
}

int stacktop(struct stack st)
{
    if(!isempty(st))
    {
        return st.s[st.top];
    }
    else
        return -1;
}
int main()
{
    struct stack st;
    create(&st);
    push(&st,10);
    push(&st,20);
    push(&st,30);
    push(&st,40);
    push(&st,50);

    printf("%d \n",pop(&st));
    display(st);

    printf("%d \n",peep(st,2));

    printf("if the stack empty %d",isempty(st));
    printf("\nif the stack full %d",isfull(st));
    printf("\nstack top %d",stacktop(st));



}
