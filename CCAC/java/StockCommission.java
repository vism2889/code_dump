/* Program: StockCommission.java
   Date:    09/21/2017
   Author:  Morgan Visnesky
   
   "Chapter 2 Programming challenge #15"
   
   The challenge:
   
  Take stock price and number of shares of stock to find total cost, 
  then apply a 2% fee taken by the stock broker for commission, 
  then find overall cost.
  Finally display all information. 

     
*/

public class StockCommission
{
   public static void main(String[] args)
   {
    final int stockAmount = 600;
    final double stockPrice = 21.77;
    final double commission = 0.02;
    
    double amountBeforeCom = stockAmount * stockPrice;
    double comAmount = commission * amountBeforeCom;
    double finalPrice = comAmount + amountBeforeCom;
    
    System.out.println("Price of Stock: " + amountBeforeCom + "\n" +
                        "Price of Commission: " + comAmount + "\n" +
                        "Total Paid: " + finalPrice);
   }
}                        