/* Program: Employee1.java
   Date:    11/21/2017
   Author:  Morgan Visnesky
   
   "Chapter 10 Programming challenge #13"
   
   The challenge:
   Design a class named Employee. The class should keep the following information in fields:
   • Employee name 
   • Employee number in the format XXX–L, where each X is a digit within the range 0–9 
     and the L is a letter within the range A–M. 
   • Hire date 
   Write one or more constructors and the appropriate accessor and mutator methods for the class. 
     
  Next, write a class named ProductionWorker that extends the Employee class. The ProductionWorker 
  class should have fields to hold the following information: 
  • Shift (an integer) 
  • Hourly pay rate (a double) The workday is divided into two shifts: day and night. 
    The shift field will be an integer value representing the shift that the employee works. 
    The day shift is shift 1 and the night shift is shift 2. 
  
  Write one or more constructors and the appropriate accessor and mutator methods for the class. 
  Demonstrate the classes by writing a program that uses a ProductionWorker object.   
*/

public class Employee1
{

   private String name;
   private String number;
   private String hireDate;


  // public methods
  
  /**
   * Default constructor.
   * This constructor sets the name, number and hire date for an employee
   * @param name The employee's name
   * @param number The employee's number
   * @param hireDate The date the employee was hired
   */
  public Employee1(String name, String number, String hireDate) {
    this.name = new String(name);
    this.number = new String(number);
    this.hireDate = new String(hireDate);
  }

  /**
   * Name accessor (getter)
   * @return the value of the name field
   */
  public String getName() {
    return name;
  }

  /**
   * Name mutator (setter)
   * @param name new value for the name field
   */
  public void setName(String name) {
    this.name = name;
  }

  /**
   * Number accessor (getter)
   * @return the value of the number field
   */
  public String getNumber() {
    return number;
  }

  /**
   * Number mutator (setter)
   * @param number new value for the number field
   */
  public void setNumber(String number) {
    this.number = number;
  }

  /**
   * Hire Date accessor (getter)
   * @return the value of the hireDate field
   */
  public String getHireDate() {
    return hireDate;
  }

  /**
   * Hire Date mutator (setter)
   * @param hireDate new value for the hireDate field
   */
  public void setHireDate(String hireDate) {
    this.hireDate = hireDate;
  }

  /**
   * To String Method.
   * This method will print a nicely formatted string representation of the
   * class' fields
   */
  public String toString() {
    String str = "Employee Name: " + name +
                 "\nEmployee Number: " + number +
                 "\nEmployee Hire Date: " + hireDate;
    return str;
  }
}
