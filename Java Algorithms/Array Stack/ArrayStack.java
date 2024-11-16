public class ArrayStack {
     int[] stackArray;
     int top;
     int maxSize;

    
    public ArrayStack(int size) {
        maxSize = size;
        stackArray = new int[size];
        top = -1;
    }

   
    public void push(int value) {
        if (top == maxSize - 1) {
            System.out.println("Stack is full");
        } else {
            stackArray[++top] = value;
        }
    }
    
    
    public int pop() {
        if (isEmpty()) {
            System.out.println("Stack is empty");
            return -1;  
        } else {
            return stackArray[top--];
        }
    }

    
    public int top() {
        if (isEmpty()) {
            System.out.println("Stack is empty.");
            return -1;  
        } else {
            return stackArray[top];
        }
    }

    
    public int size() {
        return top + 1;
    }

    public boolean isEmpty() {
        return top == -1;
    }

    public static void main(String[] args) {
       
        ArrayStack stack = new ArrayStack(5);

        stack.push(1);
        stack.push(2);
        stack.push(3);
        stack.push(4);
        stack.push(5);
        
        System.out.println("Top element: " + stack.top());
        System.out.println("Stack size: " + stack.size());
        System.out.println("Popped element: " + stack.pop());
        System.out.println("Popped element: " + stack.pop());
        System.out.println("Stack size after pop: " + stack.size());

        stack.pop();
        stack.pop();
        stack.pop();
        stack.pop();  
    }
}
