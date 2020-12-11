/* Program: ChargeAccountValidation.java
   Date:    11/11/2017
   Author:  Morgan Visnesky
   
   "Chapter 7 Programming challenge #3"
   
   The challenge:
   
   Create a class with a method that accepts a charge account number as its argument. 
   The method should determine whether the number is valid by comparing it to the following 
   list of valid charge account numbers: 
   
   5658845 4520125 7895122 8777541 8451277 1302850 
   8080152 4562555 5552012 5050552 7825877 1250255 
   1005231 6545231 3852085 7576651 7881200 4581002 
   
   These numbers should be stored in an array or an ArrayList object. 
   Use a sequential search to locate the number passed as an argument. 
   If the number is in the array, the method should return true, indicating the number is valid. 
   If the number is not in the array, the method should return false, indicating the number is invalid. 
   Write a program that tests the class by asking the user to enter a charge account number. 
   The program should display a message indicating whether the number is valid or invalid.   
       
*/
import java.util.Scanner;

public class ChargeAccountValidation
{
   public static void main(String[] args)
{
   Scanner keyboard = new Scanner(System.in);
   System.out.println("please enter an account number: ");
   int input = keyboard.nextInt();
   boolean valid = accounts(input);
   if (valid == true)
   {
      System.out.println("You have entered a VALID account number.");
   }
   else
   {
      System.out.println("You have entered an INVALID account number.");
   }
}
   
   public static boolean accounts(int value)
   {
   
  
   final int[] accounts = {5658845, 4520125, 7895122, 8777541, 8451277, 1302850, 
                     8080152, 4562555, 5552012, 5050552, 7825877, 1250255, 
                     1005231, 6545231, 3852085, 7576651, 7881200, 4581002};
   
   
                     

   boolean validation = sequentialSearch(accounts, value);
   return validation;
   }
   

public static boolean sequentialSearch(int[] array, 
                                    int value) 
{ 
   int index; 
   // Loop control variable 
   int element; 
   // Element the value is found at 
   boolean found; 
   // Flag indicating search results 

   // Element 0 is the starting point of the search. 
   index = 0; 
 
   // Store the default values element and found. 
   element = -1; 
   found = false; 

// Search the array. 
   while (!found && index < array.length) 
   { 
      if (array[index] == value) 
      { 
         found = true; 
         element = index; 
      } 
      index++; 
   } 
 
   return found; 
}
}


   
   
