// Hacktoberfest Contributions by Dhrubajyoti Chakraborty
// Selection Sort implementation


import java.util.Arrays;

public class SelectSort {
    public static void main(String[] args) {
        int [] arr=  new int[]{3,4,5,7,1,2,0,3,6,8};
        selectSort(arr);
        System.out.println(Arrays.toString(arr));

    }
    public static void selectSort(int[] arr){
      
        for(int i=0;i<arr.length;i++){
        
            int minIndex = i;
     
            for(int j = i+1;j<arr.length;j++){
         
                if(arr[minIndex]>arr[j]){
             
                    minIndex = j;
                }
            }
     
            if(i!=minIndex){
                int temp = arr[i];
                arr[i]=arr[minIndex];
                arr[minIndex]=temp;
            }
        }
    }
}