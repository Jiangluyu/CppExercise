#include<stdio.h>

int recursiveMinimum(int x[], int n)
{
    if(n != 1){
        for(int i = 0; i < n; i++){
            if(x[i+1] < x[i]){
                int temp = x[i+1];
                x[i] = x[i+1];
                x[i+1] = temp;
            }
            n--;
            recursiveMinimum(x, n);
        }
    return x[0];
    }
}

int main(void)
{
    int len;
    printf("How many numbers?\n");
    scanf("%d", &len);
    int num[len];

    for(int i = 0; i < len; i++){
        scanf("%d", &num[i]);
    }

    recursiveMinimum(num, len);

    printf("%d", recursiveMinimum(num, len));

    return 0;
}
