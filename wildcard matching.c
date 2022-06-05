bool isMatch(char * s, char * p)
{
    int len_s = strlen(s);
    int len_p = strlen(p);

    int t_rows = len_p + 1;
    int t_cols = len_s + 1;
    int t_len = t_rows * t_cols;

    bool* table = (bool*)malloc(t_len * sizeof(bool));
    memset(table, 0, t_len * sizeof(bool));

    int pos = 0;

    for (int i = 0; i < t_rows; i++) {
        for (int j = 0; j < t_cols; j++) {
            if (i == 0) {
                if (j == 0) {
                    table[0] = true;
                }
                pos++;
                continue;
            }

            if (p[i - 1] == '*') {
                if (table[pos - t_cols] == true ||
                    (j > 0 && table[pos - 1] == true))
                {
                    table[pos] = true;
                }
            } else if (p[i - 1] == '?') {
                if (j > 0 && table[pos - t_cols - 1] == true)
                {
                    table[pos] = true;
                }
            } else {
                if (j > 0 && table[pos - t_cols - 1] == true &&
                    p[i - 1] == s[j - 1])
                {
                    table[pos] = true;
                }
            }

            pos++;
        }
    }
    
    return table[pos - 1];
}
