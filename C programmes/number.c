#include <stdio.h>
void find_all_possible_numbers_with_repetition(int);
int main() {
    int num;

    printf("Enter a three-digit number: ");
    scanf("%d", &num);

    find_all_possible_numbers_with_repetition(num);

    return 0;
}

void find_all_possible_numbers_with_repetition(int num) {
    // Extract digits
    int hundreds = num / 100;
    int tens = (num % 100) / 10;
    int units = num % 10;

    printf("All possible numbers with repetition from %d:\n", num);

    // Generate and print all combinations
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            for (int k = 0; k < 3; k++) {
                printf("%d%d%d\n", hundreds, tens, units);
            }
            units = num % 10; // Reset units digit for each tens digit
        }
        tens = (num % 100) / 10; // Reset tens digit for each hundreds digit
        units = num % 10; // Reset units digit for each hundreds digit
    }
}




