#include<stdio.h>
#include<stdlib.h>
#include<string.h>

// Bekir Kurt
// Parentezlerin dengeli dagitilip dagitilmadiginin kontrolu
// Örnek :{(}) dengesiz {()}() dengeli

struct stack{

    char ifade[20];
    int top;

}stack;

void push(char parantez , int size){

    if (stack.top == (size -1))
        printf ("Stack dolu");
    else{
        stack.top = stack.top + 1;
        stack.ifade[stack.top] = parantez;
    }
}

void pop()  {
    if (stack.top == - 1){
        printf ("Stack bos");
    }
    else{
        stack.top = stack.top - 1;
    }
}
int balanced(const char ifade[] , int size){

    for(int i = 0;i < size; i++){
        if(ifade[i] == '(' || ifade[i] == '{'){
            push(ifade[i], size);
            //continue;
        }
        else if(ifade[i] == ')' || ifade[i] == '}'){

            if(ifade[i] == ')'){
                if(stack.ifade[stack.top] == '('){
                    pop();
                }
                else{
                    return 0;
                }
            }
            if(ifade[i] == '}'){
                if(stack.ifade[stack.top] == '{'){
                    pop();
                }
                else{
                    return 0;
                }
            }
        }
    }
    if(stack.top == -1){
        return 1;
    }
}

int main(){
    int size = 20;
    char ifade[size];

    stack.top = -1;
    printf("ifadeyi giriniz : ");
    scanf("%s", ifade);

    if ( balanced(ifade , size) == 0){
        printf("Dengeli degil\n");
    }
    else{
        printf("Dengeli \n");
    }

    return 0;
}
