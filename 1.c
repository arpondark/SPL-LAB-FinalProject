#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PRODUCTS 5
#define MAX_CART_ITEMS 10

void displayProducts();
void addToCart(int productId, int quantity);
void displayCart();
void addr();
void checkout();

typedef struct
{
    int id;
    char name[50];
    float price;
} Product;

typedef struct
{
    Product product;
    int quantity;
} CartItem;

Product products[MAX_PRODUCTS] = {
    {1, "Laptop", 150000},
    {2, "Phone", 300000},
    {3, "Headphones", 799},
    {4, "Keyboard", 3000},
    {5, "Mouse", 450}};

CartItem cart[MAX_CART_ITEMS];
int cartSize = 0;

int main()
{
    system("color a");
    int choice, productId, quantity;

    while (1)
    {
        printf("\n\t\t\t______________E-commerce System______________\n\n");
        printf("\t\t\t\t1. Display Products\n");
        printf("\t\t\t\t2. Add to Cart\n");
        printf("\t\t\t\t3. View Cart\n");
        printf("\t\t\t\t4. Checkout\n");
        printf("\t\t\t\t5. Refresh\n");
        printf("\t\t\t\t6. Exit\n\n\n");
        printf("\n\n\tEnter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            displayProducts();
            break;
        case 2:
            printf("\t\t\t\tEnter product ID to add to cart: ");
            scanf("%d", &productId);
            printf("\t\t\t\tEnter quantity: ");
            scanf("%d", &quantity);
            addToCart(productId, quantity);
            break;
        case 3:
            displayCart();
            break;
        case 4:
            checkout();
            break;
        case 5:
            main();
            break;
        case 6:
            exit(0);
        default:
            printf("\t\t\t\tInvalid choice. Please try again.\n");
        }
    }

    return 0;
}

void displayProducts()
{
    printf("\t\t\t\tAvailable Products:\n");
    for (int i = 0; i < MAX_PRODUCTS; i++)
    {
        printf("\t\t\t\t%d. %s - %.2f Taka\n", products[i].id, products[i].name, products[i].price);
    }
}

void addToCart(int productId, int quantity)
{
    for (int i = 0; i < MAX_PRODUCTS; i++)
    {
        if (products[i].id == productId)
        {
            cart[cartSize].product = products[i];
            cart[cartSize].quantity = quantity;
            cartSize++;
            printf("\t\t\t\tAdded %d x %s to cart.\n", quantity, products[i].name);
            return;
        }
    }
    printf("\t\t\t\tProduct not found.\n");
}

void displayCart()
{
    printf("\t\t\t\tYour Cart:\n");
    float total = 0.0;
    for (int i = 0; i < cartSize; i++)
    {
        printf("\t\t\t\t %d x %s - %.2f Taka each\n", cart[i].quantity, cart[i].product.name, cart[i].product.price);
        total += cart[i].quantity * cart[i].product.price;
    }
    printf("\t\t\t\tTotal: %.2f Taka\n", total);
}

void addr()
{
    char address[100];
    int number, y;

    getchar();

    printf("\t\tEnter Address: ");
    fgets(address, sizeof(address), stdin);
    address[strcspn(address, "\n")] = '\0';

    printf("\n\t\tPhone Number: ");
    scanf("%d", &number);

    printf("\n\t\t\t\tAddress: %s", address);
    printf("\t\t\t\tNumber: %d\n", number);

    printf("\t\t\t\tAll ok?\n");
    printf("\n\t\t\t\t1.Yes\n");
    printf("\n\t\t\t\t2.No\n");

    scanf("%d", &y);
    if (y == 1)
    {
        printf("\n\t\t\t\t--------------Thank you for your purchase!--------------\n");
    }
    else
    {
        main();
    }
}

void checkout()
{
    displayCart();

    printf("\t\t\t\tChecking out..............\n");
    int n,x;
    printf("\t\t\t\tAre You Sure to Order Now?\n");
    printf("\t\t\t\t1.Yes\n");
    printf("\t\t\t\t2.No\n");
    scanf("%d", &n);
    if (n == 1)
    {
        printf("1.COD\n");
        scanf("%d", &x);
        if (x == 1)
        {
            addr();
        }
    }
    else
    {
        main();
    }

    cartSize = 0;
}