/* Program: TestScoreAverage.java
   Date:    10/01/2017
   Author:  Morgan Visnesky
   
   "Chapter 3 Programming challenge #4"
   
   The challenge:
   
   Write a program that has variables to hold three test scores. 
   The program should ask the user to enter three test scores and 
   then assign the values entered to the variables. The program should 
   display the average of the test scores and the letter grade that is 
   assigned for the test score average.

   
*/
import java.util.Scanner;
public class TestScoreAverage
{
   public static void main(String[] args)
   {
      double testOne;
      double testTwo;
      double testThree;
      double testAverage;
      String letterGrade = "";
      
      Scanner keyboard = new Scanner(System.in);
      
      System.out.println("Please enter three test scores to get an average and your letter grade.");
      System.out.println("Enter test 1: ");
      testOne = keyboard.nextDouble();
      System.out.println("Enter test 2: ");
      testTwo = keyboard.nextDouble();
      System.out.println("Enter test 3: ");
      testThree = keyboard.nextDouble();
      
      testAverage = (testOne + testTwo + testThree)/3;
      
      if (testAverage >= 90)
      {
         letterGrade = "A";
      }
      else if (testAverage >= 80 && testAverage < 90)
      {
         letterGrade = "B";
      }
      else if (testAverage >= 70 && testAverage < 80)
      {
         letterGrade = "C";
      }
      else if (testAverage >= 60 && testAverage < 70)
      {
         letterGrade = "D";
      }
      else if (testAverage < 60)
      {
         letterGrade = "F";
      }
      
      System.out.println("Your average is: " + testAverage);
      System.out.println("Your letter grade is: " + letterGrade);
   }
}