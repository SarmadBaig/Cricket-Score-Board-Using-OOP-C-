#include<iostream>
#include<string>
#include<windows.h>
using namespace std;

class Player
{
 
 public:
   string Name;
   int NoBall;
   int WideBall;
   int runsScored;
   int runsConceded;
   int ballsPlayed;
   int ballsDelivered;
   int dotBalls;
   int sixes;
   int fours;
   int totover;
   int Wickets;
   
  Player()
  {
    Name="Enter";
    NoBall=0;
    WideBall=0;
    runsScored=0;
    runsConceded=0;
    ballsPlayed=0;
    ballsDelivered=0;
    dotBalls=0;
    sixes=0;
    fours=0;
    totover=0;
    Wickets=0;
  }
 	
};
class Team
{
	public:
	string teamName;
	string playersName[11];	
};

class Match
{
	public:
		Team T1,T2;
		
		Player Bow1[11],Bow2[11],Temp,Striker,nonStriker,currentBowler;
		Player BAT1[11], BAT2[11];
		int overs,totalRuns=0,totalRuns2=0,extras=0,Extras=0;
		int order=0,Balls=0;
		int wicket=10,w=0,W=0,o=0,O=0,t1=0;
		
		bool toss,temp[11];
		
	
		void setTeamName()
		{
		 cout<<"Enter Teams Name: "<<endl;
		 cout<<"Team 1 : ";
		 getline(cin,T1.teamName);
		 cout<<"Team 2 : ";
		 getline(cin,T2.teamName);
		 	
		}
		
		void setPlayerName()
		{
			cout<<"\n>> Enter "<<T1.teamName<<" Team Players\n";
			cout<<"----------------------------------"<<endl;
			for(int i=0;i<=10;i++)
			{
				cout<<i+1<<" : ";
				getline(cin,T1.playersName[i]);
			}
	
			cout<<"\n>> Enter "<<T2.teamName<<" Team Players\n";
			cout<<"----------------------------------"<<endl;
			for(int j=0;j<11;j++)
			{
				cout<<j+1<<" : ";
				getline(cin,T2.playersName[j]);
			}
			cout<<"\n>> Team is Finalized"<<endl;
			Sleep(2000);			
		}
		void Toss()
		{
			
			system("CLS");		
			int x;
			cout<<"\n>> Choose Which Team has decided to Bat first: "<<endl;
			cout<<"   Press 1 for "<<T1.teamName<<endl;
			cout<<"   Press 2 for "<<T2.teamName<<endl;
			cin>>x;
			if (x==1)
			{
			  cout<<"\t***************************************"<<endl;
			  cout<<"\t  "<<T1.teamName<<" has Decided to Bat First  "<<endl;
			  cout<<"\t***************************************"<<endl;
			  toss=true;	
			}
			else 
			{
			  cout<<"\t***************************************"<<endl;
			  cout<<"\t  "<<T2.teamName<<" has Decided to Bat First  "<<endl;
			  cout<<"\t***************************************"<<endl;
			  toss=false;
			}
			Sleep(2500);
		}
		void setOpeners()
		{     
		   	
		 system("CLS");
		 if(toss==true)
			{
			   hereB:
			   int x,y;
			   cout<<"\t\t>> "<<T1.teamName<<" Team Players <<<"<<endl;
			   for(int l=0;l<=10;l++)
			   {
				cout<<"> "<<l+1<<":  "<<T1.playersName[l]<<endl;
			   }
			   
			   cout<<"\n>> Select Openers from the above Menu"<<endl;
			   cin>>x>>y;
			   if(cin.fail())
			   {
			   	cin.clear();
			   	cin.ignore(1000,'\n');
			   	cout<<"Unknown Entry"<<endl;
			   	Sleep(500);
				system("CLS");
				goto hereB;
			   }
			   if(x<=0 || x>11 || y<=0 || y>11)
			   	{
				   cout<<"Wrong Entry!!. Enter Again"<<endl;
			 	   Sleep(1000);
			 	   system("CLS");
			 	   goto hereB;
		        }
			   else
			   for(int k=0;k<=10;k++)
			   {
			   	
			   	if(x==(k+1))
			   	{
			   	BAT1[order].Name=T1.playersName[k];
			    order++;
				}
				if(x==y)
				{
				   cout<<"Same Entry Detected!!. Enter Again"<<endl;
			 	   Sleep(1000);
			 	   system("CLS");
					goto hereB;
				}
			   	if(x!=y && y==(k+1))
			   	{
			   	BAT1[order].Name=T1.playersName[k];
			   	order++;
			    }
			   
			    
			   }
			   	   
			   cout<<"\n >>> Opening Batsman <<< "<<endl;
	           cout<<"> "<<BAT1[0].Name<<endl;
	           cout<<"> "<<BAT1[1].Name<<endl;  	
		   }
		   
		 else
			{ 
			   hereC:
			   int x,y;
			   cout<<"\t\t>> "<<T2.teamName<<" Team Players <<<"<<endl;
			   for(int l=0;l<=10;l++)
			   {
				cout<<"> "<<l+1<<":  "<<T2.playersName[l]<<endl;
			   }
			   
			   cout<<"\n>> Select Openers from the above Menu"<<endl;
			   cin>>x>>y;
			   if(cin.fail())
			   {
			   	cin.clear();
			   	cin.ignore(1000,'\n');
			   	cout<<"Unknown Entry"<<endl;
			   	Sleep(500);
				system("CLS");
				goto hereC;
			   }
			   if(x<=0 || x>11 || y<=0 || y>11)
			   	{
				   cout<<"Wrong Entry!!. Enter Again"<<endl;
			 	   Sleep(1000);
			 	   system("CLS");
			 	   goto hereC;
		        }
			   else
			   for(int k=0;k<=10;k++)
			   {
			   	
			   	if(x==(k+1))
			   	{
			   	BAT2[order].Name=T2.playersName[k];
			    order++;
				}
				if(x==y)
				{
				   cout<<"Same Entry Detected!!. Enter Again"<<endl;
			 	   Sleep(1000);
			 	   system("CLS");
					goto hereC;
				}
			   	if(x!=y && y==(k+1))
			   	{
			   	BAT2[order].Name=T2.playersName[k];
			   	order++;
			    }
			    
			   }
			   	   
			   cout<<"\n >>> Opening Batsman <<< "<<endl;
	           cout<<"> "<<BAT2[0].Name<<endl;
	           cout<<"> "<<BAT2[1].Name<<endl; 		 
			  
			} 
			 Sleep(2000);	
			 system("CLS");                                     
		}  		    
		
