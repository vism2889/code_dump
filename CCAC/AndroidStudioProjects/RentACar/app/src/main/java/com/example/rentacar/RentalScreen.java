package com.example.rentacar;

import android.app.ListActivity;
import android.content.Intent;
import android.net.Uri;
import android.os.Bundle;
import android.support.design.widget.FloatingActionButton;
import android.support.design.widget.Snackbar;
import android.support.v7.app.AppCompatActivity;
import android.support.v7.widget.Toolbar;
import android.view.View;
import android.widget.ArrayAdapter;
import android.widget.ListView;

public class RentalScreen extends ListActivity {

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        String[] rentalOptions = {"Enterprise", "Hertz", "Alamo", "Budget"
                            , "Avis", "Zip Car", "Home Screen"};
        setListAdapter(new ArrayAdapter<String>(this, R.layout.activity_rental_screen, R.id.travel, rentalOptions));



    }
    protected  void onListItemClick(ListView l, View v, int position, long id){
        switch(position){
            case 0:

                startActivity(new Intent(Intent.ACTION_VIEW, Uri.parse("https://www.enterprise.com/en/home.html")));
                break;
            case 1:

                startActivity(new Intent(Intent.ACTION_VIEW, Uri.parse("https://www.hertz.com/rentacar/reservation/")));
                break;
            case 2:

                startActivity(new Intent(Intent.ACTION_VIEW, Uri.parse("https://www.alamo.com/en_US/car-rental/home.html")));
                break;
            case 3:

                startActivity(new Intent(Intent.ACTION_VIEW, Uri.parse("https://www.budget.com/en/home")));
                break;

            case 4:

                startActivity(new Intent(Intent.ACTION_VIEW, Uri.parse("https://www.avis.com/en/home")));
                break;

            case 5:

                startActivity(new Intent(Intent.ACTION_VIEW, Uri.parse("https://www.zipcar.com/")));
                break;

            case 6:

                startActivity(new Intent(RentalScreen.this, MainActivity.class));
                break;

        }
    }





}
