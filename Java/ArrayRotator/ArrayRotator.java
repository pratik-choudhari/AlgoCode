import java.util.Arrays;
import java.util.Collections;
import java.util.List;

/**
 * @author Alessandro Arosio - 04/10/2020 17:46
 */
public class ArrayRotator {
    public static void main(String[] args) {
        String[] stringArray = new String[]{"I", "am", "participating", "to", "hacktoberfest", "2020"};

        // The easy way without reinventing the wheel: using Collections.rotate()
        List<String> stringList = Arrays.asList(stringArray);
        System.out.println("Array before rotation: " + stringList);

        Collections.rotate(stringList, 1);
        System.out.println("Array after rotation: " + stringList);
    }
}