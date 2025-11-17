/*Print all enum names and integer values using a loop.*/
#include <stdio.h>
enum Colors {
    RED,
    GREEN,
    BLUE,
    YELLOW,
    ORANGE,
    PURPLE,
    COLOR_COUNT // This will automatically be set to the number of colors
};
int main() {
    for (int i = 0; i < COLOR_COUNT; i++) {
        switch (i) {
            case RED:
                printf("RED = %d\n", RED);
                break;
            case GREEN:
                printf("GREEN = %d\n", GREEN);
                break;
            case BLUE:
                printf("BLUE = %d\n", BLUE);
                break;
            case YELLOW:
                printf("YELLOW = %d\n", YELLOW);
                break;
            case ORANGE:
                printf("ORANGE = %d\n", ORANGE);
                break;
            case PURPLE:
                printf("PURPLE = %d\n", PURPLE);
                break;
        }
    }
    return 0;
}