/* Program: TeamLeader.java
   Date:    12/08/2017
   Author:  Morgan Visnesky
   
   "Chapter 10 Programming challenge #3 Extra-Credit"
   
   The challenge:
   In a particular factory, a team leader is an hourly paid production worker that 
   leads a small team. In addition to hourly pay, team leaders earn a fixed monthly 
   bonus. Team leaders are required to attend a minimum number of hours of training 
   per year. Design a TeamLeader class that extends the ProductionWorker class you 
   designed in Programming Challenge 1. The TeamLeader class should have fields for 
   the monthly bonus amount, the required number of training hours, and the number 
   of training hours that the team leader has attended. Write one or more 
   constructors and the appropriate accessor and mutator methods for the class. 
   Demonstrate the class by writing a program that uses a TeamLeader object.


*/

public class TeamLeader extends ProductionWorker 
{
  private double monthlyBonus;
  private double requiredTrainingHours;
  private double completedTrainingHours;

  public TeamLeader(String name, String number, String hireDate, int shift, double payRate, double monthlyBonus, double rth, double cth) 
  {
    super(name, number, hireDate, shift, payRate);
    this.monthlyBonus = monthlyBonus;
    this.requiredTrainingHours = rth;
    this.completedTrainingHours = cth;
  }

  public TeamLeader(TeamLeader tl) 
  {
    super(tl.getName(), tl.getNumber(), tl.getHireDate(), tl.getShift(), tl.getPayRate());
    this.monthlyBonus = tl.getMonthlyBonus();
    this.requiredTrainingHours = tl.getRequiredTrainingHours();
    this.completedTrainingHours = tl.getCompletedTrainingHours();
  }


  public double getMonthlyBonus() 
  {
    return monthlyBonus;
  }


  public void setMonthlyBonus(double bonus) 
  {
    this.monthlyBonus = bonus;
  }


  public double getRequiredTrainingHours() 
  {
    return requiredTrainingHours;
  }


  public void setRequiredTrainingHours(double hours) 
  {
    this.requiredTrainingHours = hours;
  }


  public double getCompletedTrainingHours() 
  {
    return completedTrainingHours;
  }


  public void setCompletedTrainingHours(double hours) 
  {
    this.completedTrainingHours = hours;
  }


  public String toString() 
  {
    String str = super.toString();
    str += "\nEmployee Monthly Bonus: " + monthlyBonus +
           "\nEmployee Required Training Hours: " + requiredTrainingHours +
           "\nEmployee Completed Training Hours: " + completedTrainingHours;
    return str;
  }

}