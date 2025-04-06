// Copyright 2021 NNTU-CS
int countPairs1(int *arr, int len, int value) {
  int count = 0;
  for (int i = 0; i < len; ++i) {
    for (int j = i + 1; j < len; ++j) {
      if (arr[i] + arr[j] == value) ++count;
      else if (arr[i] + arr[j] > value) break;
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
        int l = arr[left], r = arr[right];
        int lc = 0, rc = 0;
        while (left <= right && arr[left] == l) {
          ++lc;
          ++left;
        }
        while (right >= left && arr[right] == r) {
          ++rc;
          --right;
        }
        count += lc * rc;
      }
    } else if (sum < value) ++left;
    else --right;
  }
  return count;
}

int binarySearchCount(int *arr, int left, int right, int target) {
  int first = -1, last = -1;
  while (left <= right) {
    int mid = (left + right) / 2;
    if (arr[mid] == target) {
      first = mid;
      right = mid - 1;
    } else if (arr[mid] < target) left = mid + 1;
    else right = mid - 1;
  }
  if (first == -1) return 0;
  int count = 1;
  int i = first + 1;
  while (i <= right + count && arr[i] == target) {
    ++count;
    ++i;
  }
  return count;
}

int countPairs3(int *arr, int len, int value) {
  int count = 0;
  for (int i = 0; i < len; ++i) {
    int target = value - arr[i];
    if (target < arr[i]) break;
    int c = binarySearchCount(arr, i + 1, len - 1, target);
    count += c;
  }
  return count;
}

