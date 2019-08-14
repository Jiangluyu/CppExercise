#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{
    int count = 0;
    char s[30][999];
    char scpy[30][999];
    printf("Enter the source text(Enter to exit):\n");
    for(int i = 0; i < 30; i++){//输入n行字符串，只有换行符时结束
        fgets(s[i], 999, stdin);
        count++;
        if(s[i][0] == '\n')
            break;
    }
    count--;
    for(int i = 0; i < count; i++){
        strcpy(scpy[i], s[i]);
    }

    //count the number of the letters from A~Z
    char letter;
    char *letterPtr = NULL;
    char *stringLetter = NULL;
    int countLetter[26] = {0};

    for(int j = 0; j < count; j++){
        stringLetter = scpy[j];
        for(int i = 65; i < 90; i++){
            letter = i;
            letterPtr = strchr(stringLetter, letter);
            while(letterPtr != NULL){
                countLetter[i - 65]++;
                stringLetter = letterPtr + 1;
                letterPtr = strchr(stringLetter, letter);
            }

            letter = i + 32;
            letterPtr = strchr(stringLetter, letter);
            while(letterPtr != NULL){
                countLetter[i - 65]++;
                stringLetter = letterPtr + 1;
                letterPtr = strchr(stringLetter, letter);
            }
            stringLetter = scpy[j];
        }
    }

    printf("  字母  \t出现次数\n");
    for(int i = 0; i < 26; i++){
        printf("    %c\t\t    %d\n", i+65, countLetter[i]);
    }

    puts("");

    //count the number of the words with different length
    char *tokenPtr = NULL;
    int countWords[20] = {0};

    for(int i = 0; i < count; i++){
        tokenPtr = strtok(scpy[i], " ");
        while(tokenPtr != NULL){
            if(tokenPtr[strlen(tokenPtr)-1] == '\n')
                countWords[strlen(tokenPtr)-2]++;
            else
                countWords[strlen(tokenPtr)-1]++;
            tokenPtr = strtok(NULL, " ");
        }
    }

    int indexWord = 0;
    for(int i = 0; i < 20; i++){
        if(countWords[i] != 0)
            indexWord = i;
    }

    printf("单词长度\t出现次数\n");
    for(int i = 0; i <= indexWord; i++){
        printf("    %d\t\t    %d\n", i+1, countWords[i]);
    }

    puts("");

    //count the number of the different words
    char word[100][20] = {0};
    char scpy1[30][999] = {0};
    char countWords1[100] = {0};
    char *tokenWordPtr = NULL;
    int indexWords = -1;
    int flag = 0;
    int k = 0;
    for(int i = 0; i < count; i++){
        strcpy(scpy1[i], s[i]);
    }

    for(int i = 0; i < count; i++){
        tokenWordPtr = strtok(scpy1[i], " ");
        while(tokenWordPtr != NULL){
            if(tokenWordPtr[strlen(tokenWordPtr)-1] == '\n')
                tokenWordPtr[strlen(tokenWordPtr)-1] = '\0';
            for(int j = 0; j < 100; j++){//查找是否word里已存在该字符串，有则flag为1，没有则flag为0
                if(strcmp(word[j], tokenWordPtr) != 0)
                    flag = 0;
                else{
                    indexWords = j;
                    flag = 1;
                    break;
                }
            }
            if(flag == 0){
                strcpy(word[k], tokenWordPtr);
                countWords1[k]++;
                k++;
            }
            else
                countWords1[indexWords]++;//计数+1
            tokenWordPtr = strtok(NULL, " ");
        }
    }
    //打印
    printf("  单词  \t\t\t出现次数\n");

    for(int i = 0; i < strlen(countWords1); i++){
        printf("  %-15s%16d\n", word[i], countWords1[i]);
    }

    return 0;
}
