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
//nge1
class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        int n=nums2.size();
        stack<int>st;
        unordered_map<int,int>mp;//ele->nge
        //right to left(Isliye jab main current element par aau, mujhe right side ki information already pata honi chahiye.)
        //monotonic decreasing stack
        for(int i=n-1;i>=0;i--){
            int curr=nums2[i];
            while(!st.empty() && st.top()<=curr){
                st.pop();
            }
            if(st.empty()){
                mp[curr]=-1;
            }else{
                mp[curr]=st.top();
            }
            st.push(curr);

        }
        vector<int>ans;
        for(int x:nums1){
        ans.push_back(mp[x]);
        }
        return ans;
    }
};
//nge2
class Solution {
public:
//isme circular hone ki wjh se array 2 bar traverse krte h n bar nhi nhi 2n bar 
//aur jb index greater than n aaye tnb use normal krne k liye use i %size of array(n)[i%n]
/*2*n traversal
i % n
if(i < n)*/
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n=nums.size();
        stack<int>st;
       vector<int>nge(n);//give size 0 size me update nhi kara paogi through index
        for(int i=2*n-1;i>=0;i--){
            int curr=nums[i%n];
            while(!st.empty() && st.top()<=curr){
                st.pop();// bada curr milte hi hatao in chutko ko
            }
            if(i<n){
            if(st.empty()){
              nge[i]=-1;
            }else{
                nge[i]=st.top();
            }}
            st.push(curr);

        }
        return nge;
        
    }
};
//nge1 brute force
class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {

        vector<int> ans;

        for(int i = 0; i < nums1.size(); i++) {

            bool found = false;

            for(int j = 0; j < nums2.size(); j++) {

                if(nums2[j] == nums1[i]) {

                    for(int k = j + 1; k < nums2.size(); k++) {

                        if(nums2[k] > nums1[i]) {

                            ans.push_back(nums2[k]);
                            found = true;
                            break;
                        }
                    }

                    break; // nums1[i] nums2 me mil gaya
                }
            }

            if(!found) {
                ans.push_back(-1);
            }
        }

        return ans;
    }
};
//nge2 brute force
class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {

        int n = nums.size();
        vector<int> nge(n, -1);

        for(int i = 0; i < n; i++) {

            for(int j = i + 1; j <= i + n - 1; j++) {

                int idx = j % n;

                if(nums[idx] > nums[i]) {
                    nge[i] = nums[idx];
                    break;
                }
            }
        }

        return nge;
    }
};
//pse 
//brute force
for(i=0 to n-1)
{
    for(j=i-1 to 0)
    {
        if(arr[j] < arr[i])
        {
            nse[i] = arr[j];
            break;
        }
    }
}
//monotonic stack
//in nge its st.top()<=curr and in nse its st.top() >= curr
//in nge it was r to l
//in nse it was l to r
class Solution {
  public:
    vector<int> prevSmaller(vector<int>& arr) {
        //  code here
        int n=arr.size();
        stack<int>st;
        vector<int>nse(n);
        for(int i=0;i<n;i++){
            int curr=arr[i];
            while(!st.empty() && st.top()>=curr){
                st.pop();
            }
            if(st.empty()){
                nse[i]=-1;
            }else{
                nse[i]=st.top();
            }
            st.push(curr);
        }
        return nse;
    }
};
//Numbe of NGEs to the right
//trapping rainwater
class Solution {
public:
    int trap(vector<int>& height) {
        //2 pointers 
        int n=height.size();
        int l=0;
        int r=n-1;
        int lmax=-1;
        int rmax=-1;
        int water=0;
        while(l<r){
            lmax=max(lmax,height[l]);
            rmax=max(rmax,height[r]);
            if(lmax<rmax){
                water+=lmax-height[l];
                l++;
            }else{
                water+=rmax-height[r];
                r--;
            }

        }
        return water;
    }
};