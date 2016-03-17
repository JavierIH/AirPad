package bq.alvaroferran.airpad2;

import android.os.Bundle;
import android.support.v7.app.AppCompatActivity;
import android.view.MotionEvent;
import android.view.View;
import android.view.WindowManager;
import android.widget.ImageButton;

import java.io.IOException;
import java.io.PrintWriter;
import java.net.InetAddress;
import java.net.Socket;
import java.net.UnknownHostException;

public class MainActivity extends AppCompatActivity {

    String IP="192.168.4.1";
    int PORT= 80;
    Socket mysocket;
    PrintWriter out;

    private ImageButton Up, Down,Left, Right,Stop, Heart,Flame, Skull, Plus, Punch,Mask;




    /********ON CREATE**************************************************************************************/

    @Override
    public void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        new Thread(new ClientThread()).start();
        setContentView(R.layout.activity_main);
        getWindow().addFlags(WindowManager.LayoutParams.FLAG_KEEP_SCREEN_ON); //Keep screen on while using the app so webview doesn't stop

    }




    /********ON RESUME**************************************************************************************/


/*try: public void onStart(){*/ //or not-> after quitting it passes through resume again
    @Override
    public void onResume() {
        super.onResume();
        procesamiento();
        super.onResume();
    }


    /********ON PAUSE***************************************************************************************/

    @Override
    public void onPause() {
        super.onPause();

    }

    /********ON STOP****************************************************************************************/

    @Override
    public void onStop() {
        super.onStop();
        try {
            out.write("quit");
            out.flush();
            mysocket.close();
        } catch (IOException e1) {
            e1.printStackTrace();
        }
    }

    /********ON ACTIVITY RESULT*****************************************************************************/
    /*
    @Override
    public void onActivityResult(int requestCode, int resultCode, Intent data){
        if(data!=null){
            String dato=data.getStringExtra("Test");    //Get string from SetUrl.java

        }
    }*/





    /********WIDGET MANAGEMENT******************************************************************************/

    private void procesamiento(){


        Up=(ImageButton) findViewById(R.id.btnUp);
        Down=(ImageButton) findViewById(R.id.btnDown);
        Left=(ImageButton) findViewById(R.id.btnLeft);
        Right=(ImageButton) findViewById(R.id.btnRight);
        Stop=(ImageButton)findViewById(R.id.btnStop);
        Heart=(ImageButton) findViewById(R.id.btnHeart);
        Flame=(ImageButton) findViewById(R.id.btnFlame);
        Skull=(ImageButton) findViewById(R.id.btnSkull);
        Plus=(ImageButton) findViewById(R.id.btnPlus);
        Punch=(ImageButton) findViewById(R.id.btnPunch);
        Mask=(ImageButton) findViewById(R.id.btnMask);


        /*
        Up.setOnClickListener(new View.OnClickListener()
        {
            public void onClick(View v)
            {
                ReadValuesAndSend(1);
            }
        });

        Down.setOnClickListener(new View.OnClickListener() {
            public void onClick(View v) {
                ReadValuesAndSend(2);
            }
        });

        Left.setOnClickListener(new View.OnClickListener()
        {
            public void onClick(View v)
            {
                ReadValuesAndSend(3);
            }
        });

        Right.setOnClickListener(new View.OnClickListener()
        {
            public void onClick(View v)
            {
                ReadValuesAndSend(4);
            }
        });
        */
        Stop.setOnClickListener(new View.OnClickListener()
        {
            public void onClick(View v) { ReadValuesAndSend(5);
            }
        });

        Heart.setOnClickListener(new View.OnClickListener()
        {
            public void onClick(View v)
            {
                ReadValuesAndSend(6);
            }
        });

        Flame.setOnClickListener(new View.OnClickListener()
        {
            public void onClick(View v)
            {
                ReadValuesAndSend(7);
            }
        });

        Skull.setOnClickListener(new View.OnClickListener() {
            public void onClick(View v) {
                ReadValuesAndSend(8);
            }
        });

        Plus.setOnClickListener(new View.OnClickListener()
        {
            public void onClick(View v)
            {
                ReadValuesAndSend(9);
            }
        });

        Punch.setOnClickListener(new View.OnClickListener()
        {
            public void onClick(View v) { ReadValuesAndSend(10);
            }
        });

        Mask.setOnClickListener(new View.OnClickListener()
        {
            public void onClick(View v) { ReadValuesAndSend(11);
            }
        });



        Up.setOnTouchListener(new View.OnTouchListener() {
            @Override
            public boolean onTouch(View v, MotionEvent event) {
                if (event.getAction() == MotionEvent.ACTION_DOWN)
                    ReadValuesAndSend(1);
                else if (event.getAction() == MotionEvent.ACTION_UP)
                    ReadValuesAndSend(5);
                return false;
            }
        });

        Down.setOnTouchListener(new View.OnTouchListener() {
            @Override
            public boolean onTouch(View v, MotionEvent event) {
                if (event.getAction() == MotionEvent.ACTION_DOWN)
                    ReadValuesAndSend(2);
                else if (event.getAction() == MotionEvent.ACTION_UP)
                    ReadValuesAndSend(5);
                return false;
            }
        });

        Left.setOnTouchListener(new View.OnTouchListener() {
            @Override
            public boolean onTouch(View v, MotionEvent event) {
                if (event.getAction() == MotionEvent.ACTION_DOWN)
                    ReadValuesAndSend(3);
                else if (event.getAction() == MotionEvent.ACTION_UP)
                    ReadValuesAndSend(5);
                return false;
            }
        });

        Right.setOnTouchListener(new View.OnTouchListener() {
            @Override
            public boolean onTouch(View v, MotionEvent event) {
                if (event.getAction() == MotionEvent.ACTION_DOWN)
                    ReadValuesAndSend(4);
                else if (event.getAction() == MotionEvent.ACTION_UP)
                    ReadValuesAndSend(5);
                return false;
            }
        });

    }

    /********READ VALUES OF WIDGETS*************************************************************************/

    public void ReadValuesAndSend(int value){
        String send=Integer.toString(value)+"+";
        out.write(send);
        out.flush();
    }



    /********ERROR EXIT*************************************************************************************/

   /* private void errorExit(String title, String message){
        Toast.makeText(getBaseContext(), title + " - " + message, Toast.LENGTH_LONG).show();
        finish();
    }*/

    /********SOCKET CLIENT THREAD***************************************************************************/

    class ClientThread implements Runnable {

        @Override
        public void run() {
            try {
                InetAddress serverAddr = InetAddress.getByName(IP);
                mysocket = new Socket(serverAddr, PORT);

                out = new PrintWriter(mysocket.getOutputStream(),true);

            } catch (UnknownHostException e1) {
                e1.printStackTrace();
                //Toast.makeText(getBaseContext(), "error socket 1", Toast.LENGTH_LONG).show();
            } catch (IOException e1) {
                e1.printStackTrace();
                //Toast.makeText(getBaseContext(), "error socket 2", Toast.LENGTH_LONG).show();
            }
        }

    }




}