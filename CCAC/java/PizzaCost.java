/* Program: PizzaCost.java
   Date:    09/21/2017
   Author:  Morgan Visnesky
   
   "Chapter 2 Programming challenge *Extra Credit* "
   
   The challenge:
   
   Only instructions given "Pizza Cost Application" Sooo..
   This program is basic, it takes the number of slices, toppings, 
   and cups of ranch dressing (PGH delicacy), then multiplies 
   the cost of all the items by the quantities provided by the user.
   Takes into account sales tax also.

     
*/

import java.util.Scanner;

public class PizzaCost
{
   public static void main(String[] args)
   {
      Scanner keyboard = new Scanner(System.in);
      
      // variables below
      // pizza toppings
      final double salesTax = 0.07;
      final double sliceCost = 1.25;
      final double toppingCost = 0.50;
      final double ranchCupCost = 0.50;
      
      System.out.println("Welcome to A' Pizza Morgoozi, " + 
                        "How many slices of pizza would you like? ");
      int numPizzaSlice = keyboard.nextInt();
      System.out.println("How many toppings would you like?");
      int numToppings = keyboard.nextInt();
      System.out.println("Would you like any extra cups of ranch dressing? " + 
                           "If so how many?");
      int ranchCups = keyboard.nextInt();
      
      double beforeTaxTotal = ((numPizzaSlice * sliceCost) +
                           (numToppings * toppingCost * numPizzaSlice) +
                           (ranchCupCost * ranchCups));
      double taxAmount = (beforeTaxTotal * salesTax);
      
      double finalCost = (beforeTaxTotal + taxAmount);
      
      System.out.println("Your pizza total after tax is: $" + finalCost +
                           " Enjoy your pizza!");                     
   }
}                           