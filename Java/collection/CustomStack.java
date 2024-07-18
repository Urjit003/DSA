package collection;

public class CustomStack<V> {
    Object[] data;
    Integer top = 0, size = 0;

    public CustomStack(int size) {
        this.size = size;
        data = new Object[size];
    }

    public void push(V val) {
        if (!isFull()) {
            data[++top] = val;
        } else {
            System.out.println("Stack is full");
        }
    }

    private boolean isFull() {
        return top == size - 1;
    }

    public int pop() {
        int val = (int) data[top];
        data[top] = null;
        --top;
        return val;
    }

    @Override
    public String toString() {
        String temp = "";
        temp += "{";
        for (int i = 0; i < data.length; i++) {
            if (i == data.length - 1)
                continue;
            temp += data[i] + ", ";
        }
        temp += "}";
        return temp;
    }
}
