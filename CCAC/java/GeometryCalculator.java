
/* Program: GeometryCalculator.java
   Date:    11/19/2017
   Author:  Morgan Visnesky
   
   "Chapter 8 Programming challenge #9 Part 2"
   
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

public class GeometryCalculator
{
   
   public static int getInput()
   {
   String input = JOptionPane.showInputDialog(null,">>Geometry Calculator<<" + "\n" +
                                          "1. Calculate the Area of a Circle." + "\n" +
                                          "2. Calculate the Area of a Rectangle." + "\n" +
                                          "3. Calculate the Area of a Triangle." + "\n" +
                                          "4. Quit." +"\n" +
                                          "Enter your choice (1-4):");
     int userInput = Integer.parseInt(input);
     return userInput;
   }
   public static void main(String[] args)
   {
     int userInput = getInput(); 
     while (userInput < 1 || userInput > 4)
     {
      JOptionPane.showMessageDialog(null,"The number you entered is out of range please enter 1-4");
      userInput = getInput();
     }
     
     if (userInput == 1)
     {
         String circInput = JOptionPane.showInputDialog(null,"Please enter the Radius of the circle" + 
                                                      "\n" + "for which you would like to find the area.");
         double radius = Double.parseDouble(circInput); 
         JOptionPane.showMessageDialog(null,"The area of the circle is: " + Geometry.circleArea(radius));
         System.exit(0);
     }
     if (userInput == 2)
     {
         String recLenInput = JOptionPane.showInputDialog(null,"Please enter the Length of the rectangle" + 
                                                        "\n" + "for which you would like to find the area.");
         double length = Double.parseDouble(recLenInput);                                               
         String recWidInput = JOptionPane.showInputDialog(null,"Please enter the Width of the rectangle" + 
                                                         "\n" + "for which you would like to find the area");
         double width = Double.parseDouble(recWidInput);
          
         JOptionPane.showMessageDialog(null,"The area of the rectangle is: " + Geometry.rectangleArea(length,width));
         System.exit(0);
     }   
     
     if (userInput == 3)
     {
         String baseInput = JOptionPane.showInputDialog(null,"Please enter the Base of the triangle" + 
                                                        "\n" + "for which you would like to find the area.");
         double length = Double.parseDouble(baseInput);                                               
         String heightInput = JOptionPane.showInputDialog(null,"Please enter the Height of the triangle" + 
                                                         "\n" + "for which you would like to find the area");
         double width = Double.parseDouble(heightInput);
          
         JOptionPane.showMessageDialog(null,"The area of the triangle is: " + Geometry.triangleArea(length,width));
         System.exit(0);
     }
     if (userInput == 4)
     {
         System.exit(0);
     }
     
   }

}                                     