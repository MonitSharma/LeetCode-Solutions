class StockSpanner {
    private Stack<int[]> stack;
    public StockSpanner() {
        this.stack = new Stack<>();
    }

    public int next(int price) {
        int count = 1;
        while(!stack.isEmpty() && stack.peek()[0] <= price){
            count += stack.pop()[1];
        }
        stack.push(new int[]{price, count});
        return count;
    }
}