		void setBowler() 
		{
		 if(toss==false) 
			{
			   hereD:
			   int x;
			   cout<<"\t\t>>  "<<T1.teamName<<" Team Players  <<"<<endl;
			   for(int j=0;j<=10;j++)
			   {
				cout<<"> "<<j+1<<" : "<<T1.playersName[j]<<endl;
			   }
			   cout<<"\n>>Select Bowler from the above Menu"<<endl;
			   cin>>x;
			   if(cin.fail())
			   {
			   	cin.clear();
			   	cin.ignore(1000,'\n');
			   	cout<<"Unknown Entry"<<endl;
			   	Sleep(500);
				system("CLS");
				goto hereD;
			   }
			    if(x>11 || x<=0)
			   {
			   	 {
	           	cout<<"Unknown Entry"<<endl;
			   	Sleep(500);
				system("CLS");
				goto hereD;
			    }
			   }
			
			   for(int k=0;k<=10;k++)
			   {
			   	if(x==(k+1))
			   	{ 
				 Bow2[k].Name=T1.playersName[k];
			   	 cout<<"\n>>  Bowler  << "<<endl;
	             cout<<Bow2[k].Name<<endl;
	             currentBowler=Bow2[k];
	             break;
	            }
	           } 
		    }
		    
		 else                 //(Toss==True)
			{ 
			   hereA:
			   int x;
			   cout<<"\t\t>>  "<<T2.teamName<<" Team Players  <<"<<endl;
			   for(int l=0;l<=10;l++)
			   {
		    	  cout<<"> "<<l+1<<" : "<<T2.playersName[l]<<endl;
		       }
		     
			   cout<<"\n>>Select Bowler from the above Menu"<<endl;
			   cin>>x;
			   if(cin.fail())
			   {
			   	cin.clear();
			   	cin.ignore(1000,'\n');
			   	cout<<"Unknown Entry"<<endl;
			   	Sleep(500);
				system("CLS");
				goto hereA;
			   }
			   if(x>11 || x<=0)
			   {
			   	 {
	           	cout<<"Unknown Entry"<<endl;
			   	Sleep(500);
				system("CLS");
				goto hereA;
			    }
			   }
			   for(int q=0;q<=10;q++)
		       {
			   	if(x==(q+1))
			   	{
				   Bow1[q].Name=T2.playersName[q];
			       cout<<"\n>> Bowler  << "<<endl;
	               cout<<Bow1[q].Name<<endl;	
	               currentBowler=Bow1[q];
	               break;
	         	}
	           }          
		    }
		 Sleep(2000);	
         system("CLS");
		}
       	
