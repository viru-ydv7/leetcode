class MinStack
 {
    public:
    vector<int>v;
    vector<int> minimum;
        MinStack() {}
        
        void push(int value) {
            v.push_back(value);
            if(minimum.empty()){
                minimum.push_back(value);
            }
            else{
                minimum.push_back(min(value,minimum.back()));
            }
        }
        
        void pop() {
        v.pop_back();
        minimum.pop_back();
            
            
        }
        
        int top() {
            return v.back() ;
        }
        int getMin() {
            return minimum.back();
            
        }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(value);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */