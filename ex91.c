#include <stdio.h>
#include <stdlib.h>

int main() {
    int choice;

    printf("Choose an option:\n");
    printf("1. Open Calculator\n");
    printf("2. Open YouTube\n");
    printf("3. Open Calendar\n");
    printf("4. Open WhatsApp\n");
    printf("5. Open Instagram\n");
    printf("6. Open Facebook\n");
    printf("7. Open File Explorer\n");
    printf("8. Open Search\n");
    printf("9. Open VS Code\n");
    printf("10. Open Chrome\n");
    printf("11. Open Brave\n");
    printf("12. Open Microsoft Store\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    switch(choice) {
        case 1:
            system("start calc");
            break;
        case 2:
            system("start https://www.youtube.com");
            break;
        case 3:
            system("start outlookcal:");
            break;
        case 4:
            system("start https://web.whatsapp.com");
            break;
        case 5:
            system("start https://www.instagram.com");
            break;
        case 6:
            system("start https://www.facebook.com");
            break;
        case 7:
            system("start explorer");
            break;
        case 8:
            system("start ms-search:");
            break;
        case 9:
            system("code");
            break;
        case 10:
            system("start chrome");
            break;
        case 11:
            system("start brave");
            break;
        case 12:
            system("start ms-windows-store:");
            break;
        default:
            printf("Invalid choice!\n");
            break;
    }

    return 0;
}