	   void setOvers()
	   {
	   	 cout<<"\n>> Enter Total Overs in a Match  <<"<<endl;
	   	 cin>>overs;
	   	 Sleep(2000);	
		 system("CLS");
	   } 
       void strikeChange()
       {
       	Temp=Striker;
       	Striker=nonStriker;
       	nonStriker=Temp;
	   }
	   
	   void nextBatsman()
	   {
		 if(toss==true)	 
		 { 
		   int x;   
		   cout<<"\n>>  "<<T1.teamName<<" Team Players  <<"<<endl;
		  
		   for(int j=0;j<=10;j++)
		   { 
		      if(temp[j]== true)
		      {
			    cout<<j+1<<": "<<T1.playersName[j]<<endl;
			  }
		   }     
		   cout<<"Select the Next Batsman"<<endl;
		   cin>>x;
		   for(int k=0;k<=10;k++)
		   {
		 	 if(x==(k+1))
		 	 {
		 		BAT1[order].Name=T1.playersName[k];
		 		Striker.Name=T1.playersName[k];
		 		Striker=BAT1[order];
		 		break;
		 	 }
		   }
	     }
		 else
		 {
		   int x;   
		   cout<<"\n>>  "<<T2.teamName<<" Team Players  <<"<<endl;
		  
		   for(int j=0;j<=10;j++)
		   { 
		      if(temp[j]== true)
		      {
			    cout<<j+1<<": "<<T2.playersName[j]<<endl;
		      }
		   }      
		   cout<<"Select the Next Batsman"<<endl;
		   cin>>x;
		   for(int k=0;k<=10;k++)
		   {
		     if(x==(k+1))
		     {
		 		BAT2[order].Name=T2.playersName[k];
		 		Striker.Name=T2.playersName[k];
		 		Striker=BAT2[order];
		 		break;
		 	 }
		   }
		 }
	   }
		
	   void statsCurrent()
		{	  
            cout<<"\nName\t\t"<<Striker.Name<<"\t\t\t"<<nonStriker.Name<<endl;
			cout<<"Runs\t\t"<<Striker.runsScored<<"\t\t\t"<<nonStriker.runsScored<<endl;
			cout<<"Fours\t\t"<<Striker.fours<<"\t\t\t"<<nonStriker.fours<<endl;
			cout<<"Sixes\t\t"<<Striker.sixes<<"\t\t\t"<<nonStriker.sixes<<endl;
			cout<<"Balls\t\t"<<Striker.ballsPlayed<<"\t\t\t"<<nonStriker.ballsPlayed<<endl;				
			
			cout<<"\nBowler\t\t"<<currentBowler.Name<<endl;
			cout<<"Overs\t\t"<<currentBowler.totover<<"."<<t1-1<<endl;
			cout<<"Runs\t\t"<<currentBowler.runsConceded<<endl;
			cout<<"Wickets\t\t"<<currentBowler.Wickets<<endl;
			cout<<"Balls\t\t"<<currentBowler.ballsDelivered<<endl;
			cout<<"Dot Balls\t"<<currentBowler.dotBalls<<endl;
				
			cout<<"\n\tCurrent Striker : "<<Striker.Name<<"\t\tCurrent Bowler : "<<currentBowler.Name<<endl;
			cout<<"\n\n>>Select from the Menu<<< \n0: Dot Ball \n1: One Run \n2: Two Runs \n3: Three Runs \n4: Four";
			cout<<"\n5: Five Runs \n6: Six \n7: No ball \n8: WideBall \n9: Wicket" <<endl;
		}
		
