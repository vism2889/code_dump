/* Program: BackwardString.java
   Date:    11/21/2017
   Author:  Morgan Visnesky
   
   "Chapter 9 Programming challenge #1"
   
   The challenge:
   
   Write a method that accepts a String object as an argument and displays its contents backward. 
   For instance, if the string argument is “gravity” the method should display -“ytivarg”. 
   Demonstrate the method in a program that asks the user to input a string and then passes it to the method.


*/
import java.util.Scanner;
public class BackwardString
{
   
   
   public static void StringReverser(String target)
   {
      String str = new String(target);
      char[] letA = str.toCharArray();
      int len = str.length();
      for (int i = len-1; i >= 0; i--)
      {
         System.out.print(letA[i]); 
      }
   }
   public static void main(String[] args)
   {
      Scanner keyboard = new Scanner(System.in);
      System.out.println("Please enter a phrase you would like to have printed backwards. ");
      String input = keyboard.nextLine();
      
      System.out.println("Here is what you entered in, but reversed: ");
      StringReverser(input);
   }

}