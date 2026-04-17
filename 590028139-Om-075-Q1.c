#include <stdio.h>
#include <stdlib.h>

struct Node {
    int sum;
    int index;
    struct Node* next;
};

#define SIZE 1000

struct Node* hashTable[SIZE];

int hash(int key) {
    return abs(key) % SIZE;
}

void insert(int sum, int index) {
    int h = hash(sum);
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->sum = sum;
    newNode->index = index;
    newNode->next = hashTable[h];
    hashTable[h] = newNode;
}

int search(int sum) {
    int h = hash(sum);
    struct Node* temp = hashTable[h];
    
    while (temp != NULL) {
        if (temp->sum == sum)
            return temp->index;
        temp = temp->next;
    }
    return -1;
}

int maxLen(int arr[], int n) {
    int prefix_sum = 0;
    int max_len = 0;

    for (int i = 0; i < SIZE; i++)
        hashTable[i] = NULL;

    for (int i = 0; i < n; i++) {
        prefix_sum += arr[i];

        if (prefix_sum == 0)
            max_len = i + 1;

        int prev_index = search(prefix_sum);

        if (prev_index != -1) {
            if (i - prev_index > max_len)
                max_len = i - prev_index;
        } else {
            insert(prefix_sum, i);
        }
    }

    return max_len;
}

int main() {
    int arr[] = {15, -2, 2, -8, 1, 7, 10, 23};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("Length of longest subarray with sum 0: %d\n", maxLen(arr, n));

    return 0;
}