	   void Innings1()	    
       {
         int x;
         
       	 for (int i=0;i<=10;i++)
		 {
		  temp[i]=true;
		 }
	
	   	 cout<<"Select Striker "<<endl;;
       	 cout<<"1: "<<BAT1[0].Name<<endl;
		 cout<<"2: "<<BAT1[1].Name<<endl;	  
		 cin>>x;
		 
		 if(x==1)
		 {
			Striker=BAT1[0];
			nonStriker=BAT1[1];
		 }
		 else
		 {
			Striker=BAT1[1];
	    	nonStriker=BAT1[0];
		 }
		 cout<<"\n"<<Striker.Name<<" is on Strike"<<endl;
	 	 Sleep(2500);	
		

		  
		
		while( o < overs || w <= wicket)
		{	
			for(int i=1;i<=6;i++)
			{
			 here1:
			 hereE:	
			 t1=i;
			 system("CLS");
			 
			 cout<<"Total Runs : "<<totalRuns<<"\t\tOvers : "<<o<<"."<<t1-1<<"/"<<overs<<"\t\tWickets :"<<w<<"\t\tExtras : "<<extras<<"\t\tTarget : "<<totalRuns2<<endl;
             statsCurrent();
			
			 int input;
			 cin>>input;
			 if(cin.fail())
			   {
			   	cin.clear();
			   	cin.ignore(1000,'\n');
			   	cout<<"Unknown Entry"<<endl;
			   	Sleep(500);
				system("CLS");
				goto hereE;
			   }
			  
			  
			 if (input == 0)
			 {
			   Striker.ballsPlayed++;
			   currentBowler.ballsDelivered++;
			   currentBowler.dotBalls++;
			 }
			 
			 else if (input == 1)
			 {
			   totalRuns++;
			   Striker.runsScored++;
			   Striker.ballsPlayed++;
			   currentBowler.runsConceded++;
			   currentBowler.ballsDelivered++;
			   strikeChange();	
			 }
			 
			 else if (input == 2)
			 {
			 	totalRuns=totalRuns+2;
			  	Striker.runsScored=Striker.runsScored+2;
			  	Striker.ballsPlayed++;
			  	currentBowler.runsConceded=currentBowler.runsConceded+2;
			  	currentBowler.ballsDelivered++;
			  
			 }
			  
			 else if (input == 3)
			 {
			  	totalRuns=totalRuns+3;
			  	Striker.runsScored=Striker.runsScored+3;
			  	Striker.ballsPlayed++;
			  	currentBowler.runsConceded=currentBowler.runsConceded+3;
			  	currentBowler.ballsDelivered++;
			  	strikeChange(); 	
			 }	
			 else if (input == 4)
			 {
			  	totalRuns=totalRuns+4;
			  	Striker.runsScored=Striker.runsScored+4;
			  	Striker.ballsPlayed++;
			  	Striker.fours++;
			  	currentBowler.ballsDelivered++;
			  	currentBowler.runsConceded=currentBowler.runsConceded+4; 	
			 }
			 
			 else if (input == 5)
			 {
			  	totalRuns=totalRuns+5;
			  	Striker.runsScored=Striker.runsScored+5;
			  	Striker.ballsPlayed++;
			  	currentBowler.runsConceded=currentBowler.runsConceded+5;
			  	currentBowler.ballsDelivered++;
			  	strikeChange();	 	
			 }
			
			 else if (input == 6)
			 {
			  	totalRuns=totalRuns+6;
			  	Striker.runsScored=Striker.runsScored+6;
			  	Striker.ballsPlayed++;
			  	Striker.sixes++;
			  	currentBowler.runsConceded=currentBowler.runsConceded+6;
			  	currentBowler.ballsDelivered++;	 	
			 }
			 
			 else if (input == 7)
			 {
			  	int noball;
			  	cout<<"Enter Runs Scored on  No-Ball"<<endl;
			  	cin>>noball;
			  	totalRuns=totalRuns+noball;
			  	Striker.runsScored=Striker.runsScored+(noball-1);
			  	currentBowler.runsConceded=currentBowler.runsConceded+noball;
			  	extras++;
			  	i--;
			 }
			  
			 else if (input == 8)
			 {
			  	int wideball;
			  	cout<<"Enter Runs Scored on  Wide-Ball"<<endl;
			  	cin>>wideball;
			  	totalRuns=totalRuns+wideball;
			  	currentBowler.runsConceded=currentBowler.runsConceded+wideball;
			  	extras=extras+wideball;
			  	i--;	
			 }
			  
			 else if (input == 9)
			 {
			  	currentBowler.Wickets++;
			  	Striker.ballsPlayed++;
			  	currentBowler.ballsDelivered++;
			    
				for(int k = 0 ; k <= 10 ; k++)
			    { 
			      if(Striker.Name==T1.playersName[k])
			      {
			        temp[k]=false;
				  }
				  
				  else if(nonStriker.Name == T1.playersName[k])
				  {
			    	temp[k]=false;
				  }     
			    }
			
			    for (int u = 0 ; u <= 10 ; u++)
			    { 
			     if (Striker.Name == BAT1[u].Name)
			  	  {
			  	    w++;
			  	    BAT1[u]=Striker;
				    cout<<BAT1[u].Name<<" got Out"<<endl;
				    
					if(w<10)
			  	    {
					  nextBatsman();
			        }
			        
			        else
			        {
			       	  i=7;
			      	  w=11;
				    }    
				    break;	
		          }
		        }
		        order++;
			 }  
			 
			 else
			 {
			 	cout<<"Wrong Entry!!. Enter Again"<<endl;
			 	Sleep(1000);
			 	goto here1;
			 }
	       }
		   
		   for (int i=0;i<=10;i++)
		   {
			
			 if(currentBowler.Name==Bow1[i].Name)
			   {
			  	 o++;
			  	 currentBowler.totover++;
			  	 Bow1[i]=currentBowler;
			    
			
			   	 system("CLS");
			   	 if(o == overs)
			   	 {
			   	    goto hereX;	
				 }
				 else
				 {
			   	    currentBowler.totover=0;
					cout<<"\t\t\t>>>>   Over Changing    <<<<"<<endl;
			   		setBowler();
			   	    break;
			   	 }
			   }
		   }
			strikeChange();
		    
       }
       hereX:
       	
       cout<<"\n\n>>>    Innings Finished   <<"<<endl;
       
       cout<<"\n>>  Match Statistics  <<"<<endl;
       
       cout<<"\nTotal Runs : "<<totalRuns<<"\t\tOvers : "<<o<<"."<<6-t1<<"/"<<overs<<"\t\tWickets :"<<w<<"\t\tExtras : "<<extras<<"\t\tTarget : "<<totalRuns2<<endl;
       cout<<"\n>>"<<T1.teamName<<" Batting Statistics"<<endl;
       cout<<"\nName\t\tRuns\t\tBalls\t\tSixes\t\tFours "<<endl;
       cout<<"-----------------------------------------------------------------"<<endl;
       for(int m=0;m<=10;m++)
       {
       	if (BAT1[m].Name != "Enter")
       	cout<<BAT1[m].Name<<"\t\t"<<BAT1[m].runsScored<<"\t\t"<<BAT1[m].ballsPlayed<<"\t\t"<<BAT1[m].sixes<<"\t\t"<<BAT1[m].fours<<endl;
	   }
	   
	   cout<<"\n>>"<<T2.teamName<<" Bowling Statistics"<<endl;
	   cout<<"\n\nName\t\tRuns\t\tBalls\t\tWickets\t\tOvers "<<endl;
	   cout<<"\n-------------------------------------------------------------"<<endl;
       for(int m=0;m<=10;m++)
       {
       	if (Bow1[m].Name != "Enter")
        cout<<Bow1[m].Name<<"\t\t"<<Bow1[m].runsConceded<<"\t\t"<<Bow1[m].ballsDelivered<<"\t\t"<<Bow1[m].Wickets<<"\t\t"<<Bow1[m].totover<<endl;
	   } 
	   
	   order=0;
	   Sleep(7000);
	   system("CLS");
      }
      
