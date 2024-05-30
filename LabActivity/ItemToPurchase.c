#include<stdio.h>
#include<string.h>
#include "ItemToPurchase.h"

void MakeItemBlank(ItemToPurchase *item) {
    strcpy((*item).itemName, "none");
    strcpy(item->itemDescription, "none");
    (*item).itemPrice = 0;
    (*item).itemQuantity = 0;
}

void PrintItemCost(ItemToPurchase *item) {
    printf("%s, %d @ $%d = $%d\n", item->itemName, item->itemQuantity, item->itemPrice, item->itemQuantity * item->itemPrice); 
}

void MakeItem(ItemToPurchase *item){
    printf("Enter the item name:\n");
    fgets(item->itemName, MAX_STRING_SIZE + 1, stdin);
    TrimNewline(item->itemName);
    printf("Enter the item description:\n");
    fgets(item->itemDescription, MAX_STRING_SIZE + 1, stdin);
    TrimNewline(item->itemDescription);
    printf("Enter the item price:\n");
    scanf("%d", &item->itemPrice);
    getchar();
    printf("Enter the item quantity:\n");
    scanf("%d", &item->itemQuantity);
    getchar();
}

void TrimNewline(char *string) {
    int i = 0;
    char c = string[i];
    while (c != '\n') {
        i++;
        c = string[i];
    }
    string[i] = '\0';
}