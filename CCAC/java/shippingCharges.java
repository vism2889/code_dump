/* Program: shippingCharges.java
   Date:    10/01/2017
   Author:  Morgan Visnesky
   
   "Chapter 3 Programming challenge #9 (Extra Credit)"
   
   The challenge:
   
   The Fast Freight Shipping Company charges the following rates: 
   Weight of Package Rate per 500 Miles Shipped
    
   2 pounds or less                             $1.10 
   Over 2 pounds but not more than 6 pounds     $2.20 
   Over 6 pounds but not more than 10 pounds    $3.70 
   Over 10 pounds                               $3.80
    
   The shipping charges per 500 miles are not prorated. 
   For example, if a 2-pound package is shipped 550 miles, 
   the charges would be $2.20. Write a program that asks the user 
   to enter the weight of a package and then displays the shipping charges.
 
*/

import java.util.Scanner;

public class shippingCharges
{
   public static void main(String[] args)
   {
      Scanner keyboard = new Scanner(System.in);
      
      double packWeight;
      double shippingCharge = 0.0;
      
      System.out.println("How much does your package weigh? ");
      packWeight = keyboard.nextDouble();
      
      if (packWeight <= 2)
      {
         shippingCharge = 1.10;
      }
      else if (packWeight > 2 && packWeight <= 6)
      {
         shippingCharge = 2.20;
      }
      else if (packWeight > 6 && packWeight <= 10)
      {
         shippingCharge = 3.70;
      }
      else if (packWeight > 10)
      {
         shippingCharge = 3.80;
      }
         
      System.out.println("Your shipping charges will be: $" + shippingCharge +
                           " For the first 500 miles, will you be shipping over a longer distance?" +"\n"
                           +"If so how many miles? ");
      int milage = keyboard.nextInt();
      double rateMult = milage/500;
      double finalRateMult = Math.ceil(rateMult); // Math.ceil used to round up number (no prorated milage) 
      
      if (milage > 500)
      {
         System.out.println("your new total is: " + finalRateMult * shippingCharge);
      }
         
   }
}
      
      