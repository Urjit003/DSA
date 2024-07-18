package collection;

public class CustomHashMap2<K> {
    Object[][] hashTable;
    Integer size;
    // Integer cursor=0;
    public CustomHashMap2(Integer size) {
        this.size = size;
        hashTable=new Object[size][2];
    }

    public boolean add(K key){
        int index = hash(key);
        if(index>size){
            resize();
        }
        //A -> 1 [1][1] = A
        //AB -> 2[2][1]= AB
        //B -> 1[1][1] != NULL , true
        // index += 1 ;
        //index = 3 , or +1
        //hT[3][1]= B
        while(hashTable[index][1] != null){
            index+=1;
        }
        hashTable[index][1]=key;
        return false;
    }
    int hash(K key)
    {
        return key.toString().length();
    }
    void resize()
    {
        size*=2;
        Object[][] tempHashTable= new Object[size][2];
        for (int i = 0; i < hashTable.length; i++) {
            tempHashTable[i][1]=hashTable[i][1];
        }
        hashTable=tempHashTable;
        for (int i = 0; i < hashTable.length; i++) {
            tempHashTable[i][1]=null;
        }
    }
    public K get(K val)
    {
        int index = hash(val);
        while(index < size && !(hashTable[index][1].equals(val))){
            System.out.println(index);
            index++;
        }
        return (K)hashTable[index][1];
    }

    public String toString() {
        String temp="";
        temp+="{";
        // System.out.println("In string");
        // System.out.println(hashTable.length);
        for(int i=0;i<hashTable.length;i++)
        {
            temp+=Integer.toString(i);
            temp+=":";
            temp+=hashTable[i][1];
            if(i==hashTable.length-1)
                continue;
            temp+=", ";
        }
        temp+="}";
        return temp;
    }

        


    
}
