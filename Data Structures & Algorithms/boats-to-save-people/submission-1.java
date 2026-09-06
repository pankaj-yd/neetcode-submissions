class Solution {
    public int numRescueBoats(int[] people, int limit) {
        Arrays.sort(people);

        int n = people.length;
        int j = n - 1;
        while(j >= 0 && people[j] >= limit) {
            j--;
        }

        int boats = n - j - 1;

        int i = 0;
        while(i < j) {
            if (people[i] + people[j] <= limit) {
                i++;
                j--;
                boats++;
            } else {
                j--;
                boats++;
            } 
        }

        if (i == j) {
            boats++;
        }
        return boats;
    }
}