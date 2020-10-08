
import java.util.*;
class Main
{
    public static void main(String[] args) {

        Scanner s = new Scanner(System.in);
          String str=s.next();
         HashMap<Character,Integer>  map=new HashMap<>();
        for (int i = 0; i < str.length(); i++) {
             if(str.charAt(i)=='0'||str.charAt(i)=='1'||str.charAt(i)=='2'||str.charAt(i)=='3'||str.charAt(i)=='4'||str.charAt(i)=='5'||str.charAt(i)=='6'||str.charAt(i)=='7'||str.charAt(i)=='8'||str.charAt(i)=='9') {
                 if (map.containsKey(str.charAt(i))) {
                     int c = map.get(str.charAt(i));
                     map.remove(str.charAt(i));
                     map.put(str.charAt(i), c + 1);
                 } else {
                     map.put(str.charAt(i), 1);
                 }
             }
        }
        System.out.println(map);
        Set<Map.Entry<Character,Integer>> entries=map.entrySet();
        int[] freq=new int[10];

        for (Map.Entry<Character,Integer> entry:entries) {
            freq[(int)(entry.getKey())-48]=entry.getValue();
        }
        String res="";
        for (int i = 0; i <freq.length ; i++) {
            res=res+freq[i]+" ";
        }
        System.out.println(res);
    }

}
