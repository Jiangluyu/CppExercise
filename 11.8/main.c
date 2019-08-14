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
    //�ӽ����ļ��ж�ȡ��¼

    rewind(fromptr);

    while(!feof(fromptr)){
        struct clientChange clientTemp = {0, 0.00};

        fread(&clientTemp, sizeof(struct clientChange), 1, fromptr);
        //�����ļ���Ѱ���˺ż�¼
        fseek(toptr, (clientTemp.acctNum-1)*sizeof(struct clientData), SEEK_SET);

        struct clientData client = {0, "", 0.00};

        fread(&client, sizeof(struct clientData), 1, toptr);
        //���ļ���û������¼
        if(client.accountNum == 0){
            fprintf(toptr,"δƥ����˻�����Ϊ%d�Ľ��׼�¼\t%.2f\n", clientTemp.acctNum, clientTemp.dollarAmount);
        }
        //���ļ���������¼
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

    //�������е����ݵ�newmast��
    while(!feof(oldptr)){
        struct clientData clientInfo = {0, "", 0.00};
        int result = fread(&clientInfo, sizeof(struct clientData), 1, oldptr);

    //����������¼��newmast��
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
