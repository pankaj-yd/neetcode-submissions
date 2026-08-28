class MyHashMap {
    private int MAX_SIZE = (int) 1e6 + 1;
    private int[] data;

    public MyHashMap() {
        data = new int[MAX_SIZE];
        Arrays.fill(data, -1);
    }
    
    public void put(int key, int value) {
        data[key] = value;
    }
    
    public int get(int key) {
        return data[key];
    }
    
    public void remove(int key) {
        data[key] = -1;
    }
}

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap obj = new MyHashMap();
 * obj.put(key,value);
 * int param_2 = obj.get(key);
 * obj.remove(key);
 */