/* Program: SalesPrediction.java
   Date:    09/21/2017
   Author:  Morgan Visnesky
   
   "Chapter 2 Programming challenge #5"
   
   The challenge:
   
   "The East Coast sales division of a company 
   generates 62 percent of total sales. Based on that percentage, 
   write a program that will predict how much the East Coast division 
   will generate if the company has $4.6 million in sales this year. 
   Hint: Use the value 0.62 to represent 62 percent."

     
*/

public class SalesPrediction
{
   public static void main(String[] args)
   {
      final double SALES_PERCENT = 0.62;
      final double YEARLY_SALES = 4.60;
      
      double eastCoastSales = SALES_PERCENT * YEARLY_SALES;
      
      System.out.println("The predicted yearly sales from the east coast division " +
                        "is " + "\n" + "$" + eastCoastSales + " million dollars");
   }
}                    