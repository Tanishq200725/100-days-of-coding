//Write a program to print the following pattern:

//*

//*
//*
//*

//*
//*
//*
//*
//*

//*
//*
//*

//*
#include <stdio.h>
int main() {
    int i;

    // Block 1: 3 stars
    for(i = 1; i <= 3; i++) {
        printf("*\n");
    }
    printf("\n");

    // Block 2: 5 stars
    for(i = 1; i <= 5; i++) {
        printf("*\n");
    }
    printf("\n");

    // Block 3: 3 stars
    for(i = 1; i <= 3; i++) {
        printf("*\n");
    }
    printf("\n");

    // Block 4: 1 star
    printf("*\n");

    return 0;
}





