class Solution {
    public List<String> fullJustify(String[] words, int maxWidth) {
        List<String> res = new ArrayList<>();
        StringBuffer sb = new StringBuffer();
        int index = 0;
        while (index < words.length) {
            int count = 0;
            int total = 0;
            if (words[index].length() == maxWidth) {
                res.add(words[index]);
                index++;
                continue;
            }
            while (index < words.length && sb.length() + 1 + words[index].length() <= maxWidth) {
                count++;
                if (sb.length() > 0) {
                    sb.append(" ");
                }
                sb.append(words[index]);
                index++;
            }
            if (count == 1 || index == words.length) {
                while (sb.length() != maxWidth) {
                    sb.append(" ");
                }
                res.add(sb.toString());
                sb = new StringBuffer();
                continue;
            }
            String s = adjust(sb.toString(), maxWidth);
            res.add(s);
            sb = new StringBuffer();
        }
        return res;
    }
    private String adjust(String s, int max) {
        String[] array = s.split(" ");
        int total = 0;
        for (String s1 : array) {
            total += s1.length();
        }
        int remain = max - total;
        while (remain > 0) {
            for (int i = 0; i < array.length - 1; i++) {
                if (remain > 0) {
                    array[i] = array[i] + " ";
                    remain--;
                } else {
                    break;
                }
            }
        }
        StringBuffer sb = new StringBuffer();
        for (String s1 : array) {
            sb.append(s1);
        }
        return sb.toString();
    }
}