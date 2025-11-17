/*Create an enum for months and print how many days each month has.*/
#include <stdio.h>
enum Month {
    JANUARY = 1,
    FEBRUARY,
    MARCH,
    APRIL,
    MAY,
    JUNE,
    JULY,
    AUGUST,
    SEPTEMBER,
    OCTOBER,
    NOVEMBER,
    DECEMBER
};
int getDaysInMonth(enum Month month, int isLeapYear) {
    switch (month) {
        case JANUARY: return 31;
        case FEBRUARY: return isLeapYear ? 29 : 28;
        case MARCH: return 31;
        case APRIL: return 30;
        case MAY: return 31;
        case JUNE: return 30;
        case JULY: return 31;
        case AUGUST: return 31;
        case SEPTEMBER: return 30;
        case OCTOBER: return 31;
        case NOVEMBER: return 30;
        case DECEMBER: return 31;
        default: return 0;
    }
}