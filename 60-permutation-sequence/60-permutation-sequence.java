class Solution {
    public String getPermutation(int n, int k) {
        ArrayList<Integer> arr = new ArrayList<>();
        int fact=1;
        for(int i=1;i<n;i++){
            fact=fact*i;
            arr.add(i);
        }
        arr.add(n);
        k=k-1;
        String ans="";
        while(true){
            int i1 = k/fact;
            int i2 = k%fact;
            ans+=arr.get(i1);
            arr.remove(i1);
            k=i2;
            if(arr.size()==0){
                break;
            }
            fact=fact/arr.size();
        }
        return ans;
    }
}