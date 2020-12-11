/* Program: TelephoneNumberConverter.java
   Date:    11/21/2017
   Author:  Morgan Visnesky
   
   "Chapter 9 Programming challenge #13"
   
   The challenge:
   
   Many companies use telephone numbers like 555-GET-FOOD so the number is easier for their 
   customers to remember. On a standard telephone, the alphabetic letters are mapped to numbers in the 
   following fashion: 
   
   A, B, and C = 2 
   D, E, and F = 3 
   G, H, and I = 4 
   J, K, and L = 5 
   M, N, and O = 6 
   P, Q, R, and S = 7 
   T, U, and V = 8 
   W, X, Y, and Z = 9 
   
   Write an application that asks the user to enter a 10-character telephone number in the 
   format XXX-XXX-XXXX. The application should display the telephone number with any alphabetic 
   characters that appeared in the original translated to their numeric equivalent. 
   For example, if the user enters 555-GET-FOOD the application should display 555-438-3663.
*/
import java.util.Scanner;
public class TelephoneNumberConverter
{
   
   public static void main(String[] args)
   {
      Scanner keyboard = new Scanner(System.in);
      String input;
      System.out.println("**   This programs converts telephone numbers with  **" + "\n" +
                         "**     words or letters in them into all digits.    **" + "\n" + 
                         "--                                                  --" + "\n" +
                         "** Enter a 10 digit telephone number in the form of **" + "\n" +
                         "**                 XXX-XXX-XXXX                     **" + "\n" +
                         "**       (For example: If you enter 555-GET-FOOD    **" + "\n" +
                         "**          your result will be 555-438-3663)       **");
      
      input = keyboard.nextLine();
      char[] teleArray = input.toCharArray();
      StringBuilder numArray = new StringBuilder();
      int len = input.length();
      for (int i = 0; i < len; i++)
      {
         if (teleArray[i] == 'A' ||teleArray[i] == 'B' ||teleArray[i] == 'C' ||teleArray[i] == '2')
            numArray.append('2');
         if (teleArray[i] == 'D' ||teleArray[i] == 'E' ||teleArray[i] == 'F' ||teleArray[i] == '3')
            numArray.append("3");
         if (teleArray[i] == 'G' ||teleArray[i] == 'H' ||teleArray[i] == 'I' ||teleArray[i] == '4')
            numArray.append("4");
         if (teleArray[i] == 'J' ||teleArray[i] == 'K' ||teleArray[i] == 'L' ||teleArray[i] == '5')
            numArray.append("5");
         if (teleArray[i] == 'M' ||teleArray[i] == 'N' ||teleArray[i] == 'O' ||teleArray[i] == '6')
            numArray.append("6");
         if (teleArray[i] == 'P' ||teleArray[i] == 'Q' ||teleArray[i] == 'R' ||teleArray[i] == 'S' ||teleArray[i] == '7')
            numArray.append("7");
         if (teleArray[i] == 'T' ||teleArray[i] == 'U' ||teleArray[i] == 'V' ||teleArray[i] == '8')
            numArray.append("8");
         if (teleArray[i] == 'W' ||teleArray[i] == 'X' ||teleArray[i] == 'Y' ||teleArray[i] == 'Z' ||teleArray[i] == '9')
            numArray.append("9");
         if (teleArray[i] == '1' ||teleArray[i] == '0')
            numArray.append(i);
      }
      numArray.insert(3, "-");
      numArray.insert(7, "-");
      System.out.print(numArray.toString());
   }

}