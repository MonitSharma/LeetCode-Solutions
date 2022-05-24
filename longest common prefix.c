char * longestCommonPrefix(char ** strs, int strsSize) {
  if (strsSize == 0)
    return "";

  size_t strMaxLen;
  int i, j;

  char * prefix = malloc(sizeof(char) * 200); 
  strMaxLen = strlen(*strs);
  
  for (i = 0; i < strMaxLen; i++) {
    for (j = 1; j < strsSize; j++) {
      if (strs[j][i] != strs[j-1][i]) {
        *prefix = '\0';
        return prefix - i;
      }
    }
    *prefix = strs[0][i];
    prefix++;
  }
  *prefix = '\0';
  return prefix-i;
}