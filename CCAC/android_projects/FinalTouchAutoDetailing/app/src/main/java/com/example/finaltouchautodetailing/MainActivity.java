package com.example.finaltouchautodetailing;

import android.app.DatePickerDialog;
import android.os.Bundle;
import android.support.design.widget.FloatingActionButton;
import android.support.design.widget.Snackbar;
import android.support.v7.app.AppCompatActivity;
import android.support.v7.widget.Toolbar;
import android.view.View;
import android.view.Menu;
import android.view.MenuItem;
import android.widget.Button;
import android.widget.CheckBox;
import android.widget.DatePicker;
import android.widget.TextView;

import java.text.DateFormat;
import java.text.DecimalFormat;
import java.text.NumberFormat;
import java.util.Calendar;

public class MainActivity extends AppCompatActivity {

    private TextView reservation;
    double totalCost;
    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);
        reservation = (TextView)findViewById(R.id.txtReservation);
        Button button = (Button)findViewById(R.id.btnDate);
        final CheckBox check1 = (CheckBox)findViewById(R.id.chkBox1);
        final CheckBox check2 = (CheckBox)findViewById(R.id.chkBox2);
        final CheckBox check3 = (CheckBox)findViewById(R.id.chkBox3);
        final CheckBox check4 = (CheckBox)findViewById(R.id.chkBox4);
        button.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                new DatePickerDialog(MainActivity.this, d,c.get(Calendar.YEAR),c.get(Calendar.MONTH),
                        c.get(Calendar.DAY_OF_MONTH)).show();
                if (check1.isChecked()){
                    totalCost += 14.99;
                }
                if (check2.isChecked()){
                    totalCost += 49.99;
                }
                if (check3.isChecked()){
                    totalCost += 189.99;
                }
                if (check4.isChecked()){
                    totalCost += 169.99;
                }


            }
        });
    }

    Calendar c = Calendar.getInstance();
    DateFormat fmtDate = DateFormat.getDateInstance();
    NumberFormat curr = new DecimalFormat("$###,###.##");
    DatePickerDialog.OnDateSetListener d = new DatePickerDialog.OnDateSetListener() {
        @Override
        public void onDateSet(DatePicker view, int year, int month, int dayOfMonth) {
            c.set(Calendar.YEAR, year);
            c.set(Calendar.MONTH, month);
            c.set(Calendar.DAY_OF_MONTH, dayOfMonth);


            reservation.setText("Your reservation is set for: " + fmtDate.format(c.getTime()) + "\n" +
                                "Your total cost is: " + curr.format(totalCost));
        }
    };

    @Override
    public boolean onCreateOptionsMenu(Menu menu) {
        // Inflate the menu; this adds items to the action bar if it is present.
        getMenuInflater().inflate(R.menu.menu_main, menu);
        return true;
    }

    @Override
    public boolean onOptionsItemSelected(MenuItem item) {
        // Handle action bar item clicks here. The action bar will
        // automatically handle clicks on the Home/Up button, so long
        // as you specify a parent activity in AndroidManifest.xml.
        int id = item.getItemId();

        //noinspection SimplifiableIfStatement
        if (id == R.id.action_settings) {
            return true;
        }

        return super.onOptionsItemSelected(item);
    }
}
