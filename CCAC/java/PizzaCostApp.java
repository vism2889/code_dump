/* Program: PizzaCostApp.java
   Date:    09/21/2017
   Author:  Morgan Visnesky
   
   "Chapter 2 Programming challenge *Extra Credit* "
   
   The challenge:
   
   The cost of making a pizza at a local shop is as follows:

   Labor cost is $0.75 per pizza, regardless of size.
   Rent cost is $1.00 per pizza, regardless of size.
   Materials is $0.05 * diameter * diameter, where diameter is measured in inches.
   You will store the labor, rent as constants.
   You will prompt the user for the size of the pizza.

   Formulas:

   materials = .05 * diameter * diameter
   pizzaCost = labor + rent + materials

   Create a PizzaCost application that displays the cost of making the pizza based on a size stored in a variable.  The application output should look similar to:

   Enter the diameter of the pizza in inches: 16
   The cost of making the pizza is: $14.55

     
*/
import java.util.Scanner;

public class PizzaCostApp
{
   public static void main(String[] args)
   {
   
      final double labor = 0.75;
      final double rent = 1.00;
      int diameter;
   
      Scanner keyboard = new Scanner(System.in);
      System.out.println("Welcome to the pizza shop!" + "\n" +
                        "How big would you like your pizza in inches? ");
      diameter = keyboard.nextInt();                     
      double materials = (0.05 * diameter * diameter);
      double pizzaCost = (labor + rent + materials);
      System.out.println("The total cost for that size of pizza is: $" + pizzaCost);
   }
}                      