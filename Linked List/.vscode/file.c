#include <stdio.h>
#include <string.h>

int main() {
    FILE *fp;
    char address[15];
    char search[15];

    printf("Enter the IP address to search: ");
    scanf("%s", search);

    fp = fopen("addresses.txt", "r");

    while (fscanf(fp, "%s", address) != EOF) {
        if (strcmp(address, search) == 0) {
            printf("address found!\n");
            return 0;
        }
    }

    printf("address not found.\n");
    return 0;
}