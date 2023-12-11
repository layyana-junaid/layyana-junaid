/*
 *Programmmer: Layyana Junaid 23k-0056
 *Date: 11th December 2023
 *Description: Calculating the Sara Stores profit and displaying the menu and all
 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// defining a structure to store the values of the prices of the items of 4 different stores
typedef struct {
	char name_ofitems[20];
	float prices[4];
} store_items; 

// defining a struture to store the values of Sara's store

typedef struct {
	store_items items[5]; // assuming there are four items in her shop
	float average_prices[5];
	float savings[5];
} mommy_savers;

void cal_avgand_savings(mommy_savers *store) {
	int i, j; // i is the counter for items and j is the counter for prices 

	for(i = 0; i < 5; i++) {
		float sum = 0; // initializing
		for(j = 0; j < 4; j++) {
			sum += store->items[i].prices[j]; 
		}
		store->average_prices[i] = sum / 4;

		float selling_price = store->average_prices[i] * 1.1;
		store->savings[i] = selling_price - store->average_prices[i]; // i bascially is storing for different products 
	}

} // end of calculating average and savings

void displaying_storeproducts(mommy_savers *store) {
	printf("Menu: \n");
	for(int i = 0; i < 5; i++) {
		printf("%s: $%.2f\n", store->items[i].name_ofitems, store->items[i].prices[0]);
	}

	printf("\nSavings:\n");
	for(int i = 0; i < 5; i++) {
		printf("%s: $%.2f\n", store->items[i].name_ofitems, store->items[i].savings[0]);
	}
}// end of menu


void customer_purchase(mommy_savers *store, char *family_members[], float budgets[]) {
	for(int i = 0; i < 5; i++) {
		printf("\n%s's Purchase:\n", family_members[i]);
		for(int j = 0; j < 5; j++) {
			printf("%s: $%.2f\n", store->items[j].name_ofitems, budgets[i] / 5);
		}
	}

} // end of customer_purchase 

int main(int argc, char const *argv[])
{
    // initializing sara's stores items
    mommy_savers mommy_savers = {
    	.items = {
    		{"Milk", {2.92, 3.89, 3.68, 3.89}},
            {"Bread", {1.5, 1.7, 1.8, 2.0}},
            {"Eggs", {1.2, 1.3, 1.25, 1.4}},
            {"Cheese", {4.5, 5.2, 4.8, 5.0}},
            {"Fruits", {6.0, 6.5, 6.2, 6.8}},
    	}
    };
    
    // calculating the average and savings
    cal_avgand_savings(&mommy_savers);

    //displaying the menu 
    displaying_storeproducts(&mommy_savers);

    // customer purchases
    char *family_members[] = {"Khalida", "Nadia", "Alisher", "Murad", "Raheem"};
    float budgets[] = {300, 450, 500, 200, 800};
    customer_purchase(&mommy_savers, family_members, budgets);

	return 0;
} // end main 