/* Program: RainfallClass.java
   Date:    10/01/2017
   Author:  Morgan Visnesky
   
   "Chapter 7 Programming challenge #1 part(1/2)"
   
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
public class Rainfall
{
   Scanner keyboard = new Scanner(System.in);
   final double months = 12.0;
   double[] monthlyRF = new double[months];
   int index;
   double rfinput;
   
   public Rainfall()
   { 
   for (int index = 0;index < monthlyRF.length; index++)
   {
      System.out.println(null,"Please enter the rainfall for " + months[index]+ ".");
      double rfinput = keyboard.nextdouble();
      monthlyRF[index] = rfinput;
   }
   }
   public static double getYearlyRainfall()
   {
      double yearlytotal = 0.0;
      for (double val : monthlyRF)
      {
         yearlytotal += val;
      }  
      return yearlytotal;
   }
   
   public static double getAverageMonthly()
   {
      double yearly = getYearlyRainfall();
      monthlyAvr = yearly/months;
      return monthlyAvr;
   }
   
   public static String getMostRainfall()
   {
      double highest = monthlyRF[0];
      for (int index = 1; index < monthlyRF.length; index++) 
      { 
         if (monthlyRF[index] > highest)
         { 
            highest = monthlyRF[index];
         } 
      }
      return highest;
   }
   
   public static String getLeastRainfall()
   {
      double lowest = monthlyRF[0];
      for (int index = 1; index < monthlyRF.length; index++) 
      { 
         if (monthlyRF[index] < lowest)
         { 
            lowest = monthlyRF[index]; 
         }
      }
      return lowest;
   }   
         
   
}