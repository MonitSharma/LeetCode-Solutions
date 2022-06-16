class Solution {
    public String simplifyPath(String path) {
        String[] arr=path.split("/");
        Stack<String> s=new Stack();
        for(String str: arr){
            if(str.equals(".") || str.length()==0){
                continue;
            }else if(str.equals("..")){
                if(s.size()>0){
                s.pop();
                }
            }else{
                s.push(str);
            }
        }
        String ans="";
        while(s.size()>0){
            ans="/"+s.pop()+ans;
        }
        if(ans.length()==0){
            ans="/";
        }
        return ans;
    }
}