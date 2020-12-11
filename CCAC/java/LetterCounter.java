/* Program: LetterCounter.java
   Date:    10/12/2017
   Author:  Morgan Visnesky
   
   "Chapter 4 Programming challenge #5"
   
   Write a program that asks the user to enter a string, 
   and then asks the user to enter a character. 
   The program should count and display the number of 
   times that the specified character appears in the 
   string.


     
*/
import javax.swing.JOptionPane;

public class LetterCounter
{
   public static void main(String[] args)
   {
   String userString;
   String stringChar;
   char userChar;
   
   userString = JOptionPane.showInputDialog("Please enter a string");
   stringChar = JOptionPane.showInputDialog("Please enter a character");
   userChar = stringChar.charAt(0);
   
  
   int counter = 0;
   for( int i=0; i<userString.length(); i++ ) 
   {
      if( userString.charAt(i) == userChar ) {
         counter++;
      } 
   }   
   
   JOptionPane.showMessageDialog(null, userChar + " appears in the" +
                                 " string you have provided " +
                                 counter + " times.");
   System.exit(0);
   }
}                              