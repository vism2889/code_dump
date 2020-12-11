/* Program: EmployeeTest.java
   Date:    10/28/2017
   Author:  Morgan Visnesky
   
   "Chapter 6 Programming challenge #1 Part 2/2"
   
   The challenge:
Write a class named Employee that has the following fields:
 • name. The name field references a String object that holds the employee’s name. 
 • idNumber. The idNumber is an int variable that holds the employee’s ID number. 
 • department. The department field references a String object that holds the name of 
   the department where the employee works. 
 • position. The position field references a String object that holds the employee’s 
   job title. 
   
 The class should have the following constructors: 
 • A constructor that accepts the following values as arguments and 
   assigns them to the appropriate fields: employee’s name, employee’s ID number, 
   department, and position. 
 • A constructor that accepts the following values as arguments and assigns them 
   to the appropriate fields: employee’s name and ID number. The department and 
   position fields should be assigned an empty string (""). 
 • A no-arg constructor that assigns empty strings ("") to the name, department, 
   and position fields, and 0 to the idNumber field. Write appropriate mutator 
   methods that store values in these fields and accessor methods that return the 
   values in these fields. 
   
   Once you have written the class, write a separate program 
   that creates three Employee objects to hold the following data: 
   Name              ID Number         Department        Position 
   Susan Meyers      47899             Accounting        Vice President 
   Mark Jones        39119             IT                Programmer 
   Joy Rogers        81774             Manufacturing     Engineer 
   
   
   The program should store this data in the three objects and then display 
   the data for each employee on the screen.

*/

public class EmployeeTest
{
   public static void main(String[] args)
   {
      Employee emp1 = new Employee("Susan Meyers", 47899, "Accounting", "Vice President");
      Employee emp2 = new Employee("Mark Jones", 39119, "IT", "Programmer");
      Employee emp3 = new Employee("Joy Rogers", 81774, "Manufacturing", "Engineer");
      
      System.out.println("Employee #1 is: " +  "\n\t" + "Name: " + emp1.getName() + "\n\t" + "ID: " + emp1.getID() 
                                             + "\n\t" + "Department: " + emp1.getDepartment() 
                                             + "\n\t" + "Position: " + emp1.getPosition());
      System.out.println("Employee #2 is: " +  "\n\t" + "Name: " + emp2.getName() + "\n\t" + "ID: " + emp2.getID() 
                                             + "\n\t" + "Department: " + emp2.getDepartment() 
                                             + "\n\t" + "Position: " + emp2.getPosition());
      System.out.println("Employee #3 is: " +  "\n\t" + "Name: " + emp3.getName() + "\n\t" + "ID: " + emp3.getID() 
                                             + "\n\t" + "Department: " + emp3.getDepartment() 
                                             + "\n\t" + "Position: " + emp3.getPosition());                                       
   }
}