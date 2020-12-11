/* Program: ShiftSupervisor.java
   Date:    12/08/2017
   Author:  Morgan Visnesky
   
   "Chapter 10 Programming challenge #2"
   
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
public class ShiftSupervisor extends Employee 
{

  private double annualSalary;
  private double annualBonus;

  public ShiftSupervisor(String name, String number, String hireDate, double salary, double bonus) 
  {
    super(name, number, hireDate);
    this.annualSalary = salary;
    this.annualBonus = bonus;
  }

  public ShiftSupervisor(ShiftSupervisor ss) 
  {
    super(ss.getName(), ss.getNumber(), ss.getHireDate());
    this.annualSalary  = ss.getAnnualSalary();
    this.annualBonus = ss.getAnnualBonus();
  }

  public double getAnnualSalary() 
  {
    return annualSalary;
  }

  public void setAnnualSalary(double newSalary) 
  {
    this.annualSalary = newSalary;
  }

  public double getAnnualBonus() 
  {
    return annualBonus;
  }

  public void setAnnualBonus(double newBonus) 
  {
    this.annualBonus = newBonus;
  }

  public String toString() 
  {
    String str = super.toString();
    str += "\nEmployee Annual Salary: " + annualSalary +
           "\nEmployee Annual Bonus: " + annualBonus;
    return str;
  }

}
