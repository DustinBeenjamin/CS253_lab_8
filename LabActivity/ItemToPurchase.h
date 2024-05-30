#define MAX_STRING_SIZE 99
#ifndef ITEM_TO_PURCHASE_H
#define ITEM_TO_PURCHASE_H
#define MAX_ITEM_SIZE 80
#define MAX_DESCRIPTION_SIZE 80

typedef struct {
    char itemName[MAX_STRING_SIZE + 1];
    char itemDescription[MAX_STRING_SIZE + 1];
    int itemPrice;
    int itemQuantity;
} ItemToPurchase;


void PrintItemCost(ItemToPurchase *item);
void MakeItemBlank(ItemToPurchase *item);
void MakeItem(ItemToPurchase *item);
void TrimNewline(char *string);


#endif