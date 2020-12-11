/* Program: RetailPriceCalculator.java
   Date:    10/17/2017
   Author:  Morgan Visnesky
   
   "Chapter 5 Programming challenge #2"
   
   The challenge:
   
   Write a program that asks the user to enter an item’s wholesale cost and its markup percentage. 
   It should then display the item’s retail price. For example: 
   
   • If an item’s wholesale cost is 5.00 and its markup percentage is 100 percent, 
   then the item’s retail price is 10.00. 
   
   • If an item’s wholesale cost is 5.00 and its markup percentage is 50 percent, 
   then the item’s retail price is 7.50. 
   
   The program should have a method named calculateRetail that receives the wholesale cost and 
   the markup percentage as arguments, and returns the retail price of the item.

      
*/
import javax.swing.JOptionPane;
 
import java.text.DecimalFormat;
public class RetailPriceCalculator
{
   public static void main(String[] args)
   {
      double wholesale = getWholesale();
      double markupPercentage = getMarkup();
      double retailPrice = calculateRetail(wholesale,markupPercentage);
      calculateRetail(wholesale, markupPercentage);
      DecimalFormat df = new DecimalFormat("0.00");
      String retailPriceOutput = df.format(retailPrice);
      
      JOptionPane.showMessageDialog(null,"The retail price of an item with a whole sale price of $" +
                                    wholesale + "," + "\n" + 
                                    "and a markup percentage of " + (markupPercentage * 100) + "%," + "\n" +
                                    "is: $" + retailPriceOutput + ".");
      System.exit(0);
                                    
      
   }
   public static double getWholesale()
   {
      double wholesalePrice;
      String input1;
      
      input1 = JOptionPane.showInputDialog(null,"Please enter the wholesale price of the item." + "\n" +
                                          "(Example input: 5.75, for 5 dollars and 75 cents.)");
      wholesalePrice = Double.parseDouble(input1);
      
      
      return wholesalePrice;
      
   }
   public static double getMarkup()
   {
      double markupPercentage;
      double markup; 
      String input2;
      input2 = JOptionPane.showInputDialog(null,"Please enter the markup percentage of the item." + "\n" +
                                          "(Example input: 70, for 70 percent.)"); 
      markup = Double.parseDouble(input2);  
      markupPercentage = markup/100;
      return markupPercentage;
   }
   public static double calculateRetail(double price, double markup)
   {
      double resultMarkup = price * markup;
      double retailPrice = price + resultMarkup;
      return retailPrice;
   }
}