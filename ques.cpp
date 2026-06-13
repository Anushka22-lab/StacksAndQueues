//Valid Parentheses
class Solution {
public:
    bool isValid(string s) {
        stack<char> st;

        for(int i = 0; i < s.size(); i++) {

            if(s[i] == '(' || s[i] == '[' || s[i] == '{') {
                st.push(s[i]);
            }
            else {

                if(st.empty())
                    return false;

                char x = st.top();
                st.pop();

                if((x == '(' && s[i] != ')') ||
                   (x == '[' && s[i] != ']') ||
                   (x == '{' && s[i] != '}')) {
                    return false;
                }
            }
        }

        if(st.empty())
            return true;

        return false;
    }
};
// implement minstack
//by 2 stacks
class MinStack {
public:
stack<int>st;
stack<int>ms;
//2 stacks maintain kro
    MinStack() {
        
        
    }
    
    void push(int value) {
        st.push(value);
        if(ms.empty()){
            ms.push(value);
        }else{
            ms.push(min(value,ms.top()));
        }
       

        
    }
    
    void pop() {
        st.pop();
        ms.pop();
       
        
    }
    
    int top() {
      return st.top();
    
        
    }
    
    int getMin() {
       return ms.top();
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
//by stack<pair<int,int>>st(inserting a 2d value each time)
class MinStack {
public:
    stack<pair<int, int>> st;
    MinStack() {
        
    }
    
    void push(int val) {
        if (!st.empty()) {
            st.push({val, min(val, st.top().second)});
        } else {
            st.push({val, val});
        }
    }
    
    void pop() {
        st.pop();
    }
    
    int top() {
        return st.top().first;
    }
    
    int getMin() {
        return st.top().second;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */
//newval=2*val-prevmin
class MinStack {
public:
    stack<long long> st;
    long long mini;

    MinStack() {
    }

    void push(int val) {

        if(st.empty()) {
            mini = val;
            st.push(val);
        }
        else {
            if(val >= mini) {
                st.push(val);
            }
            else {
                st.push(2LL * val - mini);
                mini = val;
            }
        }
    }

    void pop() {

        if(st.empty()) return;

        long long x = st.top();
        st.pop();

        if(x < mini) {
            mini = 2 * mini - x;
        }
    }

    int top() {

        long long x = st.top();

        if(x < mini)
            return mini;

        return x;
    }

    int getMin() {
        return mini;
    }
};
