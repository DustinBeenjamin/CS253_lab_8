#include<stdio.h>
#include<string.h>
#include "ShoppingCart.h"
#include "ItemToPurchase.h"

void EmptyCart(ShoppingCart *cart) {
    cart->cartSize = 0;
}


void AddItem(ShoppingCart *cart, ItemToPurchase *item) {
    cart->cartItems[cart->cartSize] = *item;
    (cart->cartSize)++;
}

void RemoveItem(ShoppingCart *cart, char *itemName) {
    for (int i = 0; i < cart->cartSize; i++) {
        if (strcmp(itemName, (cart->cartItems)[i].itemName) == 0) {
            //SHIFT THE RIGHT ELEMENTS TO THE LEFT BY ONE INDEX TO FILL THE HOLE
            for (int j = 0; j < cart->cartSize - 1 - i; j++) {
                cart->cartItems[i + j] = cart->cartItems[i + j + 1];
            }
            (cart->cartSize)--;
            break;
        }
    }
    //ITEM WAS NOT FOUND
}

int GetNumItemsInCart(ShoppingCart *cart) {
    int size = 0;
    for (int i = 0; i < cart->cartSize; i++) {
        size += (cart->cartItems[i]).itemQuantity;
    }
    return size;
}

int GetCostOfCart(ShoppingCart *cart) {
    int cost = 0;
    for (int i = 0; i < cart->cartSize; i++) {
        cost += (cart->cartItems[i].itemPrice * cart->cartItems[i].itemQuantity);
    }
    return cost;
}

void PrintInvoice(ShoppingCart *cart) {
    printf("%s's Shopping Cart - %s\n", cart->customerName, cart->currentDate);
    printf("Number of Items: %d\n\n", GetNumItemsInCart(cart));
    for (int i = 0; i < cart->cartSize; i++) {
        PrintItemCost(&(cart->cartItems[i]));
    }
    printf("\nPrice: $%d\n", GetCostOfCart(cart));
}

void PrintDescriptions(ShoppingCart *cart) {
    printf("%s's Shopping Cart - %s\n", cart->customerName, cart->currentDate);
    printf("\nItem Descriptions:\n");
    for (int i = 0; i < cart->cartSize;  i++) {
        printf("%s: %s\n", (cart->cartItems[i]).itemName, (cart->cartItems[i]).itemDescription);
    }
}

