/* Program: PaintJobEstimator.java
   Date:    10/17/2017
   Author:  Morgan Visnesky
   
   "Chapter 5 Programming challenge #4 EXTRA CREDIT"
   
   The challenge:
   
   A painting company has determined that for every 115 square feet of wall space, 
   one gallon of paint and eight hours of labor will be required. The company charges 
   $18.00 per hour for labor. 
   Write a program that allows the user to enter the number of rooms to be painted 
   and the price of the paint per gallon. It should also ask for the square feet of 
   wall space in each room. The program should have methods that return the following data: 
   • The number of gallons of paint required 
   • The hours of labor required
   • The cost of the paint 
   • The labor charges 
   • The total cost of the paint job 
   
   Then it should display the data on the screen.
      
*/
import java.util.Scanner;
import java.text.DecimalFormat;

public class PaintJobEstimator
{
   public static void main(String[] args)
   {
      Scanner keyboard = new Scanner(System.in);
      int numberOfRooms;
      double pricePerGallon;
      
      System.out.println("Please enter the number of rooms to be painted. ");
      numberOfRooms = keyboard.nextInt();
      
      System.out.println("please enter the cost of the paint per gallon. ");
      pricePerGallon = keyboard.nextDouble();
      
      int roomCount = 1;
      double wallSpace = 0;
      double wallSpacePerRoom = 0;
      
      while (roomCount <= numberOfRooms)
      {
         System.out.println("Please enter the wall space for room: " + roomCount);
         wallSpacePerRoom = keyboard.nextDouble();
         roomCount++;
         wallSpace += wallSpacePerRoom;
      }
      
      double paintRequired = gallonsOfPaint(wallSpace);
      double requiredLabor = hoursOfLabor(wallSpace);
      double laborCost = costOfLabor(requiredLabor);
      double paintCost = costOfPaint(paintRequired, pricePerGallon);
      totalJobCost(laborCost, paintCost, wallSpace);
         
   }
   public static double gallonsOfPaint(double wallSpace)
   {
      double gallons = wallSpace/115;
      return gallons;
   }
   
   public static double hoursOfLabor(double wallSpace)
   {
      double hours = (wallSpace/115) * 8;
      return hours;
   }
   
   public static double costOfPaint(double gallons, double price)
   {
      double cost = gallons*price;
      return cost;
   }
   public static double costOfLabor(double hours)
   {
      double laborCost = hours * 18;
      return laborCost;
   }
   public static void totalJobCost(double laborCost, double paintCost, double wallSpace)
   {
      DecimalFormat df = new DecimalFormat("0.00");
 		double totalCost = laborCost + paintCost;
 		System.out.println("The total wall Space is: " + wallSpace + " square feet.");
 		System.out.println("The total labor cost is: $" + df.format(laborCost));
 		System.out.println("The total paint cost: $" + df.format(paintCost));
 		System.out.println("The total cost of the paint job is: $" + df.format(totalCost));
   }
}