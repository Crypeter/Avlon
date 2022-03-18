#include <iostream>
#include <cstring>
#define MaxSize 100
using namespace std;

class stack
{
public:
    stack():top1(0){space[0]='#';};
    inline int IsFull();
    void Push(char item);
    void Pop(char *place);
    char gettop();
private:
    char space[MaxSize];
    int top1;
};
class BehindChangeMathine
{
private:
    stack calculator;
    int count;
    char wait_to_chage[MaxSize];
    char end[MaxSize];
    char rubbish[1];
    int cmp(char a,int flag);
public:
    inline void enter(char *);
    inline char *out();
    int calculate();
    BehindChangeMathine():count(0){};
};
void BehindChangeMathine::enter(char *a)
{
    strcpy(wait_to_chage,a);
}
char *BehindChangeMathine::out()
{
    return end;
}
int BehindChangeMathine::calculate()
{
    for(int i=0;i<(int)strlen(wait_to_chage);i++)
    {
        if(wait_to_chage[i]>='0'&&wait_to_chage[i]<='9')end[count++]=wait_to_chage[i];
        else if(wait_to_chage[i]==')')
        {
            do
            {
                calculator.Pop(end+count);
                count++;
            }
            while (!(calculator.gettop()=='('));
            calculator.Pop(rubbish);
        }
        else L:if(cmp(calculator.gettop(),0)<cmp(wait_to_chage[i],1))
        {
            calculator.Push(wait_to_chage[i]);
        }
        else 
        {
            calculator.Pop(end+count);
            count++;
            goto L;
        }
    }
    return 0;
}
inline int stack::IsFull()
{
    if(top1==MaxSize)return 0;
    else return 1;
}
void stack::Push(char item)
{
    space[++top1]=item;
}
void stack::Pop(char *place)
{
    *place=space[top1--];
}
char stack::gettop()
{
    return space[top1];
}
int BehindChangeMathine::cmp(char a,int flag)
{
    switch(a)
    {
        case '(':if(flag)return 4;else return 0;
        case '^':return 3;
        case '*':
        case '/':return 2;
        case '-':
        case '+':return 1;
        case '=':return 0;
        case '#':return -1;
    }
    return 0;
}
int main(void)
{
    /*char s[MaxSize]="3*(5+4)+2^3-6/3=",temp[MaxSize],rubbish[1];
    stack calculator;
    for(int i=0;i<(int)strlen(s);i++)
    {
        if(s[i]>='0'&&s[i]<='9')temp[count++]=s[i];
        else if(s[i]==')')
        {
            do
            {
                calculator.Pop(temp+count);
                count++;
            }
            while (!(calculator.gettop()=='('));
            calculator.Pop(rubbish);
        }
        else L:if(cmp(calculator.gettop(),0)<cmp(s[i],1))
        {
            calculator.Push(s[i]);
        }
        else 
        {
            calculator.Pop(temp+count);
            count++;
            goto L;
            //if(calculator.gettop()=='#')break;
        }
    }
    cout<<s<<endl;
    cout<<temp<<endl;*/
}
