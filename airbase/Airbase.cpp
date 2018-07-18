#include <string>
#include <vector>
#include <iostream>
using namespace std;

class Passenger
{
 public:
        	Passenger(string pname="",int seat=1,int dest=1,float weight=0):
            passenger_name(pname),passenger_seat(seat),passenger_destination(dest),passenger_weight(weight)
            {}
   	//access gia onoma epivath
	void setPassenger_Name(string passname)
	{passenger_name=passname;}
	string getPassenger_Name()
	{return passenger_name;}
	
	//access gia thesh epivath
	void setPassenger_Seat(int seat)
	{passenger_seat=seat;}
	int getPassenger_Seat()
	{return passenger_seat;}
	
	//access gia proorismo epivath
	void setPassenger_Destination(int destination)
	{passenger_destination=destination;}
	int getPassenger_Destination()
	{return passenger_destination;}
	
	//access gia varos aposkeuwn pelath
	void setPassenger_Weight(float weight)
	{passenger_weight=weight;}
	float getPassenger_Weight()
	{return passenger_weight;}
          
 private:
	string passenger_name;
	int passenger_seat;
	int passenger_destination;
	float passenger_weight;
};

class Plane
{public:
    // friend int pos (vector <Passenger>& v, string& pname);
    
	Plane(string name="",int type=0, string pin="", int location=0,int destination=0,float pweight=0,int mseats=0,int pvip=0,int pcomm=0,int pecon=0):
			plane_name(name),
			plane_type(type),
			pilot_name(pin),
			plane_location(location),
			plane_destination(destination),
			plane_weight(pweight),
			max_seats(mseats),
			max_economy(pecon),
			max_vip(pvip),
			max_commercial(pcomm)
				{}
			
	//access gia plane location
	int getPlane_Location()
	{return plane_location;}
	void setPlane_location(int pl)
	{plane_location=pl;}
	
	//access gia plane destination
	int getPlane_Destination()
	{return plane_destination;}
	void setPlane_destination(int pd)
	{plane_destination=pd;}
	
	//access gia onoma aeroplanou
	string getPlane_Name()
	{return plane_name;}
	void setPlane_Name(string pn)
	{plane_name=pn;}
	
	//access gia tupo aeroplanou
	int getPlane_Type()
	{return plane_type;}
	void setPlane_Type(int pt)
	{plane_type=pt;}
	
	//access gia onoma pilotou
	string getPilot_Name()
	{return pilot_name;}
	void setPilot_Name(string pin)
	{pilot_name=pin;}
	
	//access gia varos aeroplanou
	void setPlane_weight(float weight)
	{plane_weight=plane_weight+weight;}
	float getWeight()
	{return plane_weight;}
	
	//access gia max theseis
	void setMax_seats(int seats)
	{max_seats=seats;}
	float getMax_seats()
	{return max_seats=max_economy+max_commercial+max_vip;}
	
	//access gia max vip 
	void setMax_vip(int vip)
	{max_vip+=vip;}
	float getMax_vip()
	{return max_vip;}
	
	//access gia max commercial
	void setMax_commercial(int commercial)
	{max_commercial+=commercial;}
	float getMax_commercial()
	{return max_commercial;}
	
	//access gia max economy
	void setMax_economy(int economy)
	{max_economy+=economy;}
	float getMax_economy()
	{return max_economy;}
	
//public metavlhtes
 	
	 //seats
	int max_seats;
	int max_economy;
	int max_vip;
	int max_commercial;
	
	//plane details
	int plane_type;
	int plane_location;
	int plane_destination;	
	float plane_weight;
 	string pilot_name;
 	string plane_name;
 	
 	//vector for the passengers
	vector <Passenger> passengers;
};
class Airport
{
int pos2 (vector <Plane>& z, string& planename);
	public:
	
//making the waiting lists for every airport and every destination combo		
		vector<Passenger> WL_ForLondon;
		vector<Passenger> WL_ForParis;
		vector<Passenger> WL_ForAthens;
		//vector to contain the planes 
		vector<Plane> plane;		
};

//Taking the position of an available plane
int pos (vector <Plane>& v)
 { int p=1;
   for (int i = 0; i<v.size();++i)
     if ((v[i].getPlane_Destination() == 2) && (v[i].getMax_seats()!=80)) 
	 {
	 p=i;
	 break;}
	 else if ((v[i].getPlane_Destination() == 3)&&(v[i].getMax_seats()!=80))
	 {p=i;
	 break;}
   return p;}

   //Taking the position of the plane at the destination i need
int pos2 (vector <Plane>& z)
 { int f=-1;
   for (int j = 0; j<z.size();++j)
     if (z[j].getPlane_Destination() == 1) 
	 {f=j;
	 break;
	 }
	 else if  (z[j].getPlane_Destination() == 3)
	 {
	 f=j;
	 break;}
   return f;}

//checking if the name of the plane we create exists
int PlaneNameCheck(vector <Plane>& v, string& pname)
 { int p=-1;
   for (int i = 0; i<v.size();++i)
     if (v[i].getPlane_Name() == pname) p=i;
   return p;}


// counter reset 

void CounterReset(int &a,int &b,int &c)
{a=0;b=0;c=0;
}



int main()
{  //variables for the plane
	string pname;
	string pilotname;
	int plocA=1,plocL=2,plocP=3,pdestA=1,pdestL=2,pdestP=3,pdest,ptype; 

	// variables for choices
	char choice,choice1,choice2,choice3,choice4,choice5,erwthsh;
	
	int PlaneToPick;
 	int PlaneToGet;

	// making the airports 
	Airport airport_athens;
	Airport airport_london;
	Airport airport_paris;

	//passenger variables	
	string name;
    float weight;
    int seat;
    int dest;
    int plane;
	
	//counters;
	int counterA1=0,counterA2=0,counterA3=0,counterL1=0,counterL2=0,counterL3=0,counterP1=0,counterP2=0,counterP3=0;
	int maxCA,maxCL,maxCP;
	
	
	//dummy plane for swaps
	Plane temp;
	
	//freeing up 10 spaces for each airport (the number can be anything)
	airport_athens.plane.reserve(10);
	airport_london.plane.reserve(10);
	airport_paris.plane.reserve(10);
	
//making the initial 3 planes for each airport
airport_athens.plane.push_back(Plane("Boeing",1,"Mhtsaras",plocA,pdestL));
airport_london.plane.push_back(Plane("Ryan Air",1,"Xaralampos",plocL,pdestA));
airport_paris.plane.push_back(Plane("Copter",1,"Emmanouhl",plocP,pdestA));
	
	//max waiting list size set to 100 (the number can be anything)
	airport_athens.WL_ForLondon.reserve(100);
	airport_athens.WL_ForParis.reserve(100);
	airport_london.WL_ForAthens.reserve(100);
	airport_london.WL_ForParis.reserve(100);
	airport_paris.WL_ForAthens.reserve(100);
	airport_paris.WL_ForLondon.reserve(100);

    do
    {system("cls");
    		cout<<"Welcome to AKMI Airlines\n";
			cout<<"Please choose one of our Airports\n";
			cout<<"Press 1 for Athens\n";
			cout<<"Press 2 for London\n";
			cout<<"Press 3 for Paris\n";
			cout<<"Press 0 to Exit\n";
			cin>>choice2;
			switch (choice2)
				{case'1':
					do{
					system("CLS");
					cout<<"You are currently at the Athens airport.\n";
				     cout<<"Press 1 to Show our Current planes:\n";
				     cout<<"Press 2 to Make a new plane:\n";
				     cout<<"Press 3 to Show the passengers waiting at this airport:\n";
				     cout<<"Press 4 to Add a new passenger:\n";
				     cout<<"Press 0 to Exit\n";
				     cout<<"Please give your choice:";
				     cin>>choice;
				     switch (choice)
				    {case '1':system("CLS");
			                	 cout<<"Our Planes at this moment :\n";
			                 	for (int i=0;i<airport_athens.plane.size();++i)
			                    {cout<<"Plane name     Type        Destination        Location        Pilot Name\n";
								cout<<i<<")"<<airport_athens.plane[i].getPlane_Name()<<"          ";
			                    if (airport_athens.plane[i].getPlane_Type()==1)
								cout<<"Regular" <<"       ";
			                    else
			                    cout<<"Charter"<<"       ";
							    if (airport_athens.plane[i].getPlane_Destination()==1)
							    cout<<"Athens"<<"           ";
							    else if (airport_athens.plane[i].getPlane_Destination()==2)
							    cout<<"London"<<"          ";
							    else 
							    cout<<"Paris"<<"           ";
								if (airport_athens.plane[i].getPlane_Location()==1)
							    cout<<"Athens"<<"           ";
							    else if (airport_athens.plane[i].getPlane_Location()==2)
							    cout<<"London"<<"          ";
							    else 
							    cout<<"Paris"<<"           ";
							    cout<<airport_athens.plane[i].getPilot_Name()<<"     \n";
							    system("pause");
			                    }break;
			     	case '2':system("CLS");
			     				cout<<"You have "<<airport_athens.plane.size();
								cout<<"Please give the name of the plane:";
				                cin >> pname;
				                 if ((PlaneNameCheck(airport_paris.plane,pname)<0) && (PlaneNameCheck(airport_london.plane,pname)<0) && (PlaneNameCheck(airport_athens.plane,pname)<0))
				                 {	
								 cout<<"Please give Pilot name";
				                 cin >> pilotname;
				                
								cout<<"Please give the destination of the plane (2.for london/3. for paris)";
								cin>>pdest;
								if (pdest==2)
				              	{ airport_athens.plane.push_back(Plane(pname,1,pilotname,plocA,pdest));}
							  	else if (pdest==3)
				              	  {airport_athens.plane.push_back(Plane(pname,1,pilotname,plocA,pdest));}
				                }
								else
				                {cout<<"Plane name already exists!";}
				                system("Pause");
			                	break;
			
			        case '3':system("CLS");
			        		cout<<"Our Passengers at this moment :\n";
			                if (airport_athens.WL_ForLondon.size()>0)
							{cout<<"Passengers waiting for London :"<<airport_athens.WL_ForLondon.size()<<"\n";
							for (int i=0;i< airport_athens.WL_ForLondon.size();++i)
			                {
							cout<<endl;
							cout<<"Passenger Name :"<<airport_athens.WL_ForLondon[i].getPassenger_Name()<<"|     |";
			                if(airport_athens.WL_ForLondon[i].getPassenger_Seat()==1)
			                cout<<"Seat:VIP "<<"|     |";
			                else if (airport_athens.WL_ForLondon[i].getPassenger_Seat()==2)
			                cout<<"Seat:Commercial"<<"|     |";
			                else cout<<"Seat:Economy"<<"|     |";
							if (airport_athens.WL_ForLondon[i].getPassenger_Destination()==2)
							cout<<"Destination:London"<<"|     |";
							cout<<"Weight :"<<airport_athens.WL_ForLondon[i].getPassenger_Weight()<<"|     "<<endl;
							}}
							if (airport_athens.WL_ForParis.size()>0)
							{cout<<"================================================================================"<<endl;
							cout<<"\nPassengers waiting for Paris :"<<airport_athens.WL_ForParis.size()<<"\n";
							for (int i=0;i< airport_athens.WL_ForParis.size();++i)
			                {cout<<endl;
							cout<<"Passenger Name :"<<airport_athens.WL_ForParis[i].getPassenger_Name()<<"|     |"<<endl;
			                 if(airport_athens.WL_ForParis[i].getPassenger_Seat()==1)
			                cout<<"Seat:VIP "<<"|     |";
			                else if (airport_athens.WL_ForParis[i].getPassenger_Seat()==2)
			                cout<<"Seat:Commercial"<<"|     |";
			                else cout<<"Seat:Economy"<<"|     |";
							if (airport_athens.WL_ForParis[i].getPassenger_Destination()==3)
							cout<<"Destination:Paris"<<"|     |";
							cout<<"Weight :"<<airport_athens.WL_ForParis[i].getPassenger_Weight()<<"|     |"<<endl;
							}}
			                system("Pause");
			                break;
			        case '4':system("CLS");
			                cout<<"Please give the Passenger's name:";
			                cin >> name;
							cout<<"Please give the seat of the Passenger: 1 vip,2 regular,3 economy:\n";
							cin >> seat;
							cout<<"Please give the Weight of baggage:";
			                cin >> weight;
			                cout<<"Please give the destination:2 London,3 Paris:";
			                cin >> dest;
			                  if (dest=2)
				                {airport_athens.WL_ForLondon.push_back(Passenger(name,seat,dest,weight));}
								else if(dest=3)
								{airport_athens.WL_ForParis.push_back(Passenger(name,seat,dest,weight));}
			                 system("PAUSE");
			                 break;
							 case'0':break; 
			        		default :cout<<"Not a valid option!!!";system("pause");}
			        	  
						  	CounterReset(counterP1,counterP2,counterP3);
						for (int i=0;i<airport_athens.WL_ForParis.size();++i)
								{
								if (airport_athens.WL_ForParis[i].getPassenger_Seat()==1)
								{counterP1+=1;}
								
								else if (airport_athens.WL_ForParis[i].getPassenger_Seat()==2)
								{counterP2+=1;}
							
								else if (airport_athens.WL_ForParis[i].getPassenger_Seat()==3)
								{counterP3+=1;}
								}
								//kane reset tous counters
								CounterReset(counterL1,counterL2,counterL3);
								
								for (int i=0;i<airport_athens.WL_ForLondon.size();++i)
								{
								if (airport_athens.WL_ForLondon[i].getPassenger_Seat()==1)
								{counterL1+=1;}
								
								if (airport_athens.WL_ForLondon[i].getPassenger_Seat()==2)
								{counterL2+=1;}
							
								if (airport_athens.WL_ForLondon[i].getPassenger_Seat()==3)
								{counterL3+=1;}
								}

								//edw elegxw to aeroplano gia na dw ti counters na xrhsimopoihsw 
								//an einai regular (pou tha einai panta sthn arxh  tha valoume 10 40 20 )
								if (airport_athens.plane[0].getPlane_Type()==1)
								{	//periptwsh londinou (an oi counters tou londinou exoun energopoihthei )
									if ((counterL1>=1) && (counterL2>=4) && (counterL3>=2)) 
									{//kane to destination tou aeroplanou 2(londino dld)
									airport_athens.plane[0].setPlane_destination(2);
										//gemise to me tous pelates pou perimenoun sth lista 
										for (int i=0;i<	airport_athens.WL_ForLondon.size();i++)
											{//vash theshs kai varous an xwrane(edw einai gia VIP)
												if ((airport_athens.WL_ForLondon[i].getPassenger_Seat()==1) && (airport_athens.plane[0].getMax_vip()<1) && ((airport_athens.plane[0].getWeight()+airport_athens.WL_ForLondon[i].getPassenger_Weight())<=100))
												{airport_athens.plane[0].passengers.push_back(airport_athens.WL_ForLondon[i]);
												                    airport_athens.plane[0].setPlane_weight(airport_athens.WL_ForLondon[i].getPassenger_Weight());
																	airport_athens.WL_ForLondon.erase(airport_athens.WL_ForLondon.begin()+i);
												                    airport_athens.plane[0].setMax_vip(1);
																   	i--;
												}//vash theshs kai varous an xwrane(edw einai gia Commercial)
												 else if ((airport_athens.WL_ForLondon[i].getPassenger_Seat()==2) && (airport_athens.plane[0].getMax_commercial()<4) && ((airport_athens.plane[0].getWeight()+airport_athens.WL_ForLondon[i].getPassenger_Weight())<=100))
												{airport_athens.plane[0].passengers.push_back(airport_athens.WL_ForLondon[i]);
												                   airport_athens.plane[0].setPlane_weight(airport_athens.WL_ForLondon[i].getPassenger_Weight());
												                 	airport_athens.WL_ForLondon.erase(airport_athens.WL_ForLondon.begin()+i);
												                 	airport_athens.plane[0].setMax_commercial(1);
																	i--;
												}//vash theshs kai varous an xwrane(edw einai gia economy)
												 else if ((airport_athens.WL_ForLondon[i].getPassenger_Seat()==3) && (airport_athens.plane[0].getMax_economy()<2)&& ((airport_athens.plane[0].getWeight()+airport_athens.WL_ForLondon[i].getPassenger_Weight())<=100))
												{airport_athens.plane[0].passengers.push_back(airport_athens.WL_ForLondon[i]) ;      
												                        airport_athens.plane[0].setPlane_weight(airport_athens.WL_ForLondon[i].getPassenger_Weight());             
												                    	airport_athens.WL_ForLondon.erase(airport_athens.WL_ForLondon.begin()+i); 
																		airport_athens.plane[0].setMax_economy(1);
																		i--;
												}           
											}
											//kane elegxo tou varous otan tha exoun mpei arketoi pelates gia ena regular na deis an ginetai
											//na to kanoume charter kai rwta 
										if (airport_athens.plane[0].getWeight()<=70)
											{cout<<"Thes na allakseis se charter?(y/n)";
											cin>>erwthsh;
											if (erwthsh=='y')
											{//to kanoume charter kai etc thn epomenh fora pou tha kanei elegxo typou aeroplanou sthn arxh 
											//tha paei sthn periptwsh tou charter
											airport_athens.plane[0].setPlane_Type(2);
											}
											else if (erwthsh=='n')
													// an oxi peta gia londino 
													{//edw paw sto aerodromio tou londinou kai gemizw oti pelates exei ekei sto aeroplano pou einai ekei
													
														for (int i=0;i<	airport_london.WL_ForAthens.size();i++)
															{
																if ((airport_london.WL_ForAthens[i].getPassenger_Seat()==1) && (airport_london.plane[0].getMax_vip()<1) && ((airport_london.plane[0].getWeight()+airport_london.WL_ForAthens[i].getPassenger_Weight())<=100))
																{airport_london.plane[0].passengers.push_back(airport_london.WL_ForAthens[i]);
																                    airport_london.plane[0].setPlane_weight(airport_london.WL_ForAthens[i].getPassenger_Weight());
																					airport_london.WL_ForAthens.erase(airport_london.WL_ForAthens.begin()+i);
																                    airport_london.plane[0].setMax_vip(1);
																				   	i--;
																}
																 else if ((airport_london.WL_ForAthens[i].getPassenger_Seat()==2) && (airport_london.plane[0].getMax_commercial()<4) && ((airport_london.plane[0].getWeight()+airport_london.WL_ForAthens[i].getPassenger_Weight())<=100))
																{airport_london.plane[0].passengers.push_back(airport_london.WL_ForAthens[i]);
																                   airport_london.plane[0].setPlane_weight(airport_london.WL_ForAthens[i].getPassenger_Weight());
																                 	airport_london.WL_ForAthens.erase(airport_london.WL_ForAthens.begin()+i);
																                 	airport_london.plane[0].setMax_commercial(1);
																					i--;
																}
																 else if ((airport_london.WL_ForAthens[i].getPassenger_Seat()==3) && (airport_london.plane[0].getMax_economy()<2)&& ((airport_london.plane[0].getWeight()+airport_london.WL_ForAthens[i].getPassenger_Weight())<=100))
																{airport_london.plane[0].passengers.push_back(airport_london.WL_ForAthens[i]) ;      
																                        airport_london.plane[0].setPlane_weight(airport_london.WL_ForAthens[i].getPassenger_Weight());             
																                    	airport_london.WL_ForAthens.erase(airport_london.WL_ForAthens.begin()+i); 
																						airport_london.plane[0].setMax_economy(1);
																						i--;
																}           
															}
															//kanw thn allagh twn aeroplanwn
																	temp=airport_athens.plane[0];
													                airport_athens.plane[0] = airport_london.plane[0];
													                airport_london.plane[0] = temp;	
								//thetw tous tupous se regular otan prosgeiwthei to kathe plane
								airport_athens.plane[0].setPlane_Type(1);
							  	airport_london.plane[0].setPlane_Type(1);
							  	//edw adeiazw tous passengers 
								airport_athens.plane[0].passengers.clear();
								airport_london.plane[0].passengers.clear();
								//edw mhdenizw ths theseis kai to varos kai twn 2 aeroplanwn gia na einai etoima gia xrhsh 
								airport_athens.plane[0].setMax_vip(-airport_athens.plane[0].getMax_vip());
								airport_athens.plane[0].setMax_commercial(-airport_athens.plane[0].getMax_commercial());
								airport_athens.plane[0].setMax_economy(-airport_athens.plane[0].getMax_economy());
								airport_athens.plane[0].setPlane_weight(-airport_athens.plane[0].getWeight());
								//edw mhdenizw ths theseis kai to varos kai twn 2 aeroplanwn gia na einai etoima gia xrhsh 
								airport_london.plane[0].setMax_vip(-airport_london.plane[0].getMax_vip());
								airport_london.plane[0].setMax_commercial(-airport_london.plane[0].getMax_commercial());
								airport_london.plane[0].setMax_economy(-airport_london.plane[0].getMax_economy());
								airport_london.plane[0].setPlane_weight(-airport_london.plane[0].getWeight());
											system ("Pause");			                
													}
											}
											//edw einai h periptwsh pou to varos einai panw apo to orio tou charter ara apla peta 
											else 
											{	//edw o kwdikas einai idios me ton apo panw oson afora to petagma
											for (int i=0;i<	airport_london.WL_ForAthens.size();i++)
															{
																if ((airport_london.WL_ForAthens[i].getPassenger_Seat()==1) && (airport_london.plane[0].getMax_vip()<1) && ((airport_london.plane[0].getWeight()+airport_london.WL_ForAthens[i].getPassenger_Weight())<=100))
																{airport_london.plane[0].passengers.push_back(airport_london.WL_ForAthens[i]);
																                    airport_london.plane[0].setPlane_weight(airport_london.WL_ForAthens[i].getPassenger_Weight());
																					airport_london.WL_ForAthens.erase(airport_london.WL_ForAthens.begin()+i);
																                    airport_london.plane[0].setMax_vip(1);
																				   	i--;
																}
																 else if ((airport_london.WL_ForAthens[i].getPassenger_Seat()==2) && (airport_london.plane[0].getMax_commercial()<4) && ((airport_london.plane[0].getWeight()+airport_london.WL_ForAthens[i].getPassenger_Weight())<=100))
																{airport_london.plane[0].passengers.push_back(airport_london.WL_ForAthens[i]);
																                   airport_london.plane[0].setPlane_weight(airport_london.WL_ForAthens[i].getPassenger_Weight());
																                 	airport_london.WL_ForAthens.erase(airport_london.WL_ForAthens.begin()+i);
																                 	airport_london.plane[0].setMax_commercial(1);
																					i--;
																}
																 else if ((airport_london.WL_ForAthens[i].getPassenger_Seat()==3) && (airport_london.plane[0].getMax_economy()<2)&& ((airport_london.plane[0].getWeight()+airport_london.WL_ForAthens[i].getPassenger_Weight())<=100))
																{airport_london.plane[0].passengers.push_back(airport_london.WL_ForAthens[i]) ;      
																                        airport_london.plane[0].setPlane_weight(airport_london.WL_ForAthens[i].getPassenger_Weight());             
																                    	airport_london.WL_ForAthens.erase(airport_london.WL_ForAthens.begin()+i); 
																						airport_london.plane[0].setMax_economy(1);
																						i--;
																}           
															}
																	temp=airport_athens.plane[0];
													                airport_athens.plane[0] = airport_london.plane[0];
													                airport_london.plane[0] = temp;	
								airport_london.plane[0].setPlane_Type(1);
								airport_athens.plane[0].setPlane_Type(1);
								
								airport_athens.plane[0].passengers.clear();
								airport_london.plane[0].passengers.clear();
								//edw mhdenizw ths theseis kai to varos kai twn 2 aeroplanwn gia na einai etoima gia xrhsh 
								airport_athens.plane[0].setMax_vip(-airport_athens.plane[0].getMax_vip());
								airport_athens.plane[0].setMax_commercial(-airport_athens.plane[0].getMax_commercial());
								airport_athens.plane[0].setMax_economy(-airport_athens.plane[0].getMax_economy());
								airport_athens.plane[0].setPlane_weight(-airport_athens.plane[0].getWeight());
								//edw mhdenizw ths theseis kai to varos kai twn 2 aeroplanwn gia na einai etoima gia xrhsh 
								airport_london.plane[0].setMax_vip(-airport_london.plane[0].getMax_vip());
								airport_london.plane[0].setMax_commercial(-airport_london.plane[0].getMax_commercial());
								airport_london.plane[0].setMax_economy(-airport_london.plane[0].getMax_economy());
								airport_london.plane[0].setPlane_weight(-airport_london.plane[0].getWeight());
											system ("Pause");			  	
											}
									}
									//edw einai idios kwdikas apla gia thn periptwsh tou parisiou 
									//to epomeno shmantiko kommati einai sth grammh 653 kai katw
								if ((counterP1>=1) && (counterP2>=4) && (counterP3>=2))
										{airport_athens.plane[0].setPlane_destination(3);
										for (int i=0;i<	airport_athens.WL_ForParis.size();i++)
											{
												if ((airport_athens.WL_ForParis[i].getPassenger_Seat()==1) && (airport_athens.plane[0].getMax_vip()<1) && ((airport_athens.plane[0].getWeight()+airport_athens.WL_ForParis[i].getPassenger_Weight())<=100))
												{airport_athens.plane[0].passengers.push_back(airport_athens.WL_ForParis[i]);
												                    airport_athens.plane[0].setPlane_weight(airport_athens.WL_ForParis[i].getPassenger_Weight());
																	airport_athens.WL_ForParis.erase(airport_athens.WL_ForParis.begin()+i);
												                    airport_athens.plane[0].setMax_vip(1);
																   	i--;
												}
												 else if ((airport_athens.WL_ForParis[i].getPassenger_Seat()==2) && (airport_athens.plane[0].getMax_commercial()<4) && ((airport_athens.plane[0].getWeight()+airport_athens.WL_ForParis[i].getPassenger_Weight())<=100))
												{airport_athens.plane[0].passengers.push_back(airport_athens.WL_ForParis[i]);
												                   airport_athens.plane[0].setPlane_weight(airport_athens.WL_ForParis[i].getPassenger_Weight());
												                 	airport_athens.WL_ForParis.erase(airport_athens.WL_ForParis.begin()+i);
												                 	airport_athens.plane[0].setMax_commercial(1);
																	i--;
												}
												 else if ((airport_athens.WL_ForParis[i].getPassenger_Seat()==3) && (airport_athens.plane[0].getMax_economy()<2)&& ((airport_athens.plane[0].getWeight()+airport_athens.WL_ForParis[i].getPassenger_Weight())<=100))
												{airport_athens.plane[0].passengers.push_back(airport_athens.WL_ForParis[i]) ;      
												                        airport_athens.plane[0].setPlane_weight(airport_athens.WL_ForParis[i].getPassenger_Weight());             
												                    	airport_athens.WL_ForParis.erase(airport_athens.WL_ForParis.begin()+i); 
																		airport_athens.plane[0].setMax_economy(1);
																		i--;
												}           
											}
										if (airport_athens.plane[0].getWeight()<=70)
											{cout<<"Thes na allakseis se charter? (y/n)";
											cin>>erwthsh;
											if (erwthsh=='y')
											{airport_athens.plane[0].setPlane_Type(2);
											}
													else if (erwthsh=='n')
													// an oxi peta 
													{
														for (int i=0;i<	airport_paris.WL_ForAthens.size();i++)
															{
																if ((airport_paris.WL_ForAthens[i].getPassenger_Seat()==1) && (airport_paris.plane[0].getMax_vip()<1) && ((airport_paris.plane[0].getWeight()+airport_paris.WL_ForAthens[i].getPassenger_Weight())<=100))
																{airport_paris.plane[0].passengers.push_back(airport_paris.WL_ForAthens[i]);
																                    airport_paris.plane[0].setPlane_weight(airport_paris.WL_ForAthens[i].getPassenger_Weight());
																					airport_paris.WL_ForAthens.erase(airport_paris.WL_ForAthens.begin()+i);
																                    airport_paris.plane[0].setMax_vip(1);
																				   	i--;
																}
																 else if ((airport_paris.WL_ForAthens[i].getPassenger_Seat()==2) && (airport_paris.plane[0].getMax_commercial()<4) && ((airport_paris.plane[0].getWeight()+airport_paris.WL_ForAthens[i].getPassenger_Weight())<=100))
																{airport_paris.plane[0].passengers.push_back(airport_paris.WL_ForAthens[i]);
																                   airport_paris.plane[0].setPlane_weight(airport_paris.WL_ForAthens[i].getPassenger_Weight());
																                 	airport_paris.WL_ForAthens.erase(airport_paris.WL_ForAthens.begin()+i);
																                 	airport_paris.plane[0].setMax_commercial(1);
																					i--;
																}
																 else if ((airport_paris.WL_ForAthens[i].getPassenger_Seat()==3) && (airport_paris.plane[0].getMax_economy()<2)&& ((airport_paris.plane[0].getWeight()+airport_paris.WL_ForAthens[i].getPassenger_Weight())<=100))
																{airport_paris.plane[0].passengers.push_back(airport_paris.WL_ForAthens[i]) ;      
																                        airport_paris.plane[0].setPlane_weight(airport_paris.WL_ForAthens[i].getPassenger_Weight());             
																                    	airport_paris.WL_ForAthens.erase(airport_paris.WL_ForAthens.begin()+i); 
																						airport_paris.plane[0].setMax_economy(1);
																						i--;
																}           
															}
																	temp=airport_athens.plane[0];
													                airport_athens.plane[0] = airport_paris.plane[0];
													                airport_paris.plane[0] = temp;	
								airport_athens.plane[0].setPlane_Type(1);
								airport_paris.plane[0].setPlane_Type(1);
							
								airport_athens.plane[0].passengers.clear();
								airport_paris.plane[0].passengers.clear();
								//edw mhdenizw ths theseis kai to varos kai twn 2 aeroplanwn gia na einai etoima gia xrhsh 
								airport_athens.plane[0].setMax_vip(-airport_athens.plane[0].getMax_vip());
								airport_athens.plane[0].setMax_commercial(-airport_athens.plane[0].getMax_commercial());
								airport_athens.plane[0].setMax_economy(-airport_athens.plane[0].getMax_economy());
								airport_athens.plane[0].setPlane_weight(-airport_athens.plane[0].getWeight());
								//edw mhdenizw ths theseis kai to varos kai twn 2 aeroplanwn gia na einai etoima gia xrhsh 
								airport_paris.plane[0].setMax_vip(-airport_paris.plane[0].getMax_vip());
								airport_paris.plane[0].setMax_commercial(-airport_paris.plane[0].getMax_commercial());
								airport_paris.plane[0].setMax_economy(-airport_paris.plane[0].getMax_economy());
								airport_paris.plane[0].setPlane_weight(-airport_paris.plane[0].getWeight());	
										system ("Pause");	     
													}
											}
											else
											{for (int i=0;i<airport_paris.WL_ForAthens.size();i++)
															{
																if ((airport_paris.WL_ForAthens[i].getPassenger_Seat()==1) && (airport_paris.plane[0].getMax_vip()<1) && ((airport_paris.plane[0].getWeight()+airport_paris.WL_ForAthens[i].getPassenger_Weight())<=100))
																{airport_paris.plane[0].passengers.push_back(airport_paris.WL_ForAthens[i]);
																                    airport_paris.plane[0].setPlane_weight(airport_paris.WL_ForAthens[i].getPassenger_Weight());
																					airport_paris.WL_ForAthens.erase(airport_paris.WL_ForAthens.begin()+i);
																                    airport_paris.plane[0].setMax_vip(1);
																				   	i--;
																}
																 else if ((airport_paris.WL_ForAthens[i].getPassenger_Seat()==2) && (airport_paris.plane[0].getMax_commercial()<4) && ((airport_paris.plane[0].getWeight()+airport_paris.WL_ForAthens[i].getPassenger_Weight())<=100))
																{airport_paris.plane[0].passengers.push_back(airport_paris.WL_ForAthens[i]);
																                   airport_paris.plane[0].setPlane_weight(airport_paris.WL_ForAthens[i].getPassenger_Weight());
																                 	airport_paris.WL_ForAthens.erase(airport_paris.WL_ForAthens.begin()+i);
																                 	airport_paris.plane[0].setMax_commercial(1);
																					i--;
																}
																 else if ((airport_paris.WL_ForAthens[i].getPassenger_Seat()==3) && (airport_paris.plane[0].getMax_economy()<2)&& ((airport_paris.plane[0].getWeight()+airport_paris.WL_ForAthens[i].getPassenger_Weight())<=100))
																{airport_paris.plane[0].passengers.push_back(airport_paris.WL_ForAthens[i]) ;      
																                        airport_paris.plane[0].setPlane_weight(airport_paris.WL_ForAthens[i].getPassenger_Weight());             
																                    	airport_paris.WL_ForAthens.erase(airport_paris.WL_ForAthens.begin()+i); 
																						airport_paris.plane[0].setMax_economy(1);
																						i--;
																}           
															}
																	temp=airport_athens.plane[0];
													                airport_athens.plane[0] = airport_paris.plane[0];
													                airport_paris.plane[0] = temp;	
								airport_athens.plane[0].setPlane_Type(1);
								airport_paris.plane[0].setPlane_Type(1);
							
								airport_athens.plane[0].passengers.clear();
								airport_paris.plane[0].passengers.clear();
								//edw mhdenizw ths theseis kai to varos kai twn 2 aeroplanwn gia na einai etoima gia xrhsh 
								airport_athens.plane[0].setMax_vip(-airport_athens.plane[0].getMax_vip());
								airport_athens.plane[0].setMax_commercial(-airport_athens.plane[0].getMax_commercial());
								airport_athens.plane[0].setMax_economy(-airport_athens.plane[0].getMax_economy());
								airport_athens.plane[0].setPlane_weight(-airport_athens.plane[0].getWeight());
								//edw mhdenizw ths theseis kai to varos kai twn 2 aeroplanwn gia na einai etoima gia xrhsh 
								airport_paris.plane[0].setMax_vip(-airport_paris.plane[0].getMax_vip());
								airport_paris.plane[0].setMax_commercial(-airport_paris.plane[0].getMax_commercial());
								airport_paris.plane[0].setMax_economy(-airport_paris.plane[0].getMax_economy());
								airport_paris.plane[0].setPlane_weight(-airport_paris.plane[0].getWeight());	
											system ("Pause");	    
											}
										}
								}
					
								//edw einai h periptwsh tou charter sauto to programma den tha doulepsei epeidh den eimaste se loopa omws o kwdikas prepei na einai swstos
								//autos o elegxos tha ginetai meta thn kataxwrhsh kathe pelath opote sto kanoniko programma tha doulepsei
								else if (airport_athens.plane[0].getPlane_Type()==2)
								{//edw xrhsimopoiw mono ton counter gia economy theseis kai lew oti prepei na parei toulaxistwn 2 pelates (to neo orio twn thesewn ginetai +2)
								//kai tous elegxw an to varos tous plhrei to orio tou charter an nai kai tous valei tote peta alliws vale osous xwrane kai meta peta
								// epishs elegxo an o proorismos einai gia londino gia na mhn mperdepsei tous passenger 
									if ((counterL3>=2) && (airport_athens.plane[0].getPlane_Destination()==2))
									{//einai idio for opws sta panw paradeigmata
									for (int i=0;i<airport_athens.WL_ForLondon.size();i++)
									{if ((airport_athens.WL_ForLondon[i].getPassenger_Seat()==3) && (airport_athens.plane[0].getMax_economy()<2)&& ((airport_athens.plane[0].getWeight()+airport_athens.WL_ForLondon[i].getPassenger_Weight())<=70))
											{airport_athens.plane[0].passengers.push_back(airport_athens.WL_ForLondon[i]) ;      
																                        airport_athens.plane[0].setPlane_weight(airport_athens.WL_ForLondon[i].getPassenger_Weight());             
																                    	airport_athens.WL_ForLondon.erase(airport_athens.WL_ForLondon.begin()+i); 
																						airport_athens.plane[0].setMax_economy(1);
																						i--;
											}           	
									}//edw einai idios kwdikas gia na gemisei to aeroplano tou londinou kai na kanei to swap
									for (int i=0;i<	airport_london.WL_ForAthens.size();i++)
															{
																if ((airport_london.WL_ForAthens[i].getPassenger_Seat()==1) && (airport_london.plane[0].getMax_vip()<2) && ((airport_london.plane[0].getWeight()+airport_london.WL_ForAthens[i].getPassenger_Weight())<=100))
																{airport_london.plane[0].passengers.push_back(airport_london.WL_ForAthens[i]);
																                    airport_london.plane[0].setPlane_weight(airport_london.WL_ForAthens[i].getPassenger_Weight());
																					airport_london.WL_ForAthens.erase(airport_london.WL_ForAthens.begin()+i);
																                    airport_london.plane[0].setMax_vip(1);
																				   	i--;
																}
																 else if ((airport_london.WL_ForAthens[i].getPassenger_Seat()==2) && (airport_london.plane[0].getMax_commercial()<3) && ((airport_london.plane[0].getWeight()+airport_london.WL_ForAthens[i].getPassenger_Weight())<=100))
																{airport_london.plane[0].passengers.push_back(airport_london.WL_ForAthens[i]);
																                   airport_london.plane[0].setPlane_weight(airport_london.WL_ForAthens[i].getPassenger_Weight());
																                 	airport_london.WL_ForAthens.erase(airport_london.WL_ForAthens.begin()+i);
																                 	airport_london.plane[0].setMax_commercial(1);
																					i--;
																}
																 else if ((airport_london.WL_ForAthens[i].getPassenger_Seat()==3) && (airport_london.plane[0].getMax_economy()<3)&& ((airport_london.plane[0].getWeight()+airport_london.WL_ForAthens[i].getPassenger_Weight())<=100))
																{airport_london.plane[0].passengers.push_back(airport_london.WL_ForAthens[i]) ;      
																                        airport_london.plane[0].setPlane_weight(airport_london.WL_ForAthens[i].getPassenger_Weight());             
																                    	airport_london.WL_ForAthens.erase(airport_london.WL_ForAthens.begin()+i); 
																						airport_london.plane[0].setMax_economy(1);
																						i--;
																}           
															}
																	temp=airport_athens.plane[0];
													                airport_athens.plane[0] = airport_london.plane[0];
													                airport_london.plane[0] = temp;	
								airport_athens.plane[0].setPlane_Type(1);
								airport_london.plane[0].setPlane_Type(1);
								//edw adeiazw tous passengers 
								airport_athens.plane[0].passengers.clear();
								airport_london.plane[0].passengers.clear();
								//edw mhdenizw ths theseis kai to varos kai twn 2 aeroplanwn gia na einai etoima gia xrhsh 
								airport_athens.plane[0].setMax_vip(-airport_athens.plane[0].getMax_vip());
								airport_athens.plane[0].setMax_commercial(-airport_athens.plane[0].getMax_commercial());
								airport_athens.plane[0].setMax_economy(-airport_athens.plane[0].getMax_economy());
								airport_athens.plane[0].setPlane_weight(-airport_athens.plane[0].getWeight());
								//edw mhdenizw ths theseis kai to varos kai twn 2 aeroplanwn gia na einai etoima gia xrhsh 
								airport_london.plane[0].setMax_vip(-airport_london.plane[0].getMax_vip());
								airport_london.plane[0].setMax_commercial(-airport_london.plane[0].getMax_commercial());
								airport_london.plane[0].setMax_economy(-airport_london.plane[0].getMax_economy());
								airport_london.plane[0].setPlane_weight(-airport_london.plane[0].getWeight());
											system ("Pause");	
									}
									//edw einai o counter gia wait list paris gia economy theseis
									if ((counterP3>=2) && (airport_athens.plane[0].getPlane_Destination()==3))
									{	
									for (int i=0;i<airport_athens.WL_ForParis.size();i++)
									{if ((airport_athens.WL_ForParis[i].getPassenger_Seat()==3) && (airport_athens.plane[0].getMax_economy()<2)&& ((airport_athens.plane[0].getWeight()+airport_athens.WL_ForParis[i].getPassenger_Weight())<=70))
												{airport_athens.plane[0].passengers.push_back(airport_athens.WL_ForParis[i]) ;      
												                        airport_athens.plane[0].setPlane_weight(airport_athens.WL_ForParis[i].getPassenger_Weight());             
												                    	airport_athens.WL_ForParis.erase(airport_athens.WL_ForParis.begin()+i); 
																		airport_athens.plane[0].setMax_economy(1);
																		i--;
												}          
									}
											for (int i=0;i<	airport_paris.WL_ForAthens.size();i++)
															{
																if ((airport_paris.WL_ForAthens[i].getPassenger_Seat()==1) && (airport_paris.plane[0].getMax_vip()<1) && ((airport_paris.plane[0].getWeight()+airport_paris.WL_ForAthens[i].getPassenger_Weight())<=100))
																{airport_paris.plane[0].passengers.push_back(airport_paris.WL_ForAthens[i]);
																                    airport_paris.plane[0].setPlane_weight(airport_paris.WL_ForAthens[i].getPassenger_Weight());
																					airport_paris.WL_ForAthens.erase(airport_paris.WL_ForAthens.begin()+i);
																                    airport_paris.plane[0].setMax_vip(1);
																				   	i--;
																}
																 else if ((airport_paris.WL_ForAthens[i].getPassenger_Seat()==2) && (airport_paris.plane[0].getMax_commercial()<4) && ((airport_paris.plane[0].getWeight()+airport_paris.WL_ForAthens[i].getPassenger_Weight())<=100))
																{airport_paris.plane[0].passengers.push_back(airport_paris.WL_ForAthens[i]);
																                   airport_paris.plane[0].setPlane_weight(airport_paris.WL_ForAthens[i].getPassenger_Weight());
																                 	airport_paris.WL_ForAthens.erase(airport_paris.WL_ForAthens.begin()+i);
																                 	airport_paris.plane[0].setMax_commercial(1);
																					i--;
																}
																 else if ((airport_paris.WL_ForAthens[i].getPassenger_Seat()==3) && (airport_paris.plane[0].getMax_economy()<2)&& ((airport_paris.plane[0].getWeight()+airport_paris.WL_ForAthens[i].getPassenger_Weight())<=100))
																{airport_paris.plane[0].passengers.push_back(airport_paris.WL_ForAthens[i]) ;      
																                        airport_paris.plane[0].setPlane_weight(airport_paris.WL_ForAthens[i].getPassenger_Weight());             
																                    	airport_paris.WL_ForAthens.erase(airport_paris.WL_ForAthens.begin()+i); 
																						airport_paris.plane[0].setMax_economy(1);
																						i--;
																}           
															}
																	temp=airport_athens.plane[0];
													                airport_athens.plane[0] = airport_paris.plane[0];
													                airport_paris.plane[0] = temp;		
								airport_athens.plane[0].setPlane_Type(1);
								airport_paris.plane[0].setPlane_Type(1);
							
								airport_athens.plane[0].passengers.clear();
								airport_paris.plane[0].passengers.clear();
								//edw mhdenizw ths theseis kai to varos kai twn 2 aeroplanwn gia na einai etoima gia xrhsh 
								airport_athens.plane[0].setMax_vip(-airport_athens.plane[0].getMax_vip());
								airport_athens.plane[0].setMax_commercial(-airport_athens.plane[0].getMax_commercial());
								airport_athens.plane[0].setMax_economy(-airport_athens.plane[0].getMax_economy());
								airport_athens.plane[0].setPlane_weight(-airport_athens.plane[0].getWeight());
								//edw mhdenizw ths theseis kai to varos kai twn 2 aeroplanwn gia na einai etoima gia xrhsh 
								airport_paris.plane[0].setMax_vip(-airport_paris.plane[0].getMax_vip());
								airport_paris.plane[0].setMax_commercial(-airport_paris.plane[0].getMax_commercial());
								airport_paris.plane[0].setMax_economy(-airport_paris.plane[0].getMax_economy());
								airport_paris.plane[0].setPlane_weight(-airport_paris.plane[0].getWeight());	
											system ("Pause");	     
									}
								}
						  
						  	
			    } while (choice!='0');
			    break;
    case '2':
			do{
			system("cls");
					cout<<"You are currently at the London Airport.\n";
				     cout<<"Press 1 to Show our Current planes:\n";
				     cout<<"Press 2 to Make a new plane:\n";
				     cout<<"Press 3 to Show the passengers waiting at this airport:\n";
				     cout<<"Press 4 to Add a new passenger:\n";
				     cout<<"Press 0 to Exit\n";
				     cout<<"Please give your choice:";
		     		cin>>choice3;
		     		switch (choice3)
	       		{case '1':system("CLS");
		                	 cout<<"Our Planes at this moment :\n";
		                 	for (int i=0;i<airport_london.plane.size();++i)
		                    	{
								cout<<i<<")Plane name:"<<airport_london.plane[i].getPlane_Name()<<"          ";
			                    if (airport_london.plane[i].getPlane_Type()==1)
								cout<<"Plane Type:Regular" <<"         ";
			                    else
			                    cout<<"Plane Type:Charter"<<"          ";
							    if (airport_london.plane[i].getPlane_Destination()==1)
							    cout<<"Destination:Athens"<<"           ";
							    else if (airport_london.plane[i].getPlane_Destination()==2)
							    cout<<"Destination:London"<<"            ";
							    else 
							    cout<<"Destination:Paris"<<"             ";
								if (airport_london.plane[i].getPlane_Location()==1)
							    cout<<"Location:Athens"<<"             ";
							    else if (airport_london.plane[i].getPlane_Location()==2)
							    cout<<"Location:London"<<"            ";
							    else 
							    cout<<"Location:Paris"<<"             ";
							    cout<<"Pilot Name:"<<airport_london.plane[i].getPilot_Name()<<"     "<<endl;
							}
						    system("pause");
		                    break;
     			case '2':system("CLS");
     							cout<<"You have "<<airport_london.plane.size()<<"planes at this airport!";
								cout<<"Please give the name of the plane:";
				                cin >> pname;
				            if ((PlaneNameCheck(airport_paris.plane,pname)<0) && (PlaneNameCheck(airport_london.plane,pname)<0) && (PlaneNameCheck(airport_athens.plane,pname)<0))
				                {	
								cout<<"Please give Pilot name";
				                cin >> pilotname;
				                
							if (airport_london.WL_ForAthens.size()>airport_london.WL_ForParis.size())
				              	{ airport_london.plane.push_back(Plane(pname,1,pilotname,plocL,1));}
							else
				              	{airport_london.plane.push_back(Plane(pname,1,pilotname,plocL,3));}
				                }
							else
				                {cout<<"Plane name already exists!";}
				                system("Pause");
			                	break;
       			 case '3':system("CLS");
        				cout<<"Our passengers at this moment :\n";
			            if (airport_london.WL_ForAthens.size()>0)
						{cout<<"Passengers waiting for Athens :"<<airport_london.WL_ForAthens.size()<<"\n";
							for (int i=0;i< airport_london.WL_ForAthens.size();++i)
			                {
							cout<<endl;
							cout<<"Passenger Name :"<<airport_london.WL_ForAthens[i].getPassenger_Name()<<"|     |";
			               if(airport_london.WL_ForAthens[i].getPassenger_Seat()==1)
			                cout<<"Seat:VIP "<<"|     |";
			                else if (airport_london.WL_ForAthens[i].getPassenger_Seat()==2)
			                cout<<"Seat:Commercial"<<"|     |";
			                else cout<<"Seat:Economy"<<"|     |";
							if (airport_london.WL_ForAthens[i].getPassenger_Destination()==1)
							cout<<"Destination:Athens"<<"|     |";
							cout<<"Weight :"<<airport_london.WL_ForAthens[i].getPassenger_Weight()<<"|     "<<endl;
							}
						}
						if (airport_london.WL_ForParis.size()>0)
						{cout<<"\nPassengers waiting for Paris :"<<airport_london.WL_ForParis.size()<<"\n";
							cout<<"================================================================================"<<endl;
						for (int i=0;i< airport_london.WL_ForParis.size();++i)
			                {
							cout<<endl;
							cout<<"Passenger Name :"<<airport_london.WL_ForParis[i].getPassenger_Name()<<"|     |"<<endl;
			                if(airport_london.WL_ForParis[i].getPassenger_Seat()==1)
			                cout<<"Seat:VIP "<<"|     |";
			                else if (airport_london.WL_ForParis[i].getPassenger_Seat()==2)
			                cout<<"Seat:Commercial"<<"|     |";
			                else cout<<"Seat:Economy"<<"|     |";
							if (airport_london.WL_ForParis[i].getPassenger_Destination()==3)
							cout<<"Destination:Paris"<<"|     |";
							cout<<"Weight :"<<airport_london.WL_ForParis[i].getPassenger_Weight()<<"|     |"<<endl;
							}
						}
			                system("Pause");
			                break;
        case '4':system("CLS");
        		   		cout<<"Please give the Passenger's name:";
			            cin >> name;
						cout<<"Please give the seat of the Passenger: 1 vip,2 regular,3 economy:\n";
						cin >> seat;
						cout<<"Please give the Weight of baggage:";
			            cin >> weight;
			            cout<<"Please give the destination:1 for Athens,3 for Paris:";
			            cin >> dest;
			           if (dest=1)
				            {airport_london.WL_ForAthens.push_back(Passenger(name,seat,dest,weight));}
							else if(dest=3)
							{airport_london.WL_ForParis.push_back(Passenger(name,seat,dest,weight));}
			                 system("PAUSE");
			            break;
			case'0':break; 
			    default :cout<<"Not a valid option!!!";system("pause");} 
			        	
				
					CounterReset(counterP1,counterP2,counterP3);
				for (int i=0;i<airport_london.WL_ForParis.size();++i)
								{
								if (airport_london.WL_ForParis[i].getPassenger_Seat()==1)
								{counterP1+=1;}

								else if (airport_london.WL_ForParis[i].getPassenger_Seat()==2)
								{counterP2+=1;}

								else if (airport_london.WL_ForParis[i].getPassenger_Seat()==3)
								{counterP3+=1;}
								}
								//kane reset tous counters
								CounterReset(counterL1,counterL2,counterL3);
							for (int i=0;i<airport_london.WL_ForAthens.size();++i)
								{
								if (airport_london.WL_ForAthens[i].getPassenger_Seat()==1)
								{counterL1+=1;}

								if (airport_london.WL_ForAthens[i].getPassenger_Seat()==2)
								{counterL2+=1;}

								if (airport_london.WL_ForAthens[i].getPassenger_Seat()==3)
								{counterL3+=1;}
								}


								if (airport_london.plane[0].getPlane_Type()==1)
								{	//periptwsh athens
									if ((counterL1>=1) && (counterL2>=4) && (counterL3>=2))
									{airport_london.plane[0].setPlane_destination(1);
										for (int i=0;i<	airport_london.WL_ForAthens.size();i++)
											{
												if ((airport_london.WL_ForAthens[i].getPassenger_Seat()==1) && (airport_london.plane[0].getMax_vip()<1) && ((airport_london.plane[0].getWeight()+airport_london.WL_ForAthens[i].getPassenger_Weight())<=100))
												{airport_london.plane[0].passengers.push_back(airport_london.WL_ForAthens[i]);
												                    airport_london.plane[0].setPlane_weight(airport_london.WL_ForAthens[i].getPassenger_Weight());
																	airport_london.WL_ForAthens.erase(airport_london.WL_ForAthens.begin()+i);
												                    airport_london.plane[0].setMax_vip(1);
																   	i--;
												}
												 else if ((airport_london.WL_ForAthens[i].getPassenger_Seat()==2) && (airport_london.plane[0].getMax_commercial()<4) && ((airport_london.plane[0].getWeight()+airport_london.WL_ForAthens[i].getPassenger_Weight())<=100))
												{airport_london.plane[0].passengers.push_back(airport_london.WL_ForAthens[i]);
												                   airport_london.plane[0].setPlane_weight(airport_london.WL_ForAthens[i].getPassenger_Weight());
												                 	airport_london.WL_ForAthens.erase(airport_london.WL_ForAthens.begin()+i);
												                 	airport_london.plane[0].setMax_commercial(1);
																	i--;
												}
												 else if ((airport_london.WL_ForAthens[i].getPassenger_Seat()==3) && (airport_london.plane[0].getMax_economy()<2)&& ((airport_london.plane[0].getWeight()+airport_london.WL_ForAthens[i].getPassenger_Weight())<=100))
												{airport_london.plane[0].passengers.push_back(airport_london.WL_ForAthens[i]) ;
												                        airport_london.plane[0].setPlane_weight(airport_london.WL_ForAthens[i].getPassenger_Weight());
												                    	airport_london.WL_ForAthens.erase(airport_london.WL_ForAthens.begin()+i);
																		airport_london.plane[0].setMax_economy(1);
																		i--;
												}
											}

										if (airport_london.plane[0].getWeight()<=70)
											{cout<<"Thes na allakseis se charter?(y/n)";
											cin>>erwthsh;
											if (erwthsh=='y')
											{airport_london.plane[0].setPlane_Type(2);
											}
											else if (erwthsh=='n')
													// an oxi peta
													{
														for (int i=0;i<	airport_athens.WL_ForLondon.size();i++)
															{
																if ((airport_athens.WL_ForLondon[i].getPassenger_Seat()==1) && (airport_athens.plane[0].getMax_vip()<1) && ((airport_athens.plane[0].getWeight()+airport_athens.WL_ForLondon[i].getPassenger_Weight())<=100))
																{airport_athens.plane[0].passengers.push_back(airport_athens.WL_ForLondon[i]);
																                    airport_athens.plane[0].setPlane_weight(airport_athens.WL_ForLondon[i].getPassenger_Weight());
																					airport_athens.WL_ForLondon.erase(airport_athens.WL_ForAthens.begin()+i);
																                    airport_athens.plane[0].setMax_vip(1);
																				   	i--;
																}
																 else if ((airport_athens.WL_ForLondon[i].getPassenger_Seat()==2) && (airport_athens.plane[0].getMax_commercial()<4) && ((airport_athens.plane[0].getWeight()+airport_athens.WL_ForLondon[i].getPassenger_Weight())<=100))
																{airport_athens.plane[0].passengers.push_back(airport_athens.WL_ForLondon[i]);
																                   airport_athens.plane[0].setPlane_weight(airport_athens.WL_ForLondon[i].getPassenger_Weight());
																                 	airport_athens.WL_ForLondon.erase(airport_athens.WL_ForLondon.begin()+i);
																                 	airport_athens.plane[0].setMax_commercial(1);
																					i--;
																}
																 else if ((airport_athens.WL_ForLondon[i].getPassenger_Seat()==3) && (airport_athens.plane[0].getMax_economy()<2)&& ((airport_athens.plane[0].getWeight()+airport_athens.WL_ForLondon[i].getPassenger_Weight())<=100))
																{airport_athens.plane[0].passengers.push_back(airport_athens.WL_ForLondon[i]) ;
																                        airport_athens.plane[0].setPlane_weight(airport_athens.WL_ForLondon[i].getPassenger_Weight());
																                    	airport_athens.WL_ForLondon.erase(airport_athens.WL_ForLondon.begin()+i);
																						airport_athens.plane[0].setMax_economy(1);
																						i--;
																}
															}

																	temp=airport_london.plane[0];
													                airport_london.plane[0] = airport_athens.plane[0];
													                airport_athens.plane[0] = temp;
													                
								airport_athens.plane[0].setPlane_Type(1);
							  	airport_london.plane[0].setPlane_Type(1);
								airport_athens.plane[0].passengers.clear();
								airport_london.plane[0].passengers.clear();
								//mhdenise to aeroplano
								airport_athens.plane[0].setMax_vip(-airport_athens.plane[0].getMax_vip());
								airport_athens.plane[0].setMax_commercial(-airport_athens.plane[0].getMax_commercial());
								airport_athens.plane[0].setMax_economy(-airport_athens.plane[0].getMax_economy());
								airport_athens.plane[0].setPlane_weight(-airport_athens.plane[0].getWeight());
								//mhdenise to aeroplano
								airport_london.plane[0].setMax_vip(-airport_london.plane[0].getMax_vip());
								airport_london.plane[0].setMax_commercial(-airport_london.plane[0].getMax_commercial());
								airport_london.plane[0].setMax_economy(-airport_london.plane[0].getMax_economy());
								airport_london.plane[0].setPlane_weight(-airport_london.plane[0].getWeight());
											system ("Pause");
													}
											}

											else
											{	for (int i=0;i<	airport_athens.WL_ForLondon.size();i++)
															{
																if ((airport_athens.WL_ForLondon[i].getPassenger_Seat()==1) && (airport_athens.plane[0].getMax_vip()<1) && ((airport_athens.plane[0].getWeight()+airport_athens.WL_ForLondon[i].getPassenger_Weight())<=100))
																{airport_athens.plane[0].passengers.push_back(airport_athens.WL_ForLondon[i]);
																                    airport_athens.plane[0].setPlane_weight(airport_athens.WL_ForLondon[i].getPassenger_Weight());
																					airport_athens.WL_ForLondon.erase(airport_athens.WL_ForLondon.begin()+i);
																                    airport_athens.plane[0].setMax_vip(1);
																				   	i--;
																}
																 else if ((airport_athens.WL_ForLondon[i].getPassenger_Seat()==2) && (airport_athens.plane[0].getMax_commercial()<4) && ((airport_athens.plane[0].getWeight()+airport_athens.WL_ForLondon[i].getPassenger_Weight())<=100))
																{airport_athens.plane[0].passengers.push_back(airport_athens.WL_ForLondon[i]);
																                   airport_athens.plane[0].setPlane_weight(airport_athens.WL_ForLondon[i].getPassenger_Weight());
																                 	airport_athens.WL_ForLondon.erase(airport_athens.WL_ForLondon.begin()+i);
																                 	airport_athens.plane[0].setMax_commercial(1);
																					i--;
																}
																 else if ((airport_athens.WL_ForLondon[i].getPassenger_Seat()==3) && (airport_athens.plane[0].getMax_economy()<2)&& ((airport_athens.plane[0].getWeight()+airport_athens.WL_ForLondon[i].getPassenger_Weight())<=100))
																{airport_athens.plane[0].passengers.push_back(airport_athens.WL_ForLondon[i]) ;
																                        airport_athens.plane[0].setPlane_weight(airport_athens.WL_ForLondon[i].getPassenger_Weight());
																                    	airport_athens.WL_ForLondon.erase(airport_athens.WL_ForLondon.begin()+i);
																						airport_athens.plane[0].setMax_economy(1);
																						i--;
																}
															}
																	temp=airport_london.plane[0];
													                airport_london.plane[0] = airport_athens.plane[0];
													                airport_athens.plane[0] = temp;
								airport_athens.plane[0].setPlane_Type(1);
								airport_london.plane[0].setPlane_Type(1);
								airport_athens.plane[0].passengers.clear();
								airport_london.plane[0].passengers.clear();
									//mhdenise to aeroplano
								airport_athens.plane[0].setMax_vip(-airport_athens.plane[0].getMax_vip());
								airport_athens.plane[0].setMax_commercial(-airport_athens.plane[0].getMax_commercial());
								airport_athens.plane[0].setMax_economy(-airport_athens.plane[0].getMax_economy());
								airport_athens.plane[0].setPlane_weight(-airport_athens.plane[0].getWeight());
								//mhdenise to aeroplano
								airport_london.plane[0].setMax_vip(-airport_london.plane[0].getMax_vip());
								airport_london.plane[0].setMax_commercial(-airport_london.plane[0].getMax_commercial());
								airport_london.plane[0].setMax_economy(-airport_london.plane[0].getMax_economy());
								airport_london.plane[0].setPlane_weight(-airport_london.plane[0].getWeight());
											system ("Pause");

											}
									}


									//periptwsh apo london se paris
								if ((counterP1>=1) && (counterP2>=4) && (counterP3>=2))
										{airport_london.plane[0].setPlane_destination(3);
										for (int i=0;i<	airport_london.WL_ForParis.size();i++)
											{
												if ((airport_london.WL_ForParis[i].getPassenger_Seat()==1) && (airport_london.plane[0].getMax_vip()<1) && ((airport_london.plane[0].getWeight()+airport_london.WL_ForParis[i].getPassenger_Weight())<=100))
												{airport_london.plane[0].passengers.push_back(airport_athens.WL_ForParis[i]);
												                    airport_london.plane[0].setPlane_weight(airport_london.WL_ForParis[i].getPassenger_Weight());
																	airport_london.WL_ForParis.erase(airport_london.WL_ForParis.begin()+i);
												                    airport_london.plane[0].setMax_vip(1);
																   	i--;
												}
												 else if ((airport_london.WL_ForParis[i].getPassenger_Seat()==2) && (airport_london.plane[0].getMax_commercial()<4) && ((airport_london.plane[0].getWeight()+airport_london.WL_ForParis[i].getPassenger_Weight())<=100))
												{airport_athens.plane[0].passengers.push_back(airport_london.WL_ForParis[i]);
												                   airport_london.plane[0].setPlane_weight(airport_london.WL_ForParis[i].getPassenger_Weight());
												                 	airport_london.WL_ForParis.erase(airport_london.WL_ForParis.begin()+i);
												                 	airport_london.plane[0].setMax_commercial(1);
																	i--;
												}
												 else if ((airport_london.WL_ForParis[i].getPassenger_Seat()==3) && (airport_london.plane[0].getMax_economy()<2)&& ((airport_london.plane[0].getWeight()+airport_london.WL_ForParis[i].getPassenger_Weight())<=100))
												{airport_london.plane[0].passengers.push_back(airport_london.WL_ForParis[i]) ;
												                        airport_london.plane[0].setPlane_weight(airport_london.WL_ForParis[i].getPassenger_Weight());
												                    	airport_london.WL_ForParis.erase(airport_london.WL_ForParis.begin()+i);
																		airport_london.plane[0].setMax_economy(1);
																		i--;
												}
											}
										if (airport_london.plane[0].getWeight()<=70)
											{cout<<"Thes na allakseis se charter? (y/n)";
											cin>>erwthsh;
											if (erwthsh=='y')
											{airport_london.plane[0].setPlane_Type(2);
											}
													else if (erwthsh=='n')
													// an oxi peta
													{
														for (int i=0;i<	airport_paris.WL_ForLondon.size();i++)
															{
																if ((airport_paris.WL_ForLondon[i].getPassenger_Seat()==1) && (airport_paris.plane[0].getMax_vip()<1) && ((airport_paris.plane[0].getWeight()+airport_paris.WL_ForLondon[i].getPassenger_Weight())<=100))
																{airport_paris.plane[0].passengers.push_back(airport_paris.WL_ForLondon[i]);
																                    airport_paris.plane[0].setPlane_weight(airport_paris.WL_ForLondon[i].getPassenger_Weight());
																					airport_paris.WL_ForLondon.erase(airport_paris.WL_ForLondon.begin()+i);
																                    airport_paris.plane[0].setMax_vip(1);
																				   	i--;
																}
																 else if ((airport_paris.WL_ForLondon[i].getPassenger_Seat()==2) && (airport_paris.plane[0].getMax_commercial()<4) && ((airport_paris.plane[0].getWeight()+airport_paris.WL_ForLondon[i].getPassenger_Weight())<=100))
																{airport_paris.plane[0].passengers.push_back(airport_paris.WL_ForLondon[i]);
																                   airport_paris.plane[0].setPlane_weight(airport_paris.WL_ForLondon[i].getPassenger_Weight());
																                 	airport_paris.WL_ForLondon.erase(airport_paris.WL_ForLondon.begin()+i);
																                 	airport_paris.plane[0].setMax_commercial(1);
																					i--;
																}
																 else if ((airport_paris.WL_ForLondon[i].getPassenger_Seat()==3) && (airport_paris.plane[0].getMax_economy()<2)&& ((airport_paris.plane[0].getWeight()+airport_paris.WL_ForLondon[i].getPassenger_Weight())<=100))
																{airport_paris.plane[0].passengers.push_back(airport_paris.WL_ForLondon[i]) ;
																                        airport_paris.plane[0].setPlane_weight(airport_paris.WL_ForLondon[i].getPassenger_Weight());
																                    	airport_paris.WL_ForLondon.erase(airport_paris.WL_ForLondon.begin()+i);
																						airport_paris.plane[0].setMax_economy(1);
																						i--;
																}
															}
																	temp=airport_paris.plane[0];
													                airport_paris.plane[0] = airport_london.plane[0];
													                airport_london.plane[0] = temp;
								airport_paris.plane[0].setPlane_Type(1);
								airport_london.plane[0].setPlane_Type(1);
								airport_paris.plane[0].passengers.clear();
								airport_london.plane[0].passengers.clear();
								  	//mhdenise to aeroplano
								airport_paris.plane[0].setMax_vip(-airport_paris.plane[0].getMax_vip());
								airport_paris.plane[0].setMax_commercial(-airport_paris.plane[0].getMax_commercial());
								airport_paris.plane[0].setMax_economy(-airport_paris.plane[0].getMax_economy());
								airport_paris.plane[0].setPlane_weight(-airport_paris.plane[0].getWeight());
								//mhdenise to aeroplano
								airport_london.plane[0].setMax_vip(-airport_london.plane[0].getMax_vip());
								airport_london.plane[0].setMax_commercial(-airport_london.plane[0].getMax_commercial());
								airport_london.plane[0].setMax_economy(-airport_london.plane[0].getMax_economy());
								airport_london.plane[0].setPlane_weight(-airport_london.plane[0].getWeight());
											system ("Pause");
													}
											}
											else
											{for (int i=0;i<airport_paris.WL_ForLondon.size();i++)
															{
																if ((airport_paris.WL_ForLondon[i].getPassenger_Seat()==1) && (airport_paris.plane[0].getMax_vip()<1) && ((airport_paris.plane[0].getWeight()+airport_paris.WL_ForLondon[i].getPassenger_Weight())<=100))
																{airport_paris.plane[0].passengers.push_back(airport_paris.WL_ForLondon[i]);
																                    airport_paris.plane[0].setPlane_weight(airport_paris.WL_ForLondon[i].getPassenger_Weight());
																					airport_paris.WL_ForLondon.erase(airport_paris.WL_ForLondon.begin()+i);
																                    airport_paris.plane[0].setMax_vip(1);
																				   	i--;
																}
																 else if ((airport_paris.WL_ForLondon[i].getPassenger_Seat()==2) && (airport_paris.plane[0].getMax_commercial()<4) && ((airport_paris.plane[0].getWeight()+airport_paris.WL_ForLondon[i].getPassenger_Weight())<=100))
																{airport_paris.plane[0].passengers.push_back(airport_paris.WL_ForLondon[i]);
																                   airport_paris.plane[0].setPlane_weight(airport_paris.WL_ForLondon[i].getPassenger_Weight());
																                 	airport_paris.WL_ForLondon.erase(airport_paris.WL_ForLondon.begin()+i);
																                 	airport_paris.plane[0].setMax_commercial(1);
																					i--;
																}
																 else if ((airport_paris.WL_ForLondon[i].getPassenger_Seat()==3) && (airport_paris.plane[0].getMax_economy()<2)&& ((airport_paris.plane[0].getWeight()+airport_paris.WL_ForLondon[i].getPassenger_Weight())<=100))
																{airport_paris.plane[0].passengers.push_back(airport_paris.WL_ForLondon[i]) ;
																                        airport_paris.plane[0].setPlane_weight(airport_paris.WL_ForLondon[i].getPassenger_Weight());
																                    	airport_paris.WL_ForLondon.erase(airport_paris.WL_ForLondon.begin()+i);
																						airport_paris.plane[0].setMax_economy(1);
																						i--;
																}
															}
																	temp=airport_london.plane[0];
													                airport_london.plane[0] = airport_paris.plane[0];
													                airport_paris.plane[0] = temp;
								airport_paris.plane[0].setPlane_Type(1);
								airport_london.plane[0].setPlane_Type(1);
								airport_paris.plane[0].passengers.clear();
								airport_london.plane[0].passengers.clear();
								//mhdenise to aeroplano
								airport_paris.plane[0].setMax_vip(-airport_paris.plane[0].getMax_vip());
								airport_paris.plane[0].setMax_commercial(-airport_paris.plane[0].getMax_commercial());
								airport_paris.plane[0].setMax_economy(-airport_paris.plane[0].getMax_economy());
								airport_paris.plane[0].setPlane_weight(-airport_paris.plane[0].getWeight());
								//mhdenise to aeroplano
								airport_london.plane[0].setMax_vip(-airport_london.plane[0].getMax_vip());
								airport_london.plane[0].setMax_commercial(-airport_london.plane[0].getMax_commercial());
								airport_london.plane[0].setMax_economy(-airport_london.plane[0].getMax_economy());
								airport_london.plane[0].setPlane_weight(-airport_london.plane[0].getWeight());
											system ("Pause");
											}

										}
								}
								else if (airport_london.plane[0].getPlane_Type()==2)
								{
									if ((counterL3>=2) && (airport_london.plane[0].getPlane_Destination()==1))
									{
									for (int i=0;i<airport_london.WL_ForAthens.size();i++)
									{if ((airport_london.WL_ForAthens[i].getPassenger_Seat()==3) && (airport_london.plane[0].getMax_economy()<2)&& ((airport_london.plane[0].getWeight()+airport_london.WL_ForAthens[i].getPassenger_Weight())<=70))
											{airport_london.plane[0].passengers.push_back(airport_london.WL_ForAthens[i]) ;
																                        airport_london.plane[0].setPlane_weight(airport_london.WL_ForAthens[i].getPassenger_Weight());
																                    	airport_london.WL_ForAthens.erase(airport_london.WL_ForAthens.begin()+i);
																						airport_london.plane[0].setMax_economy(1);
																						i--;
											}

									}
									for (int i=0;i<	airport_athens.WL_ForLondon.size();i++)
															{
																if ((airport_athens.WL_ForLondon[i].getPassenger_Seat()==1) && (airport_athens.plane[0].getMax_vip()<1) && ((airport_athens.plane[0].getWeight()+airport_athens.WL_ForLondon[i].getPassenger_Weight())<=100))
																{airport_athens.plane[0].passengers.push_back(airport_athens.WL_ForLondon[i]);
																                    airport_athens.plane[0].setPlane_weight(airport_athens.WL_ForLondon[i].getPassenger_Weight());
																					airport_athens.WL_ForLondon.erase(airport_athens.WL_ForLondon.begin()+i);
																                    airport_athens.plane[0].setMax_vip(1);
																				   	i--;
																}
																 else if ((airport_athens.WL_ForLondon[i].getPassenger_Seat()==2) && (airport_athens.plane[0].getMax_commercial()<4) && ((airport_athens.plane[0].getWeight()+airport_athens.WL_ForLondon[i].getPassenger_Weight())<=100))
																{airport_athens.plane[0].passengers.push_back(airport_athens.WL_ForLondon[i]);
																                   airport_athens.plane[0].setPlane_weight(airport_athens.WL_ForLondon[i].getPassenger_Weight());
																                 	airport_athens.WL_ForLondon.erase(airport_athens.WL_ForLondon.begin()+i);
																                 	airport_athens.plane[0].setMax_commercial(1);
																					i--;
																}
																 else if ((airport_athens.WL_ForLondon[i].getPassenger_Seat()==3) && (airport_athens.plane[0].getMax_economy()<2)&& ((airport_athens.plane[0].getWeight()+airport_athens.WL_ForLondon[i].getPassenger_Weight())<=100))
																{airport_athens.plane[0].passengers.push_back(airport_athens.WL_ForLondon[i]) ;
																                        airport_athens.plane[0].setPlane_weight(airport_athens.WL_ForLondon[i].getPassenger_Weight());
																                    	airport_athens.WL_ForLondon.erase(airport_athens.WL_ForLondon.begin()+i);
																						airport_athens.plane[0].setMax_economy(1);
																						i--;
																}
															}
																	temp=airport_london.plane[0];
													                airport_london.plane[0] = airport_athens.plane[0];
													                airport_athens.plane[0] = temp;
								airport_athens.plane[0].setPlane_Type(1);
								airport_london.plane[0].setPlane_Type(1);
								airport_athens.plane[0].passengers.clear();
								airport_london.plane[0].passengers.clear();
								  	//mhdenise to aeroplano
								airport_athens.plane[0].setMax_vip(-airport_athens.plane[0].getMax_vip());
								airport_athens.plane[0].setMax_commercial(-airport_athens.plane[0].getMax_commercial());
								airport_athens.plane[0].setMax_economy(-airport_athens.plane[0].getMax_economy());
								airport_athens.plane[0].setPlane_weight(-airport_athens.plane[0].getWeight());
								//mhdenise to aeroplano
								airport_london.plane[0].setMax_vip(-airport_london.plane[0].getMax_vip());
								airport_london.plane[0].setMax_commercial(-airport_london.plane[0].getMax_commercial());
								airport_london.plane[0].setMax_economy(-airport_london.plane[0].getMax_economy());
								airport_london.plane[0].setPlane_weight(-airport_london.plane[0].getWeight());
											system ("Pause");
									}

									if ((counterP3>=2) && (airport_london.plane[0].getPlane_Destination()==3))
									{
									for (int i=0;i<airport_london.WL_ForParis.size();i++)

									{if ((airport_london.WL_ForParis[i].getPassenger_Seat()==3) && (airport_london.plane[0].getMax_economy()<2)&& ((airport_london.plane[0].getWeight()+airport_london.WL_ForParis[i].getPassenger_Weight())<=70))
												{airport_london.plane[0].passengers.push_back(airport_athens.WL_ForParis[i]) ;
												                        airport_london.plane[0].setPlane_weight(airport_london.WL_ForParis[i].getPassenger_Weight());
												                    	airport_london.WL_ForParis.erase(airport_london.WL_ForParis.begin()+i);
																		airport_london.plane[0].setMax_economy(1);
																		i--;
												}
									}

									for (int i=0;i<	airport_paris.WL_ForLondon.size();i++)
															{
																if ((airport_paris.WL_ForLondon[i].getPassenger_Seat()==1) && (airport_paris.plane[0].getMax_vip()<1) && ((airport_paris.plane[0].getWeight()+airport_paris.WL_ForLondon[i].getPassenger_Weight())<=100))
																{airport_paris.plane[0].passengers.push_back(airport_paris.WL_ForLondon[i]);
																                    airport_paris.plane[0].setPlane_weight(airport_paris.WL_ForLondon[i].getPassenger_Weight());
																					airport_paris.WL_ForLondon.erase(airport_paris.WL_ForLondon.begin()+i);
																                    airport_paris.plane[0].setMax_vip(1);
																				   	i--;
																}
																 else if ((airport_paris.WL_ForLondon[i].getPassenger_Seat()==2) && (airport_paris.plane[0].getMax_commercial()<4) && ((airport_paris.plane[0].getWeight()+airport_paris.WL_ForLondon[i].getPassenger_Weight())<=100))
																{airport_paris.plane[0].passengers.push_back(airport_paris.WL_ForLondon[i]);
																                   airport_paris.plane[0].setPlane_weight(airport_paris.WL_ForLondon[i].getPassenger_Weight());
																                 	airport_paris.WL_ForLondon.erase(airport_paris.WL_ForLondon.begin()+i);
																                 	airport_paris.plane[0].setMax_commercial(1);
																					i--;
																}
																 else if ((airport_paris.WL_ForLondon[i].getPassenger_Seat()==3) && (airport_paris.plane[0].getMax_economy()<2)&& ((airport_paris.plane[0].getWeight()+airport_paris.WL_ForLondon[i].getPassenger_Weight())<=100))
																{airport_paris.plane[0].passengers.push_back(airport_paris.WL_ForLondon[i]) ;
																                        airport_paris.plane[0].setPlane_weight(airport_paris.WL_ForLondon[i].getPassenger_Weight());
																                    	airport_paris.WL_ForLondon.erase(airport_paris.WL_ForLondon.begin()+i);
																						airport_paris.plane[0].setMax_economy(1);
																						i--;
																}
															}
																	temp=airport_london.plane[0];
													                airport_london.plane[0] = airport_paris.plane[0];
													                airport_paris.plane[0] = temp;
								airport_paris.plane[0].setPlane_Type(1);
								airport_london.plane[0].setPlane_Type(1);
								airport_paris.plane[0].passengers.clear();
								airport_london.plane[0].passengers.clear();
								//mhdenise to aeroplano
								airport_paris.plane[0].setMax_vip(-airport_paris.plane[0].getMax_vip());
								airport_paris.plane[0].setMax_commercial(-airport_paris.plane[0].getMax_commercial());
								airport_paris.plane[0].setMax_economy(-airport_paris.plane[0].getMax_economy());
								airport_paris.plane[0].setPlane_weight(-airport_paris.plane[0].getWeight());
								//mhdenise to aeroplano
								airport_london.plane[0].setMax_vip(-airport_london.plane[0].getMax_vip());
								airport_london.plane[0].setMax_commercial(-airport_london.plane[0].getMax_commercial());
								airport_london.plane[0].setMax_economy(-airport_london.plane[0].getMax_economy());
								airport_london.plane[0].setPlane_weight(-airport_london.plane[0].getWeight());
											system ("Pause");
									//peta
						}
					}
		 	} 			while (choice3!='0');
			break;	
		case '3':
				do{
				system("CLS");
					cout<<"You are currently at the Paris Airport.\n";
				     cout<<"Press 1 to Show our Current planes:\n";
				     cout<<"Press 2 to Make a new plane:\n";
				     cout<<"Press 3 to Show the passengers waiting at this airport:\n";
				     cout<<"Press 4 to Add a new passenger:\n";
				     cout<<"Press 0 to Exit\n";
				     cout<<"Please give your choice:";
			     cin>>choice4;
			     switch (choice4)
			       {case '1':system("CLS");
                	 cout<<"Our Planes at this moment :\n";
                 	for (int i=0;i<airport_paris.plane.size();++i)
                    {
					cout<<i<<")"<<airport_paris.plane[i].getPlane_Name()<<"          ";
                    if (airport_paris.plane[i].getPlane_Type()==1)
					cout<<"Plane Type:Regular" <<"       ";
                    else
                    cout<<"Plane Type:Charter"<<"       ";
				    if (airport_paris.plane[i].getPlane_Destination()==1)
				    cout<<"Destination:Athens"<<"           ";
				    else if (airport_paris.plane[i].getPlane_Destination()==2)
				    cout<<"Destination:London"<<"          ";
				    else 
				    cout<<"Destination:Paris"<<"           ";
				if (airport_paris.plane[i].getPlane_Location()==1)
				    cout<<"Location:Athens"<<"           ";
				    else if (airport_paris.plane[i].getPlane_Location()==2)
				    cout<<"Location:London"<<"          ";
				    else 
				    cout<<"Location:Paris"<<"           ";
				    cout<<"Pilot Name:"<<airport_paris.plane[i].getPilot_Name()<<"     "<<endl;}
				    system("pause");
                    break;
     	case '2':system("CLS");
 						cout<<"You have "<<airport_paris.plane.size()<<"planes at this airport!";
							cout<<"Please give the name of the plane:";
			                cin >> pname;
			            if ((PlaneNameCheck(airport_paris.plane,pname)<0) && (PlaneNameCheck(airport_london.plane,pname)<0) && (PlaneNameCheck(airport_athens.plane,pname)<0))
			                {	
							cout<<"Please give Pilot name";
			                cin >> pilotname;
			                
						if (airport_paris.WL_ForAthens.size()>airport_paris.WL_ForLondon.size())
			              	{ airport_paris.plane.push_back(Plane(pname,1,pilotname,plocP,1));}
						else
			              	{airport_paris.plane.push_back(Plane(pname,1,pilotname,plocP,2));}
			                }
						else
			                {cout<<"Plane name already exists!";}
			                system("Pause");
		                	break;
        case '3':system("CLS");
        					cout<<"Our passengers at this moment :\n";
			            if (airport_paris.WL_ForAthens.size()>0)
							{cout<<"Passengers waiting for Athens:"<<airport_paris.WL_ForAthens.size()<<"\n";
						for (int i=0;i< airport_paris.WL_ForAthens.size();++i)
			                {
							cout<<endl;
							cout<<"Passenger Name :"<<airport_paris.WL_ForAthens[i].getPassenger_Name()<<"|     |";
			                 if(airport_paris.WL_ForAthens[i].getPassenger_Seat()==1)
			                cout<<"Seat:VIP "<<"|     |";
			                else if (airport_paris.WL_ForAthens[i].getPassenger_Seat()==2)
			                cout<<"Seat:Commercial"<<"|     |";
			                else cout<<"Seat:Economy"<<"|     |";
							if (airport_paris.WL_ForAthens[i].getPassenger_Destination()==1)
							cout<<"Destination:Athens"<<"|     |";
							cout<<"Weight :"<<airport_paris.WL_ForAthens[i].getPassenger_Weight()<<"|     "<<endl;
							}
							}
						if (airport_paris.WL_ForLondon.size()>0)
							{cout<<"\nPassengers waiting for London:"<<airport_paris.WL_ForLondon.size()<<"\n";
							cout<<"================================================================================"<<endl;
							for (int i=0;i< airport_paris.WL_ForLondon.size();++i)
			                {
							cout<<endl;
							cout<<"Passenger Name :"<<airport_paris.WL_ForLondon[i].getPassenger_Name()<<"|     |"<<endl;
			                 if(airport_paris.WL_ForLondon[i].getPassenger_Seat()==1)
			                cout<<"Seat:VIP "<<"|     |";
			                else if (airport_paris.WL_ForLondon[i].getPassenger_Seat()==2)
			                cout<<"Seat:Commercial"<<"|     |";
			                else cout<<"Seat:Economy"<<"|     |";
							if (airport_paris.WL_ForLondon[i].getPassenger_Destination()==2)
							cout<<"Destination:London"<<"|     |";
							cout<<"Weight :"<<airport_paris.WL_ForLondon[i].getPassenger_Weight()<<"|     |"<<endl;
							}
							}
			            system("Pause");
			            break;
        case '4':system("CLS");
        				cout<<"Please give the Passenger's name:";
			            cin >> name;
						cout<<"Please give the seat of the Passenger: 1 vip,2 regular,3 economy:\n";
						cin >> seat;
						cout<<"Please give the Weight of the passengers's baggage:";
			            cin >> weight;
			            cout<<"Please give the destination:1 For Athens,2 London:";
			            cin >> dest;
			           	if (dest=1)
				            {airport_paris.WL_ForAthens.push_back(Passenger(name,seat,dest,weight));}
							else if(dest=2)
							{airport_paris.WL_ForLondon.push_back(Passenger(name,seat,dest,weight));}
			                 system("PAUSE");
			            break; 
			        		case'0':break; 
			        		default :cout<<"Not a valid option!!!";system("pause");}
					
								CounterReset(counterP1,counterP2,counterP3);
							for (int i=0;i<airport_paris.WL_ForLondon.size();++i)
								{
								if (airport_paris.WL_ForLondon[i].getPassenger_Seat()==1)
								{counterP1+=1;}

								else if (airport_paris.WL_ForLondon[i].getPassenger_Seat()==2)
								{counterP2+=1;}

								else if (airport_paris.WL_ForLondon[i].getPassenger_Seat()==3)
								{counterP3+=1;}
								}
								//kane reset tous counters
								CounterReset(counterL1,counterL2,counterL3);
								for (int i=0;i<airport_paris.WL_ForAthens.size();++i)
								{
								if (airport_paris.WL_ForAthens[i].getPassenger_Seat()==1)
								{counterL1+=1;}

								if (airport_paris.WL_ForAthens[i].getPassenger_Seat()==2)
								{counterL2+=1;}

								if (airport_paris.WL_ForAthens[i].getPassenger_Seat()==3)
								{counterL3+=1;}
								}


								if (airport_paris.plane[0].getPlane_Type()==1)
								{	//periptwsh athens
									if ((counterL1>=1) && (counterL2>=4) && (counterL3>=2))
									{airport_paris.plane[0].setPlane_destination(1);
										for (int i=0;i<	airport_paris.WL_ForAthens.size();i++)
											{
												if ((airport_paris.WL_ForAthens[i].getPassenger_Seat()==1) && (airport_paris.plane[0].getMax_vip()<1) && ((airport_paris.plane[0].getWeight()+airport_paris.WL_ForAthens[i].getPassenger_Weight())<=100))
												{airport_paris.plane[0].passengers.push_back(airport_paris.WL_ForAthens[i]);
												                    airport_paris.plane[0].setPlane_weight(airport_paris.WL_ForAthens[i].getPassenger_Weight());
																	airport_paris.WL_ForAthens.erase(airport_paris.WL_ForAthens.begin()+i);
												                    airport_paris.plane[0].setMax_vip(1);
																   	i--;
												}
												 else if ((airport_paris.WL_ForAthens[i].getPassenger_Seat()==2) && (airport_paris.plane[0].getMax_commercial()<4) && ((airport_paris.plane[0].getWeight()+airport_paris.WL_ForAthens[i].getPassenger_Weight())<=100))
												{airport_paris.plane[0].passengers.push_back(airport_paris.WL_ForAthens[i]);
												                   airport_paris.plane[0].setPlane_weight(airport_paris.WL_ForAthens[i].getPassenger_Weight());
												                 	airport_paris.WL_ForAthens.erase(airport_paris.WL_ForAthens.begin()+i);
												                 	airport_paris.plane[0].setMax_commercial(1);
																	i--;
												}
												 else if ((airport_paris.WL_ForAthens[i].getPassenger_Seat()==3) && (airport_paris.plane[0].getMax_economy()<2)&& ((airport_paris.plane[0].getWeight()+airport_paris.WL_ForAthens[i].getPassenger_Weight())<=100))
												{airport_paris.plane[0].passengers.push_back(airport_paris.WL_ForAthens[i]) ;
												                        airport_paris.plane[0].setPlane_weight(airport_paris.WL_ForAthens[i].getPassenger_Weight());
												                    	airport_paris.WL_ForAthens.erase(airport_paris.WL_ForAthens.begin()+i);
																		airport_paris.plane[0].setMax_economy(1);
																		i--;
												}
											}

										if (airport_paris.plane[0].getWeight()<=70)
											{cout<<"Thes na allakseis se charter?(y/n)";
											cin>>erwthsh;
											if (erwthsh=='y')
											{airport_paris.plane[0].setPlane_Type(2);
											}
											else if (erwthsh=='n')
													// an oxi
													{
														for (int i=0;i<	airport_athens.WL_ForParis.size();i++)
															{
																if ((airport_athens.WL_ForParis[i].getPassenger_Seat()==1) && (airport_athens.plane[0].getMax_vip()<2) && ((airport_athens.plane[0].getWeight()+airport_athens.WL_ForParis[i].getPassenger_Weight())<=100))
																{airport_athens.plane[0].passengers.push_back(airport_athens.WL_ForParis[i]);
																                    airport_athens.plane[0].setPlane_weight(airport_athens.WL_ForParis[i].getPassenger_Weight());
																					airport_athens.WL_ForParis.erase(airport_athens.WL_ForParis.begin()+i);
																                    airport_athens.plane[0].setMax_vip(1);
																				   	i--;
																}
																 else if ((airport_athens.WL_ForParis[i].getPassenger_Seat()==2) && (airport_athens.plane[0].getMax_commercial()<3) && ((airport_athens.plane[0].getWeight()+airport_athens.WL_ForParis[i].getPassenger_Weight())<=100))
																{airport_athens.plane[0].passengers.push_back(airport_athens.WL_ForParis[i]);
																                   airport_athens.plane[0].setPlane_weight(airport_athens.WL_ForParis[i].getPassenger_Weight());
																                 	airport_athens.WL_ForParis.erase(airport_athens.WL_ForParis.begin()+i);
																                 	airport_athens.plane[0].setMax_commercial(1);
																					i--;
																}
																 else if ((airport_athens.WL_ForParis[i].getPassenger_Seat()==3) && (airport_athens.plane[0].getMax_economy()<3)&& ((airport_athens.plane[0].getWeight()+airport_athens.WL_ForParis[i].getPassenger_Weight())<=100))
																{airport_athens.plane[0].passengers.push_back(airport_athens.WL_ForParis[i]) ;
																                        airport_athens.plane[0].setPlane_weight(airport_athens.WL_ForParis[i].getPassenger_Weight());
																                    	airport_athens.WL_ForParis.erase(airport_athens.WL_ForParis.begin()+i);
																						airport_athens.plane[0].setMax_economy(1);
																						i--;
																}
															}

																	temp=airport_paris.plane[0];
													                airport_paris.plane[0] = airport_athens.plane[0];
													                airport_athens.plane[0] = temp;
								airport_athens.plane[0].setPlane_Type(1);
							  	airport_paris.plane[0].setPlane_Type(1);
								airport_athens.plane[0].passengers.clear();
								airport_paris.plane[0].passengers.clear();
								//mhdenise to aeroplano
								airport_athens.plane[0].setMax_vip(-airport_athens.plane[0].getMax_vip());
								airport_athens.plane[0].setMax_commercial(-airport_athens.plane[0].getMax_commercial());
								airport_athens.plane[0].setMax_economy(-airport_athens.plane[0].getMax_economy());
								airport_athens.plane[0].setPlane_weight(-airport_athens.plane[0].getWeight());
								//mhdenise to aeroplano
								airport_paris.plane[0].setMax_vip(-airport_paris.plane[0].getMax_vip());
								airport_paris.plane[0].setMax_commercial(-airport_paris.plane[0].getMax_commercial());
								airport_paris.plane[0].setMax_economy(-airport_paris.plane[0].getMax_economy());
								airport_paris.plane[0].setPlane_weight(-airport_paris.plane[0].getWeight());
											system ("Pause");
													}
											}

											else
											{	for (int i=0;i<	airport_athens.WL_ForParis.size();i++)
															{
																if ((airport_athens.WL_ForParis[i].getPassenger_Seat()==1) && (airport_athens.plane[0].getMax_vip()<1) && ((airport_athens.plane[0].getWeight()+airport_athens.WL_ForParis[i].getPassenger_Weight())<=100))
																{airport_athens.plane[0].passengers.push_back(airport_athens.WL_ForParis[i]);
																                    airport_athens.plane[0].setPlane_weight(airport_athens.WL_ForParis[i].getPassenger_Weight());
																					airport_athens.WL_ForParis.erase(airport_athens.WL_ForParis.begin()+i);
																                    airport_athens.plane[0].setMax_vip(1);
																				   	i--;
																}
																 else if ((airport_athens.WL_ForParis[i].getPassenger_Seat()==2) && (airport_athens.plane[0].getMax_commercial()<4) && ((airport_athens.plane[0].getWeight()+airport_athens.WL_ForParis[i].getPassenger_Weight())<=100))
																{airport_athens.plane[0].passengers.push_back(airport_athens.WL_ForParis[i]);
																                   airport_athens.plane[0].setPlane_weight(airport_athens.WL_ForParis[i].getPassenger_Weight());
																                 	airport_athens.WL_ForParis.erase(airport_athens.WL_ForParis.begin()+i);
																                 	airport_athens.plane[0].setMax_commercial(1);
																					i--;
																}
																 else if ((airport_athens.WL_ForParis[i].getPassenger_Seat()==3) && (airport_athens.plane[0].getMax_economy()<2)&& ((airport_athens.plane[0].getWeight()+airport_athens.WL_ForParis[i].getPassenger_Weight())<=100))
																{airport_athens.plane[0].passengers.push_back(airport_athens.WL_ForParis[i]) ;
																                        airport_athens.plane[0].setPlane_weight(airport_athens.WL_ForParis[i].getPassenger_Weight());
																                    	airport_athens.WL_ForParis.erase(airport_athens.WL_ForParis.begin()+i);
																						airport_athens.plane[0].setMax_economy(1);
																						i--;
																}
															}
																	temp=airport_paris.plane[0];
													                airport_paris.plane[0] = airport_athens.plane[0];
													                airport_athens.plane[0] = temp;
								airport_athens.plane[0].setPlane_Type(1);
							  	airport_paris.plane[0].setPlane_Type(1);
								airport_athens.plane[0].passengers.clear();
								airport_paris.plane[0].passengers.clear();
								//mhdenise to aeroplano
								airport_athens.plane[0].setMax_vip(-airport_athens.plane[0].getMax_vip());
								airport_athens.plane[0].setMax_commercial(-airport_athens.plane[0].getMax_commercial());
								airport_athens.plane[0].setMax_economy(-airport_athens.plane[0].getMax_economy());
								airport_athens.plane[0].setPlane_weight(-airport_athens.plane[0].getWeight());
								//mhdenise to aeroplano
								airport_paris.plane[0].setMax_vip(-airport_paris.plane[0].getMax_vip());
								airport_paris.plane[0].setMax_commercial(-airport_paris.plane[0].getMax_commercial());
								airport_paris.plane[0].setMax_economy(-airport_paris.plane[0].getMax_economy());
								airport_paris.plane[0].setPlane_weight(-airport_paris.plane[0].getWeight());
											system ("Pause");
							}
						}
									//periptwsh apo paris se london
								if ((counterP1>=1) && (counterP2>=4) && (counterP3>=2))
										{airport_paris.plane[0].setPlane_destination(2);
										for (int i=0;i<	airport_paris.WL_ForLondon.size();i++)
											{
												if ((airport_paris.WL_ForLondon[i].getPassenger_Seat()==1) && (airport_paris.plane[0].getMax_vip()<1) && ((airport_paris.plane[0].getWeight()+airport_paris.WL_ForLondon[i].getPassenger_Weight())<=100))
												{airport_paris.plane[0].passengers.push_back(airport_athens.WL_ForLondon[i]);
												                    airport_paris.plane[0].setPlane_weight(airport_paris.WL_ForLondon[i].getPassenger_Weight());
																	airport_paris.WL_ForLondon.erase(airport_paris.WL_ForLondon.begin()+i);
												                    airport_paris.plane[0].setMax_vip(1);
																   	i--;
												}
												 else if ((airport_paris.WL_ForLondon[i].getPassenger_Seat()==2) && (airport_paris.plane[0].getMax_commercial()<4) && ((airport_paris.plane[0].getWeight()+airport_paris.WL_ForLondon[i].getPassenger_Weight())<=100))
												{airport_paris.plane[0].passengers.push_back(airport_paris.WL_ForLondon[i]);
												                   airport_paris.plane[0].setPlane_weight(airport_paris.WL_ForLondon[i].getPassenger_Weight());
												                 	airport_paris.WL_ForLondon.erase(airport_paris.WL_ForLondon.begin()+i);
												                 	airport_paris.plane[0].setMax_commercial(1);
																	i--;
												}
												 else if ((airport_paris.WL_ForLondon[i].getPassenger_Seat()==3) && (airport_paris.plane[0].getMax_economy()<2)&& ((airport_paris.plane[0].getWeight()+airport_paris.WL_ForLondon[i].getPassenger_Weight())<=100))
												{airport_paris.plane[0].passengers.push_back(airport_paris.WL_ForLondon[i]) ;
												                        airport_paris.plane[0].setPlane_weight(airport_paris.WL_ForLondon[i].getPassenger_Weight());
												                    	airport_paris.WL_ForLondon.erase(airport_paris.WL_ForLondon.begin()+i);
																		airport_paris.plane[0].setMax_economy(1);
																		i--;
												}
											}
										if (airport_paris.plane[0].getWeight()<=70)
											{cout<<"Thes na allakseis se charter? (y/n)";
											cin>>erwthsh;
											if (erwthsh=='y')
											{airport_paris.plane[0].setPlane_Type(2);
											}
							else if (erwthsh=='n')
													// an oxi peta
								{
										for (int i=0;i<	airport_london.WL_ForParis.size();i++)
											{
												if ((airport_london.WL_ForParis[i].getPassenger_Seat()==1) && (airport_london.plane[0].getMax_vip()<2) && ((airport_london.plane[0].getWeight()+airport_london.WL_ForParis[i].getPassenger_Weight())<=100))
												{airport_london.plane[0].passengers.push_back(airport_london.WL_ForParis[i]);
												                    airport_london.plane[0].setPlane_weight(airport_london.WL_ForParis[i].getPassenger_Weight());
																	airport_london.WL_ForParis.erase(airport_london.WL_ForParis.begin()+i);
												                    airport_london.plane[0].setMax_vip(1);
																   	i--;
												}
												 else if ((airport_london.WL_ForParis[i].getPassenger_Seat()==2) && (airport_london.plane[0].getMax_commercial()<3) && ((airport_london.plane[0].getWeight()+airport_london.WL_ForParis[i].getPassenger_Weight())<=100))
												{airport_london.plane[0].passengers.push_back(airport_london.WL_ForParis[i]);
												                   airport_london.plane[0].setPlane_weight(airport_london.WL_ForParis[i].getPassenger_Weight());
												                 	airport_london.WL_ForParis.erase(airport_london.WL_ForParis.begin()+i);
												                 	airport_london.plane[0].setMax_commercial(1);
																	i--;
												}
												 else if ((airport_london.WL_ForParis[i].getPassenger_Seat()==3) && (airport_london.plane[0].getMax_economy()<3)&& ((airport_london.plane[0].getWeight()+airport_london.WL_ForParis[i].getPassenger_Weight())<=100))
												{airport_london.plane[0].passengers.push_back(airport_london.WL_ForParis[i]) ;
												                        airport_london.plane[0].setPlane_weight(airport_london.WL_ForParis[i].getPassenger_Weight());
												                    	airport_london.WL_ForParis.erase(airport_london.WL_ForParis.begin()+i);
																		airport_london.plane[0].setMax_economy(1);
																		i--;
												}
															}
																	temp=airport_london.plane[0];
													                airport_london.plane[0] = airport_paris.plane[0];
													                airport_paris.plane[0] = temp;
														airport_london.plane[0].setPlane_Type(1);
													  	airport_paris.plane[0].setPlane_Type(1);
														airport_london.plane[0].passengers.clear();
														airport_paris.plane[0].passengers.clear();
														//mhdenise to aeroplano
														airport_london.plane[0].setMax_vip(-airport_london.plane[0].getMax_vip());
														airport_london.plane[0].setMax_commercial(-airport_london.plane[0].getMax_commercial());
														airport_london.plane[0].setMax_economy(-airport_london.plane[0].getMax_economy());
														airport_london.plane[0].setPlane_weight(-airport_london.plane[0].getWeight());
														//mhdenise to aeroplano
														airport_paris.plane[0].setMax_vip(-airport_paris.plane[0].getMax_vip());
														airport_paris.plane[0].setMax_commercial(-airport_paris.plane[0].getMax_commercial());
														airport_paris.plane[0].setMax_economy(-airport_paris.plane[0].getMax_economy());
														airport_paris.plane[0].setPlane_weight(-airport_paris.plane[0].getWeight());
																	system ("Pause");
								
								}
											}
									else
										{for (int i=0;i<airport_london.WL_ForParis.size();i++)
										{
												if ((airport_london.WL_ForParis[i].getPassenger_Seat()==1) && (airport_london.plane[0].getMax_vip()<1) && ((airport_london.plane[0].getWeight()+airport_london.WL_ForParis[i].getPassenger_Weight())<=100))
												{airport_london.plane[0].passengers.push_back(airport_athens.WL_ForParis[i]);
												                    airport_london.plane[0].setPlane_weight(airport_london.WL_ForParis[i].getPassenger_Weight());
																	airport_london.WL_ForParis.erase(airport_london.WL_ForParis.begin()+i);
												                    airport_london.plane[0].setMax_vip(1);
																   	i--;
												}
												 else if ((airport_london.WL_ForParis[i].getPassenger_Seat()==2) && (airport_london.plane[0].getMax_commercial()<4) && ((airport_london.plane[0].getWeight()+airport_london.WL_ForParis[i].getPassenger_Weight())<=100))
												{airport_london.plane[0].passengers.push_back(airport_london.WL_ForParis[i]);
												                   airport_london.plane[0].setPlane_weight(airport_london.WL_ForParis[i].getPassenger_Weight());
												                 	airport_london.WL_ForParis.erase(airport_london.WL_ForParis.begin()+i);
												                 	airport_london.plane[0].setMax_commercial(1);
																	i--;
												}
												 else if ((airport_london.WL_ForParis[i].getPassenger_Seat()==3) && (airport_london.plane[0].getMax_economy()<2)&& ((airport_london.plane[0].getWeight()+airport_london.WL_ForParis[i].getPassenger_Weight())<=100))
												{airport_london.plane[0].passengers.push_back(airport_london.WL_ForParis[i]) ;
												                        airport_london.plane[0].setPlane_weight(airport_london.WL_ForParis[i].getPassenger_Weight());
												                    	airport_london.WL_ForParis.erase(airport_london.WL_ForParis.begin()+i);
																		airport_london.plane[0].setMax_economy(1);
																		i--;
												}
															}
																	temp=airport_paris.plane[0];
													                airport_paris.plane[0] = airport_london.plane[0];
													                airport_london.plane[0] = temp;
															airport_london.plane[0].setPlane_Type(1);
														  	airport_paris.plane[0].setPlane_Type(1);
															airport_london.plane[0].passengers.clear();
															airport_paris.plane[0].passengers.clear();
															//mhdenise to aeroplano
															airport_london.plane[0].setMax_vip(-airport_london.plane[0].getMax_vip());
															airport_london.plane[0].setMax_commercial(-airport_london.plane[0].getMax_commercial());
															airport_london.plane[0].setMax_economy(-airport_london.plane[0].getMax_economy());
															airport_london.plane[0].setPlane_weight(-airport_london.plane[0].getWeight());
															//mhdenise to aeroplano
															airport_paris.plane[0].setMax_vip(-airport_paris.plane[0].getMax_vip());
															airport_paris.plane[0].setMax_commercial(-airport_paris.plane[0].getMax_commercial());
															airport_paris.plane[0].setMax_economy(-airport_paris.plane[0].getMax_economy());
															airport_paris.plane[0].setPlane_weight(-airport_paris.plane[0].getWeight());
																		system ("Pause");
									}

								}
								}
								else if (airport_paris.plane[0].getPlane_Type()==2)
								{
									if ((counterL3>=2) && (airport_paris.plane[0].getPlane_Destination()==1))
									{
									for (int i=0;i<airport_paris.WL_ForAthens.size();i++)
									{if ((airport_paris.WL_ForAthens[i].getPassenger_Seat()==3) && (airport_paris.plane[0].getMax_economy()<2)&& ((airport_paris.plane[0].getWeight()+airport_paris.WL_ForAthens[i].getPassenger_Weight())<=70))
											{airport_paris.plane[0].passengers.push_back(airport_paris.WL_ForAthens[i]) ;
																                        airport_paris.plane[0].setPlane_weight(airport_paris.WL_ForAthens[i].getPassenger_Weight());
																                    	airport_paris.WL_ForAthens.erase(airport_paris.WL_ForAthens.begin()+i);
																						airport_paris.plane[0].setMax_economy(1);
																						i--;
											}

									}
									for (int i=0;i<	airport_athens.WL_ForParis.size();i++)
															{
																if ((airport_athens.WL_ForParis[i].getPassenger_Seat()==1) && (airport_athens.plane[0].getMax_vip()<1) && ((airport_athens.plane[0].getWeight()+airport_athens.WL_ForParis[i].getPassenger_Weight())<=100))
																{airport_athens.plane[0].passengers.push_back(airport_athens.WL_ForParis[i]);
																                    airport_athens.plane[0].setPlane_weight(airport_athens.WL_ForParis[i].getPassenger_Weight());
																					airport_athens.WL_ForParis.erase(airport_athens.WL_ForParis.begin()+i);
																                    airport_athens.plane[0].setMax_vip(1);
																				   	i--;
																}
																 else if ((airport_athens.WL_ForParis[i].getPassenger_Seat()==2) && (airport_athens.plane[0].getMax_commercial()<4) && ((airport_athens.plane[0].getWeight()+airport_athens.WL_ForParis[i].getPassenger_Weight())<=100))
																{airport_athens.plane[0].passengers.push_back(airport_athens.WL_ForParis[i]);
																                   airport_athens.plane[0].setPlane_weight(airport_athens.WL_ForParis[i].getPassenger_Weight());
																                 	airport_athens.WL_ForParis.erase(airport_athens.WL_ForParis.begin()+i);
																                 	airport_athens.plane[0].setMax_commercial(1);
																					i--;
																}
																 else if ((airport_athens.WL_ForParis[i].getPassenger_Seat()==3) && (airport_athens.plane[0].getMax_economy()<2)&& ((airport_athens.plane[0].getWeight()+airport_athens.WL_ForParis[i].getPassenger_Weight())<=100))
																{airport_athens.plane[0].passengers.push_back(airport_athens.WL_ForParis[i]) ;
																                        airport_athens.plane[0].setPlane_weight(airport_athens.WL_ForParis[i].getPassenger_Weight());
																                    	airport_athens.WL_ForParis.erase(airport_athens.WL_ForParis.begin()+i);
																						airport_athens.plane[0].setMax_economy(1);
																						i--;
																}
															}
																	temp=airport_paris.plane[0];
													                airport_paris.plane[0] = airport_athens.plane[0];
													                airport_athens.plane[0] = temp;
								airport_athens.plane[0].setPlane_Type(1);
							  	airport_paris.plane[0].setPlane_Type(1);
								airport_athens.plane[0].passengers.clear();
								airport_paris.plane[0].passengers.clear();
								//mhdenise to aeroplano
								airport_athens.plane[0].setMax_vip(-airport_athens.plane[0].getMax_vip());
								airport_athens.plane[0].setMax_commercial(-airport_athens.plane[0].getMax_commercial());
								airport_athens.plane[0].setMax_economy(-airport_athens.plane[0].getMax_economy());
								airport_athens.plane[0].setPlane_weight(-airport_athens.plane[0].getWeight());
								//mhdenise to aeroplano
								airport_paris.plane[0].setMax_vip(-airport_paris.plane[0].getMax_vip());
								airport_paris.plane[0].setMax_commercial(-airport_paris.plane[0].getMax_commercial());
								airport_paris.plane[0].setMax_economy(-airport_paris.plane[0].getMax_economy());
								airport_paris.plane[0].setPlane_weight(-airport_paris.plane[0].getWeight());
											system ("Pause");
									}

									if ((counterP3>=2) && (airport_paris.plane[0].getPlane_Destination()==2))
									{
									for (int i=0;i<airport_paris.WL_ForLondon.size();i++)

									{if ((airport_paris.WL_ForLondon[i].getPassenger_Seat()==3) && (airport_paris.plane[0].getMax_economy()<2)&& ((airport_paris.plane[0].getWeight()+airport_paris.WL_ForLondon[i].getPassenger_Weight())<=70))
												{airport_paris.plane[0].passengers.push_back(airport_athens.WL_ForLondon[i]) ;
												                        airport_paris.plane[0].setPlane_weight(airport_paris.WL_ForLondon[i].getPassenger_Weight());
												                    	airport_paris.WL_ForLondon.erase(airport_paris.WL_ForLondon.begin()+i);
																		airport_paris.plane[0].setMax_economy(1);
																		i--;
												}
									}

									for (int i=0;i<airport_london.WL_ForParis.size();i++)
											{
												if ((airport_london.WL_ForParis[i].getPassenger_Seat()==1) && (airport_london.plane[0].getMax_vip()<1) && ((airport_london.plane[0].getWeight()+airport_london.WL_ForParis[i].getPassenger_Weight())<=100))
												{airport_london.plane[0].passengers.push_back(airport_athens.WL_ForParis[i]);
												                    airport_london.plane[0].setPlane_weight(airport_london.WL_ForParis[i].getPassenger_Weight());
																	airport_london.WL_ForParis.erase(airport_london.WL_ForParis.begin()+i);
												                    airport_london.plane[0].setMax_vip(1);
																   	i--;
												}
												 else if ((airport_london.WL_ForParis[i].getPassenger_Seat()==2) && (airport_london.plane[0].getMax_commercial()<4) && ((airport_london.plane[0].getWeight()+airport_london.WL_ForParis[i].getPassenger_Weight())<=100))
												{airport_london.plane[0].passengers.push_back(airport_london.WL_ForParis[i]);
												                   airport_london.plane[0].setPlane_weight(airport_london.WL_ForParis[i].getPassenger_Weight());
												                 	airport_london.WL_ForParis.erase(airport_london.WL_ForParis.begin()+i);
												                 	airport_london.plane[0].setMax_commercial(1);
																	i--;
												}
												 else if ((airport_london.WL_ForParis[i].getPassenger_Seat()==3) && (airport_london.plane[0].getMax_economy()<2)&& ((airport_london.plane[0].getWeight()+airport_london.WL_ForParis[i].getPassenger_Weight())<=100))
												{airport_london.plane[0].passengers.push_back(airport_london.WL_ForParis[i]) ;
												                        airport_london.plane[0].setPlane_weight(airport_london.WL_ForParis[i].getPassenger_Weight());
												                    	airport_london.WL_ForParis.erase(airport_london.WL_ForParis.begin()+i);
																		airport_london.plane[0].setMax_economy(1);
																		i--;
												}
															}
																	temp=airport_paris.plane[0];
													                airport_paris.plane[0] = airport_london.plane[0];
													                airport_london.plane[0] = temp;
								airport_paris.plane[0].setPlane_Type(1);
								airport_london.plane[0].setPlane_Type(1);
								airport_paris.plane[0].passengers.clear();
								airport_london.plane[0].passengers.clear();
								//mhdenise to aeroplano
								airport_paris.plane[0].setMax_vip(-airport_paris.plane[0].getMax_vip());
								airport_paris.plane[0].setMax_commercial(-airport_paris.plane[0].getMax_commercial());
								airport_paris.plane[0].setMax_economy(-airport_paris.plane[0].getMax_economy());
								airport_paris.plane[0].setPlane_weight(-airport_paris.plane[0].getWeight());
								//mhdenise to aeroplano
								airport_london.plane[0].setMax_vip(-airport_london.plane[0].getMax_vip());
								airport_london.plane[0].setMax_commercial(-airport_london.plane[0].getMax_commercial());
								airport_london.plane[0].setMax_economy(-airport_london.plane[0].getMax_economy());
								airport_london.plane[0].setPlane_weight(-airport_london.plane[0].getWeight());
											system ("Pause");
								
									}
								}
							
		 			} while (choice4!='0');
    		break;
				
			}
		
			}while(choice2!=0);
		
    system("PAUSE");
}
