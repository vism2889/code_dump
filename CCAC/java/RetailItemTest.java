/* Program: RetailItemTest.java
   Date:    10/28/2017
   Author:  Morgan Visnesky
   
   "Chapter 6 Programming challenge #4 Part 2/2"
   
   The challenge:
   Write a class named RetailItem that holds data about an item in a retail store. 
   The class should have the following fields: 
   • description. The description field references a String object that holds a brief description of the item. 
   • unitsOnHand. The unitsOnHand field is an int variable that holds the number of units currently in inventory. 
   • price. The price field is a double that holds the item’s retail price. 
   
   Write a constructor that accepts arguments for each field, appropriate mutator methods that store values in these 
   fields, and accessor methods that return the values in these fields. 
   Once you have written the class, write a separate program that creates three RetailItem objects and stores 
   the following data in them: 
   Description             Units on Hand           Price  
   Item #1 Jacket               12                 59.95 
   Item #2 Designer Jeans       40                 34.95 
   Item #3 Shirt                20                 24.95

*/
public class RetailItemTest
{
   public static void main(String[] args)
   {
      RetailItem item1 = new RetailItem("Jacket",12,59.95);
      RetailItem item2 = new RetailItem("Designer Jeans",40,34.95);
      RetailItem item3 = new RetailItem("Shirt",20,24.95);
      
      System.out.println("Retail Item # 1:" + 
                         "\n\t" + "Description: " + item1.getDesc() +
                         "\n\t" + "Units On Hand: " + item1.getUnits() +
                         "\n\t" + "Price: $" + item1.getPrice());
      
      System.out.println("Retail Item # 2:" + 
                         "\n\t" + "Description: " + item2.getDesc() +
                         "\n\t" + "Units On Hand: " + item2.getUnits() +
                         "\n\t" + "Price: $" + item2.getPrice());                   
                           
      System.out.println("Retail Item # 3:" + 
                         "\n\t" + "Description: " + item3.getDesc() +
                         "\n\t" + "Units On Hand: " + item3.getUnits() +
                         "\n\t" + "Price: $" + item3.getPrice());
   }
}
   