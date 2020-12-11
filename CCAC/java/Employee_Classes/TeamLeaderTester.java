/* Program: TeamLeaderTester.java
   Date:    12/08/2017
   Author:  Morgan Visnesky
   
   "Chapter 10 Programming challenge #3 Extra-Credit part 2"
   
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
public class TeamLeaderTester {
   public static void main(String[] args)
   {
      TeamLeader TL = new TeamLeader("Morgan Visnesky","123-A", "10/03/2017", 2, 65.00, 150.00, 200.00, 175.00);
      
      System.out.println("\nThis is an TeamLeader object");
      System.out.println(TL);
   }
}