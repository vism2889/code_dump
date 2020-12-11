/* Program: softwareSales.java
   Date:    10/01/2017
   Author:  Morgan Visnesky
   
   "Chapter 3 Programming challenge #8"
   
   The challenge:
   
   A software company sells a package that retails for $99. 
   Quantity discounts are given according to the following table: 
   Quantity Discount 
   10–19 20% 
   20–49 30% 
   50–99 40% 
   100 or more 50%

   Write a program that asks the user to enter the number of packages 
   purchased. The program should then display the amount of the discount 
   (if any) and the total amount of the purchase after the discount.

   
*/

import java.util.Scanner;

public class softwareSales
{
   public static void main(String[] args)
   {
   
   final int packagePrice = 99;
   int packageNumber;
   double discountPercentage = 0.0;
   
   Scanner keyboard = new Scanner(System.in);
   
   System.out.println("How many packages did you purchase? ");
   packageNumber = keyboard.nextInt();
   
   if (packageNumber >=10 && packageNumber < 20)
   {
      discountPercentage = 0.20;
   }
   else if (packageNumber >=20 && packageNumber <50)
   {
      discountPercentage = 0.30;
   }
   else if (packageNumber >=50 && packageNumber <100)
   {
      discountPercentage = 0.40;
   }
   else if (packageNumber > 100)
   {
      discountPercentage = 0.50;
   }
      
   double totalPrice = packageNumber * packagePrice;
   double totalDiscount = totalPrice * discountPercentage;
   double finalSales = totalPrice - totalDiscount;
   
   System.out.println("Your subtotal is: " + totalPrice);
   System.out.println("Your discount is: " + totalDiscount); 
   System.out.println("Your Final sale price is: " + finalSales);   
   }
} 