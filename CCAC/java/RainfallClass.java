/* Program: RainfallClass.java
   Date:    11/09/2017
   Author:  Morgan Visnesky
   
   "Chapter 7 Programming challenge #1"
   
   The challenge:
   
   Write a RainFall class that stores the total rainfall for each of 12 months into an array of doubles. 
   The program should have methods that return the following: 
   • the total rainfall for the year 
   • the average monthly rainfall 
   • the month with the most rain 
   • the month with the least rain 
   
   Demonstrate the class in a complete program. 
   
   Input Validation: Do not accept negative numbers for monthly rainfall figures.    
*/
import java.util.Scanner;

   

public class RainfallClass
{
   
   /**
   The getYearlyRainfall method displays the yearly total rainfall.
   Sums all values of array argument.
     
   @param array Values to sum. 
   */

   public static double getYearlyRainfall(double[] array)
   {
      
      double yearlytotal = 0.0;
      for (double val : array)
      {
         yearlytotal += val;
      }  
      return yearlytotal;
   }
   
   /**
   The getAverageMonthly method displays the average monthly rainfall.
   Sums all values of array argument, then divides by 12 (because there are 12 months in the year).
     
   @param array Values to sum. 
   */
   
   public static double getAverageMonthly(double[] array)
   {
      double yearlytotal = 0.0;
      for (double val : array)
      {
         yearlytotal += val;
      }  
      double yearly = yearlytotal;
      double monthlyAvr = yearly/12.0;
      return monthlyAvr;
   }
   
   /**
   The getMostRainfall method displays the highest rainfall value.
     
   @param array Determines highest value in array. 
   */
   
   public static double getMostRainfall(double[] array)
   {
      double highest = array[0];
      for (int index = 1; index < array.length; index++) 
      { 
         if (array[index] > highest)
         { 
            highest = array[index];
         } 
      }
      return highest;
   }
   
   /**
   The getLeastRainfall method displays the lowest rainfall value.
     
   @param array Determines lowest value in array. 
   */
   
   public static double getLeastRainfall(double[] array)
   {
      double lowest = array[0];
      for (int index = 1; index < array.length; index++) 
      { 
         if (array[index] < lowest)
         { 
            lowest = array[index]; 
         }
      }
      return lowest;
   }   
   
   public static double[] setRainfall()
   {
      Scanner keyboard = new Scanner(System.in);
      final int months = 12;
      double[] monthlyRF = new double[months]; // array that will store the rainfall data
      
      
      
         // acquiring rainfall data from user
         for (int index = 0;index < months; index++)
         {
            System.out.println("Please enter the rainfall for month " + (index+1) + ".");
         
            double rfinput = keyboard.nextDouble();
            
            // input validation via while loop
            while (rfinput < 0.0)
            {
            System.out.println("Please enter a positive number for the rainfall for month " + (index+1) + ".");
         
            rfinput = keyboard.nextDouble();
            }
            monthlyRF[index] = rfinput;
         }
         
         return monthlyRF;
   }      
   

public static void main(String[] args)
   { 
      double[] monthlyRF = setRainfall();  
      //Prints data to the screen using methods defined above with the array of rainfall data passed as arguments
      System.out.println("The yearly rainfall is: " + getYearlyRainfall(monthlyRF));
      System.out.println("The average monthly rainfall is: " + getAverageMonthly(monthlyRF));
      System.out.println("The most rainfall in one month is: " + getMostRainfall(monthlyRF));
      System.out.println("The least rainfall in one month is: " + getLeastRainfall(monthlyRF));
   }
}