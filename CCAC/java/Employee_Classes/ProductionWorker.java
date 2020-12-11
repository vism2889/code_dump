/* Program: ProductionWorker.java
   Date:    11/21/2017
   Author:  Morgan Visnesky
   
   "Chapter 10 Programming challenge #1"
   
   The challenge:
   Design a class named Employee. The class should keep the following information in fields:
   • Employee name 
   • Employee number in the format XXX–L, where each X is a digit within the range 0–9 
     and the L is a letter within the range A–M. 
   • Hire date Write one or more constructors and the appropriate accessor and mutator 
     methods for the class. 
     
  Next, write a class named ProductionWorker that extends the Employee class. The ProductionWorker 
  class should have fields to hold the following information: 
  • Shift (an integer) 
  • Hourly pay rate (a double) The workday is divided into two shifts: day and night. 
    The shift field will be an integer value representing the shift that the employee works. 
    The day shift is shift 1 and the night shift is shift 2. 
  
  Write one or more constructors and the appropriate accessor and mutator methods for the class. 
  Demonstrate the classes by writing a program that uses a ProductionWorker object.   
*/

public class ProductionWorker extends Employee {
  
  
  private int shift;
  private double hourlyPayRate;

  public ProductionWorker(String name, String number, String hireDate, int shift, double payRate) 
  {
    super(name, number, hireDate);
    this.shift = shift;
    this.hourlyPayRate = payRate;
  }

  public int getShift() 
  {
    return shift;
  }

  public void setShift(int newShift) 
  {
    this.shift = newShift;
  }

  public double getPayRate() 
  {
    return hourlyPayRate;
  }
 
  public void setPayRate(double newPayRate) 
  {
    this.hourlyPayRate = newPayRate;
  }

  public String toString() 
  {
    String str = super.toString();
    str += "\nEmployee Shift: " + shift +
           "\nEmployee Hourly Pay Rate: " + hourlyPayRate;
    return str;
  }

}