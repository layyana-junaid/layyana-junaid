#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure to represent an employee
typedef struct {
    int employee_ID;
    char first_name[50];
    char last_name[50];
    double hourly_rate;
    double hours_per_week;
} Employee;

// Function to input employee data from the user
void inputEmployeeData(Employee *employee) {
    printf("Enter Employee ID: ");
    scanf("%d", &employee->employee_ID);

    printf("Enter First Name: ");
    scanf("%s", employee->first_name);

    printf("Enter Last Name: ");
    scanf("%s", employee->last_name);

    printf("Enter Hourly Rate: ");
    scanf("%lf", &employee->hourly_rate);

    printf("Enter Hours per Week: ");
    scanf("%lf", &employee->hours_per_week);
}

// Function to store the new record(s) in the file
void storeRecordInFile(Employee *employee, FILE *file) {
    fprintf(file, "%d,%s,%s,%.2lf,%.2lf\n",
            employee->employee_ID, employee->first_name, employee->last_name,
            employee->hourly_rate, employee->hours_per_week);
}

// Function to calculate weekly income for an employee
double calculateWeeklyIncome(Employee *employee) {
    return employee->hourly_rate * employee->hours_per_week;
}

// Function to compare employees for sorting in descending order
int compareEmployees(const void *a, const void *b) {
    return ((Employee *)b)->hourly_rate * ((Employee *)b)->hours_per_week -
           ((Employee *)a)->hourly_rate * ((Employee *)a)->hours_per_week;
}

// Function to display salaries for all employees in descending order
void displaySalariesDescending(Employee *employees, int numEmployees) {
    qsort(employees, numEmployees, sizeof(Employee), compareEmployees);

    printf("\nSalaries in Descending Order:\n");
    printf("%-15s%-15s%-15s%-15s%-15s\n",
           "Employee ID", "First Name", "Last Name", "Hourly Rate", "Weekly Income");

    for (int i = 0; i < numEmployees; ++i) {
        double weeklyIncome = calculateWeeklyIncome(&employees[i]);
        printf("%-15d%-15s%-15s%-15.2lf%-15.2lf\n",
               employees[i].employee_ID, employees[i].first_name, employees[i].last_name,
               employees[i].hourly_rate, weeklyIncome);
    }
}

// Function to remove a record based on full name
void removeRecordByFullName(char *fullName, FILE *inputFile, FILE *outputFile) {
    Employee employee;

    // Read records from the input file
    while (fscanf(inputFile, "%d,%[^,],%[^,],%lf,%lf\n",
                  &employee.employee_ID, employee.first_name, employee.last_name,
                  &employee.hourly_rate, &employee.hours_per_week) == 5) {
        // Check if the full name matches
        char full_name[100];
        snprintf(full_name, sizeof(full_name), "%s %s", employee.first_name, employee.last_name);

        if (strcmp(full_name, fullName) != 0) {
            // Save the record in the output file
            fprintf(outputFile, "%d,%s,%s,%.2lf,%.2lf\n",
                    employee.employee_ID, employee.first_name, employee.last_name,
                    employee.hourly_rate, employee.hours_per_week);
        }
    }
}

int main() {
    FILE *file = fopen("Employees.txt", "a+");
    if (file == NULL) {
        perror("Error opening file");
        return 1;
    }

    int numEmployees;
    printf("Enter the number of employees to input: ");
    scanf("%d", &numEmployees);

    // Input employee data and store records in the file
    for (int i = 0; i < numEmployees; ++i) {
        Employee employee;
        inputEmployeeData(&employee);
        storeRecordInFile(&employee, file);
    }

    // Read all records from the file for processing
    rewind(file);
    Employee *employees = malloc(numEmployees * sizeof(Employee));
    int index = 0;

    while (fscanf(file, "%d,%[^,],%[^,],%lf,%lf\n",
                  &employees[index].employee_ID, employees[index].first_name, employees[index].last_name,
                  &employees[index].hourly_rate, &employees[index].hours_per_week) == 5) {
        index++;
    }

    // Display salaries in descending order
    displaySalariesDescending(employees, numEmployees);

    // Remove a record based on full name
    char fullNameToRemove[100];
    printf("\nEnter the full name to remove (First Last): ");
    scanf(" %[^\n]", fullNameToRemove);

    FILE *outputFile = fopen("TempEmployees.txt", "w");
    if (outputFile == NULL) {
        perror("Error opening output file");
        fclose(file);
        free(employees);
        return 1;
    }

    removeRecordByFullName(fullNameToRemove, file, outputFile);

    // Close and reopen the input file to truncate it
    fclose(file);
    file = fopen("Employees.txt", "w");
    fclose(outputFile);

    // Copy the contents of TempEmployees.txt back to Employees.txt
    outputFile = fopen("TempEmployees.txt", "r");
    if (outputFile == NULL) {
        perror("Error opening output file");
        fclose(file);
        free(employees);
        return 1;
    }

    char c;
    while ((c = fgetc(outputFile)) != EOF) {
        fputc(c, file);
    }

    fclose(file);
    fclose(outputFile);

    // Clean up and free memory
    free(employees);

    return 0;
}
