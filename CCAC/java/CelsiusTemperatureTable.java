/* Program: CelsiusTemperatureTable.java
   Date:    10/17/2017
   Author:  Morgan Visnesky
   
   "Chapter 5 Programming challenge #6"
   
   The challenge:
   
   The formula for converting a temperature from Fahrenheit to Celsius is 
   
   C = 5/9(F-32) 
   
   where F is the Fahrenheit temperature and C is the Celsius temperature. 
   Write a method named celsius that accepts a Fahrenheit temperature as an argument. 
   The method should return the temperature, converted to Celsius. 
   
   Demonstrate the method by calling it in a loop that displays a table of the 
   Fahrenheit temperatures 0 through 20 and their Celsius equivalents.


      
*/
//import javax.swing.JOptionPane
import java.text.DecimalFormat;
public class CelsiusTemperatureTable
{
   public static void main(String[] args)
   {
      double loopVar = 0.0;
      System.out.println("F"+"_____________"+"C"+"\n");
      while (loopVar <= 20 )
      {
        
         double celsiusDeg = celsius(loopVar);
         
         DecimalFormat df = new DecimalFormat("0.00");
         String celDeg = df.format(celsiusDeg);
      
         System.out.println(loopVar + "          " + celDeg);
         
         loopVar++;
      }
   }
   
   public static double celsius(double fahrenheitTemp)
   {
      double celsiusTemp = (5.0/9.0)*(fahrenheitTemp - 32.0);
      return celsiusTemp;
      
      
   }
}