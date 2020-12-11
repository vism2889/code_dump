/* Program: TheaterRevenue.java
   Date:    12/11/2017
   Author:  Morgan Visnesky
   
   "Chapter 12 Programming challenge #5"
   
   The challenge:
   A movie theater only keeps a percentage of the revenue earned from ticket sales. 
   The remainder goes to the movie company. Create a GUI application that allows 
   the user to enter the following data into text fields: 
   • Price per adult ticket 
   • Number of adult tickets sold 
   • Price per child ticket 
   • Number of child tickets sold 
   The application should calculate and display the following data for one 
   night’s box office business at a theater: 
   • Gross revenue for adult tickets sold. 
     This is the amount of money taken in for all adult tickets sold. 
   • Net revenue for adult tickets sold. 
     This is the amount of money from adult ticket sales left over 
     after the payment to the movie company has been deducted. 
   • Gross revenue for child tickets sold. 
     This is the amount of money taken in for all child tickets sold. 
   • Net revenue for child tickets sold. 
     This is the amount of money from child ticket sales left over after 
     the payment to the movie company has been deducted. 
   • Total gross revenue. 
     This is the sum of gross revenue for adult and child tickets sold. 
   • Total net revenue.
     This is the sum of net revenue for adult and child tickets sold. 
     
   Assume the theater keeps 20 percent of its box office receipts. 
   Use a constant in your code to represent this percentage.
*/
import javax.swing.*;
import java.awt.event.*;
import java.awt.*;
public class TheaterRevenue extends JFrame
{
   private JPanel panel;  
   private JLabel adultTixPriceLabel;
   private JLabel childTixPriceLabel;
   private JLabel numAdultTixLabel;
   private JLabel numChildTixLabel;  
   private JTextField adultTixPrice;
   private JTextField childTixPrice;
   private JTextField numAdultTix;
   private JTextField numChildTix; 
   private JButton calcButton;  
   private final int WINDOW_WIDTH = 350;  
   private final int WINDOW_HEIGHT = 200; 

   public TheaterRevenue()
   {
      setTitle("Monthly Sales Tax");
      setSize(WINDOW_WIDTH, WINDOW_HEIGHT);
      setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
      buildPanel();
      add(panel);
      setLocationRelativeTo(null);
      setVisible(true);
      panel.setLayout(new FlowLayout());
      
   }
   private void buildPanel()
   {
      adultTixPriceLabel = new JLabel("Adult Ticket Price: ");
      adultTixPrice = new JTextField(10);
      childTixPriceLabel = new JLabel("Child Ticket Price: ");
      childTixPrice = new JTextField(10);
      numAdultTixLabel = new JLabel("Number of adult ticket sales: ");
      numAdultTix = new JTextField(10);
      numChildTixLabel = new JLabel("Number of child ticket sales: ");
      numChildTix = new JTextField(10);
      calcButton = new JButton("Calculate");
      
      calcButton.addActionListener(new CalcButtonListener());
      panel = new JPanel();
      panel.add(adultTixPriceLabel, BorderLayout.WEST);
      panel.add(adultTixPrice, BorderLayout.EAST);
      panel.add(childTixPriceLabel, BorderLayout.WEST);
      panel.add(childTixPrice, BorderLayout.EAST);
      panel.add(numAdultTixLabel, BorderLayout.WEST);
      panel.add(numAdultTix,BorderLayout.EAST);
      panel.add(numChildTixLabel, BorderLayout.WEST);
      panel.add(numChildTix, BorderLayout.EAST);
      
      
      
      
      panel.add(calcButton);
   }
   private class CalcButtonListener implements ActionListener
   {
      public void actionPerformed(ActionEvent e)
      {
         final double THEATER_KEEP = 0.20;
         
         String ATPinput; 
         String CTPinput;
         String NATinput;
         String NCTinput;
         double ATPrice;
         double CTPrice;
         double ATNum;
         double CTNum;
         ATPinput = adultTixPrice.getText();
         ATPrice = Double.parseDouble(ATPinput);
         CTPinput = childTixPrice.getText();
         CTPrice = Double.parseDouble(CTPinput);
         NATinput = numAdultTix.getText();
         ATNum = Double.parseDouble(NATinput);
         NCTinput = numChildTix.getText();
         CTNum = Double.parseDouble(NCTinput);
         
         double grossAdult = ATPrice*ATNum;
         double grossChild = CTPrice*CTNum;
         double netAdult = grossAdult*THEATER_KEEP;
         double netChild = grossChild*THEATER_KEEP;
         double totalGross = grossAdult+grossChild;
         double totalNet = netAdult+netChild;
         
         JOptionPane.showMessageDialog(null, "Nightly Revenue Calculation is as follows: " +
                                             "\nGross Adult Sales: $" + grossAdult +
                                             "\nGross Child Sales: $" + grossChild +
                                             "\nNet Adult Sales:  $" + netAdult + 
                                             "\nNet child Sales:  $" + netChild +
                                             "\nTotal Gross Sales:  $" + totalGross +
                                             "\nTotal Net Sales:  $" + totalNet);
      }
   }
   public static void main(String[] args)
   {
      new TheaterRevenue();
   }
}