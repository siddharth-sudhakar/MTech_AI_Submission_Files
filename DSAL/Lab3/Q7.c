#include <stdio.h>

struct Date {
    int day;
    int month;
    int year;
};

void compareDates(struct Date d1, struct Date d2) {
    if (d1.year < d2.year) {
        printf("Date %d/%d/%d is earlier.\n", d1.day, d1.month, d1.year);
    } else if (d2.year < d1.year) {
        printf("Date %d/%d/%d is earlier.\n", d2.day, d2.month, d2.year);
    } else { // Years are the same, check months
        if (d1.month < d2.month) {
            printf("Date %d/%d/%d is earlier.\n", d1.day, d1.month, d1.year);
        } else if (d2.month < d1.month) {
            printf("Date %d/%d/%d is earlier.\n", d2.day, d2.month, d2.year);
        } else { // Months are also the same, check days
            if (d1.day < d2.day) {
                printf("Date %d/%d/%d is earlier.\n", d1.day, d1.month, d1.year);
            } else if (d2.day < d1.day) {
                printf("Date %d/%d/%d is earlier.\n", d2.day, d2.month, d2.year);
            } else {
                printf("Both dates are the same.\n");
            }
        }
    }
}

int main() {
    struct Date date1, date2;

    printf("Enter the first date (dd mm yyyy): ");
    
    scanf("%d %d %d", &date1.day, &date1.month, &date1.year);

    printf("Enter the second date (dd mm yyyy): ");
    scanf("%d %d %d", &date2.day, &date2.month, &date2.year);

    compareDates(date1, date2);

    return 0;
}