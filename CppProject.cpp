#include<iostream>
#include<string>
using namespace std;
class Land
{
private:
	int landid;
	float area;
	string soiltype;
	string irrigationsource;
	bool wateravailability;
public:
	int getLandId()
	{
		return landid;
	}
	void setLandId(int id)
	{
		landid=id;
	}
	void getLandDetails()
	{
		cout<<"Enter the Area(acres) of the Land: ";
		cin>>area;
		cout<<"Enter the Soil Type: ";
		getline(cin>>ws,soiltype);
		cout<<"Enter the Irrigation Source: "; 
		getline(cin>>ws,irrigationsource);
		cout<<"Enter the Water Availability (0/1): ";
		cin>>wateravailability;
		cout<<endl;
	}
	void displayLandDetails()
	{
		cout<<"\n============== Land Details =============="<<endl;
		cout<<"Land ID: "<<landid<<endl;
		cout<<"Total Area(acres): "<<area<<endl;
		cout<<"Soil Type: "<<soiltype<<endl;
		cout<<"Irrigation Source: "<<irrigationsource<<endl;
		cout<<"Water Availability: "
		    <<(wateravailability?"Available":"Not Available")<<endl;
	}
	int searchLand(int id)
	{
		if(landid==id)
		{
			displayLandDetails();
			return 1;
		}
		return 0;
	}
	void updateLandDetails()
	{
		cout<<"\nEnter New Land ID: ";
		cin>>landid;
		cout<<"Enter New Area of the Land: ";
		cin>>area;
		cout<<"Enter New Soil Type: ";
		getline(cin>>ws,soiltype);
		cout<<"Enter New Irrigation Source: ";
		getline(cin>>ws,irrigationsource);
		cout<<"Enter New Water Availability (0/1): ";
		cin>>wateravailability;
		cout<<"\nLand Details Updated Successfully!"<<endl<<endl;
	}
	void modifyLandDetails()
	{
		cout<<"\nEnter New Land ID: ";
		cin>>landid;
		cout<<"Enter New Area of the Land: ";
		cin>>area;
		cout<<"Enter New Soil Type: ";
		getline(cin>>ws,soiltype);
		cout<<"Enter New Irrigation Source: ";
		getline(cin>>ws,irrigationsource);
		cout<<"Enter New Water Availability (0/1): ";
		cin>>wateravailability;
		cout<<"\nLand Details modified Successfully!"<<endl<<endl;
	}
};
class Crop
{
private:
	int cropid;
	string cropname;
	string season;
	int duration;
	float seedrate;
	float waterneed;
public:
	void getCropDetails()
	{
		cout<<"\nEnter the Crop ID: ";
		cin>>cropid;
		cout<<"Enter the Crop Name: ";
		getline(cin>>ws,cropname);
		cout<<"Enter the Season: ";
		getline(cin>>ws,season);
		cout<<"Enter the Crop Duration(months): ";
		cin>>duration;
		cout<<"Enter the Seed Rate(in Rs): ";
		cin>>seedrate;
		cout<<"Enter Amount of Water needed(in lts): ";
		cin>>waterneed;
	}
	void displayCropDetails()
	{
		cout<<"\nCrop ID: "<<cropid<<endl;
		cout<<"Crop Name: "<<cropname<<endl;
		cout<<"Season: "<<season<<endl;
		cout<<"Crop Duration: "<<duration<<" Months"<<endl;
		cout<<"Seed Rate: "<<seedrate<<" Rs"<<endl;
		cout<<"Water Need: "<<waterneed<<" lts"<<endl;
	}
   
};
int main()
{
	int n,id,choice;
	int found=0;
	cout<<"Enter Number of Lands: ";
	cin>>n;
	if(n<=0 || n>100)
	{
		cout<<"Invalid Number of Lands!";
		return 0;
	}
	Land l[100];
	for(int i=0;i<n;i++)
	{
		cout<<"\nEnter Details for Land "<<i+1<<endl;
		int newId;
		int duplicate;
		do
		{
			duplicate=0;
			cout<<"Enter Land ID: ";
			cin>>newId;
			if(l[i].getLandId() == newId)
			{
				for(int j=i;j<n-1;j++)
				{
					duplicate=1;
					cout<<"\nLand ID Already Exists!";
					cout<<"\nPlease Enter a Different Land ID.\n";
					break;
				}
			}
		} while(duplicate==1);
		l[i].setLandId(newId);
		l[i].getLandDetails();
	}
	do
	{
		cout<<"\n========== LAND MANAGEMENT SYSTEM ==========\n";
		cout<<"1.Search Land by ID"<<endl;
		cout<<"2.Display All Land Details"<<endl;
		cout<<"3.Modify land Details"<<endl;
		cout<<"4.Update Land Details"<<endl;
		cout<<"5.Add Land"<<endl;
		cout<<"6.Delete Land"<<endl;
		cout<<"7.Exit"<<endl;
		cout<<"Enter Your Choice: ";
		cin>>choice;
		switch(choice)
		{
		case 1:
		{
			cout<<"Enter Land ID to Search: ";
			cin>>id;
			found=0;
			for(int i=0; i<n; i++)
			{
				if(l[i].searchLand(id))
				{
					found=1;
					break;
				}
			}
			if(found==0)
			{
				cout<<"\nLand ID Not Found!"<<endl;
			}

			break;
		}
		case 2:
		{
			for(int i=0;i<n;i++)
			{
				l[i].displayLandDetails();
			}

			break;
		}
		case 3:
		{
			int updateid;
			int updateFound=0;
			cout<<"Enter Land ID to Modify: ";
			cin>>updateid;
			for(int i=0;i<n;i++)
			{
				if(l[i].searchLand(updateid))
				{
					l[i].modifyLandDetails();
					updateFound=1;
					break;
				}
			}
			if(updateFound==0)
			{
				cout<<"\nLand ID Not Found!"<<endl;
			}
			break;
		}
		case 4:
		{
			int updateid;
			int updateFound=0;
			cout<<"Enter Land ID to Update: ";
			cin>>updateid;
			for(int i=0;i<n;i++)
			{
				if(l[i].searchLand(updateid))
				{
					l[i].updateLandDetails();
					updateFound=1;
					break;
				}
			}
			if(updateFound==0)
			{
				cout<<"\nLand ID Not Found!"<<endl;
			}
			break;
		}
		case 5:
		{
			if(n>=100)
			{
				cout<<"\nLand List is Full! Cannot Add More."<<endl;
				break;
			}
			int newId;
			int duplicate;
			cout<<"\nEnter Details for New Land"<<endl;
			do
			{
				duplicate=0;
				cout<<"Enter Land ID: ";
				cin>>newId;
				for(int i=0;i<n;i++)
				{
					if(l[i].getLandId()==newId)
					{
						duplicate=1;
						cout<<"\nLand ID Already Exists!";
						cout<<"\nPlease Enter a Different Land ID.\n";
						break;
					}
				}
			} while(duplicate==1);
			l[n].setLandId(newId);
			l[n].getLandDetails();
			n++;
			cout<<"\nLand Added Successfully!"<<endl;
			break;
		}
		case 6:
		{
			int deleteid;
			int deletefound=0;
			if(n==0)
			{
				cout<<"\n No lands to delete!"<<endl;
				break;
			}
			cout<<"Enter landid to delete: ";
			cin>>deleteid;
			for(int i=0;i<n;i++)
			{
				if(l[i].getLandId()==deleteid)
					for(int j=1; j<n-1; j++)
					{
						l[j]=l[j+1];
					}
				n--;
				deletefound=1;
				cout<<"Land deleted successfully";
				break;
			}
			if(deletefound==0)
			{
				cout<<"\nLand Id not found"<<endl;
			}
			break;
		}
		case 7:
		{
			cout<<"Thank You for Using Land Management System!";
			break;
		}
		default:
		{
			cout<<"Invalid Choice! Try Again."<<endl;
		}
		}
	} while(choice!=7);
	Crop c;
	c.getCropDetails();
	c.displayCropDetails();
	return 0;
}
