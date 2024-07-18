package collection;

public class CustomHashMap<V> {
    private Object[][] hashTable;
    // private Integer cursor = 0;
    Integer size;

    public CustomHashMap(Number size) {
        this.size = (Integer) size;
        hashTable = new Object[(int) size][2];
    }
    @Override
    protected void finalize() throws Throwable {
        clear_hashTable();
    }
    public CustomHashMap() {
        hashTable = new Object[10][2];
    }

    public void add(V key) { // I SIZE 10 ,"123456789101" , key = 12
        int index = hash(key);
        if (index > size) {
            resize();
        }
        while (hashTable[index][1] != null) {
            index += 1;
        }
        hashTable[index][1] = key;
    }
    
    private void resize() {
        int size = 2 * hashTable.length;
        Object[][] tempData = new Object[size][2];

        for (int i = 0; i < hashTable.length; i++) {
            tempData[i] = hashTable[i];
        }
        hashTable = tempData;
    }

    private int hash(V key) {
        return key.toString().length();
    }
    
    // public V get(V val)
    // {
    //     int index = hash(val);
    //     while(index < size && !(hashTable[index][1].equals(val))){
    //         System.out.println(index);
    //         index++;
    //     }
    //     return (V)hashTable[index][1];
    // }
    public int get(V key) {
        int index = hash(key);
        while (index < size && !(hashTable[index][1].equals(key))) {
            index++;
        }
        return index;
    }

    @Override
    public String toString() {
        String ans = "";
        ans += "{";
        for (int i = 0; i < hashTable.length; i++) {
            ans += String.valueOf(i);
            ans += ":";
            ans += hashTable[i][1];
            if (i == hashTable.length - 1)
                continue;
            ans += ", ";
        }
        ans += "}";
        return ans;
    }

    private void clear_hashTable() {
        for (int i = 0; i < hashTable.length; i++) {
            hashTable[i][1] = null;
        }
    }
}
