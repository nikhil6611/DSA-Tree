class StockSpanner {
public:
    stack<int>s;
    vector<int>arr;
    StockSpanner() {
        
    }
    
    int next(int price) {
        
        arr.push_back(price);
        while(!s.empty() && arr[s.top()]<=price){
            s.pop();
        }
        if(s.empty()){
            s.push(arr.size()-1);
            return arr.size();
        }
        else{
            int val=arr.size()-1 - s.top();
            s.push(arr.size()-1);
            return val;
        }
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */