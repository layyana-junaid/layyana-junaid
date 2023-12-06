#include <stdio.h>
#include <math.h>
#include <string.h>


     //Making a function to print the table for headache identification
     #define Row 6
     #define Col 6

      char HeadacheTable[Row][Col][200] = {
         {"1. A tight band or vice around the head \n",
          "2. Quick jabs or jolts of severe pain around one of the eyes or at the temple"},
         {"3. Pounding or pulsing pain usually in the forehead, the side of the head, or around the eyes \n",
          "4. A dull or throbbing pain in the temples or forehead and throughout the nose and cheekbone areas.\n"
             "5. Other"}
         };

        void print_HeadacheTable(char HeadacheTable[][Col][200], int rowa, int cola) {
        int m, n;

             for(m = 0; m < rowa; m++) {
                 for(n = 0; n < cola; n++) {
                     printf("%s\t", HeadacheTable[m][n]);
                    } //closing first for
                     printf("\n");
                } //closing second for
         }//function for headache table is completed




     //Making a function to print the table for cough identification
     #define Rows 3
     #define Cols 3

      char CoughTable[Rows][Cols][20] = {
         {"1. Dry Cough", "2. Paraoxysmal Cough",},
         {"3. Wet Cough ", "4. Other"}
         };

           void print_CoughTable(char CoughTable[][Cols][20], int row, int col) {
            int a, b;

             for(a = 0; a < row; a++) {
                 for(b = 0; b < col; b++) {
                     printf("%s\t", CoughTable[a][b]);
                    } //closing first for
                     printf("\n");
                } //closing second for
         }//function for cough table is completed




     //Making a function for table printing
     #define ROWS 2
     #define COLS 2

     char table[ROWS][COLS][20] = {
           {"1. Fever", "2. Cough"},
           {"3. Headache", "4. Blood pressure"}
           };

           void print_table(char table[][COLS][20], int rows, int cols) {
         int i, j;

              for(i = 0; i < rows; i++) {
                 for(j = 0; j < cols; j++) {
                    printf("%s\t", table[i][j]);
                         }//closing first for
                      printf("\n");
                  }//closing second for
              }//function for making the table is completed




         //Making a function for fever
          void fever_function(float *temperature, float *NewTemp, char choice){
                     printf("Do you want to enter the temperature in Fahrenheit or Celsius?");
                    printf("For Fahrenheit enter f and for Celsius enter c.");
                      scanf(" %c", &choice);
                      printf("What is the body temperature: ");
                      scanf("%f", &temperature);
                      printf("This is a herbal tea which is very beneficial in order to cure fever / sore throat / flu so I would recommend that you try it.");
                      printf("\n");
                      printf("Ingredients:");
                      printf("\n");
                      printf("250ml of water");
                      printf("\n");
                      printf("1 inch piece of ginger");
                      printf("\n");
                      printf("1 tablespoon honey");
                      printf("\n");
                      printf("4 cloves");
                      printf("\n");
                      printf("4 whole black pepper seeds");
                      printf("\n");
                      printf("2 green cardamoms");
                      printf("\n");
                      printf("Procedure:");
                      printf("\n");
                      printf("Put the water in a pot and turn in the flame. Now, add all of the ingredients and allow it to boil for 2-3 minutes on high flame. Then, turn down the heat to a medium to low flame and alow the tea to simmer for 6-7 minutes. Now, turn off the flame. Strain the tea and drink it.");
                      printf("\n");
                      if (choice == 'c') {
                       *NewTemp = 32 + (*temperature * 9/5);
                       if (*NewTemp < 90) {
                           printf("The reading you have taken is incorrect so please try again");
                      }
                      else if (*NewTemp > 99 && *NewTemp < 101) {
                           printf("You have a fever!");
                           printf("\n");
                           printf("If there are no other symptoms like shivering, sore throat, flu, you should do the following:");
                           printf("\n");
                           printf("Take a paracetamol tablet, namely Panadol or Calpol of 300mg");
                           printf("\n");
                           printf("Use a cold compress");
                           printf("\n");
                           printf("Drink plenty of water");
                           printf("\n");
                           printf("If the fever doesn't subside in 3-4 days, consult a doctor");
                      }//first else if
                      else if (*NewTemp > 101 && *NewTemp < 103) {
                           printf("You have a very high fever!");
                           printf("\n");
                           printf("You should do the following:");
                           printf("\n");
                           printf("Sit in a bathtub filled with water of 25 degrees celsius for about 20-30 minutes so that the fever goes down");
                           printf("\n");
                           printf("Recheck the temperature and if the it has gone down, by even 1 degree fahrenheit, take a Panadol or Calpol of 300 mg");
                           printf("\n");
                           printf("Drink plenty of water");
                           printf("\n");
                           printf("If the fever doesn't subside in 3-4 days, consult a doctor");
                      }//second else if
                      else if (*NewTemp > 103 && *NewTemp < 105) {
                           printf("You have extremely high fever!");
                           printf("\n");
                           printf("You should do the following:");
                           printf("\n");
                           printf("If you have such a high fever it means you have severe infection which can only be detected by getting some bloodtests done.");
                           printf("These are the blood tests that I recommend should be done:");
                           printf("\n");
                           printf("Blood CP and Blood C/S");
                           printf("\n");
                           printf("After getting the report, immediately go to a doctor as I am not capable enough to assist you further");
                           printf("\n");
                           printf("But while you wait for the reports you can do this:");
                           printf("\n");
                           printf("Sit in a bathtub filled with water of 25 degrees celsius for about 20-30 minutes so that the fever goes down");
                           printf("\n");
                           printf("Recheck the temperature and if the it has gone down, by even 1 degree fahrenheit, take a Panadol or Calpol of 300 mg");
                           printf("\n");
                           printf("Drink plenty of water");
                           printf("\n");
                      }//second else if
                      else if (*NewTemp > 105) {
                           printf("Immwdiately take the patient to the hospital");
                      }//third else if
                       }//end choice if
                      else if (choice == 'f') {
                       if (*NewTemp < 90) {
                           printf("The reading you have taken is incorrect so please try again");
                      }
                      else if (*NewTemp > 99 && *NewTemp < 101) {
                           printf("You have a fever!");
                           printf("\n");
                           printf("If there are no other symptoms like shivering, sore throat, flu, you should do the following:");
                           printf("\n");
                           printf("Take a paracetamol tablet, namely Panadol or Calpol of 300mg");
                           printf("\n");
                           printf("Use a cold compress");
                           printf("\n");
                           printf("Drink plenty of water");
                           printf("\n");
                           printf("If the fever doesn't subside in 3-4 days, consult a doctor");
                      }//first else if
                      else if (*NewTemp > 101 && *NewTemp < 103) {
                           printf("You have a very high fever!");
                           printf("\n");
                           printf("You should do the following:");
                           printf("\n");
                           printf("Sit in a bathtub filled with water of 25 degrees celsius for about 20-30 minutes so that the fever goes down");
                           printf("\n");
                           printf("Recheck the temperature and if the it has gone down, by even 1 degree fahrenheit, take a Panadol or Calpol of 300 mg");
                           printf("\n");
                           printf("Drink plenty of water");
                           printf("\n");
                           printf("If the fever doesn't subside in 3-4 days, consult a doctor");
                      }//second else if
                      else if (*NewTemp > 103 && *NewTemp < 105) {
                           printf("You have extremely high fever!");
                           printf("\n");
                           printf("You should do the following:");
                           printf("\n");
                           printf("If you have such a high fever it means you have severe infection which can only be detected by getting some bloodtests done.");
                           printf("These are the blood tests that I recommend should be done:");
                           printf("\n");
                           printf("Blood CP and Blood C/S");
                           printf("\n");
                           printf("After getting the report, immediately go to a doctor as I am not capable enough to assist you further");
                           printf("\n");
                           printf("But while you wait for the reports you can do this:");
                           printf("\n");
                           printf("Sit in a bathtub filled with water of 25 degrees celsius for about 20-30 minutes so that the fever goes down");
                           printf("\n");
                           printf("Recheck the temperature and if the it has gone down, by even 1 degree fahrenheit, take a Panadol or Calpol of 300 mg");
                           printf("\n");
                           printf("Drink plenty of water");
                           printf("\n");
                      }//second else if
                      else if (*NewTemp > 105) {
                           printf("Immediately take the patient to the hospital");
                      }//third else if
                    }//end else if
            //Our fever function has ended here





         //Making a function for cough
          void cough(int CoughOption ){
          printf("What kind of cough do you have?");
          printf("\n");
                      printf("A dry or unproductive cough is caused by inflammation in your throat and upper airways, which creates a tickly sensation.");
                      printf("\n");
                      printf("A paroxysmal cough is violent and uncontrolled coughing that is exhausting and painful.");
                      printf("\n");
                      printf("A productive or wet cough is when you have a cough that produces mucus or phlegm (sputum).");
                         
                        // Calling the function
                        print_CoughTable(CoughTable, Rows, Cols);

                      printf("Select the option: ");
                      scanf("%d", &CoughOption);
                       if (CoughOption == 1){
                           printf("You have Dry Cough!");
                           printf("\n");
                           printf("This means that recently you were suffering from flu, which means this is a post-viral cough. However, it can also be caused by an allergy, asthma or chronic acid reflux. Less common dry cough causes include environmental factors like a dry atmosphere, air pollution or a sudden change in temperature.");
                           printf("\n");
                           printf("If you have a post-viral cough, you should:");
                           printf("\n");
                           printf("You can use this nasal spray: Sinosil Nasal Decongestant (spray) by Herbion Pakistan Pvt Ltd");
                           printf("\n");
                           printf("Disclaimer: Use this product if you are above 12 years of age.");
                           printf("\n");
                           printf("If you are not comfortable in using this nasal spray, you can use these nasal drops: Norsaline-p 0.9% nasal drops");
                           printf("\n");
                           printf("If you want to go for a home remedy, take steam using a kettle or a pot for 5=6 minutes. Make sure that your face is not too close to the spout because the steam can burn you.");
                           printf("\n");
                           printf("If your cough is caused by an allergy (that you are aware of), asthma or chronic acid reflux, you should:");
                           printf("\n");
                           printf("Consult a doctor since I do not have your medical history to prescribe a certain medication for you.");
                           printf("\n");
                           printf("If the cause of your cough is dry atmosphere, air pollution or a sudden change in temperature, you should:");
                           printf("\n");
                           printf("Gargle with plain water up to three times a day to get rid of bacteria in your mouth and throat.");
                           printf("\n");
                           printf("Stay hydrated by drinking plenty of fluids each day.");
                           printf("\n");
                           printf("Try consuming hot drinks with honey and lemon to relieve coughing");
                           printf("\n");
                           printf("Don't try to suppress coughs as this can make them worse.");
                           printf("\n");
                           printf("Use a humidifier.");
                           printf("\n");
                      }//ending first if
                     
                       else if (CoughOption == 2) {
                           printf("You have Paraoxysmal Cough!");
                           printf("\n");
                           printf("This is commonly caused by Bordetella pertussis bacterium. This bacterium infects the respiratory tract (your nose, throat, windpipe, and lungs). This infection is extremely contagious.");
                           printf("\n");
                           printf("These coughing fits usually last 1 to 6 weeks but can last for up to 10 weeks.");
                           printf("\n");
                           printf("Paraoxysmal cough is a major symptom of tuburculosis so it is advised that you immediately get yourself tested.");
                           printf("\n");
                           printf("The tests for identifying tuburculosis germs in the body are TB skin test (TST) and TB blood tests.");
                           printf("\n");
                           printf("If test results come back as positive, immediately distance yourself from other people.");
                           printf("\n");
                           printf("Then, consult a doctor or go to a hospital and they will guide you on what should be done.");  
                           printf("\n");
                           printf("If the test result is negative, you should do the following:");
                           printf("\n");
                           printf("Keep your home free from irritants that can trigger coughing, such as smoke, dust, and chemical fumes.");
                           printf("\n");
                           printf("Different medications are prescribed for people of different ages.");
                           printf("\n");
                           
                           int age;
                           
                             if (age < 0) {
                                printf("The age you have entered is incorrect. Please enter the correct age.");
                           }//end nested if
                             else if (age > 0 && age < 5){
                                printf("Macrolides erythromycin, clarithromycin, and azithromycin are preferred for the treatment of pertussis in persons 1 month of age and older.");
                           }//end nested else if
                             else if (age > 5 && age < 10){
                                printf("You can give the child this medicine: Robitussin Maximum Strength Honey Cough Plus Chest Congestion DM, Cough Medicine for Cough and Chest Congestion Relief Made with Real Honey for Flavor - 8 Fl Oz x 2");
                                printf("\n");
                                printf("This medicine should be given to the kid twice a day, that is after breakfast and before going to bed at night.");
                                printf("\n");
                                printf("If that is not available, you can also use: Robitussin Nighttime Cough Long-Acting DM, Cough Medicine for Kids, Fruit Punch Flavor - 4 Fl Oz Bottle");
                                printf("\n");
                                printf("Give one tablespoon to your child before going to bed at night.");
                                printf("\n");
                                printf("Note: If you are unsure about the dosage, read the instructions written on the box.");
                           }//end nested else if
                             else if (age > 10 && age < 100){
                                printf("You can take this medicine: ACTIFED-DM by the company GLAXOSMITHKLINE");
                                printf("\n");
                                printf("Disclaimer: Dextromethorphan is a commonly abused drug so make sure you use it wisely.");
                                printf("\n");
                                printf("If you want to use an antibiotic, you can use: Augmentin (amoxicillin), Novidat (ciprofloxacin), Amoxil (metronidazole)");
                                printf("\n");
                                printf("Make sure you carefully read the dosage instructions given on each box");
                                printf("\n");
                           }//end nested else if
                             else{
                                printf("Please consult a doctor as this is a sensitive case.");
                           }//ending nested else
                  }//ending CoughOption else if

                      else if (CoughOption == 3) {
                           printf("You have a Wet Cough!");
                           printf("\n");
                           printf("A range of conditions can cause a wet cough, including respiratory infections, chronic lung conditions, and CHF.");
                           printf("\n");
                           printf("If you are having wet cough as well as other diseases like influenza and fever, you should do the following:");
                           printf("\n");
                           printf("Drink plenty of fluids, which can help thin the mucus and make it easier to cough up;");
                           printf("\n");
                           printf("Take a hot, steamy shower to help break down the mucus (phlegm) and make it easier to cough up.");
                           printf("\n");
                           printf("Get plenty of rest");
                           printf("\n");
                           printf("Gargle with hot salt water");
                           printf("\n");
                           printf("Take steam using a kettle or a pot for 5-6 minutes. Make sure that your face is not too close to the spout because the steam can burn you.");
                           printf("\n");
                           printf("This is a herbal tea which is very beneficial in order to cure fever / sore throat / flu so I would recommend that you try it.");
                           printf("\n");
                           printf("Ingredients:");
                           printf("\n");
                           printf("250ml of water");
                           printf("\n");
                           printf("1 inch piece of ginger");
                           printf("\n");
                           printf("1 tablespoon honey");
                           printf("\n");
                           printf("4 cloves");
                           printf("\n");
                           printf("4 whole black pepper seeds");
                           printf("\n");
                           printf("2 green cardamoms");
                           printf("\n");
                           printf("Procedure:");
                           printf("\n");
                           printf("Put the water in a pot and turn in the flame. Now, add all of the ingredients and allow it to boil for 2-3 minutes on high flame. Then, turn down the heat to a medium to low flame and alow the tea to simmer for 6-7 minutes. Now, turn off the flame. Strain the tea and drink it.");
                           printf("\n");
                           printf("As for medication, you can take a Panadol, once after breakfast and then again, before going to bed.");
                           printf("\n");
                           printf("If your wet cough is the result of chronic lung conditions:");
                           printf("\n");
                           printf("A chronic cough has many possible underlying causes, including:");
                           printf("\n");
                           printf("Asthma");
                           printf("\n");
                           printf("Chronic obstructive pulmonary disease (COPD)");
                           printf("\n");
                           printf("Gastroesophageal reflux disease (GERD)");
                           printf("\n");
                           printf("Allergies");
                           printf("\n");
                           printf("Cigarette smoking");
                           printf("\n");
                           printf("Postnasal drip");
                           printf("\n");
                           printf("Bronchitis");
                           printf("\n");
                           printf("Because there are so many different conditions that may cause chronic lung disease, you should consult a physician since I am not able to handle such complex diseases.");
                           printf("\n");
                           printf("If your wet cough is the result of CHF, which is also known as congestive heart failure, you need to know what CHF is:");
                           printf("\n");
                           printf("Congestive heart failure (CHF) occurs when the heart has difficulty pumping blood throughout the body. When this ineffective pumping occurs on the left side of the heart, it causes fluid to leak into the air sacs within the lungs. The result is a wet cough, crackles, and wheezing.");
                           printf("\n");
                           printf("This is actually pretty serious and you should immediately go to the nearest hospital.");
                           printf("\n");
                      }//ending else if

                      else if (CoughOption == 4) {
                       //Letting the person input "other" option
                         char other[200];
                         printf("Enter the other type of cough that you are having: ");
                         fgets(other, sizeof(other), stdin);
                         size_t len = strlen(other);
                         printf("I'm sorry but this problem is too complex for me to handle as an AI healthbot.");
                      }//ending else if
                      else {
                           printf("You have entered an incorrect option");
                           printf("\n");
                      }//ending else
                   }//function for cough has ended




          //Making a function for blood pressure
          void BloodPressure(int bpup, int bpdown, char height){
                      printf("If your height is between 0ft - 5ft, enter s.");
                      printf("\n");
                      printf("If your height is between 5ft - 8ft, enter t.");
                      printf("\n");
                      scanf(" %c", &height);
                      printf("What is the systolic blood pressure (upper)");
                      scanf(" %d", &bpup);
                      printf("\n");
                      printf("What is the diastolic blood pressure (lower)");
                      scanf(" %d", &bpdown);

              if (height == 's') {
                 if (bpup <= 115 && bpup > 80 && bpdown >= 40 && bpdown <= 75) {
                     printf("Your blood pressure is extremely low!");
                           printf("\n");
                           printf("If you are feeling drowsy, do the following:");
                           printf("\n");
                           printf("Drink 2 glasses of ORS water. To prepare the ORS water, read the instructions written on the back of the packet. ORS powder will be available from any medical store near your house.");
                           printf("\n");
                           printf("Eat a boiled egg");
                           printf("\n");
                           printf("Drink a mug of coffee");
                           printf("\n");
                           printf("Get plenty of rest");
                           printf("\n");
                     }//ending first if


                 else if (bpup <= 130 && bpup >= 116 && bpdown >= 76 && bpdown <= 90 ) {
                         printf("Congratulations! Your blood pressure is normal!");
                         printf("\n");
                    }//ending first else if


                 else if (bpup <= 180 && bpup > 131 && bpdown > 90 && bpdown < 110) {
                           printf("\n");
                           printf("Your blood pressure is extremely high!");
                           printf("\n");
                           printf("You should immediately do the following:");
                           printf("\n");
                           printf("Drink some water");
                           printf("\n");
                           printf("Eat some dark chocolate");
                           printf("\n");
                           printf("Take a cold shower");
                           printf("\n");
                           printf("Take a deep breath and try to relax");
                           printf("\n");
                           printf("Add 1 tablespoon of honey to cold water and drink that");
                           printf("\n");
                           printf("It is recommended that you monitor your blood pressure for a week and in case you find it fluctuating a lot, visit a general physician so that they could guide you further.");
                           printf("\n");
                     }//ending second else if


                 else {
                      printf("Please make sure you have entered the correct values, since the reading you have entered is not possible.");
                      printf("\n");
                     }//ending else
              }//ending first height if

              if (height == 't') {                
                  if (bpup <= 110 && bpup > 75 && bpdown >= 35 && bpdown <= 70) {
                     printf("Your blood pressure is extremely low!");
                           printf("\n");
                           printf("If you are feeling drowsy, do the following:");
                           printf("\n");
                           printf("Drink 2 glasses of ORS water. To prepare the ORS water, read the instructions written on the back of the packet. ORS powder will be available from any medical store near your house.");
                           printf("\n");
                           printf("Eat a boiled egg");
                           printf("\n");
                           printf("Drink a mug of coffee");
                           printf("\n");
                           printf("Get plenty of rest");
                           printf("\n");
                     }//ending first if


                 else if (bpup <= 125 && bpup >= 111 && bpdown >= 71 && bpdown <= 85 ) {
                         printf("Congratulations! Your blood pressure is normal!");
                         printf("\n");
                     }//ending first else if


                 else if(bpup <= 175 && bpup > 125 && bpdown > 85 && bpdown < 105) {
                           printf("\n");
                           printf("Your blood pressure is extremely high!");
                           printf("\n");
                           printf("You should immediately do the following:");
                           printf("\n");
                           printf("Drink some water");
                           printf("\n");
                           printf("Eat some dark chocolate");
                           printf("\n");
                           printf("Take a cold shower");
                           printf("\n");
                           printf("Take a deep breath and try to relax");
                           printf("\n");
                           printf("Add 1 tablespoon of honey to cold water and drink that");
                           printf("\n");
                           printf("It is recommended that you monitor your blood pressure for a week and in case you find it fluctuating a lot, visit a general physician so that they could guide you further.");
                           printf("\n");
                     }//ending second else if


                 else {
                      printf("Please make sure you have entered the correct values, since the reading you have entered is not possible.");
                      printf("\n");
                     }//ending else
              }//ending second height if
            }//Our bp function has ended here



         //Making a function for headache
          void Headache(int HeadacheOption ) {
          printf("Which part of your head hurts?");
          printf("\n");
                         
                        // Calling the function
                      print_HeadacheTable(HeadacheTable, Row, Col);

                      printf("Select the option: ");
                      scanf("%d", &HeadacheOption);
                       if (HeadacheOption == 1){
                           printf("You have a tension headache!");
                           printf("\n");
                           printf("To relieve the headache, you should:");
                           printf("\n");
                           printf("Get a head massage");
                           printf("\n");
                           printf("Eat a panadol of 300mg");
                           printf("\n");
                           printf("Take a hot bath or shower");
                           printf("\n");
                           printf("Avoid excess caffeine");
                           printf("\n");
                           printf("Take a nap of 45 - 60 minutes");
                           printf("\n");
                           printf("Apply heat to relieve tense neck and shoulder muscles");
                           printf("\n");
                      }//ending first if
                     
                       else if (HeadacheOption == 2) {
                           printf("You have a cluster headache!");
                           printf("\n");
                           printf("To relieve the cluter headache, you should:");
                           printf("\n");
                           printf("Take in oxygen, which is breathed through a mask.");
                           printf("\n");
                           printf("Subcutaneous sumatriptan and intranasal zolmitriptan are considered effective first-line treatments for episodic and chronic cluster headache.");
                           printf("\n");
                           printf("Use a device to give mild electrical pulses to the back of the neck.");
                           printf("\n");
                           printf("Drink plenty of water");
                           printf("\n");
                           printf("Note: All of these given recommendations should be done under the supervision of a trained healthcare professional.");
                           printf("\n");
                        }//ending first else if

                      else if (HeadacheOption == 3) {
                           printf("You may be suffering from a migraine!");
                           printf("\n");
                           printf("To relieve the migraine, you should:");
                           printf("\n");
                           printf("Ease Pressure on Your scalp or head");
                           printf("\n");
                           printf("Dim the Lights");
                           printf("\n");
                           printf("Take the migraine medicines that have been prescribed by your doctor.");
                           printf("\n");
                           printf("Drink plenty of water");
                           printf("\n");
                           printf("Try Not to Chew");
                           printf("\n");
                           printf("If you have a migraine, place a cold pack on your forehead.");
                           printf("\n");
                           printf("Get a scalp massage so muscles can be relieved of tension and stress, which are common migraine triggers");
                           printf("\n");
                           printf("Sleep, as too little sleep can cause migraine attacks");
                           printf("\n");
                       }//ending else if

                      else if (HeadacheOption == 4) {
                           printf("You may be suffering from a sinus or allergy headache!");
                           printf("\n");
                           printf("To relieve the headache, you should:");
                           printf("\n");
                           printf("Use decongestants such as Sinosil Nasal Decongestant (spray) by Herbion Pakistan Pvt Ltd");
                           printf("\n");
                           printf("Use a warm compress or a heating pad");
                           printf("\n");
                           printf("Take steam using a kettle or a pot for 5-6 minutes. Make sure that your face is not too close to the spout because the steam can burn you.");
                           printf("\n");
                           printf("Drink plenty of water");
                           printf("\n");
                           printf("Use a saline nasal spray");
                           printf("\n");
                           printf("Take a hot shower");
                           printf("\n");
                           printf("Gargle with warm salt");
                           printf("\n");
                           printf("Take plenty of rest");
                           printf("\n");
                       }//ending else if



                      else if (HeadacheOption == 5) {
                       //Letting the person input "other" option
                         char headother[200];
                         printf("Enter the other type of headache that you are having: ");
                         fgets(headother, sizeof(headother), stdin);
                         size_t len = strlen(headother);
                         printf("I'm sorry but this problem is too complex for me to handle as an AI healthbot.");
                      }//ending else if

                      else {
                           printf("You have entered an incorrect option");
                           printf("\n");
                      }//ending else
                   }//function for headache has ended





 
int main(){

           int age;
           int CoughOption, HeadacheOption, bpup, bpdown;
           char height;

           printf("--Hello! Welcome to Healthbot. You are now using an AI tool which will assist you by looking at the problem you're facing, and then it'll give you the solution on what should be done. Please note that that it is not an actual doctor, and it will only ASSIST you. In case of serious medical emergencies, consult a doctor ASAP. Note: Before using any medication prescribed by the healthbot, carefully do your own research regarding the medicine. Thank you!--");
           printf("\n");
        //Taking the name of the person as input
        char person_name[20];
        printf("Enter the name of the person: ");
        fgets(person_name, sizeof(person_name), stdin);

        size_t len = strlen(person_name);
         printf("\n");
        printf("What is your age?");
        scanf("%d", &age);

    print_table(table, ROWS, COLS);
    
          int FinalOption;
          char yn;

    printf("\nEnter the option you want to select: \n");
    scanf("%d", &FinalOption);
     printf("\nAre you sure that you want to select option %d? Press y for yes and n for no: ", FinalOption);
    scanf(" %c", &yn);

     //Using switch
     switch(FinalOption) {
                      case '1' :
                      //Calling the function
                        fever_function(temperature, NewTemp, choice);
                        break;

                      case '2':
                      //Calling the function
                        cough(CoughOption);
                        break;

                      case '3':
                      //Calling the function
                        Headache(HeadacheOption ); 
                        break;

                      case '4':
                      //Calling the function
                        BloodPressure(bpup, bpdown, height);
                        break;
    default:
            printf("Choose the correct option");
            break;
   
} // end switch


}//end main

}//end main


