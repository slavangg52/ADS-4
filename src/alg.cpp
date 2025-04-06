// Copyright 2021 NNTU-CS
int countPairs1(int *arr, int len, int value) {
  int count = 0;
  for (int i = 0; i < len; ++i) {
    for (int j = i + 1; j < len; ++j) {
      if (arr[i] + arr[j] == value)
        ++count;
      else if (arr[i] + arr[j] > value)
        break;
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
      int l = arr[left], r = arr[right];
      int lc = 0, rc = 0;
      while (left < right && arr[left] == l) {
        ++lc;
        ++left;
      }
      while (right >= left && arr[right] == r) {
        ++rc;
        --right;
      }
      count += lc * rc;
    } else if (sum < value) {
      ++left;
    } else {
      --right;
    }
  }
  return count;
}

int binarySearch(int *arr, int start, int end, int target) {
  int count = 0;
  while (start <= end) {
    int mid = (start + end) / 2;
    if (arr[mid] == target) {
      int i = mid;
      while (i >= start && arr[i] == target) {
        ++count;
        --i;
      }
      i = mid + 1;
      while (i <= end && arr[i] == target) {
        ++count;
        ++i;
      }
      return count;
    } else if (arr[mid] < target) {
      start = mid + 1;
    } else {
      end = mid - 1;
    }
  }
  return 0;
}

int countPairs3(int *arr, int len, int value) {
  int count = 0;
  for (int i = 0; i < len; ++i) {
    int target = value - arr[i];
    if (target < arr[i]) break;
    count += binarySearch(arr, i + 1, len - 1, target);
  }
  return count;
}
