class Solution {
    public int largestRectangleArea(int[] heights) {
        Stack < Integer > stack = new Stack < > ();
        int[] left = new int[heights.length];
        int[] right = new int[heights.length];
        Arrays.fill(right,heights.length);
        Arrays.fill(left,-1);
        for(int i = 0;i<heights.length;i++){
            while(!stack.empty()&&heights[stack.peek()]>heights[i]){
                right[stack.peek()] = i;
                stack.pop();
            }
            stack.push(i);
        }
        
        stack = new Stack<>();
        for(int i = heights.length-1;i>=0;i--){
            while(!stack.empty()&&heights[stack.peek()]>heights[i]){
                left[stack.peek()] = i;
                stack.pop();
            }
            stack.push(i);
        }
        
        
        int maxArea = 0;
        for (int i = 0; i < heights.length; ++i) {
            maxArea = Math.max(maxArea,(right[i]-left[i]-1)*heights[i]);
        }
        
        return maxArea;
    }
}