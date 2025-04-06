// Copyright 2021 NNTU-CS
int countPairs1(int *arr, int len, int value) {
  int count = 0;
  for (int i = 0; i < len; i++) {
    for (int j = i + 1; j < len; j++) {
      if (arr[i] + arr[j] == value) {
        count++;
      } else if (arr[i] + arr[j] > value) {
        break;
      }
    }
  }
  return count;
}

int countPairs2(int *arr, int len, int value) {
  int count = 0;
  int left = 0, right = len - 1;
  while (left < right) {
    int sum = arr[left] + arr[right];
    if (sum == value) {
      if (arr[left] == arr[right]) {
        int n = right - left + 1;
        count += n * (n - 1) / 2;
        break;
      } else {
        int lCount = 0, rCount = 0;
        int leftVal = arr[left], rightVal = arr[right];
        while (left < len && arr[left] == leftVal) {
          lCount++;
          left++;
        }
        while (right >= 0 && arr[right] == rightVal) {
          rCount++;
          right--;
        }
        count += lCount * rCount;
      }
    } else if (sum < value) {
      left++;
    } else {
      right--;
    }
  }
  return count;
}

int lower_bound_custom(int *arr, int left, int right, int target) {
  int l = left, r = right;
  while (l <= r) {
    int mid = l + (r - l) / 2;
    if (arr[mid] < target) {
      l = mid + 1;
    } else {
      r = mid - 1;
    }
  }
  return l;
}

int upper_bound_custom(int *arr, int left, int right, int target) {
  int l = left, r = right;
  while (l <= r) {
    int mid = l + (r - l) / 2;
    if (arr[mid] <= target) {
      l = mid + 1;
    } else {
      r = mid - 1;
    }
  }
  return l;
}

int binarySearchCount(int *arr, int left, int right, int target) {
  int lb = lower_bound_custom(arr, left, right, target);
  int ub = upper_bound_custom(arr, left, right, target);
  return ub - lb;
}

int countPairs3(int *arr, int len, int value) {
  int count = 0;
  for (int i = 0; i < len; i++) {
    int target = value - arr[i];
    if (target < arr[i]) {
      break;
    }
    int cnt = binarySearchCount(arr, i + 1, len - 1, target);
    count += cnt;
  }
  return count;
}
