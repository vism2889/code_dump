/*

   ChangeMoney.java
*/

public class ChangeMoney
{
   public static void main(String[] args)
   {
      double fourQuarters;
      double sevenQuarters;
      fourQuarters = new Double(quartersToDollars(4));
      sevenQuarters = new Double(quartersToDollars(7));
   
      System.out.println(fourQuarters);
      System.out.println(sevenQuarters);
   }
   public static double quartersToDollars( int quarterNum)
   {
      double quarter = new Double(quarterNum);
      double dollars = quarter/4.0;
      return dollars;
   
   }
}