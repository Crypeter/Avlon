#include <iostream>
#include <cstring>
#include <cmath>
#define MaxSize 100
using namespace std;
int count=0;
struct stack
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
int main(void){
    char s1[MaxSize]="3*(5+4)+2^3-6/3=" ;  
    char s[MaxSize]="354+*23^+63/-",temp;
    char math1,math2;
    stack calculator;
    for(int i=0;i<(int)strlen(s);i++)
    {
        if(s[i]=='#')break;
        else if(s[i]>='0'&&s[i]<='9')
        {
            calculator.Push(s[i]);
        }
        else 
        {
            calculator.Pop(&math1);
            calculator.Pop(&math2);
            switch(s[i])
    {
        case '^':temp=(char)pow((math2-'0'),(math1-'0'))+'0';break;
        case '*':temp=(char)((math1-'0')*(math2-'0'))+'0';break;
        case '/':temp=(char)((math2-'0')/(math1-'0'))+'0';break;
        case '-':temp=(char)((math2-'0')-(math1-'0'))+'0';break;
        case '+':temp=(char)((math1-'0')+(math2-'0'))+'0';break;
    }
        calculator.Push(temp);
        }
    }
        calculator.Pop(&temp);
        cout<<s1;
        cout<<int(temp-'0')<<endl;
}