char* addBinary(char* a, char* b) {
  int i = strlen(a) - 1, j = strlen(b) - 1;
  if (i < j) {
    char* t = a;
    a = b, b = t;
    int k = i;
    i = j, j = k;
  }
  const int aLen = i+1;;

  while (i > 0 && j >= 0) {
    a[i] += b[j] - '0';
    a[i - 1] += (a[i] - '0') >> 1;
    a[i] = (a[i] & 1) + '0';
    j--;
    i--;
  }
  if (j == 0)
    a[0] += b[0] - '0';
  else
    while (i > 0 && a[i] > '1') {
      a[i - 1] += (a[i] - '0') >> 1;
      a[i] = (a[i] & 1) + '0';
      i--;
    }

  if (a[0] > '1') {
    char *c = malloc(aLen+2);
    memcpy(c+1, a, aLen);
    c[0] = '0' + ((c[1] - '0') >> 1);
    c[1] = (c[1]&1) + '0';
    c[aLen+1] = 0;
    a = c;
  }
  return a;
}