/* Program: TestAverageAndGrade.java
   Date:    10/17/2017
   Author:  Morgan Visnesky
   
   "Chapter 5 Programming challenge #6"
   
   The challenge:
   
   Write a program that asks the user to enter five test scores. 
   The program should display a letter grade for each score and the 
   average test score. 
   
   Write the following methods in the program: 
   
   • calcAverage—This method should accept five test scores as arguments and 
   return the average of the scores. 
   
   • determineGrade—This method should accept a test score as an argument and 
   return a letter grade for the score, based on the following grading scale: 
   
   Score    Letter Grade 
   90–100      A 
   80–89       B 
   70–79       C 
   60–69       D 
   00-59       F
      
*/
import javax.swing.JOptionPane;

public class TestAverageAndGrade
{
   public static void main(String[] args)
   {
   String t1,t2,t3,t4,t5;
   double test01,test02,test03,test04,test05;
   
   JOptionPane.showMessageDialog(null,"This program calculates the average of five test scores and" + "\n" + 
                                 " displays corresponding letter grade information.");
   t1 = JOptionPane.showInputDialog(null,"Please enter test score #1: ");
   test01 = Double.parseDouble(t1);
   //String test1letter = determineGrade(test01);
   JOptionPane.showMessageDialog(null,t1 + " is in the " + determineGrade(test01) + " range.");
   
   t2 = JOptionPane.showInputDialog(null,"Please enter test score #2: ");
   test02 = Double.parseDouble(t2);
   JOptionPane.showMessageDialog(null,t2 + " is in the " + determineGrade(test02) + " range.");
   
   t3 = JOptionPane.showInputDialog(null,"Please enter test score #3: ");
   test03 = Double.parseDouble(t3);
   JOptionPane.showMessageDialog(null,t3 + " is in the " + determineGrade(test03) + " range.");
   
   t4 = JOptionPane.showInputDialog(null,"Please enter test score #4: ");
   test04 = Double.parseDouble(t4);
   JOptionPane.showMessageDialog(null,t4 + " is in the " + determineGrade(test04) + " range.");
   
   t5 = JOptionPane.showInputDialog(null,"Please enter test score #5: ");
   test05 = Double.parseDouble(t5);
   JOptionPane.showMessageDialog(null,t5 + " is in the " + determineGrade(test05) + " range.");
   
   double averageNum = calcAverage(test01,test02,test03,test04,test05);
   
   JOptionPane.showMessageDialog(null,"Your average grade is: " + averageNum + "\n" +
                                 "That is in the " + (determineGrade(averageNum)) + " range.");
   System.exit(0);
      
   }
   public static double calcAverage(double test1, double test2, 
                                    double test3, double test4, 
                                    double test5)
   {
      double sum = test1 + test2 + test3 + test4 + test5;
      double average = sum/5.0;
      return average;
   
   }
      
   public static String determineGrade(double testScore)
   {
      String grade = "";
      if (testScore >= 90.0)
      {
         grade = "A";
      }
      else if (testScore >= 80.0 && testScore < 90.0)
      {
         grade = "B";
      }
      else if (testScore >= 70.0 && testScore < 80.0)
      {
         grade = "C";
      }
      else if (testScore >= 60.0 && testScore < 70.0)
      {
         grade = "D";
      }
      else if (testScore < 60.0)
      {
         grade = "F";
      }
      
      return grade;
   }
}