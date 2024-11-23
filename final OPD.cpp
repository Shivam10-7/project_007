#include <iostream>
#include <string>
using namespace std;

class Patient {
public:
    string name, date, gender, issue, symptoms, loc1;
    string pno, mail, non_c_disease, time;
    int gen_ch, insure, non_d, check_non_d, choice, doc_choice;

    /*Constructor to initialize member variables
    Patient() : gen_ch(0), insure(0), non_d(0), check_non_d(0), choice(0), doc_choice(0) {
        name = date = gender = issue = symptoms = loc1 = pno = mail = non_c_disease = time = "";
    }*/

    void inputDetails() {
        cout << "WELCOME TO THE CONSULTANCY BOOKING PORTAL!!" << endl << endl;
        cout << "Name: ";
        getline(cin, name);
        cout << endl << "----- ENTER YOUR DOB ----- " << endl << "Date (DD/MM/YYYY): ";
        getline(cin, date);
        cout << endl << "Gender: " << endl << "1. Male\n2. Female" << endl << "Your choice: ";
        cin >> gen_ch;
        cin.ignore(); // To consume the newline character
        if (gen_ch == 1)
            gender = "Male";
        else if (gen_ch == 2)
            gender = "Female";
        else
            cout << "Wrong choice" << endl;

        cout << endl << "Phone Number: ";
        cin >> pno;
        cin.ignore();
        cout << endl << "Email Address: ";
        getline(cin, mail);

        cout << endl << "Do you have any Health Insurance? " << endl << "1. Yes\n2. No" << endl << "Your choice: ";
        cin >> insure;
        cin.ignore();
        cout << endl << "Issues Currently Facing (Precise): ";
        getline(cin, issue);

        cout << endl << "Do You Have Any Non-Communicable Diseases?" << endl << "1. Yes\n2. No" << endl << "Your choice: ";
        cin >> check_non_d;
        cin.ignore();
        if (check_non_d == 1) {
            cout << endl << "Which one of the following diseases do you have?" << endl;
            cout << "1. Heart Disease\n2. Diabetes\n3. Chronic Respiratory Diseases\n4. Cancer\n";
            cout << "5. Stroke\n6. Kidney Disease\n7. Obesity\n8. Hypertension" << endl;
            cout << "Numeric Value: ";
            cin >> non_d;
            cin.ignore();
        }

        cout << endl << "How many Symptoms among these you have?" << endl;
        cout << "1. Fever\n2. Cough\n3. Fatigue\n4. Shortness of breath\n5. Headache\n";
        cout << "6. Body aches\n7. Sore throat\n8. Nausea\n9. Loss of appetite" << endl;
        cout << "Example: fever, cough, and body aches\n-->";
        getline(cin, symptoms);
        cout << endl << "Enter your preferred location:" << endl;
        cout << "1. Nagpur\n2. Kamptee\nYour choice: ";
        getline(cin, loc1);
    }

    void chooseLocation() {
        cout << endl;
        if (loc1 == "Nagpur" || loc1 == "nagpur" || loc1 == "1") {
            cout << "Our hospitals in Nagpur:" << endl;
            cout << "1. Appolo Hospital Gaddigodam\n2. Alexis Hospital Shankar Nagar\n";
            cout << "3. Lata Mangeshkar Hospital Sitabuldi\nYour choice: ";
            cin >> choice;
            if (choice == 1)
                loc1 = "Appolo Hospital Gaddigodam";
            else if (choice == 2)
                loc1 = "Alexis Hospital Shankar Nagar";
            else if (choice == 3)
                loc1 = "Lata Mangeshkar Hospital Sitabuldi";
            else
                cout << "Invalid choice, defaulting to Appolo Hospital Gaddigodam" << endl;
        } else if (loc1 == "Kamptee" || loc1 == "kamptee" || loc1 == "2") {
            cout << "Our hospitals in Kamptee:" << endl;
            cout << "1. Asha Hospital Kamptee (Cant.)\n2. Choudhary Hospital Jaistambh Chowk\n";
            cout << "3. JN Hospital Kanhan\nYour choice: ";
            cin >> choice;
            if (choice == 1)
                loc1 = "Asha Hospital Kamptee (Cant.)";
            else if (choice == 2)
                loc1 = "Choudhary Hospital Jaistambh Chowk";
            else if (choice == 3)
                loc1 = "JN Hospital Kanhan";
            else
                cout << "Invalid choice, defaulting to Asha Hospital Kamptee (Cant.)" << endl;
        }
    }

    void displayDetails() {
        cout << endl << "--- Consultation Details ---" << endl << endl;
        cout << "Name: " << name << endl;
        cout << "Date of Birth: " << date << endl;
        cout << "Gender: " << gender << endl;
        cout << "Phone Number: " << pno << endl;
        cout << "Email Address: " << mail << endl;
        cout << "Insurance: " << (insure == 1 ? "Yes" : "No") << endl;
        cout << "Issues Currently Facing: " << issue << endl;
        cout<<"Hospital allocated: "<<loc1<<endl;
        cout<<"Time slot: "<<time<<endl;

        if (check_non_d == 1) {
            switch (non_d) {
                case 1: non_c_disease = "Heart Disease"; break;
                case 2: non_c_disease = "Diabetes"; break;
                case 3: non_c_disease = "Chronic Respiratory Diseases"; break;
                case 4: non_c_disease = "Cancer"; break;
                case 5: non_c_disease = "Stroke"; break;
                case 6: non_c_disease = "Kidney Disease"; break;
                case 7: non_c_disease = "Obesity"; break;
                case 8: non_c_disease = "Hypertension"; break;
                default: non_c_disease = "Unknown"; break;
            }
        } else {
            non_c_disease = "None";
        }

        cout << "Non-communicable Disease: " << non_c_disease << endl;
        cout<<"---------------"<<endl;
    }
};

class Doctor : public Patient {
public:
    void doctorSelect() {
        cout << "Which specialist do you want to consult?" << endl;
        cout << "1. General Physicians (Overall Health Check-ups)\n";
        cout << "2. Cardiologists (Heart and Blood Vessels)\n";
        cout << "3. Dermatologists (Skin, Hair, and Nails)\n";
        cout << "4. Orthopedic Surgeons (Bones and Joints)\n";
        cout << "5. Pediatricians (Children Health)" << endl;
        cout << "Your choice: ";
        cin >> doc_choice;
    }
   friend void no_of_patient(Doctor &);

};
    void no_of_patient(Doctor *p)
        {int gp_count=0,c_count=0,d_count=0,os_count=0,p_count=0;static int exit=0;
            for(int i=0;i<10;i++)
           { switch(p->doc_choice)
                    {
                        case 1:gp_count++; break;
                        case 2:c_count++;break;
                        case 3:d_count++;break;
                        case 4:os_count++;break;
                        case 5:p_count++;break;
                                default:{cout<<"somthing went wrong"<<endl<<endl;    exit=1;}
                    }
        if(exit==1)
        {
            break;
        }
         p++;  }
         p=p-10;
        cout<<"Number of patients are :"<<endl<<endl;
        cout<<"General Physicians : "<<gp_count<<endl<<"Cardiologists : "<<c_count<<endl
        <<"Dermatologists : "<<d_count<<endl<<"Orthopedic Surgeons : "<<os_count<<endl<<"Pediatricians : "<<p_count<<endl<<endl;
        }


void times(string &time, const string &location) {
    cout << "Available time slots at " << location << ":" << endl;
    cout << "1. 9:30\n2. 10:45\n3. 11:30\n4. 12:30\n5. 1:45\n6. 2:30" << endl;
    cout << "Your choice: ";
    int a;
    cin >> a;
    switch (a) {
        case 1: time = "9:30"; break;
        case 2: time = "10:45"; break;
        case 3: time = "11:30"; break;
        case 4: time = "12:30"; break;
        case 5: time = "1:45"; break;
        case 6: time = "2:30"; break;
        default:
            cout << "Invalid choice, defaulting to 9:30" << endl;
            time = "9:30";
            break;
    }
}

int main() {
    Doctor p[10];
    int i = 0;

    while (true) {
        cout << "Who are you?\n1. Doctor\n2. Patient\n3. Exit\nYour choice: "<<endl;
        int doc_or_pat;
        cin>>doc_or_pat;

        if (doc_or_pat == 1) {
            while (true) {
                cout << "1. View number of Patients\n2. View Doctors\n3. Exit\nYour choice: ";
                int a;
                cin >> a;
                if (a == 1) {
                    no_of_patient(&p[0]);
                } else if (a == 2) {
                    cout << "Feature not implemented yet." << endl;
                } else {
                    break;
                }
            }
        } else if (doc_or_pat == 2) {
            cin.ignore();
            p[i].inputDetails();
            p[i].chooseLocation();
            times(p[i].time, p[i].loc1);
            cout << "The time slot you have chosen is: " << p[i].time << endl;
            p[i].doctorSelect();
            p[i].displayDetails();
            i++;
            cout<<endl;
        } else if (doc_or_pat == 3) {
            break;
        } else {
            cout << "Invalid input. Try again." << endl;
        }
    }

    return 0;
}
