#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void searchOnGoogle(const char *query) {
    // Create the search URL
    char url[256] = "https://www.google.com/search?q=";
    strcat(url, query);

    // Construct the command to open the browser
    #ifdef _WIN32
        // For Windows systems
        char command[256] = "start ";
        strcat(command, url);
    #elif __linux__
        // For Linux systems
        char command[256] = "xdg-open ";
        strcat(command, url);
    #elif __APPLE__
        // For macOS systems
        char command[256] = "open ";
        strcat(command, url);
    #else
        printf("Unsupported operating system\n");
        return;
    #endif

    // Execute the command to open the browser
    system(command);
}

int main() {
    char query[100];
    printf("Enter your search query: ");
    scanf("%[^\n]", query);

    searchOnGoogle(query);

    return 0;
}