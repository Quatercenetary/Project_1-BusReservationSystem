#include <iostream>
#include <string.h>
#include <cstdlib>

using namespace std;

static int count = 0;


class BusRes{
    public:
        char busNo[5], driverN[10], arriveT[5], departT[5], from[10], to[10], seatNo[18][4][10];
    public:
        void empty();
        void create();
        void allotSeat();
        void position(int x);
        void show();
        void onDuty();
        
}bus[10];

void makeLine(char ch){
    for(int i = 50; i>0; i--) cout<<ch;
}


void BusRes::create(){
    cout<<"Enter Bus Nunmber: ";
    cin>>bus[count].busNo;
    cout<<"\nEnter Driver's Name: ";
    cin>>bus[count].driverN;
    cout<<"\nEnter Departure Time: ";
    cin>>bus[count].departT;
    cout<<"\nEnter Arrival Time: ";
    cin>>bus[count].arriveT;
    cout<<"\nDepart from: ";
    cin>>bus[count].from;
    cout<<"\nArrive at: ";
    cin>>bus[count].to;
    cout<<"\nBus No. "<<bus[count].busNo<<" is assigned for duty.\n";
    bus[count].empty();
    count++;
    
}

void BusRes::allotSeat(){
    int seat;
    char BNo[5];
    int flag = 1;
    do{
        flag = 1;
        cout<<"Enter Bus number: ";
        cin>>BNo;
        int i;
        for(i = 0; i<count; i++){
            if(strcmp(bus[i].busNo, BNo) == 0) break;
        }
        while(i<count+1){
            cout<<"\nEnter Seat Number: ";
            cin>>seat;
            if(seat > 72) cout<<"\nThere are 72 seats in the bus.";
            else{
                if(strcmp(bus[i].seatNo[seat/4][(seat%4)-1],"Empty") == 0){
                    cout<<"\nEnter Passenger Name: ";
                    cin>>bus[i].seatNo[seat/4][(seat%4)-1];
                    break;
                }
                else cout<<"This seat is already reserved.\n";
            }
        }
        if(i>count){
            cout<<"Bus of this number doesn't exist.\n";
            flag = 0;
        }
    }while(flag = 0);
}

void BusRes::empty(){
    for(int i = 0; i < 18; i++){
        for(int j = 0; j < 4; j++){
            strcpy(bus[count].seatNo[i][j], "Empty");
        }
    }
}

void BusRes::position(int x){
    int no = 0, it = 0;
    for(int i = 0; i < 18; i++){
        cout<<endl;
        for(int j = 0; j < 4; j++){
            no++;
            if(strcmp(bus[x].seatNo[i][j],"Empty") == 0){
                if(no < 10){
                    cout<<"      ";
                    cout<<no<<".";
                }
                if(no >= 10){
                    cout<<"     ";
                    cout<<no<<".";
                }
                cout<<"  ";
                cout<<bus[x].seatNo[i][j];
                it++;
            }
            else{
                if(no < 10){
                    cout<<"      ";
                    cout<<no<<".";
                }
                if(no >= 10){
                    cout<<"     ";
                    cout<<no<<".";
                }
                cout<<"  ";
                cout<<bus[x].seatNo[i][j];
            }
        }
    }
    cout<<"\n\nThere are "<<it<<" seats empty in Bus No.: "<<bus[x].busNo;
}
 
void BusRes::show(){
    char BNo[5];
    cout<<"Enter Bus Number: ";
    cin>>BNo;
    int t;
    for(t = 0; t < count; t++){
        if(strcmp(bus[t].busNo, BNo) == 0) break;
    }
    while(t<count){
        cout<<endl;
        makeLine('-');
        cout<<endl<<"\t\tBUS SEAT MAP\n";
        makeLine('-');
        cout<<"\nBus No.: "<<bus[t].busNo<<endl<<"\n\nDriver: "<<bus[t].driverN<<"\tDeparture Time: "<<bus[t].departT<<"\tArrival Time: "<<bus[t].arriveT<<endl<<"\n\t\tFrom: "<<bus[t].from<<"\t\tTo: "<<bus[t].to<<endl;
        makeLine('-');
        bus[0].position(t);
        int it;
        for(int i = 0; i < 18; i++){
            for(int j = 0; j < 4; j++){
                it++;
                if(strcmp(bus[t].seatNo[i][j], "Empty") != 0) cout<<"\nSeat No. "<<it<<" is reserved for "<<bus[t].seatNo[i][j]<<".";
            }
        }
        break;
    }
    if(t > count) cout<<"Bus with this number doesn't exist.\n";
}

void BusRes::onDuty(){
    cout<<endl;
    makeLine('-');
    cout<<endl<<"\t\tBUSES ON DUTY\n";
    for(int i = 0; i < count; i++){
        makeLine('-');
        cout<<"\nBus No. "<<bus[i].busNo<<"\n\nDriver: "<<bus[i].driverN<<"\tDeparture Time: "<<bus[i].departT<<"\tArrival Time: "<<bus[i].arriveT<<endl<<"\n\t\tFrom: "<<bus[i].from<<"\t\tTo: "<<bus[i].to<<endl;
        makeLine('-');
        cout<<endl;
    }
}

int main(){
    int choice;
    while(1){
    cout<<endl;
    system("pause");
    system("cls");
        cout<<"\n\n\n\n\n";
        cout<<"\t\t\t1. Assign Bus\n\t\t\t2. Reservation\n\t\t\t3. Show Seat Map\n\t\t\t4. Buses on duty\n\t\t\t5. Exit";
        cout<<"\n\n\t\t\tEnter your choice: ";
        cin>>choice;
        switch(choice){
            case 1: bus[count].create();
            break;

            case 2: bus[count].allotSeat();
            break;

            case 3: bus[0].show();
            break;

            case 4: bus[0].onDuty();
            break;

            case 5: exit(0);
        }
    }

    return 0;
}
