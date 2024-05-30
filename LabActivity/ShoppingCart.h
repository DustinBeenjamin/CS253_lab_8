#define MAX_STRING_SIZE 99

#ifndef SHOPPING_CART_H
#define SHOPPING_CART_H

#include "ItemToPurchase.h"

#define MAX_CUSTOMER_NAME_SIZE 50
#define MAX_CURRENT_DATE_SIZE 50
#define MAX_CART_SIZE 10


typedef struct {
    char customerName[MAX_STRING_SIZE + 1];
    char currentDate[MAX_STRING_SIZE + 1];
    ItemToPurchase cartItems[MAX_CART_SIZE];
    int cartSize;
} ShoppingCart;

void AddItem(ShoppingCart *cart, ItemToPurchase *item);
void RemoveItem(ShoppingCart *cart, char *itemName);
int GetNumItemsInCart(ShoppingCart *cart);
int GetCostOfCart(ShoppingCart *cart);
void PrintInvoice(ShoppingCart *cart);
void PrintDescriptions(ShoppingCart *cart);
void EmptyCart(ShoppingCart *cart);


#endif
