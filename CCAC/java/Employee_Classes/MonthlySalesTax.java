/* Program: MonthlySalesTax.java
   Date:    12/11/2017
   Author:  Morgan Visnesky
   
   "Chapter 12 Programming challenge #2"
   
   The challenge:
   A retail company must file a monthly sales tax report listing the total sales 
   for the month, and the amount of state and county sales tax collected. 
   The state sales tax rate is 4 percent and the county sales tax rate is 2 percent. 
   Create a GUI application that allows the user to enter the total sales for the 
   month into a text field. From this figure, the application should calculate and 
   display the following: 
   • The amount of county sales tax 
   • The amount of state sales tax 
   • The total sales tax (county plus state) 
   In the application’s code, represent the county tax rate (0.02) and the state tax 
   rate (0.04) as named constants.
*/
import javax.swing.*;
import java.awt.event.*;
public class MonthlySalesTax extends JFrame
{
   private JPanel panel;  
   private JLabel messageLabel;  
   private JTextField salesTextField;  
   private JButton calcButton;  
   private final int WINDOW_WIDTH = 310;  
   private final int WINDOW_HEIGHT = 100; 

   public MonthlySalesTax()
   {
      setTitle("Monthly Sales Tax");
      setSize(WINDOW_WIDTH, WINDOW_HEIGHT);
      setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
      buildPanel();
      add(panel);
      setLocationRelativeTo(null);
      setVisible(true);
      
   }
   private void buildPanel()
   {
      messageLabel = new JLabel("Monthly sales: ");
      salesTextField = new JTextField(10);
      calcButton = new JButton("Calculate");
      
      calcButton.addActionListener(new CalcButtonListener());
      panel = new JPanel();
      panel.add(messageLabel);
      panel.add(salesTextField);
      panel.add(calcButton);
   }
   private class CalcButtonListener implements ActionListener
   {
      public void actionPerformed(ActionEvent e)
      {
         final double COUNTY_TAX = 0.02;
         final double STATE_TAX = 0.04;
         String input;
         double mSales;
         input= salesTextField.getText();
         mSales= Double.parseDouble(input);
         
         double mCountyTax = mSales*COUNTY_TAX;
         double mStateTax = mSales*STATE_TAX;
         double mTotalTax = mCountyTax + mStateTax;
         
         JOptionPane.showMessageDialog(null, "Your monthly taxes for $" + input +
                                             " is as follows: " +
                                             "\nCounty Taxes: $" + mCountyTax +
                                             "\nState Taxes:  $" + mStateTax +
                                             "\nTotal Taxes:  $" + mTotalTax);
      }
   }
   public static void main(String[] args)
   {
      new MonthlySalesTax();
   }
}
         