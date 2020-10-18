class hotel():

    def calculateFee(self):
        """
        This Method calculates cost of hotel room based
        on described scenario.
        :return:
        none.
        """
        testCases = int(input("Enter no of test cases:"))
        totalCost = 0
        while (testCases != 0):
            roomType = input("Select room-type (standard/luxury) :")
            bedrooms = int(input("Enter no of bedrooms:"))
            bathrooms = int(input("Enter no of bathrooms:"))
            roomCost = 5 * bedrooms + 2 * bathrooms
            if (roomType == 'luxury'):
                roomCost += 200
            totalCost += roomCost
            print(totalCost)
            testCases -= 1


# object created and method calling
objHotel = hotel()
objHotel.calculateFee()
