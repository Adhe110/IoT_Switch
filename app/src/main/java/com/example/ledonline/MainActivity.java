package com.example.ledonline;

import android.os.Bundle;
import android.widget.CompoundButton;
import android.widget.Switch;
import android.widget.TextView;
import androidx.annotation.NonNull;
import androidx.appcompat.app.AppCompatActivity;

import com.google.firebase.database.DataSnapshot;
import com.google.firebase.database.DatabaseError;
import com.google.firebase.database.DatabaseReference;
import com.google.firebase.database.FirebaseDatabase;
import com.google.firebase.database.ValueEventListener;

public class MainActivity extends AppCompatActivity {

    private Switch switchLED;
    private TextView statusText;

    private DatabaseReference ledRef;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);

        switchLED = findViewById(R.id.switchLED);
        statusText = findViewById(R.id.statusText);

        // Referensi ke node /led_status di Firebase Realtime Database
        ledRef = FirebaseDatabase.getInstance().getReference("led_status");

        // Ambil status LED dari Firebase saat aplikasi mulai
        ledRef.addValueEventListener(new ValueEventListener() {
            @Override
            public void onDataChange(@NonNull DataSnapshot snapshot) {
                String status = snapshot.getValue(String.class);
                if (status != null && (status.equalsIgnoreCase("ON") || status.equalsIgnoreCase("true"))) {
                    switchLED.setChecked(true);
                    statusText.setText("Status LED: ON");
                } else {
                    switchLED.setChecked(false);
                    statusText.setText("Status LED: OFF");
                }
            }

            @Override
            public void onCancelled(@NonNull DatabaseError error) {
                statusText.setText("Gagal membaca data Firebase");
            }
        });

        // Ketika Switch digeser, update status ke Firebase
        switchLED.setOnCheckedChangeListener(new CompoundButton.OnCheckedChangeListener() {
            @Override
            public void onCheckedChanged(CompoundButton buttonView, boolean isChecked) {
                if (isChecked) {
                    ledRef.setValue("ON");
                    statusText.setText("Status LED: ON");
                } else {
                    ledRef.setValue("OFF");
                    statusText.setText("Status LED: OFF");
                }
            }
        });
    }
}
