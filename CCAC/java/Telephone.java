/* Program: Telephone.java
   Date:    11/21/17
   Author:  Morgan Visnesky
   
   Telephone numbers in the United states are commonly formatted to appear in the 
   following manner:
      (XXX)XXX-XXXX
      
   In the format, X represents a digit.  The three digits that appear inside the 
   parentheses are the area code.  The three digits following the area code are the
   prefix, and the four digits after the hyphen are the line number.  Here is an example:
   
      (919)555-1212
   Although the parentheses and the hyphen make the number easier for people to read,
   those characters are unnecessary for processing by a computer.  In a computer system,
   a telephone number is commonly stored as an unformatted series of digits, as shown here:
   
      9195551212
      
   A program that works with telephone numbers usually needs to unformat numbers that have been entered
   by the user.  This means that the parentheses and the hyphen must be removed before the number is stored in
   a file or processed in some other way.  In addition, such a program needs the ability to format the digits
   so that the number contains the parentheses and the hyphen when it appears on the screen or is printed
   on paper.
   
   Telephone class contains the following static methods:
   
   -  isFormatted- This method accepts a string argument and returns tru is the argument is formatted as
      (XXX)XXX-XXXX.  If the argument is not formatted this way, the method returns false.
   
   -  unformat- This method accepts a String argument.  If the argument is formatted as (XXX)XXX-XXXX, the 
      method returns an unformatted version of the argument with the parentheses and hyphen removed.
      Otherwise, the method returns the original argument.
   
   -  format- This method's purpose is to format a sequence of digits as (XXX)XXX-XXXX.  The sequence
      of digits is passed as a String argument.  If the argument is 10 characters in length, then the method 
      returns the argument with parentheses and a hyphen inserted.  Otherwise, the method returns the 
      original argument.   
*/

/**
   The telephone class provides static methods for formatting and unformatting U.S. telephone numbers
*/

public class Telephone
{
   //These constant fields hold the valid lengths of
   //strings that are formatted and unformatted.
   public final static int FORMATTED_LENGTH = 13;
   public final static int UNFORMATTED_LENGTH = 10;
   
   /**
      The isFormatted method determines whether a 
      string is properly formatted as a U.S. telphone number
      in the following manner:
      (XXX)XXX-XXXX
      @param str The string to test.
      @return true is the string is properly formatted, or false otherwise.
   */
   public static boolean isFormatted(String str)
   {
      boolean valid; // Flag toindicate valid foramt
      
      // Determine whether str is properly foramtted.
      if (str.length() == FORMATTED_LENGTH &&
          str.charAt(0) == '(' &&
          str.charAt(4) == ')' &&
          str.charAt(8) == '-')
          valid = true;
       else
         valid = false;
         
       // Return the value of the valid flag.
       return valid;
    }
    
    /**
      The unformat method accepts a string containing a 
      telephone number formatted as (XXX)XXX-XXXX.
      If the argument is formatted in this way, the 
      method returns as unformatted string where the
      parentheses and hyphen have been removed.  Otherwise,
      it returns the original argument.
      @param str The string to unformat.
      @return An unformatted string.
    */
    
    public static String unformat(String str)
    {
      // Create a StringBuilder initialized with str.
      StringBuilder strb = new StringBuilder(str);
      
      // If the argument is properly formatted, then
      //  unformat it.
      if (isFormatted(str))
      {
         // First, delete the left paran at position 0.
         strb.deleteCharAt(0);
         
         // Next, delete the right paren.  Because of the 
         // previous deletion it is now located at
         // position 3.
         strb.deleteCharAt(3);
         
         // Next, delete the hyphen.  Because of the 
         // previous deletions it is now located at
         // position 6.
         strb.deleteCharAt(6);
      }
      
      // Return the unformatted string.
      return strb.toString();
   }
   
   /**
      The format method formats a string as: (XXX)XXX-XXXX.
      If the length of the argument is UNFORMATTED_LENGTH
      the method retusn the formatted string.  Otherwise, 
      it returns the original argument.
      @param str The string to format.
      @return A string formatted as a U.S. telephone number.
   */
   
   public static String format(String str)
   {
      // Creat a StringBuilder initialized with str.
      StringBuilder strb = new StringBuilder(str);
      
      // If the argument is the correct length, then format it.
      if (str.length() == UNFORMATTED_LENGTH)
      {
         // First, insert the left paren at postion 0.
         strb.insert(0,"(");
         
         // Next, insert the right paren at postion 4.
         strb.insert(4, ")");
         
         // Next insert the hyphen at postion 8.
         strb.insert(8, "-");
      }
      
      // Return the formatted string.
      return strb.toString();
   }
}