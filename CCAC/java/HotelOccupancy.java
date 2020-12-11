/* Program: HotelOccupancy.java
   Date:    10/12/2017
   Author:  Morgan Visnesky
   
   "Chapter 4 Programming challenge #7"
   
   A hotel’s occupancy rate is calculated as follows: 
   Occupancy rate = Number of rooms occupied / Total number of rooms
   
   Write a program that calculates the occupancy rate 
   for each floor of a hotel. The program should start 
   by asking for the number of floors in the hotel. 
   A loop should then iterate once for each floor. 
   During each iteration, the loop should ask the user 
   for the number of rooms on the floor and the number 
   of them that are occupied. After all the iterations, 
   the program should display the number of rooms the 
   hotel has, the number of them that are occupied, 
   the number that are vacant, and the occupancy rate 
   for the hotel. Input Validation: Do not accept a 
   value less than 1 for the number of floors. 
   Do not accept a number less than 10 for the number 
   of rooms on a floor.
     
*/
import javax.swing.JOptionPane;

public class HotelOccupancy
{

   public static void main(String[] args)
   {
      String floorNumber = null;
      int floorNum = 0;
      String roomNumber = null;
      int roomNum = 0;
      String vacancyNumber = null;
      int vacancyNum = 0;
      
      int roomTotal = 0;
      int vacancyTotal = 0;
      double occupancyRate;
      
      
      while (floorNum < 1)
      {
         floorNumber = JOptionPane.showInputDialog(
                        "How many floors are in the hotel? "+ "\n"
                        + "Please enter a floor number of 1 or greater. ");
         floorNum = Integer.parseInt(floorNumber);
         
         
         for( int i=1; i<=floorNum; i++ ) 
         {
            roomNum = 0;
            
            while (roomNum < 10)
            
            {
            roomNumber = JOptionPane.showInputDialog(null,"How many rooms are there on floor #" + i + "?" 
                                                      + "\n" + "Please enter a room number of 10 or greater.");
            roomNum = Integer.parseInt(roomNumber);
            }
            vacancyNumber = JOptionPane.showInputDialog("How many vacant rooms are there on this floor? ");
            vacancyNum = Integer.parseInt(vacancyNumber);
            
         roomTotal = roomTotal + roomNum;
         vacancyTotal = vacancyTotal + vacancyNum;
         
              
         }
      }
      int roomsOccupied = roomTotal - vacancyTotal;
      occupancyRate = ((double)roomsOccupied/roomTotal)*100.0;
      
      JOptionPane.showMessageDialog(null,"The total number of rooms is " +
                                       roomTotal + "\n" + "The total number of vacant rooms is:"
                                       + vacancyTotal + "." + "\n" +
                                       "The total rooms occupied is: " + roomsOccupied + "\n" +
                                       "The occupancy rate is: " + occupancyRate + "%");
      System.exit(0);
   }
}
                  