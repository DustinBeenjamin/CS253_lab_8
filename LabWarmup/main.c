#include <stdio.h>
#include "itemToPurchase.h"
#define SHOPPING_CART_SIZE 3
#define MAX_ITEM_SIZE 100

void ClearBuffer();
void TrimNewline(char *string);

int main() {
    
    ItemToPurchase shopping_cart[SHOPPING_CART_SIZE];
    int total_cost = 0;

    for (int i = 0; i < SHOPPING_CART_SIZE; i++) {
        ItemToPurchase *item = &shopping_cart[i];
        printf("Item %d\n", i + 1);
        printf("Enter the item name:\n");
        fgets(item->itemName, MAX_ITEM_SIZE, stdin);
        //TRIM THE NEWLINE THAT FGETS INCLUDED
        TrimNewline(item->itemName);
        printf("Enter the item price: \n");
        scanf("%d", &(item->itemPrice));
        //CLEAR THE BUFFER OF THE NEWLINE THAT SCANF LEFT BEHIND
        ClearBuffer();
        printf("Enter the item quantity:\n");
        scanf("%d", &(item->itemQuantity));
        //CLEAR THE BUFFER OF THE NEWLINE THAT SCANF LEFT BEHIND
        ClearBuffer();
        printf("\n");
    }

    printf("TOTAL COST\n");
    for (int i = 0; i < SHOPPING_CART_SIZE; i++) {
        PrintItemCost(&(shopping_cart[i]));
        total_cost += shopping_cart[i].itemPrice * shopping_cart[i].itemQuantity;
    }
    printf("\nTotal: $%d", total_cost);
}

void ClearBuffer() {
    //NEVER CALL THIS FUNCTION IF THERE IS NOTHING IN THE BUFFER, 
    //THAT WOULD PAUSE THE PROGRAM FOR THE USER TO PROVIDE AN ENTRY
    int c = getchar();
    while (c != '\n' && c != EOF) {
        c = getchar();
    }
}

void TrimNewline(char *string) {
    int i = 0;
    int c = string[i];
    while (c != '\n') {
        i++;
        c = string[i];
    }    
    string[i] = '\0';

}