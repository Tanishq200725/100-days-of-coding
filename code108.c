//Write a Program to take an integer array nums. Print an array answer such that answer[i] is equal to the product of all the elements of nums except nums[i]. The product of any prefix or suffix of nums is guaranteed to fit in a 32-bit integer.
#include <stdio.h>
void productExceptSelf(int* nums, int numsSize, int* answer) {
    int leftProduct = 1;
    for (int i = 0; i < numsSize; i++) {
        answer[i] = leftProduct;
        leftProduct *= nums[i];
    }

    int rightProduct = 1;
    for (int i = numsSize - 1; i >= 0; i--) {
        answer[i] *= rightProduct;
        rightProduct *= nums[i];
    }
}
int main() {
    int nums[] = {1, 2, 3, 4};
    int numsSize = sizeof(nums) / sizeof(nums[0]);
    int answer[numsSize];

    productExceptSelf(nums, numsSize, answer);

    printf("Output array: ");
    for (int i = 0; i < numsSize; i++) {
        printf("%d ", answer[i]);
    }
    printf("\n");

    return 0;
}