#include <stdio.h>
#include <string.h>

// Structure for products
typedef struct {
    char name[50];
    int price;
    int stock;
} Product;

// Structure for members
typedef struct {
    char name[50];
    int points;
} Member;

// Display products
void checkProduct(Product db[], int size) {
    int i;

    printf("\n--- PRODUCT CATALOG ---\n");

    for (i = 0; i < size; i++) {
        printf("%d. %s - Rp%d (Stock: %d)\n",
               i + 1, db[i].name, db[i].price, db[i].stock);
    }
}

// Display members
void checkMember(Member db[], int size) {
    int i;

    printf("\n--- MEMBER DATA ---\n");

    for (i = 0; i < size; i++) {
        printf("%d. %s - Points: %d\n",
               i + 1, db[i].name, db[i].points);
    }
}

// Buy a product
void buyProduct(Product *p, Member *m, int qty) {
    int total;

    if (qty <= 0) {
        printf("Invalid quantity!\n");
    }
    else if (p->stock >= qty) {
        p->stock = p->stock - qty;
        total = p->price * qty;

        printf("\nPurchase successful!\n");
        printf("Product: %s\n", p->name);
        printf("Quantity: %d\n", qty);
        printf("Total: Rp%d\n", total);

        if (total >= 20000 && m != NULL) {
            m->points = m->points + 100;
            printf("%s earned 100 points!\n", m->name);
        }
    }
    else {
        printf("Not enough stock!\n");
    }
}

// Challenge 1: Update price
void updatePrice(Product *p, int newPrice) {
    if (newPrice > 0) {
        p->price = newPrice;
        printf("Price updated successfully!\n");
    }
    else {
        printf("Price must be greater than zero!\n");
    }
}

// Challenge 2: Update name
void updateName(Product *p, char newName[]) {
    if (strlen(newName) > 0 && strlen(newName) < 50) {
        strcpy(p->name, newName);
        printf("Product name updated successfully!\n");
    }
    else {
        printf("Invalid product name!\n");
    }
}

int main() {
    Product dbProduct[5] = {
        {"Soap", 5000, 10},
        {"Shampoo", 15000, 5},
        {"Bread", 12000, 8},
        {"Milk", 25000, 15},
        {"Coffee", 22000, 20}
    };

    Member dbMember[2] = {
        {"Anisa", 500},
        {"Budi", 100}
    };

    int choice;
    int productNumber;
    int quantity;
    int newPrice;
    int memberNumber;
    char newName[50];

    
    while (1) {
        printf("\n===== Newton MINI MARKET MENU =====\n");
        printf("1. View Products\n");
        printf("2. View Members\n");
        printf("3. Buy Product\n");
        printf("4. Update Product Price\n");
        printf("5. Update Product Name\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");

        if (scanf("%d", &choice) != 1) {
            printf("Invalid input! Please enter a number.\n");
            return 1;
        }

        switch (choice) {

            case 1:
                checkProduct(dbProduct, 5);
                break;

            case 2:
                checkMember(dbMember, 2);
                break;

            case 3:
                checkProduct(dbProduct, 5);

                printf("Enter product number (1-5): ");
                if (scanf("%d", &productNumber) != 1) {
                    printf("Invalid input!\n");
                    return 1;
                }

                if (productNumber < 1 || productNumber > 5) {
                    printf("Invalid product number!\n");
                    break;
                }

                printf("Enter quantity: ");
                if (scanf("%d", &quantity) != 1) {
                    printf("Invalid input!\n");
                    return 1;
                }

                printf("Enter member number (1-2, or 0 for non-member): ");
                if (scanf("%d", &memberNumber) != 1) {
                    printf("Invalid input!\n");
                    return 1;
                }

                if (memberNumber == 0) {
                    buyProduct(&dbProduct[productNumber - 1],
                               NULL, quantity);
                }
                else if (memberNumber >= 1 && memberNumber <= 2) {
                    buyProduct(&dbProduct[productNumber - 1],
                               &dbMember[memberNumber - 1], quantity);
                }
                else {
                    printf("Invalid member number!\n");
                }

                break;

            case 4:
                checkProduct(dbProduct, 5);

                printf("Enter product number (1-5): ");
                if (scanf("%d", &productNumber) != 1) {
                    printf("Invalid input!\n");
                    return 1;
                }

                if (productNumber < 1 || productNumber > 5) {
                    printf("Invalid product number!\n");
                    break;
                }

                printf("Enter new price: ");
                if (scanf("%d", &newPrice) != 1) {
                    printf("Invalid input!\n");
                    return 1;
                }

                updatePrice(&dbProduct[productNumber - 1], newPrice);
                break;

            case 5:
                checkProduct(dbProduct, 5);

                printf("Enter product number (1-5): ");
                if (scanf("%d", &productNumber) != 1) {
                    printf("Invalid input!\n");
                    return 1;
                }

                if (productNumber < 1 || productNumber > 5) {
                    printf("Invalid product number!\n");
                    break;
                }

                printf("Enter new product name: ");
                if (scanf(" %49[^\n]", newName) != 1) {
                    printf("Invalid product name!\n");
                    return 1;
                }

                updateName(&dbProduct[productNumber - 1], newName);
                break;

            case 6:
                printf("Thank you for using Newton Mini Market!\n");
                return 0;

            default:
                printf("Invalid choice! Please select 1-6.\n");
        }
    }

    return 0;
}