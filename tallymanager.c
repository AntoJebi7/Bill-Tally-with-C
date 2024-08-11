#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct entries {
    char item[20];
    float price;
    int qty;
};
struct users {
    char name[50];
    char date[30];
    int nop;
    struct entries ent[50];
};
int csid() {
    return 10000 + rand() % 90000;
}
void billTop(char name[50], char date[30]) {
    printf("\n\n");
    printf("\t    ADV. Restaurant");
    printf("\n\t   -----------------");
    printf("\nDate: %s", date);
    printf("\nInvoice To: %s", name);
    printf("\n");
    printf("---------------------------------------\n");
    printf("Items\t\t");
    printf("Quantity\t\t");
    printf("Total\t\t");
    printf("\n---------------------------------------");
    printf("\n\n");
}
void billBody(char item[30], int qty, float price) {
    printf("%s\t\t", item);
    printf("\t%d\t\t", qty);
    printf("%.2f\t", qty * price);
    printf("\n");
}

void billDetails(float total) {
    printf("\n");
    float dis = 0.1 * total;
    float netTotal = total - dis;
    float cgst = 0.09 * netTotal, grandTotal = netTotal + 2 * cgst; // netTotal + cgst + sgst
    printf("---------------------------------------\n");
    printf("Sub Total\t\t\t%.2f", total);
    printf("\nDiscount @10%%\t\t%.2f", dis);
    printf("\n\t\t\t\t\t-------");
    printf("\nNet Total\t\t\t%.2f", netTotal);
    printf("\nCGST @9%%\t\t\t%.2f", cgst);
    printf("\nSGST @9%%\t\t\t%.2f", cgst);
    printf("\n---------------------------------------");
    printf("\nGrand Total\t\t\t%.2f", grandTotal);
    printf("\n---------------------------------------\n");
}

int main() {
    int option, cid, n;
    struct users usr;
    struct users user;
    char store_entries= 'y',contFlag='y';
    char name[50];

    FILE *flp;
    while(contFlag == 'y') {
        system("clear");
        float total = 0;
        int bill_found=0;
        printf("\t============AJ Billing System============");
        printf("\n\nOptions:");
        printf("\n\n1.Start Bill");
        printf("\n2.Get History");
        printf("\n3.Show Recent Bill");
        printf("\n4.Close");
        printf("\n\nPick the Action You Want to Take : \t");
        scanf("%d", &option);
        fgetc(stdin);

        switch (option) {
            case 1:
                system("clear");
            cid = csid();
            printf("\nBill Id number : %d", cid);
            printf("\nEnter customer name : ");
            fgets(usr.name, 50, stdin);
            usr.name[strlen(usr.name) - 1] = 0;
            strcpy(usr.date, __DATE__);
            printf("\nEnter number of Products\t");
            scanf("%d", &n);
            usr.nop = n;
            for (int i = 0; i < n; i++) {
                fgetc(stdin);
                printf("\n\n");
                printf("Enter the item %d :\t", i + 1);
                fgets(usr.ent[i].item, 20, stdin);
                usr.ent[i].item[strlen(usr.ent[i].item) - 1] = 0;
                printf("Enter Quantity :\t");
                scanf("%d", &usr.ent[i].qty);
                printf("Enter unit price :\t");
                scanf("%f", &usr.ent[i].price);
                total += usr.ent[i].qty * usr.ent[i].price;
            }
            billTop(usr.name, usr.date);
            for (int i = 0; i < usr.nop; i++) {
                billBody(usr.ent[i].item, usr.ent[i].qty, usr.ent[i].price);
            }
            billDetails(total);
            printf("\n do you want to store the bill [y/n]? : \t");
            scanf("%s",&store_entries);
            if (store_entries == 'y') {
                flp = fopen("bill_storage.dat","a+");
                fwrite(&usr,sizeof(struct users),1,flp);
                if(fwrite!=0) {
                    printf("\n Sucessfully Saved");
                }else {
                    printf("error in storing the file");
                    fclose(flp);
                }
                break;
            }
            case 2:
                system("clear");
            flp = fopen("bill_storage.dat","r");
            printf("\n  Bill History \n");
            while(fread(&user,sizeof(struct users),1,flp)){
                float bt = 0;
                billTop(user.name,user.date);
                int randomNumber = 10000 + rand() % 90000;
                printf("Bill Id: %d\n", randomNumber);
                for(int i=0;i<user.nop;i++){
                    billBody(user.ent[i].item,user.ent[i].qty,user.ent[i].price);
                    bt+=user.ent[i].qty * user.ent[i].price;
                }
                billDetails(bt);
            }
            fclose(flp);
            break;
            case 3:
                printf("\n Enter Name of the customer:");
            //fgetc(stdin);
            fgets(name,50,stdin);
            name[strlen(name)-1]=0;

            system("clear");
            flp = fopen("bill_storage.dat","r");
            printf("\n Tracking Bill for user name : %s \n",name);
            while(fread(&user,sizeof(struct users),1,flp)){
                float bt = 0;
                if(!strcmp(user.name,name)) {
                    billTop(user.name,user.date);
                    int randomNumber = 10000 + rand() % 90000;
                    printf("Bill Id: %d\n", randomNumber);
                    for(int i=0;i<user.nop;i++){
                        billBody(user.ent[i].item,user.ent[i].qty,user.ent[i].price);
                        bt+=user.ent[i].qty * user.ent[i].price;
                    }
                    billDetails(bt);
                    bill_found=1;
                }

            }
            if(!bill_found){
                printf("Unable to track the bill for user : %s",name);
                fclose(flp);
                break;
            }
            case 4:
                printf("\n\t\t Closed...");
            exit(0);
            break;
            default:
                printf("invalid action !");
            break;

        }
        printf("do you want to continue ?[y/n]\t");
        scanf("%s",&contFlag);
    }
    printf("\n\t\t Closed...");
    printf("\n\n");

    return 0;
}
