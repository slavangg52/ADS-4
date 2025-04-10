// Copyright 2021 NNTU-CS
int countPairs1(int *array, int length, int target) {
    int pairCount = 0;
    for (int first = 0; first < length; first++) {
        for (int second = first + 1; second < length; second++) {
            if (array[first] + array[second] == target) {
                pairCount++;
            }
        }
    }
    return pairCount;
}

int countPairs2(int *array, int length, int target) {
    int pairCount = 0;
    int upperBound = length - 1;

    while (upperBound > 0 && array[upperBound] > target) {
        upperBound--;
    }

    for (int left = 0; left < length; left++) {
        for (int right = upperBound; right > left; right--) {
            if (array[left] + array[right] == target) {
                pairCount++;
            }
        }
    }

    return pairCount;
}

int countPairs3(int *array, int length, int target) {
    int pairCount = 0;

    for (int index = 0; index < length; ++index) {
        int required = target - array[index];
        int low = index + 1;
        int high = length - 1;

        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (array[mid] >= required) {
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        int firstMatch = low;

        low = index + 1;
        high = length - 1;
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (array[mid] <= required) {
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
        int lastMatch = high;

        if (firstMatch <= lastMatch) {
            pairCount += lastMatch - firstMatch + 1;
        }
    }

    return pairCount;
}
