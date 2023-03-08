 class StockSpanner {
 public:
 	StockSpanner() {}		
 	int next(int price) {
 		int span = 1;
 		while(!stack_.empty() && price >= stack_.top().first){
 			span += stack_.top().second;
 			stack_.pop();
 		}
 		stack_.emplace(price, span);
 		return span;
 	}
 private:
 	stack<pair<int, int>> stack_; // first: price, second: span
 };