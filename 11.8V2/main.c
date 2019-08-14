#include <stdio.h>
#include <string.h>

struct info{
    int acctNum;
    float currentBalance;
    char name[20];
};

void function()
{
    struct info client[10] = {0};
    struct info trans[10] = {0};

    FILE *ofptr;
    ofptr = fopen("oldmast.txt", "r");
    int count = 0;
    while(!feof(ofptr)){
        fscanf(ofptr, "%d%f%20s", &client[count].acctNum, &client[count].currentBalance, client[count].name);
        count++;
    }

    fclose(ofptr);

    FILE *tfptr;
    tfptr = fopen("trans.txt", "r");
    count = 0;
    while(!feof(tfptr)){
        fscanf(tfptr, "%d %f", &trans[count].acctNum, &trans[count].currentBalance);
        count++;
    }

    for(int i = 0; i < 10; i++){
        for(int j = 0; j < 10; j++){
            if(client[j].acctNum == trans[j].acctNum){
                client[j].currentBalance += trans[j].currentBalance;
                trans[j].currentBalance = 0;
            }
        }
    }


    fclose(tfptr);

    FILE *nfptr;
    nfptr = fopen("newmast.txt", "w");
    count = 0;

    fprintf(tfptr, "%s %s %s\n", "accountNum", "name", "currentBalance");
    while(client[count].acctNum != 0){
        fprintf(nfptr, "%d %s %.2f\n", client[count].acctNum, client[count].name, client[count].currentBalance);
        count++;
    }

    for (int i = 0; i < 10; i++)
	{
	if(trans[i].currentBalance != 0)
		fprintf(tfptr, "未匹配的账户号码为%d的交易记录\n", trans[i].acctNum);
	}

    fclose(nfptr);
}

int main(void)
{
    printf("Loading...\n");
    function();
    printf("Done!\n");
    return 0;
}
