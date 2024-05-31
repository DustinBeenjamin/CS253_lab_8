#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include "ItemToPurchase.h"
#include "ShoppingCart.h"

int main() {
    
    ShoppingCart cart;
    EmptyCart(&cart);
    char command = 'w';

    printf("Enter customer's name:\n");
    fgets(cart.customerName, MAX_STRING_SIZE, stdin);
    TrimNewline(cart.customerName);
    printf("Enter today's date (MM/DD/YY):\n");
    fgets(cart.currentDate, MAX_STRING_SIZE, stdin);
    TrimNewline(cart.currentDate);

    while (command != 'q') {
        printf("\nPROGRAM MENU\n");
        printf("a - Add item to cart\n");
        printf("r - Remove item from cart\n");
        printf("i - Output item descriptions\n");
        printf("o - Output shopping cart\n");
        printf("q - Quit\n\n");
        printf("Choose an option:\n");

        command = getchar();    
        getchar();

        //THIS CANNOT HANDLE MULTIPLE CHARACTER INPUTS
        switch (command) {
        case 'a':
            ItemToPurchase item;
            MakeItem(&item);
            AddItem(&cart, &item);
            break;
        case 'r':
            char target[MAX_STRING_SIZE];
            printf("Enter name of item to remove:\n");
            fgets(target, MAX_STRING_SIZE, stdin);
            TrimNewline(target);
            RemoveItem(&cart, target);
            break;
        case 'i':
            PrintDescriptions(&cart);
            break;
        case 'o':
            PrintInvoice(&cart);
            break;
        case 'q':
            //DO NOTHING TO LET THE PROGRAM TERMINATE NORMALLY
            break;
        default:
            printf("Error. That is not a valid option. Please try again.\n");
        }
    }
   

}

