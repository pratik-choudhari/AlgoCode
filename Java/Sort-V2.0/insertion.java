// Hacktoberfest Contributions by Dhrubajyoti Chakraborty
// Insertion Sort implementation


import java.util.Arrays;

public class InsertSort {
    public static void main(String[] args) {
        int[] arr = new int[] {5,3,2,8,5,9,1,0};
        insertSort(arr);
        System.out.println(Arrays.toString(arr));
    }
    public static void insertSort(int[] arr){
        int i,j,key,temp;

        for(i = 1;i<arr.length;i++){
            key = arr[i];
            j = i-1;
            while(j>=0&&arr[j]>arr[j+1]){
                temp = arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=temp;
                j--;
            }
            arr[j+1]=key;
        }
    }
}