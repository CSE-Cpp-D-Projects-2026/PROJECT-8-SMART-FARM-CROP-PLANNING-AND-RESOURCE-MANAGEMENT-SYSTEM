
#include<iostream>
#include<string>
using namespace std;
class Land{
    private:
        int landID;
        float area;
        string soiltype;
        string irrigationsource;
        int wateravailability;

    public:
      //------------Gets land details------------//
        void getLandDetails(){
            cout<<"Enter Land ID: ";
            cin>>landID;
            cout<<"Enter the Area of the Land: ";
            cin>>area;
            cout<<"Enter the Soil Type: ";
            getline(cin>>ws,soiltype);
            cout<<"Enter the Irrigation Source: ";
            getline(cin>>ws,irrigationsource);
            cout<<"Enter the Water Availability (0/1): ";
            cin>>wateravailability;
        }
           //-------------displays land details----------------//
        void displayLandDetails(){
            cout<<"\n============== Land Details ==============\n";
            cout<<"Land ID: "<<landID<<endl;
            cout<<"Total Area: "<<area<<endl;
            cout<<"Soil Type: "<<soiltype<<endl;
            cout<<"Irrigation Source: "<<irrigationsource<<endl;

            if(wateravailability==1){
                cout<<"Water Availability: Available"<<endl;
            }
            else{
                cout<<"Water Availability: Not Available"<<endl;
            }
        }
         //--------------------searches the land--------------------//
        int searchLand(int id)
        {
            if(landID==id){
                displayLandDetails();
                return 1;
            }
            return 0;
        }

       //---------------Updates the land details after modifying---------//
        int updateLandDetails(int id)
        {
            if(landID==id){
                cout<<"\n========== Update Land Details ==========\n";
                cout<<"Enter New Area: ";
                cin>>area;
                cout<<"Enter New Soil Type: ";
                getline(cin>>ws,soiltype);
                cout<<"Enter New Irrigation Source: ";
                getline(cin>>ws,irrigationsource);
                cout<<"Enter New Water Availability (0/1): ";
                cin>>wateravailability;
                cout<<"\nLand Details Updated Successfully!"<<endl;

                return 1;
            }
            return 0;
        }
};

int main()
{
    int n,id,choice;
    int found=0;
    cout<<"Enter Number of Lands: ";
    cin>>n;
    if(n<=0)
    {
        cout<<"Invalid Number of Lands!";
        return 0;
    }
  //------------------Gets the land details ------------------//
    Land l[n];

    for(int i=0;i<n;i++)
    {
        cout<<"\nEnter Details for Land "<<i+1<<endl;
        l[i].getLandDetails();
    }
    do
    {
        cout<<"\n========== LAND MANAGEMENT SYSTEM ==========\n";
        cout<<"1. Search Land by ID"<<endl;
        cout<<"2. Display All Land Details"<<endl;
        cout<<"3. Update Land Details"<<endl;
        cout<<"4. Exit"<<endl;

        cout<<"Enter Your Choice: ";
        cin>>choice;

        switch(choice)
        {
            case 1:
            {
                cout<<"Enter Land ID to Search: ";
                cin>>id;

                found=0;

                for(int i=0;i<n;i++)
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
                cout<<"Enter Land ID to Update: ";
                cin>>id;
                found=0;
                for(int i=0;i<n;i++)
                {
                    if(l[i].updateLandDetails(id))
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
            case 4:
                cout<<"Thank You for Using Land Management System!";
                break;

            default:
                cout<<"Invalid Choice! Try Again."<<endl;
        }

    }while(choice!=4);
    return 0;
}
