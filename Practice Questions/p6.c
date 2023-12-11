/*
 *Programmer: Layyana Junaid 23k-0056
 *Date: 11th December 2023
 *Description: Filing Processing
 *
 */

#include <stdio.h>
#include <stdlib.h>

// creating function for menu 
void menu() {
    printf("\n Menu: \n");
    printf("1-Add Categories.");
    printf("2-Add Products.");
    printf("3-Generate Final Report.");
    printf("Enter '0' to stop the program.");
} // end menu 

void add_categories() {
    FILE *categories_file = fopen("categories.txt", "a"); // command to edit the file
    if(categories_file == NULL) {
        printf("Error Opening categories.txt file!\n");
        exit(1);
    }

    char category_name[50]; // name of categories present in the file
    int category_id; // user will input this

    printf("Enter the name of Category: ");
    scanf("%s", category_name);

    printf("Enter the Category ID: ");
    scanf("%d", &category_id);

    fprintf(categories_file, "%s %d\n", category_name, category_id);
    fclose(categories_file);

} // end of add categories

void add_products() {
    FILE *products_file = fopen("products.txt", "a"); // command to edit the file
    if(products_file == NULL) {
        printf("Error Opening products.txt file!\n");
        exit(1);
    }

    char product_name[50]; // name of the products present in the file 
    int product_id; //user will input this value
    float product_price; // price of the products entered by the user

    printf("Enter the name of Products: ");
    scanf("%s", product_name);

    printf("Enter the Category ID: ");
    scanf("%d", &product_id);

    printf("Enter the price of the product: ");
    scanf("%.2f", &product_price);

    fprintf(products_file,"%s %d %.2f\n", product_name, product_id, product_price);
    fclose(products_file);

} // end of add products 

void generate_finalresult() {
    FILE *categories_file = fopen("categories.txt", "r");
    FILE *products_file = fopen("products.txt", "r");
    FILE *final_file = fopen("final.txt", "w");

    if(categories_file == NULL || products_file == NULL || final_file == NULL) {
        printf("Error opening the file!\n");
        exit(1);
    }
    while(!feof(categories_file)) {
        char category_name[50];
        int category_id;
        fscanf(categories_file, "%s %d", category_name, &category_id);
        fprintf(final_file,"%s ", category_name);

        while(!feof(products_file)) {
            char product_name[50];
            int product_id;
            float product_price;
            fscanf(products_file, "%s %d %.2f", product_name, &product_id, &product_price);

            if(product_id == category_id) {
                fprintf(final_file, "%s %.2f", product_name, product_price);
            }
        }

        fseek(products_file, 0, SEEK_SET); // reset file pointer for the next category
        fprintf(final_file, "\n");
    }
    fclose(categories_file);
    fclose(products_file);
    fclose(final_file);
} // end of generating final file 

int main() {
    int choices; // input from the user
    do {
        menu();
        printf("Enter your choice: ");
        scanf("%d", &choices);

        switch (choices) {
        case 1: 
            add_categories();
             break;
        case 2:
            add_products();
            break;
        case 3:
            generate_finalresult();
            break;
        case 0:
            printf("Exiting the program!\n");
            break;
        default:
            printf("Invalid Choice! Please try again\n");

        } // ending switch 

    } while(choices != 0);

    return 0;
} // end main 