#include <stdio.h>

struct Book {
    char title[100];
    char author[50];
    float price;
};

int main() {
    int n;
    printf("Enter the number of books: ");
    scanf("%d", &n);

    struct Book books[n];

    for (int i = 0; i < n; i++) {
        printf("\nEnter details for book %d:\n", i + 1);
        printf("Title: ");
        scanf(" %[^\n]s", books[i].title); // Read string with spaces
        printf("Author: ");
        scanf(" %[^\n]s", books[i].author);
        printf("Price: ");
        scanf("%f", &books[i].price);
    }

    float price_threshold;
    printf("\nEnter the price threshold to filter books: ");
    scanf("%f", &price_threshold);


    printf("\n--- Books with price > %.2f ---\n", price_threshold);
    int count = 0;
    for (int i = 0; i < n; i++) {
        if (books[i].price > price_threshold) {
            printf("Title: %s, Author: %s, Price: %.2f\n",
                   books[i].title, books[i].author, books[i].price);
            count++;
        }
    }
    
    if (count == 0) {
        printf("No books found above that price.\n");
    }

    return 0;
}