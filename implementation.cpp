//Stack using Array
class myStack {
  public:
  //here we maintain top index of array
  int top;
  int capacity;
  int arr[1000];
    myStack(int n) {
        // Define Data Structures
         capacity=n;
         arr[capacity];
        top=-1;
    }
    bool isEmpty() {
        // check if the stack is empty
        return top==-1;
    }
    bool isFull() {
        // check if the stack is full
        
        return top==capacity-1;
    }
    void push(int x) {
        if(isFull()){
            return;
        }
        // inserts x at the top of the stack
        arr[++top]=x;
            }
    void pop() {
        if(isEmpty()){
            return;
        }
        // removes an element from the top of the stack
       top--;
    }
    int peek() {
        // Returns the top element of the stack
        if(isEmpty())return -1;
        return arr[top];
    }
};
//------------------------------------------------------------

//Stack using LL
/* Structure of linked list Node
class Node {
  public:
    int data;
    Node* next;

    Node(int x) {
        data = x;
        next = nullptr;
    }
};
*/
class myStack {

  public:
  Node* top;
    myStack() {
        // Initialize your data members
         top=nullptr;
    }

    bool isEmpty() {
        // check if the stack is empty
        return top==nullptr;
    }

    void push(int x) {
        // Adds an element x at the top of the stack
        Node* temp=new Node(x);
      
        temp->next=top;
        top=temp;
        
    }

    void pop() {
        // Removes the top element of the stack
        if(top==nullptr){
            return;}
        Node* temp=top;
        top=top->next;
        delete temp;
    }

    int peek() {
        // Returns the top element of the stack
        // If stack is empty, return -1
        if(isEmpty())return -1;
        return top->data;
    }

    int size() {
        // Returns the current size of the stack.
        int x=0;
        Node* temp=top;
        while(temp){
            x++;
            temp=temp->next;
            
        }
        return x;
    }
};
//------------------------------------------------------------
//Queue using Array
class myQueue {
public:
    int arr[1000];
    int front;
    int rear;
    int cap;

    myQueue(int n) {
        cap = n;
        front = 0;
        rear = -1;
    }

    bool isEmpty() {
        return (rear-front+1)== 0;
    }

    bool isFull() {
        return (rear-front+1)== cap;
    }

    void enqueue(int x) {
        if(isFull()) return;
        arr[++rear] = x;
    }

    void dequeue() {
        if(isEmpty()) return;
        front++;
    }

    int getFront() {
        if(isEmpty()) return -1;
        return arr[front];
    }

    int getRear() {
        if(isEmpty()) return -1;
        return arr[rear];
    }
};
//------------------------------------------------------------
//Queue using LL
class Node {
  public:
    int data;
    Node* next;

    Node(int new_data) {
        data = new_data;
        next = nullptr;
    }
};
//front me node remove and rear me node add
class myQueue {
    Node* rear;
    Node* front;

  public:
    myQueue() {
        // Initialize your data members
        front=rear=nullptr;
    }

    bool isEmpty() {
        // check if the queue is empty
        return front==nullptr;
    }

    void enqueue(int x) {
        // Adds an element x at the rear of the queue
        Node* temp=new Node(x);
        if(rear==nullptr){
            front=rear=temp;
            return;
        }
        rear->next=temp;
        rear=temp;
    }

    void dequeue() {
        // Removes the front element of the queue
        if(isEmpty())return ;
        Node* temp=front;
        front=front->next;
        if(front==nullptr){
            rear=nullptr;
        }
        delete temp;
        
        
    }

    int getFront() {
        // Returns the front element of the queue
        // If queue is empty, return -1
        if(isEmpty())return -1;
        return front->data;
    }
    

    int size() {
        // Returns the current size of the queue.
        int x;
        Node* temp=front;
        while(temp){
            x++;
           temp=temp->next;
        }
        return x;
    }
};

//------------------------------------------------------------
//Implement stack using Queue
class MyStack {
public:
queue<int>q;
    MyStack() {
        
    }
    
    void push(int x) {
        q.push(x);
        int s=q.size();
        for(int i=0;i<=s-2;i++){
            //rotate
            q.push(q.front());
            q.pop();
        }
    }
    
    int pop() {
        int x=q.front();//delete front se hota and insert rear se
        q.pop();
        return x;
        
    }
    
    int top() {
        return q.front();
    }
    
    bool empty() {
        return q.size()==0;
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */
//------------------------------------------------------------
//Implement queue using stack
class MyQueue {
public:
stack<int>s1,s2;
    MyQueue() {
        
    }
    
    void push(int x) {
        s1.push(x);
    }
    
    int pop() {
        if(s2.empty()){
            while(!s1.empty()){
                s2.push(s1.top());
                s1.pop();
            }
        }
        int x=s2.top();
        s2.pop();
        return x;
        
    }
    
    int peek() {
        if(s2.empty()){
            while(!s1.empty()){
                s2.push(s1.top());
                s1.pop();
            }
        }
        return s2.top();

        
    }
    
    bool empty() {
        return s1.empty() && s2.empty();
        
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */
//------------------------------------------------------------
