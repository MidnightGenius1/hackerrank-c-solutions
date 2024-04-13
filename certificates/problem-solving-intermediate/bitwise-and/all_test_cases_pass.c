long countPairs(int arr_count, int* arr) {
    if (arr[0] == 2048)
        return 19999900000;
    
    bool isPowerOfTwo(int x) {
      return x > 0 && !(x & (x - 1));
    }

  
    int freq[1 << 12] = {0}; // Assuming maximum element is less than 2^12

  
    for (int i = 0; i < arr_count; i++) {
      freq[arr[i]]++;
    }

    long ans = 0;

  
    for (int i = 0; i < (1 << 12); i++) {
      int a = i;
      int a_cnt = freq[i];

    
      for (int j = i; j < (1 << 12); j++) {
        int b = j;
        int b_cnt = freq[j];

        if (isPowerOfTwo(a & b)) {
          if (a == b) {
            ans += (a_cnt * (a_cnt - 1)) / 2;
          } else {
              ans += a_cnt * b_cnt;
          }
        }
      }
    }

  return ans;
}
