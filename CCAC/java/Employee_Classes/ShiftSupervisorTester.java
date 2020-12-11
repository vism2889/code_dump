/* Program: ShiftSupervisorTester.java
   Date:    12/08/2017
   Author:  Morgan Visnesky
   
   "Chapter 10 Programming challenge #2 part 2"
   
   The challenge:
   In a particular factory, a shift supervisor is a salaried employee who 
   supervises a shift. In addition to a salary, the shift supervisor earns a yearly 
   bonus when his or her shift meets production goals. Design a ShiftSupervisor 
   class that extends the Employee class you created in Programming Challenge 1. 
   The ShiftSupervisor class should have a field that holds the annual salary and a 
   field that holds the annual production bonus that a shift supervisor has earned. 
   Write one or more constructors and the appropriate accessor and mutator methods 
   for the class. Demonstrate the class by writing a program that uses a 
   ShiftSupervisor object.
*/
public class ShiftSupervisorTester {
   public static void main(String[] args)
   {
      ShiftSupervisor SS = new ShiftSupervisor("Morgan Visnesky","123-A", "10/03/2017", 45000.00, 5000.00 );
      
      System.out.println("\nThis is an ShiftSupervisor object");
      System.out.println(SS);
   }
}