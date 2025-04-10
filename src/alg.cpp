// Copyright 2021 NNTU-CS
int pairCountBrute(int *array, int size, int targetSum) {
    int totalPairs = 0;
    for (int a = 0; a < size; a++) {
        for (int b = a + 1; b < size; b++) {
            if (array[a] + array[b] == targetSum) {
                totalPairs++;
            }
        }
    }
    return totalPairs;
}

int pairCountOptimized(int *array, int size, int targetSum) {
    int totalPairs = 0;
    int maxIndex = size - 1;

    while (maxIndex > 0 && array[maxIndex] > targetSum) {
        maxIndex--;
    }

    for (int i = 0; i < size; i++) {
        for (int j = maxIndex; j > i; j--) {
            if (array[i] + array[j] == targetSum) {
                totalPairs++;
            }
        }
    }

    return totalPairs;
}

int pairCountBinary(int *array, int size, int targetSum) {
    int totalPairs = 0;

    for (int i = 0; i < size; ++i) {
        int required = targetSum - array[i];
        int left = i + 1;
        int right = size - 1;

        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (array[mid] >= required) {
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }
        int firstMatch = left;

        left = i + 1;
        right = size - 1;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (array[mid] <= required) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
        int lastMatch = right;

        if (firstMatch <= lastMatch) {
            totalPairs += lastMatch - firstMatch + 1;
        }
    }

    return totalPairs;
}
