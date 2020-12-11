/* Program: HeadsOrTails.java
   Date:    10/12/2017
   Author:  Morgan Visnesky
   
   "Chapter 4 Programming challenge Extra Credit"
   
   Write a program that will compute statistics for eight coin tosses. 
   The user will enter either an h for heads or a t for tails for the eight tosses. 
   The program will then display the total number and percentages of heads and tails. 
   Use the increment operator to count each h and t that is entered.

   Example:

   For each coin toss enter either h for heads or t for tails.

   Toss 1: h
   Toss 2: t
   Toss 3: t
   Toss 4: h
   Toss 5: t
   Toss 6: h
   Toss 7: t
   Toss 8: t
   Number of Heads: 3
   Number of Tails: 5
   Percent heads: 37.5
   Percent tails: 62.5
     
*/

import javax.swing.JOptionPane;

public class HeadsOrTails
{
   public static void main(String[] args)
   {
      final int tossNum = 8;
      int headsTotal = 0;
      int tailsTotal = 0;
      double percentHeads;
      double percentTails;
      String userCharString;
      char userChar;
      char heads = 'h';
      char tails = 't';
      
      JOptionPane.showMessageDialog(null, "This program will compute the statistics " + 
                                       "for 8 user determined coin tosses.  ");
      
      for (int i=1;i<=tossNum; i++) 
      {
         userCharString = JOptionPane.showInputDialog("Enter either an h for heads or a t for tails. ");
         userChar = userCharString.charAt(0);
         if(userChar == heads ) 
         {
         headsTotal++;
         }
         else if(userChar == tails)
         {
         tailsTotal++;
         }
         
      }
      percentHeads = (headsTotal/8.0)*100.0;
      percentTails = (tailsTotal/8.0)*100.0;
      JOptionPane.showMessageDialog(null,"Total number of heads is: " +headsTotal + "\n" +
                                          "Total number of tails is: " +tailsTotal + "\n" +
                                          "The pernteage of heads is: " +percentHeads + "%" +"\n" +
                                          "The pernteage of tails is: " +percentTails + "%");
   System.exit(0);
   }
}