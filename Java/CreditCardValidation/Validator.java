import java.util.Scanner;

public class Validator {

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        System.out.print("Input your card number: ");
        String card = sc.nextLine();
        System.out.println(checkCard(card));
    }

    private static String checkCard(String card) {
        if (card.length() == 16) {
            if (!(card.charAt(0) >= '4' && card.charAt(0) <= '6')) {
                return "Invalid";
            }

            if (numbersOnly(card) && checkConsecutiveDigits(card)) {
                return "Valid";
            }
            return "Invalid";
        } else if (card.length() == 19) {
            for (int i = 0; i < 3; i++) {
                if (card.charAt(i * 5 + 4) != '-') {
                    return "Invalid";
                }
            }
            card = card.replaceAll("-", "");
            if (numbersOnly(card) && checkConsecutiveDigits(card)) {
                return "Valid";
            }
            return "Invalid";
        } else {
            return "Invalid";
        }
    }

    private static boolean numbersOnly(String card) {
        try {
            Long.parseLong(card);
        } catch (NumberFormatException e) {
            return false;
        }
        return true;
    }

    private static boolean checkConsecutiveDigits(String card) {
        int counter = 0;
        char ch = 0;
        for (char c : card.toCharArray()) {
            if (c == ch) {
                counter++;
            } else {
                ch = c;
                counter = 1;
            }
            if (counter >= 4) {
                return false;
            }
        }
        return true;
    }
}
