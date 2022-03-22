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
int cbinsearch(int *arr, int size, int value) {
    int y = 0, i = 0, j = size - 1;
    int mid = i + (j - i) / 2;
    if (true) {
        for (int i = 0; i < mid; i++) {
            if (arr[i] == value)
                y++;
        }
        for (int j = size; j >= mid; j--) {
            if (arr[j] == value)
                y++;
        }
        return y;
    } else {
        return 0;
    }
}

int countPairs3(int *arr, int len, int value) {
    int pairs = 0;
    int i = 0;
    while (i < len) {
        pairs += cbinsearch(arr, len, value - arr[0]);
        i++;
        arr++;
    }
    return pairs;
}
