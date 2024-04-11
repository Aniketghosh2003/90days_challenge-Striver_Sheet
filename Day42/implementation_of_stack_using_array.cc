class Stack {
    
public:
   int Top;
   int* arr;
   int capacity;
    
    Stack(int capacity) {
        this->capacity = capacity;
        arr = new int[capacity];
        Top = -1;
    }

    void push(int num) {
       if(isFull()){
           return ;
       }
       arr[++Top] = num;
    }

    int pop() {
         if(isEmpty()){
            return -1;
        }
        int val = arr[Top--];
        return val;
    }
    
    int top() {
        if(isEmpty()){
            return -1;
        }
        return arr[Top];
    }
    
    int isEmpty() {
        if(Top == -1){
            return 1;
        }
        else{
            return 0;
        }
    }
    
    int isFull() {
       if(Top == capacity-1){
           return 1;
       }
       else{
           return 0 ;
       }
    }
    
};
