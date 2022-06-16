class Solution {
    public String addBinary(String a, String b) {

        int i = a.length() - 1;
        int j = b.length() - 1;

        StringBuilder sb = new StringBuilder();
        int sum = 0;

        while(i >= 0 || j >= 0){

            sum /= 2;
            if(i >= 0) sum += a.charAt(i) - '0';
            if(j >= 0) sum += b.charAt(j) - '0';

            sb.append(sum % 2);
            i--;
            j--;

        }

        if(sum / 2 != 0) sb.append(1);
        return sb.reverse().toString();
    }
}