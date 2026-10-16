#include <stdio.h>
#include <string.h>

#define MAX 100

int main() {
    char id[MAX][20];
    char title[MAX][50];
    char author[MAX][50];
    char category[MAX][30];
    int edition[MAX];
    float price[MAX];

    int count = 0;
    int choice, i, found;
    char searchId[20];
    float limit;

    FILE *fp = fopen("task8.txt", "r");

    if (fp != NULL) {
        while (count < MAX && fscanf(fp, "%19s %49s %49s %29s %d %f",
                      id[count],
                      title[count],
                      author[count],
                      category[count],
                      &edition[count],
                      &price[count]) == 6) {
            count++;
        }

        fclose(fp);
    }

    do {
        printf("\n==================== MENU ====================\n");
        printf("1. Add a record\n");
        printf("2. Search a record by Id\n");
        printf("3. Show all records\n");
        printf("4. Show books with price greater than a given limit\n");
        printf("5. Save and exit\n");
        printf("Enter your choice: ");

        if (scanf("%d", &choice) != 1) {
            printf("Invalid input!\n");
            return 1;
        }

        switch (choice) {

            case 1:
                if (count >= MAX) {
                    printf("Library is full!\n");
                    break;
                }

                printf("Enter Book ID: ");
                scanf("%19s", id[count]);

                found = 0;

                for (i = 0; i < count; i++) {
                    if (strcmp(id[i], id[count]) == 0) {
                        found = 1;
                        break;
                    }
                }

                if (found) {
                    printf("Book ID already exists!\n");
                    break;
                }

                printf("Enter Title: ");
                scanf("%49s", title[count]);

                printf("Enter Author: ");
                scanf("%49s", author[count]);

                printf("Enter Category: ");
                scanf("%29s", category[count]);

                printf("Enter Edition: ");
                scanf("%d", &edition[count]);

                printf("Enter Price: ");
                scanf("%f", &price[count]);

                count++;

                printf("Book added successfully!\n");
                break;

            case 2:
                printf("Enter Book ID to search: ");
                scanf("%19s", searchId);

                found = 0;

                for (i = 0; i < count; i++) {
                    if (strcmp(id[i], searchId) == 0) {
                        printf("\nBook Found!\n");
                        printf("ID: %s\n", id[i]);
                        printf("Title: %s\n", title[i]);
                        printf("Author: %s\n", author[i]);
                        printf("Category: %s\n", category[i]);
                        printf("Edition: %d\n", edition[i]);
                        printf("Price: %.2f\n", price[i]);

                        found = 1;
                        break;
                    }
                }

                if (!found) {
                    printf("Book not found!\n");
                }

                break;

            case 3:
                if (count == 0) {
                    printf("No records available!\n");
                    break;
                }

                for (i = 0; i < count; i++) {
                    printf("\nBook %d\n", i + 1);
                    printf("ID: %s\n", id[i]);
                    printf("Title: %s\n", title[i]);
                    printf("Author: %s\n", author[i]);
                    printf("Category: %s\n", category[i]);
                    printf("Edition: %d\n", edition[i]);
                    printf("Price: %.2f\n", price[i]);
                }

                break;

            case 4:
                printf("Enter price limit: ");

                if (scanf("%f", &limit) != 1) {
                    printf("Invalid price!\n");
                    return 1;
                }

                found = 0;

                for (i = 0; i < count; i++) {
                    if (price[i] > limit) {
                        printf("%s %s %s %s %d %.2f\n",
                               id[i],
                               title[i],
                               author[i],
                               category[i],
                               edition[i],
                               price[i]);

                        found = 1;
                    }
                }

                if (!found) {
                    printf("No books found above this price!\n");
                }

                break;

            case 5:
                fp = fopen("task8.txt", "w");

                for (i = 0; i < count; i++) {
                    fprintf(fp, "%s %s %s %s %d %.2f\n",
                            id[i],
                            title[i],
                            author[i],
                            category[i],
                            edition[i],
                            price[i]);
                }

                fclose(fp);

                printf("Records saved successfully!\n");
                printf("Exiting program...\n");
                break;

            default:
                printf("Invalid choice! Select 1-5.\n");
        }

    } while (choice != 5);

    return 0;
}

