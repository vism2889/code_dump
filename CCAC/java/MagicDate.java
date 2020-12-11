/* Program: MagicDate.java
   Date:    10/01/2017
   Author:  Morgan Visnesky
   
   "Chapter 3 Programming challenge #2"
   
   The challenge:
   
   Write a program that asks the user to enter a month (in numeric form),
   a day, and a twodigit year. The program should then determine whether 
   the month times the day is equal to the year. If so, it should display 
   a message saying the date is magic. Otherwise, it should display a 
   message saying the date is not magic.


     
*/

import java.util.Scanner;

public class MagicDate
{
   public static void main(String[] args)
   {
      int month;
      int day;
      int year;
      
      Scanner keyboard = new Scanner(System.in);
      
      System.out.println("Please enter a date, we will start with the month: ");
      month = keyboard.nextInt();
      System.out.println("Now please enter the day: ");
      day = keyboard.nextInt();
      System.out.println("Lastly enter the year: ");
      year = keyboard.nextInt();
      
      if (month*day == year)
      {
         System.out.println("This is a magic date.");
      }
      else 
      {
         System.out.println("This is not a magic date.");
      }
   }
}