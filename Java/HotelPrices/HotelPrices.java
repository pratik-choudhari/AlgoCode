import java.util.Scanner;

class HotelPrices {

    public static void main(String[] args)  {
        Scanner sc = new Scanner(System.in);
        int testCases  = sc.nextInt();
        long totalCost = 0; // Cost of all the rooms in the hotel

        while (testCases-- !=0) {
            String roomType = sc.next();
            int bedrooms = sc.nextInt();
            int bathrooms = sc.nextInt();
            long roomCost = 5 * bedrooms + 2 * bathrooms;
            if (roomType.equalsIgnoreCase("luxury")) { // Add additional charges for Luxury Rooms
                roomCost += 200;
            }
            totalCost += roomCost;
        }

        System.out.println(totalCost);
    }
}