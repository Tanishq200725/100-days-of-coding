/*Show that enums store integers by printing assigned values.*/
#include <stdio.h>
enum Weekday { Sunday = 1, Monday, Tuesday, Wednesday, Thursday, Friday, Saturday };
int main() {
    enum Weekday today;
    today = Wednesday;
    printf("The value of Wednesday is: %d\n", today);
    return 0;
}