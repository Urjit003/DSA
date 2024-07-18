package collection;

import java.util.Arrays;

public class CustomArrayList<T extends Number> {
    private Object[] data;
    private static int DEFAULT_SIZE = 10;
    private int size = 0;

    public CustomArrayList() {
        this.data = new Object[DEFAULT_SIZE];
    }

    public void add(Number num) {
        if (isFull(num))
            resize();
        data[size] = num;
        size++;
    }

    private void resize() {
        Object[] tempData = new Object[2 * data.length];

        // copying current items in the TEMPDATA
        for (int i = 0; i < data.length; i++) {
            tempData[i] = data[i];
        }
        data = tempData;

    }

    private boolean isFull(Number num) {
        return size == data.length;
    }

    public Number remove() {
        Number removed = (Number) data[--size];
        return removed;
    }

    public Number get(int index) {
        return (Number) data[index];
    }

    public void set(int index, Number newNumber) {
        this.data[index] = newNumber;
    }

    public int size() {
        return size;
    }

    @Override
    public String toString() {
        return Arrays.toString(data);
    }

}
