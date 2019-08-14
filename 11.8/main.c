#include <stdio.h>

struct clientData{
    int accountNum;
    char name[15];
    float currentBalance;
};

struct clientChange{
    int acctNum;
    float dollarAmount;
};

void updateData(FILE *fromptr, FILE *toptr)
{
    //从交易文件中读取记录

    rewind(fromptr);

    while(!feof(fromptr)){
        struct clientChange clientTemp = {0, 0.00};

        fread(&clientTemp, sizeof(struct clientChange), 1, fromptr);
        //在主文件中寻找账号记录
        fseek(toptr, (clientTemp.acctNum-1)*sizeof(struct clientData), SEEK_SET);

        struct clientData client = {0, "", 0.00};

        fread(&client, sizeof(struct clientData), 1, toptr);
        //主文件中没有主记录
        if(client.accountNum == 0){
            fprintf(toptr,"未匹配的账户号码为%d的交易记录\t%.2f\n", clientTemp.acctNum, clientTemp.dollarAmount);
        }
        //主文件中有主记录
        else{
            client.currentBalance += clientTemp.dollarAmount;

            fseek(toptr, (client.accountNum-1)*sizeof(struct clientData), SEEK_SET);

            fwrite(&client, sizeof(struct clientData), 1, toptr);
        }

        fseek(fromptr, (clientTemp.acctNum-1)*sizeof(struct clientChange), SEEK_CUR);

    }
}

void newMast(FILE *oldptr)
{
    FILE *nfptr;
    nfptr = fopen("newmast.txt", "w");

    rewind(oldptr);

    fprintf(nfptr, "%s\t%s\t%s\n", "accountNum", "name", "currentBalance");

    //拷贝所有的数据到newmast中
    while(!feof(oldptr)){
        struct clientData clientInfo = {0, "", 0.00};
        int result = fread(&clientInfo, sizeof(struct clientData), 1, oldptr);

    //拷贝单条记录到newmast中
        if(result != 0 && clientInfo.accountNum != 0){
            fprintf(nfptr, "%d\t%s\t%.2f\n", clientInfo.accountNum, clientInfo.name, clientInfo.currentBalance);
        }
        fclose(nfptr);
    }
}

int main(void)
{
    FILE *ofptr;
    ofptr = fopen("oldmast.txt", "r");

    FILE *tfptr;
    tfptr = fopen("trans.txt", "r");

    updateData(tfptr, ofptr);

    newMast(ofptr);

    return 0;
}
