#define MAX_ITEM_SIZE 100  

typedef struct {
    char itemName[MAX_ITEM_SIZE];
    int itemPrice;
    int itemQuantity;
} ItemToPurchase;


void PrintItemCost(ItemToPurchase *item);
void MakeItemBlank(ItemToPurchase *item);