#include<iostream>
using namespace std;

int search(int nums[], int size, int target){
    int low = 0;
    int high = size - 1;

    while(low <= high){
        int mid = (low + high) / 2;

        if(nums[mid] == target){
            return mid;
        }
        else if(nums[mid] < target){
            low = mid + 1;
        }
        else{
            high = mid - 1;
        }
    }
    return -1;  
}

int main(void){
    int nums[] = {-1, 0, 3, 5, 9, 12};
    int size = sizeof(nums) / sizeof(nums[0]);
    int target1 = 9;
    int target2 = 2;

    cout << "INDEX OF TARGET 1: " << search(nums, size, target1) << endl;
    cout << "INDEX OF TARGET 2: " << search(nums, size, target2) << endl;

    return 0;
}