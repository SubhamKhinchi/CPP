#include<bits/stdc++.h>
using namespace std;
//Since driver have so many properties let's construct a classs for drivers that will store their info.
class DriversDetails{
	public:
		char key;
		string name;
		float rating;
		int ride;
		DriversDetails(char ch, string n, float rt, int rd){
			key =ch;
			name=n;
			rating =rt;
			ride = rd;
		}
};

//this function will return the key of driver which will be assigned for the trip. Key is a unique for each driver.
char AssignDriver(vector<DriversDetails> Drr, string str, int s){
	char ans;
	//assign driver with more then or equal to 4.8 rating to Platinum level customer.
	if(str=="Platinum"){
		for(int i=0; i<s; i++){
			if(Drr[i].rating >=4.8){			
				ans= Drr[i].key;
				break;
			}
		}		
	}
	//assign driver with more then or equal to 4.5 rating to Gold level customer.
	else if(str=="Gold"){
		for(int i=0; i<s; i++){
			if(Drr[i].rating >=4.5){			
				ans= Drr[i].key;
				break;
			}
		}
	}
	//assign driver with less then 4.5 rating to Silver level customer.
	else if(str=="Silver"){
		for(int i=0; i<s; i++){
			if(Drr[i].rating <4.5){			
				ans= Drr[i].key;
				break;
			}
		}
	}
	return ans;
}

//this will calculate the Total Fare of the trip using given parameters such as distance, travel time, rate, surge etc.
float FareAmount(float dist, float trvl_tm, float pr_km_rt, float srg_prc, float wt_tm, 
					bool rd_cncld_aftr_strt, bool rd_cncld_bfr_strt){
	
	float TotalFare =0;
	
	
	//if ride gets cancelled before starting the trip			
	if(rd_cncld_bfr_strt){
		//And the waiting time is more than 4 min, charge 50Rs cancellation charge
		if(wt_tm>4){
			TotalFare+=50.0;
			return TotalFare;
		}
		else{
			//If waiting time is less than 4 min, do not charge anything.
			return TotalFare;
		}
	}
	//when ride starts we start adding amount to TotalFare accordingly.
	//Add amount for travelled distances to Total Fare at the rate of per_km_rate
	TotalFare+=dist*pr_km_rt;
	
	//Add amount for travel time at the rate of 1Rs/min
	TotalFare+=trvl_tm*1.0;
	
	//Add surge price to total fare
	TotalFare+=srg_prc;
	
	//waiting time charges:
	// *if waiting time is more than 4 min the charge 10Rs/min
	if(wt_tm>4){
		TotalFare+=floor(wt_tm-4.0)*10.0;
	}
	
	//if ride gets cancelled after starting the trip (mid-way cancellation of a trip)
	if(rd_cncld_aftr_strt){
		//then in this condition do not charge for any extra charge and return the TotalFare
		return TotalFare;		
	}
	// if ride gets completed without any cancellation just return the TotalFare
	return TotalFare;
}

int main(){
	
	//make Driver object using constructor
	DriversDetails driver1('a',"DriverAA",4.3,10);
	DriversDetails driver2('b',"DriverBB", 0.0, 0);
	DriversDetails driver3('c',"DriverCC", 4.83, 15);
	DriversDetails driver4('d',"DriverDD", 4.8, 4);
	DriversDetails driver5('e',"DriverEE", 4.5,2);
	
	//store customer types in string vector
	vector<string> customer;
	customer.push_back("Silver");
	customer.push_back("Gold");
	customer.push_back("Platinum");
	
	//This is an vector of objects which will store our driver object in it and will make iteration easy.
	vector<DriversDetails> Arr;
	Arr.push_back(driver1);
	Arr.push_back(driver2);
	Arr.push_back(driver3);
	Arr.push_back(driver4);
	Arr.push_back(driver5);
	
	//no. of test cases to perform.
	//if we input more than 1 test cases we can see the updated rating of driver in single compilation.
	cout<<"Please enter number of test cases : ";
	int t;
	cin>>t;
	
	while(t--){
		string customertype;
		cout<<"Please enter your customer type(Silver/Gold/Platinum) : ";
		cin>>customertype;
		
		//to check we haven't input customertype other then Silver/Gold/Platinum
		if(find(customer.begin(),customer.end(),customertype)!=customer.end()){
			
			int size = Arr.size();
			
			for(int i=0; i<size; i++){
				//if drivers ride is more than 5 rides and rating is less than 4 then we will erase that driver from over vector of driver's object.
			    if(Arr[i].ride>5 && Arr[i].rating * Arr[i].ride < 20){
			        Arr.erase(Arr.begin()+i);
			    }
			}
			
			//storing assigned driver's key in S and will get drivers details as output.
			char s = AssignDriver(Arr, customertype,size);
				cout<<"Here are drivers details as follows : "<<endl;
				for(int i=0; i<size; i++){
					if(Arr[i].key==s){
						cout<<"Name : "<<Arr[i].name<<endl;
						
						if(Arr[i].ride <5){
							cout<<"Rating : "<<5<<endl;
						}
						else{
							cout<<"Rating : "<<Arr[i].rating<<endl;
						}
						cout<<"No. of Rides : "<<Arr[i].ride<<endl;
					}
				}
		
		    	float distance, travel_time, waiting_time, per_km_rate, surge_price;
		    	bool ride_cancelled_after_starting, ride_cancelled_before_starting;
		    	float base_fare = 50.0;
				int driver_rating;
		    	
		    	cout<<"Please enter travelled distance(can be decimal) in Km : ";
		    	cin>>distance;
		    	
		    	cout<<"Please enter travel time (can be decimal) in min : ";
		    	cin>>travel_time;
		    	
		    	cout<<"Please enter per km rate of ride (in rupees) : ";
		    	cin>>per_km_rate;
		    	
		    	cout<<"Please enter surge price (in rupees) : ";
		    	cin>>surge_price;
		    	
		    	cout<<"Please enter waiting time (can be decimal) in min : ";
		    	cin>>waiting_time;
		    	
		    	cout<<"Did ride cancelled after starting the trip (1/0) : ";
		    	cin>>ride_cancelled_after_starting;
		    	
		    	cout<<"Did ride cancelled before starting the trip (1/0) : ";
		    	cin>>ride_cancelled_before_starting;
		    	
		    	//storing Total Fare
		    	float Total_Fare = FareAmount(distance, travel_time, per_km_rate, surge_price, waiting_time, 
		    												ride_cancelled_after_starting, ride_cancelled_before_starting
		    											);
		    											
		    	cout<<"Youar total amount of fare is  : ";
		    	//if Total Fare is more than base fare the return Total Fare.
				if(Total_Fare > base_fare){
		    		cout<<Total_Fare<<endl;
				}
				// If base fare is more than total fare then return base fare.
				else{
					cout<<base_fare<<endl;
				}
		    	cout<<"Please give rating to the driver(1-5) : ";
		    	cin>>driver_rating;
		    	
		    	//let's updae the driver rating and number of rides with the help of cutomer rating
		    	//we know our current driver's key is S 
		    	for(int i=0; i<size; i++){
		    		if(Arr[i].key==s){
		    			float star = Arr[i].rating * Arr[i].ride;
		    			Arr[i].ride+=1;
		    			Arr[i].rating = (star+driver_rating)/Arr[i].ride;
		    			break;
					}
				}
		    	cout<<"Thank You!"<<endl;
		}
		//when we input wrong customer type.
		else{
			cout<<"bad input"<<endl;
		}

	}

	return 0;
}
