#include<iostream>
#include<string>
using namespace std;
class Land{
    private:
        int landid;
        float area;
        string soiltype;
        string irrigationsource;
        bool wateravailability;
    public:
        void getLandDetails(){
            cout<<"Enter Land ID: ";
            cin>>landid;
            cout<<"Enter the Area of the Land: ";
            cin>>area;
            cout<<"Enter the Soil Type: ";
            getline(cin>>ws,soiltype);
            cout<<"Enter the Irrigation Source: ";
            getline(cin>>ws,irrigationsource);
            cout<<"Enter the Water Availability (0/1): ";
            cin>>wateravailability;
            cout<<endl;
        }
        void displayLandDetails(){
            cout<<"/n============== Land Details =============="<<endl;
            cout<<"Land ID: "<<landid<<endl;
            cout<<"Total Area: "<<area<<endl;
            cout<<"Soil Type: "<<soiltype<<endl;
            cout<<"Irrigation Source: "<<irrigationsource<<endl;
            cout<<"Water Availability: "<<(wateravailability?"Available":"Not Available")<<endl;
        }
        int searchLand(int id){
            if(landid==id){
                displayLandDetails();
                return 1;
            }
            return 0;
        }
        void updateLandDetails(){
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
            cout<<"\nLand Details Updated Successfully!"<<endl;
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
                found=1;
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
            case 4:
                cout<<"Thank You for Using Land Management System!";
                break;
            default:
                cout<<"Invalid Choice! Try Again."<<endl;
        }
    }while(choice!=4);
    return 0;
}
