// Copyright 2021 NNTU-CS
int countPairs1(int *arr, int len, int value) {
  int pairs = 0;
    for (int i = 0; i < len-1; i++)  {
        for (int j = i + 1; j < len; j++) {
            if (arr[i] + arr[j] == value) {
                pairs++;
            }
        }
    }
    return pairs;
}
int countPairs2(int *arr, int len, int value) {
    int pairs = 0;
    for (int i = 0; i < len - 1; i++) {
        for (int j = len - 1; j > i; j--) {
            if (arr[i] + arr[j] == value) {
                pairs++;
            }
        }
    }
    return pairs;
}
int cbinsearch(int *arr, int size, int value, int l) {
  int pairs = 0, i = l, j = size - 1, mid = 0;
    while (i < j) {
        mid = i + (j - i) / 2;
       if (arr[mid] == value && mid != l) {
            pairs++;
            int r = mid, l = mid;
               while (arr[r--] == value && r > l) {
                    pairs++;
                }
                while (arr[l++] == value) {
                    pairs++;
                }
                return pairs;
        } else if (arr[mid] > value) {
            j = mid - 1;
        } else {
            i = mid + 1;
        }
     }
        return 0;
    }
int countPairs3(int *arr, int len, int value) {
    int pairs = 0;
    int i = 0;
     while (i < len) {   
        if (arr[i] <= value - arr[i]) {
            pairs += cbinsearch(arr, len, value - arr[i], i);
        }
        i++;
    }
  return pairs;
}
