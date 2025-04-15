// Copyright 2021 NNTU-CS
int countPairs1(int *arr, int len, int value) {
  int a = 0;
    for (int i = 0; i < len - 1; i++) {
        if (arr[i] > value) break;
        for (int j = i + 1; j < len; ++j) {
            if (arr[i] + arr[j] == value) {
                a++;
            }
            else if (arr[i] + arr[j] > value) {
                break;
            }
        }
    }
    return a;
}

int countPairs2(int *arr, int len, int value) {
  int a = 0;
    int start = 0, end = len - 1;
    while (start < end) {
        int sum = arr[start] + arr[end];
        if (sum == value) {
            int countStart = 1, countEnd = 1;
            while (start + countStart < end && arr[start + countStart] == arr[start]) {
                countStart++;
            }
            while (end - countEnd > start && arr[end - countEnd] == arr[end]) {
                countEnd++;
            }
            a += countStart * countEnd;
            start += countStart;
            end -= countEnd;
        } else if (sum < value) {
            start++;
        } else {
            end--;
        }
    }
    return a;
}

int countPairs3(int *arr, int len, int value) {
  int a = 0;
    for (int i = 0; i < len; ++i) {
        int target = value - arr[i];
        int first = -1, low = i + 1, high = len - 1;
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (arr[mid] >= target) {
                high = mid - 1;
                if (arr[mid] == target) first = mid;
            } else {
                low = mid + 1;
            }
        }
        if (first != -1) {
            int last = first;
            low = first;
            high = len - 1;
            while (low <= high) {
                int mid = low + (high - low) / 2;
                if (arr[mid] <= target) {
                    low = mid + 1;
                    if (arr[mid] == target) last = mid;
                } else {
                    high = mid - 1;
                }
            }
            a += last - first + 1;
        }
    }
    return a;
}
