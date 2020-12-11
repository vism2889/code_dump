/* Program: PenniesForPay.java
   Date:    10/12/2017
   Author:  Morgan Visnesky
   
   "Chapter 4 Programming challenge #4"
   
   Write a program that calculates the amount a person 
   would earn over a period of time if his or her salary
   is one penny the first day, two pennies the second day,
   and continues to double each day. The program should 
   display a table showing the salary for each day, and 
   then show the total pay at the end of the period. 
   The output should be displayed in a dollar amount, 
   not the number of pennies. Input Validation: 
   Do not accept a number less than 1 for the number of 
   days worked.

     
*/
import javax.swing.JOptionPane;
import java.text.DecimalFormat;
public class PenniesForPay
{
   public static void main(String[] args)
   {
      
      DecimalFormat decFormat = new DecimalFormat("#,##0.00");     
      
      String userDaysWorked = null;
      int daysWorkedConver = 0;
      final double multiplier = 0.01;
      int counter = 0;
      double sum = 0;
      double finalSum;
      double cents = 0;
      
      while (daysWorkedConver < 1)
      {
         userDaysWorked = JOptionPane.showInputDialog("Please enter the days you have worked." +
                                                   "\n" + "The number of days cannot be less than 1.");
         daysWorkedConver = Integer.parseInt(userDaysWorked);
      
      
         for (counter = 1, cents = 0.01; counter < daysWorkedConver; counter++, cents *=2, sum+=cents)
         {
           
         }
      }
         
      finalSum = sum * multiplier;
      //System.out.println(decFormat.format(finalSum));
      JOptionPane.showMessageDialog(null, "This is your pay for " +
                                    userDaysWorked +" "+"days: $" 
                                    + decFormat.format(sum)+ ".");
      System.exit(0);                              
    }
 }