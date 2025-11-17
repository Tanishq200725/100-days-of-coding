/*Assign explicit values starting from 10 and print them.*/
#include <stdio.h>
enum Numbers {
    TEN = 10,
    ELEVEN,
    TWELVE,
    THIRTEEN,
    FOURTEEN
};
int main() {
    printf("TEN: %d\n", TEN);
    printf("ELEVEN: %d\n", ELEVEN);
    printf("TWELVE: %d\n", TWELVE);
    printf("THIRTEEN: %d\n", THIRTEEN);
    printf("FOURTEEN: %d\n", FOURTEEN);
    return 0;
}