
/* Program: Geometry.java
   Date:    11/19/2017
   Author:  Morgan Visnesky
   
   "Chapter 8 Programming challenge #9"
   
   The challenge:
   
   Design a Geometry class with the following methods: 
   • A static method that accepts the radius of a circle and returns the area of the circle. 
      Use the following formula: 
      Area 5 πr 2 Use Math.PI for π and the radius of the circle for r. 
   • A static method that accepts the length and width of a rectangle and returns the area of the rectangle. 
      Use the following formula: 
      Area 5 Length 3 Width 
   • A static method that accepts the length of a triangle’s base and the triangle’s height. 
      The method should return the area of the triangle.
      Use the following formula: 
      Area 5 Base 3 Height 3 0.5 
   
   The methods should display an error message if negative values are used for the circle’s radius, 
   the rectangle’s length or width, or the triangle’s base or height. 
   
   Next, write a program to test the class, which displays the following menu and responds 
   to the user’s selection: 
   Geometry Calculator 
   1. Calculate the Area of a Circle 
   2. Calculate the Area of a Rectangle 
   3. Calculate the Area of a Triangle 
   4. Quit 
   Enter your choice (1-4): 
   
   Display an error message if the user enters a number outside the range of 1 through 4 when 
   selecting an item from the menu.

*/
import javax.swing.JOptionPane;


public class Geometry
{
   
   
   public static double circleArea(double radius)
   {
      double area;
      while (radius < 0.0)
      {
      String input = JOptionPane.showInputDialog("The number you entered for the radius was negative" +"\n" +
                                   "Please enter a positive value");
                                   
      radius = Double.parseDouble(input); 
      }
      
      area = Math.PI * radius * radius; 
      return area;                          
   }
   
   public static double rectangleArea(double length, double width)
   {
      double area;
      while (length < 0.0)
      {
      String input = JOptionPane.showInputDialog("The number you entered for the length was negative" +"\n" +
                                   "Please enter a positive value");
                                   
      length = Double.parseDouble(input); 
      }
      while (width < 0.0)
      {
      String input = JOptionPane.showInputDialog("The number you entered for the width was negative" +"\n" +
                                   "Please enter a positive value");
                                   
      width = Double.parseDouble(input); 
      }
      
      area = length*width;
      return area;
   }
   
   public static double triangleArea(double base, double height)
   {
   double area;
   while (base < 0.0)
      {
      String input = JOptionPane.showInputDialog("The number you entered for the base was negative" +"\n" +
                                   "Please enter a positive value");
                                   
      base = Double.parseDouble(input); 
      }
      while (height < 0.0)
      {
      String input = JOptionPane.showInputDialog("The number you entered for the height was negative" +"\n" +
                                   "Please enter a positive value");
                                   
      height = Double.parseDouble(input); 
      }
   
   area = base * height *0.5;
   return area; 
   
   }
}