      void Innings2()	    
       {
       	 int x;
       	 
       	 for (int i=0;i<=10;i++)
		   {
		   	 temp[i]=true;
		   }
	
	   	 cout<<"Select Striker "<<endl;;
       	 cout<<"1: "<<BAT2[0].Name<<endl;
		 cout<<"2: "<<BAT2[1].Name<<endl;	  
		 cin>>x;
		 
		 if(x==1)
		 {
			Striker=BAT2[0];
			nonStriker=BAT2[1];
		 }
		 else
		 {
			Striker=BAT2[1];
	    	nonStriker=BAT2[0];
		 }
	 	 Sleep(2500);	
		 system("CLS");

		 cout<<"\n"<<Striker.Name<<" is on Strike"<<endl; 
		
		while( O < overs|| W <= wicket)
		{	
			for(int i=1;i<=6;i++)
			{
			
			 hereA:	
			 t1=i;
			 hereF:
			 system("CLS");
			 
			 cout<<"Total Runs : "<<totalRuns2<<"\t\tOvers : "<<O<<"."<<t1-1<<"/"<<overs<<"\t\tWickets :"<<W<<"\t\tExtras : "<<Extras<<"\t\tTarget : "<<totalRuns<<endl;
			 statsCurrent();
			
			 int input;
			 cin>>input;
			if(cin.fail())
			  {
	        	cin.clear();
			   	cin.ignore(1000,'\n');
			   	cout<<"Unknown Entry"<<endl;
			   	Sleep(500);
				system("CLS");
				goto hereF;
			   }
			 if (input == 0)
			 {
			   Striker.ballsPlayed++;
			   currentBowler.ballsDelivered++;
			   currentBowler.dotBalls++;
			 }
			 
			 else if (input == 1)
			 {
			   totalRuns2++;
			   Striker.runsScored++;
			   Striker.ballsPlayed++;
			   currentBowler.runsConceded++;
			   currentBowler.ballsDelivered++;
			   strikeChange();	
			 }
			 
			 else if (input == 2)
			 {
			 	totalRuns2=totalRuns2+2;
			  	Striker.runsScored=Striker.runsScored+2;
			  	Striker.ballsPlayed++;
			  	currentBowler.runsConceded=currentBowler.runsConceded+2;
			  	currentBowler.ballsDelivered++;
			  
			 }
			  
			 else if (input == 3)
			 {
			  	totalRuns2=totalRuns2+3;
			  	Striker.runsScored=Striker.runsScored+3;
			  	Striker.ballsPlayed++;
			  	currentBowler.runsConceded=currentBowler.runsConceded+3;
			  	currentBowler.ballsDelivered++;
			  	strikeChange(); 	
			 }	
			 else if (input == 4)
			 {
			  	totalRuns2=totalRuns2+4;
			  	Striker.runsScored=Striker.runsScored+4;
			  	Striker.ballsPlayed++;
			  	Striker.fours++;
			  	currentBowler.ballsDelivered++;
			  	currentBowler.runsConceded=currentBowler.runsConceded+4; 	
			 }
			 
			 else if (input == 5)
			 {
			  	totalRuns2=totalRuns2+5;
			  	Striker.runsScored=Striker.runsScored+5;
			  	Striker.ballsPlayed++;
			  	currentBowler.runsConceded=currentBowler.runsConceded+5;
			  	currentBowler.ballsDelivered++;
			  	strikeChange();	 	
			 }
			
			 else if (input == 6)
			 {
			  	totalRuns2=totalRuns2+6;
			  	Striker.runsScored=Striker.runsScored+6;
			  	Striker.ballsPlayed++;
			  	Striker.sixes++;
			  	currentBowler.runsConceded=currentBowler.runsConceded+6;
			  	currentBowler.ballsDelivered++;	 	
			 }
			 
			 else if (input == 7)
			 {
			  	int noball;
			  	cout<<"Enter Runs Scored on  No-Ball"<<endl;
			  	cin>>noball;
			  	totalRuns2=totalRuns2+noball;
			  	Striker.runsScored=Striker.runsScored+(noball-1);
			  	Striker.ballsPlayed++;
			  	currentBowler.runsConceded=currentBowler.runsConceded+noball;
			  	Extras++;
			  	
			 }
			  
			 else if (input == 8)
			 {
			  	int wideball;
			  	cout<<"Enter Runs Scored on  Wide-Ball"<<endl;
			  	cin>>wideball;
			  	totalRuns2=totalRuns2+wideball;
			  	currentBowler.runsConceded=currentBowler.runsConceded+wideball;
			  	Extras=Extras+wideball;
			  	i--;	
			 }
			  
			 else if (input == 9)
			 {
			  	currentBowler.Wickets++;
			  	Striker.ballsPlayed++;
			  	currentBowler.ballsDelivered++;
			    
				for(int k = 0 ; k <= 10 ; k++)
			    { 
			      if(Striker.Name==T2.playersName[k])
			      {
			        temp[k]=false;
				  }
				  
				  else if(nonStriker.Name == T2.playersName[k])
				  {
			    	temp[k]=false;
				  }     
			    }
			
			    for (int u = 0 ; u <= 10 ; u++)
			    { 
			     if (Striker.Name == BAT2[u].Name)
			  	  {
			  	    W++;
			  	    BAT2[u]=Striker;
				    cout<<BAT2[u].Name<<" got Out"<<endl;
				    
					if(W<10)
			  	    {
					  nextBatsman();
			        }
			        
			        else
			        {
			       	  i=7;
			      	  W=11;
				    }    
				    break;	
		          }
		        }
		        order++;
			 } 
			 else
			 {
			 	cout<<"Wrong Entry!!. Enter Again"<<endl;
			 	goto hereA;
			 } 
	       }
		   
		   for (int i=0;i<=10;i++)
		   {
			
			 if(currentBowler.Name==Bow2[i].Name)
			   {
			  	 O++;
			  	 currentBowler.totover++;
			  	 Bow2[i]=currentBowler;
			     //currentBowler.ballsDelivered++;
			
			   	 system("CLS");
			   	 if(O==overs)
			   	 {
			   	    goto hereY;	
				 }
				 else
				 {
			   	    currentBowler.totover=0;
					cout<<"\t\t\t>>>>   Over Changing    <<<<"<<endl;
			   		setBowler();
			   	    break;
			   	 }
			   }
		   }
			strikeChange();
		    
       }
       hereY:
       	
       cout<<"\n\n>>>    Innings Finished   <<"<<endl;
       
       cout<<"\n>>  Match Statistics  <<"<<endl;
       cout<<"\nTotal Runs : "<<totalRuns2<<"\t\tOvers : "<<O<<"."<<6-t1<<"/"<<overs<<"\t\tWickets :"<<W<<"\t\tExtras : "<<Extras<<"\t\tTarget : "<<totalRuns<<endl; 
       cout<<"\n>>"<<T2.teamName<<" Batting Statistics"<<endl;
       cout<<"\nName\t\tRuns\t\tBalls\t\tSixes\t\tFours "<<endl;
       cout<<"-----------------------------------------------------------------"<<endl;
       for(int m=0;m<=10;m++)
       {
       	if(BAT2[m].Name != "Enter")
        cout<<BAT2[m].Name<<"\t\t"<<BAT2[m].runsScored<<"\t\t"<<BAT2[m].ballsPlayed<<"\t\t"<<BAT2[m].sixes<<"\t\t"<<BAT2[m].fours<<endl;
	   }
	   
	   cout<<"\n>>"<<T1.teamName<<" Bowling Statistics"<<endl;
	   cout<<"\n\nName\t\tRuns\t\tBalls\t\tWickets\t\tOvers "<<endl;
	   cout<<"\n-------------------------------------------------------------"<<endl;
       for(int m=0;m<=10;m++)
       {
       	if(Bow2[m].Name != "Enter")
        cout<<Bow2[m].Name<<"\t\t"<<Bow2[m].runsConceded<<"\t\t"<<Bow2[m].ballsDelivered<<"\t\t"<<Bow2[m].Wickets<<"\t\t"<<Bow2[m].totover<<endl;
	   }
	   order=0;
	   Sleep(7000);
	   system("CLS");
    
   }
    void startMatch()
	{
		system("CLS");
	    setOvers();	
	    
	    if(toss == true)
		{
		  setOpeners();
		  setBowler();
		  Innings1();
		  
		  toss=false;
		  setOpeners();
		  setBowler();
		  Innings2();
		  
		  if(totalRuns>totalRuns2)
		  {
		  	cout<<"\nCongratulations!!!  Team "<<T1.teamName<<" . You Won the Match By "<<wicket-w<<" Wickets & "<<totalRuns-totalRuns2<<" Runs       :)"<<endl;
		  }
		  else
		  {
		  	cout<<"\nCongratulations!!!  Team "<<T2.teamName<<" . You Won the Match By "<<wicket-W<<" Wickets    :)"<<endl;
		  }
		}
		else
		{
		  setOpeners();
		  setBowler();
		  Innings2();
		  
		  toss=true;
		  setOpeners();
		  setBowler();
		  Innings1();
		  
		  if(totalRuns2>totalRuns)
		  {
		  	cout<<"\nCongratulations!!!  Team "<<T2.teamName<<" . You Won the Match By "<<wicket-W<<" Wickets & "<<totalRuns2-totalRuns<<" Runs  :)"<<endl;
		  }	
		  else
		  {
		  	cout<<"\nCongratulations!!!  Team "<<T1.teamName<<" . You Won the Match By "<<wicket-w<<" Wickets     :)"<<endl;
		  }
		}
			
	  }	
};	  	

int main()
{	
	Match t1;
	t1.setTeamName();
	t1.setPlayerName();
	t1.Toss();
    t1.startMatch();
} 







