/* Program: StringManipulator.java
   Date:    09/21/2017
   Author:  Morgan Visnesky
   
   "Chapter 2 Programming challenge #12"
   
   The challenge:
   
  Takes a city name as user input, then proceeds to 
  manipulate the string in 4 ways

     
*/
import java.util.Scanner;

public class StringManipulator
{
   public static void main(String[] args)
   {
   
   
   Scanner keyboard = new Scanner(System.in);//Scanner creation for input
   
   System.out.println("Please enter the name of your favorite city!");
   
   String favCity = keyboard.next(); //takes user input assigns to string variable
   
   //declaring manipulation varaible below
   int stringSize;
   String allCaps;
   String allLower;
   char firstLetter;
   
   // below are operations being performed by methods of the string class
   firstLetter = favCity.charAt(0);
   
   stringSize = favCity.length();
   
   allCaps = favCity.toUpperCase();
   
   allLower = favCity.toLowerCase();
   
   System.out.println(stringSize + "\n" +
                     allCaps + "\n" +
                     allLower + "\n" +
                     firstLetter);
   
   
   }
}      