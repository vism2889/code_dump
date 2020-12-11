/* Program: PersonalInformation.java
   Date:    09/21/2017
   Author:  Morgan Visnesky
   
   "Chapter 2 Programming challenge #1"
   
   This program declares variables, puts values in the variables, then prints a string
   with the stored variables in a "JOptionPane.MessageDialog" window.  
   
     
*/

import javax.swing.JOptionPane; // Using JoptionPane to display message window

public class PersonalInformation
{
   public static void main(String[] args)
  {
      // Declares variables 
      String name;
      int age;
      double annualPay;
      
      // Stores personal data in variables
      name = "Morgan";
      age = 27;
      annualPay = 0.0;
      
      // JOptionPane to print string structure with above variables
      JOptionPane.showMessageDialog(null, "My name is " + name + ", " +
                                          "I am " + age + " " + 
                                          "years old," + "\n" +
                                          "and i have $" + annualPay + " " +
                                          "annual income," +"\n" +
                                          "because i left my job " +
                                          "to be a student.");
      System.exit(0);
   }
}