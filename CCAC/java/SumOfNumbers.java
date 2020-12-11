/* Program: SumOfNumbers.java
   Date:    10/12/2017
   Author:  Morgan Visnesky
   
   "Chapter 4 Programming challenge #1"
   
   Write a program that asks the user for a positive 
   nonzero integer value. The program should use a loop 
   to get the sum of all the integers from 1 up to the 
   number entered. For example, if the user enters 50, 
   the loop will find the sum of 1, 2, 3, 4, . . . 50.
     
*/

import java.util.Scanner;

public class SumOfNumbers
{
   public static void main(String[] args)
   {
      Scanner keyboard = new Scanner(System.in);
      int userNum;
      int counter = 0;
      int sumNum = 0;
      
      System.out.println("Please enter a non-zero integer");
      userNum = keyboard.nextInt();
      
      while (counter < userNum)
      {
         counter++;
         sumNum = sumNum + counter;
      }
      
      System.out.println("The sum of all the Numbers " +
                           "from 1 up to " + userNum +
                           " " + "is " + sumNum + ".");
   }
}