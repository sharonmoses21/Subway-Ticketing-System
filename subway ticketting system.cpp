#include<iostream>
#include<cmath>
#include <ctime>
#include<string.h>

#define ATSTART 0
#define ATEND 1
#define BETWEEN 2
using namespace std;
int ID = 0;           /// taking ID of subway station ///
int transactionID = 100;
int ticketID = 500;
int cusID = 200;


///// class having details of each subway station /////
class subway{
private:
    int subwayID;
    string currentStationName;
    string previousStationName;
    string nextStationName;
    int travelDistanceBetweenPreviousStation;
    float travelFareBetweenPreviousStation;
    int travelTimeBetweenPreviousStation;
    int travelDistanceBetweenNextStation;
    float travelFareBetweenNextStation;
    int travelTimeBetweenNextStation;

public:
	subway() {
		subwayID = 0;
        previousStationName = "";
        currentStationName = "";
        nextStationName = "";
        travelDistanceBetweenPreviousStation = 0;
        travelFareBetweenPreviousStation = 0.0;
        travelTimeBetweenPreviousStation = 0;
        travelDistanceBetweenNextStation = 0;
        travelFareBetweenNextStation = 0.0;
        travelTimeBetweenNextStation = 0;
	}


    subway(int subwayID, string currentStationName, string previousStationName,
        string nextStationName, int travelDistanceBetweenPreviousStation,
        float travelFareBetweenPreviousStation, int travelTimeBetweenPreviousStation,
        int travelDistanceBetweenNextStation, float travelFareBetweenNextStation,
        int travelTimeBetweenNextStation){
            
            this->subwayID = subwayID;
            this->previousStationName = previousStationName;
            this->currentStationName = currentStationName;
            this->nextStationName = nextStationName;
            this->travelDistanceBetweenPreviousStation = travelDistanceBetweenPreviousStation;
            this->travelFareBetweenPreviousStation = travelFareBetweenPreviousStation;
            this->travelTimeBetweenPreviousStation = travelTimeBetweenPreviousStation;
            this->travelDistanceBetweenNextStation = travelDistanceBetweenNextStation;
            this->travelFareBetweenNextStation = travelFareBetweenNextStation;
            this->travelTimeBetweenNextStation = travelTimeBetweenNextStation;
    }

    void setTravelTimePrev(int time){
        this->travelTimeBetweenPreviousStation = time;
    }

    void setTravelTimeNext(int time){
        this->travelTimeBetweenNextStation = time;
    }

    void setTravelFarePrev(float amount){
        this->travelFareBetweenPreviousStation = amount;
    }

    void setTravelFareNext(float amount){
        this->travelFareBetweenNextStation = amount;
    }


    void setCurreneStationName(string name){
        this->currentStationName = name;
    }


    int getSubwayID(){
        return subwayID;
    }

    string getCurrentStationName(){
        return currentStationName;
    }

    string getPreviousStationName(){
        return previousStationName;
    }

    string getNextStationName(){
        return nextStationName;
    }

    int getDistanceBetweenPreviousStation(){
        return travelDistanceBetweenPreviousStation;
    }

    float getFareBetweenPreviousStation(){
        return travelFareBetweenPreviousStation;
    }

    int getTimeBetweenPreviousStation(){
        return travelTimeBetweenPreviousStation;
    }


    int getDistanceBetweenNextStation(){
        return travelDistanceBetweenNextStation;
    }

    float getFareBetweenNextStation(){
        return travelFareBetweenNextStation;
    }

    int getTimeBetweenNextStation(){
        return travelTimeBetweenNextStation;
    }
};
subway* getStationInfo(int flag);

class Date{
private:
    int day;
    int month;
    int year;
public:
    Date(){
       day = 0;
       month = 0;
       year = 0; 
    }

    Date(int day, int month, int year){
        this->day = day;
        this->month = month;
        this->year = year;
    }

    int getDay(){
        return day;
    }

    int getMonth(){
        return month;
    }

    int getYear(){
        return year;
    }

    void printDate(){
        cout << day << "/"<< month <<"/"<< year << endl;
    }
};




class Time{
    int hour;
    int min;
    int sec;
public:
    Time(){
        hour = 0;
        min = 0;
        sec = 0;
    }

    Time(int hour, int min, int sec){
        this->hour = hour;
        this->min = min;
        this->sec = sec;
    }

    int getHour(){
        return hour;
    }

    int getMin(){
        return min;
    }

    int getSec(){
        return sec;
    }

    void printTime(){
        cout << hour << ":"<< min<< ":"<< sec << endl; 
    }
};

class Node {
    subway* station;
	Node* next;
	Node* prev;

public:
	Node() {
        station = NULL;
		next = NULL;
		prev = NULL;
	}


    Node(subway* station){
        this->station = station;
    }


	void setNext(Node* next) {
		this->next = next;
	}

	Node* getNext() {
		return next;
	}

	void setPrev(Node* prev) {
		this->prev = prev;
	}

	Node* getPrev() {
		return prev;
	}

    subway* getStation(){
        return station;
    }
};




class TransactionNode{
public:
	int transactionId;
    int ticketId;
    string sourceStation;
    string targetStation;
    float totalTicketAmount;
	Date* transactionDate;
    Time* transactionTime;
    Time* DepartureTime;
    int customerID;
    string customerName;
    string customerIDCard;
	TransactionNode* next;

public:
	TransactionNode() {
        transactionId = 0;
        ticketId = 0;
        sourceStation = "";
        targetStation = "";
        totalTicketAmount = 0.0;
        customerID = 0;
        customerName = "";
        customerIDCard = "";
        DepartureTime = NULL;
		transactionDate = NULL;
		transactionTime = NULL;
        next = NULL;
	}

    TransactionNode(TransactionNode* node) {
        this->transactionId = node->transactionId;
        this->ticketId = node->ticketId;
        this->sourceStation = node->sourceStation;
        this->targetStation = node->targetStation;
        this->totalTicketAmount = node->totalTicketAmount;
        this->customerID = node->customerID;
        this->customerName = node->customerName;
        this->customerIDCard = node->customerIDCard;
        this->DepartureTime = node->DepartureTime;
		this->transactionDate = node->transactionDate;
		this->transactionTime = node->transactionTime;
		next = NULL;
	}


    TransactionNode(string sourceStation, string targetStation,
        float totalTicketAmount , string customerName, string customerIDCard){

            this->transactionId = transactionID;
            this->ticketId = ticketID;
            this->sourceStation = sourceStation;
            this->targetStation = targetStation;
            this->totalTicketAmount = totalTicketAmount;
            this->customerID = cusID;
            this->customerName = customerName;
            this->customerIDCard = customerIDCard;

            transactionID++;
            ticketID++;
            cusID++;

            time_t t = time(NULL);
            tm* tPtr = localtime(&t);
            
            transactionDate = new Date(tPtr->tm_mday, (tPtr->tm_mon)+1, (tPtr->tm_year)+1900);
            transactionTime = new Time((tPtr->tm_hour)%12, tPtr->tm_min, tPtr->tm_sec);
            DepartureTime = new Time((tPtr->tm_hour + 1)%12, tPtr->tm_min, tPtr->tm_sec);
    }


    void setSourceStation(string source){
        this->sourceStation = source;
    }

    void setTargeteStation(string target){
        this->targetStation = target;
    }

    void setPrice(float price){
        this->totalTicketAmount = price;
    }

	void setNext(TransactionNode* next) {
		this->next = next;
	}


	TransactionNode* getNext() {
		return next;
	}
  

    int getTransactionID(){
      return transactionId;
    }

    int getTicketID(){
      return ticketId;
    }

    string getSourceStation(){
        return sourceStation;
    }

    string gettargetStation(){
        return targetStation;
    }

    float getTicketAmount(){
        return totalTicketAmount;
    }

    Date* getTransactionDate(){
        return transactionDate;
    }

    Time* getTransactionTime(){
        return transactionTime;
    }

    Time* getDepartureTime(){
        return DepartureTime;
    }

    string getCustomerName(){
        return customerName;
    }

    int getCustomerID(){
        return customerID;
    }

    string getCustomerIDCard(){
        return customerIDCard;
    }

};



class List {
	Node* head;
	Node* last;
    int count;
public:
	List() {
		head = NULL;
		last = NULL;
        count = 0;
	}

    int stationType(int index){
        Node *cur = head;
        Node *prev = NULL;
        subway *station;
        for(int i=0; i< index; i++) {            
            prev = cur;
            cur->setNext(cur->getNext());
        }

        if(cur == NULL) {
            //printf("%s","at start");
            return ATEND;
        }
        else if(prev == NULL) {
            //printf("%s","at start");
            return ATSTART;
        }
        else {
            //printf("%s","between");
            return BETWEEN;
        }
    }
	void Insert(subway* station) {
        subway* obj = new subway(station->getSubwayID(), station->getCurrentStationName(),
        station->getPreviousStationName(), station->getNextStationName(), 
        station->getDistanceBetweenPreviousStation(), station->getFareBetweenPreviousStation(),
        station->getTimeBetweenPreviousStation(), station->getDistanceBetweenNextStation(), 
        station->getFareBetweenNextStation(), station->getTimeBetweenNextStation());
		
        Node* newNode = new Node(obj);
		
		newNode->setNext(NULL);
		if (head == NULL) {
			head = newNode;
		}
		else {
			newNode->setPrev(last);
			last->setNext(newNode);
		}
		last = newNode;
		ID++;

        count++;                        /// keeping track of number of stations ///
	}


    int getCount(){
        return count;
    }


    void traverse() {
        Node* ptr = head;
		while (ptr != NULL) {

            printStationInfo(ptr);
			
            ptr = ptr->getNext();
		}
	}


    //// print all stations names////
    void printStations(){
        int stationNumber = 1;
        subway* sub = NULL;
        Node* ptr = head;
		while (ptr != NULL) {
            sub = ptr->getStation();
            cout << stationNumber <<": ";
            cout << sub->getCurrentStationName() << "\n";
            stationNumber++;
			ptr = ptr->getNext();
		}
    }



    /// remaining fuctions ///

    TransactionNode* decideRoute(){
        int sourceIndex, desIndex;
        printStations();
        cout << "Enter source station number = ";
        cin >> sourceIndex;
        cout << "Enter destination station numer = ";
        cin >> desIndex;
        if((sourceIndex >0 && sourceIndex<=ID) && (desIndex > 0 && desIndex <=ID)){
            TransactionNode* node;
            if(sourceIndex == desIndex)
                cout << "Source And destination can't be same\n";
            else
                node = findDetailsBetweenSelectedCities(sourceIndex, desIndex);

            return node;
        }
        else{
            cout <<"\n Source or Destination Index is invalid.\n";
            return NULL;
        }
    }



    TransactionNode* findDetailsBetweenSelectedCities(int sourceIndex, int desIndex){
        char choice;
        subway* ptr = NULL;
        Node* departureStation = searchStation(sourceIndex);
        Node* ArrivalStation = searchStation(desIndex);
        int totalDistance = 0, totalTime = 0;
        float totalExpense = 0.0;
        string sourceStation , desStation;

        ptr = departureStation->getStation();
        sourceStation = ptr->getCurrentStationName();

        ptr = ArrivalStation->getStation();
        desStation = ptr->getCurrentStationName();

        /// if arrival station is on the right side of departure station 
        if(desIndex > sourceIndex){
            
            while(departureStation != ArrivalStation){
                ptr = departureStation->getStation();
                
                totalDistance = totalDistance + ptr->getDistanceBetweenNextStation();
                totalExpense = totalExpense + ptr->getFareBetweenNextStation();
                totalTime = totalTime + ptr->getTimeBetweenNextStation();

                departureStation = departureStation->getNext();
            }

        }

        /// if arrival station is on the left side of departure station 
        else if(desIndex < sourceIndex){
            while(departureStation != ArrivalStation){
                ptr = departureStation->getStation();
                
                totalDistance = totalDistance + ptr->getDistanceBetweenPreviousStation();
                totalExpense = totalExpense + ptr->getFareBetweenPreviousStation();
                totalTime = totalTime + ptr->getTimeBetweenPreviousStation();

                departureStation = departureStation->getPrev();
            }
        }


        cout << "Total Travel Distance from "<< sourceStation <<" to "<< desStation <<" = " << totalDistance << " KM\n";
        cout << "Total Travel Expenses from "<< sourceStation <<" to "<< desStation <<" = RM " << totalExpense << "\n";
        cout << "Total Travel Time from "<< sourceStation <<" to "<< desStation <<" = " << totalTime << " min \n"; 
        
        cout << "\n Would you like to book a ticket(y/n) = ";
        cin >> choice;
        TransactionNode* node;
        if(choice == 'y' || choice == 'Y'){
            system("clear");
            node = BookTicket(sourceStation, desStation, totalDistance, totalExpense, totalTime);    
        }
        else
            node = NULL;

        return node;
    }


    Node* searchStation(int index){
        int counter = 1;
        Node* ptr = head;
        while(ptr != NULL){
            if(counter == index)
                return ptr;
            else{
                ptr = ptr->getNext();
                counter++;
            }
        }
        return NULL;
    }


   TransactionNode* BookTicket(string sourceStation, string desStation, int totalDistance, float totalExpense,
    int totalTime){

        string cName, IDcard;
        cout << "Enter your Name = ";
        cin >> cName;
       // std::getline(std::cin, cName);
        //cin.getline(cName, 50);
        cout << "Enter your ID Card Number = ";
        // //getline(cin, IDcard);
        // cin.getline(IDcard, 50);
        cin >> IDcard;
        TransactionNode* node = new TransactionNode(sourceStation, desStation, totalExpense,cName, IDcard);
        return node;
   }

    


    void printStationInfo(Node* ptr){
            subway* sub = ptr->getStation();
            cout << "subway ID = "<<sub->getSubwayID() << "\n";
            cout << "Previous Station Name = " << sub->getPreviousStationName() << "\n";
            cout << "Current Station Name = " << sub->getCurrentStationName() << "\n";
            cout << "Next Station Name = " << sub->getNextStationName() << "\n";
            
            cout << "Travel Distance between previous Station = " << sub->getDistanceBetweenPreviousStation() << " KM\n";
            cout << "Travel Fare between previous Station = RM "  << sub->getFareBetweenPreviousStation( ) << "\n";
            cout << "Travel Time between previous Station = " << sub->getTimeBetweenPreviousStation() << " min\n";

            cout << "Travel Distance between Next Station = " <<sub->getDistanceBetweenNextStation() << " KM\n";
            cout << "Travel Fare between Next Station = RM " << sub->getFareBetweenNextStation() << "\n";
            cout << "Travel Time between Next Station = " << sub->getTimeBetweenNextStation() << " min\n\n\n";
    }



    void printSubwayStationDetails(){
        int index;
        printStations();
        cout << "Which station number details you want to see = ";
        cin >> index;
        if(index > ID || index < 1){
            cout << "Invalid index\n";
            return;
        }
        else{
            Node* ptr = searchStation(index);
            system("clear");
            printStationInfo(ptr);
        }
       
    }
    
    void insert(subway* station, int index){
        if(head != NULL){
            Node *cur = head;
            Node *prev = NULL;
            subway *station;
            for(int i=0; i< index-1; i++) {
                prev = cur;
                cur->setNext(cur->getNext());
            }
            
            if(prev == NULL){
                // insert at head
                // do not take previous statation's info
                station = getStationInfo(ATSTART);
                Node *node = new Node(station);                
                node->setNext(head);
            }
            else if(cur == NULL){
                // insert at last
                // don't takes next station's info
                station = getStationInfo(ATEND);
                Node *node = new Node(station); 
                prev->setNext(node);                
            }
            else{
                // between
                // don't get stattions's at all
                // pre -> cur -> cur->next
                // 1 -x> 2 -> 3
                // links: prev(next); station(cur->prev, next); cur(pre)
                station = getStationInfo(BETWEEN);
                Node *node = new Node(station);
                node->setNext(cur);
                node->setPrev(prev);
                prev->setNext(node);
                cur->setPrev(node);
            }
        }        
    }

    void addNewStation(subway* station, int index){
        subway* obj = new subway(station->getSubwayID(), station->getCurrentStationName(),
        station->getPreviousStationName(), station->getNextStationName(), 
        station->getDistanceBetweenPreviousStation(), station->getFareBetweenPreviousStation(),
        station->getTimeBetweenPreviousStation(), station->getDistanceBetweenNextStation(), 
        station->getFareBetweenNextStation(), station->getTimeBetweenNextStation());

        
        Node* newNode = new Node(obj);
        newNode->setNext(NULL);
        newNode->setPrev(NULL);

        if(index < 1) {
            cout<<"\nIndex should be >= 1.";
        } else if (index == 1) {
  
            /// it means insertig new node at start ///
            newNode->setNext(head);
            head->setPrev(newNode);
            head = newNode;
        } 
        else{
            
            Node* temp = head;
            for(int i = 1; i < index-1; i++) {
                if(temp != NULL) {
                temp = temp->getNext();
                }
            }

            if(temp != NULL) {
                newNode->setNext(temp->getNext());
                newNode->setPrev(temp);
                temp->setNext(newNode);
                if(newNode->getNext() != NULL)
                    newNode->getNext()->setPrev(newNode);  
            }

        }

    }



    void EditStationInformation(){
        char ch;
        int index, choice;
        printStations();
        cout << "\nWhich station number information you want to eidt = ";
        cin >> index;
        if(index > ID || index < 1){
            cout << "\nStation number not exist\n\n";
        }
        else{
            Node* ptr = searchStation(index);
            system("clear");


            subway* sub = ptr->getStation();

            //do{
                cout << "\t1: Edit travel fare between previous city\n";
                cout << "\t2: Edit travel fare between next city\n";
                cout << "\t3: Edit travel time between previous city\n";
                cout << "\t4: Edit travel time between next city\n";
                cout << "\t5: Edit station name\n";
                cout << "What you wish to edit = ";
                cin >> choice;
                switch(choice){
                    case 1:{
                        float fare;
                        cout << "\nEnter new fare between previous city = ";
                        cin >> fare;
                        sub->setTravelFarePrev(fare);
                        cout << "\nChanged Successfully\n";
                    }
                        
                        break;

                    case 2:{
                        float fare;
                        cout << "\nEnter new fare between next city = ";
                        cin >> fare;
                        sub->setTravelFareNext(fare);
                        cout << "\nChanged Successfully\n";
                    }
                        break;

                    case 3:{
                        int time;
                        cout << "\nEnter new travel time between previous city = ";
                        cin >> time;
                        sub->setTravelTimePrev(time);
                        cout << "\nChanged Successfully\n";
                    }

                        break;

                    case 4:{
                        int time;
                        cout << "\nEnter new travel time between next city = ";
                        cin >> time;
                        sub->setTravelTimeNext(time);
                        cout << "\nChanged Successfully\n";
                    }

                        break;

                    case 5:{
                        string station;
                        cout << "\nEnter new station name = ";
                        cin >> station;
                        sub->setCurreneStationName(station);
                        cout << "\nChanged Successfully\n";
                    }

                        break;

                    default:
                        cout << " Incorrect input.\n ";
                        break;
                }

            //         cout << " Do you want to do more changes (y/n)= ";
            //         cin >> ch;
            //         system("clear");
            // }while(ch =='y' || ch == 'Y');   
        }
    }



    ~List(){
        if(head != NULL){
            while(head != NULL){
                Node* temp = head;
                head = head->getNext();
                delete temp;
            }
        }   
    }

};


 

//////////////////////////////////////////////////////////////////////////////////////////////////


// TransactionNode* swap(TransactionNode* ptr1, TransactionNode* ptr2)
// {
//     TransactionNode* tmp = ptr2->getNext();
//     ptr2->setNext(ptr1);
//     ptr1->setNext(tmp);
//     return ptr2;                       /// this will be in start now //
// }




class TransactionList {
private:
	TransactionNode* head;
	TransactionNode* current;
    int tCount;
public:
	/// @brief 
	TransactionList() {
		head = NULL;
		current = NULL;
        tCount = 0;
	}

	void SetHead(TransactionNode* head) {
		this->head = head;
	}

	TransactionNode* getHead() {
		return head;
	}

	void insert(TransactionNode* ptr) {
        ptr->setNext(NULL);

        /// if this is first entry ///
        if (head == NULL) {
            head = ptr;
        }
        else {
            current->setNext(ptr);
        }
        current = ptr;
		tCount++;
	}

    int getTCount(){
        return tCount;
    }

    void sort(){
        if(tCount > 1){
            for(int i=0; i < tCount; i++){
                TransactionNode *cur = head;
                for(int j=0; j < tCount-i && cur->next != NULL; j++){                    
                    TransactionNode *next = cur->getNext();                    
                    if(strcmp((cur->getCustomerName()).c_str(),
                              (next->getCustomerName()).c_str()) > 0){
                        // case1: swapping head                        
                        if(cur == head){
                            TransactionNode *temp = new TransactionNode(cur);
                            temp->setNext(cur->getNext()->getNext());
                            cur = next;
                            cur->setNext(temp);
                            head = cur;
                        }
                        else{
                            // case2: swaping non head
                            TransactionNode *temp = new TransactionNode(cur);
                            temp->setNext(cur->getNext()->getNext());
                            cur = next;
                            cur->setNext(temp);
                        }
                    }
                }
            }
        }
        
    }

	bool displayAllTransactions() {
        int transactionNumber = 1;
		TransactionNode* temp = head;
		if (temp == NULL){
			cout << "Transaction Record is Empty.\n";
            return false;
        } else {
			while (temp != NULL) {
                cout << "\t-------- Transaction No: "<< transactionNumber <<" -------\n";

                cout << "\nTransaction ID = " << temp->getTransactionID();
                cout << "\nTicket ID = " << temp->getTicketID();
                cout << "\nSource Station = " << temp->getSourceStation();
                cout << "\nTarget Station = " << temp->gettargetStation();
                cout << "\nTotal Ticket Amount = RM " << temp->getTicketAmount();
                cout << "\nTransaction Date = ";
                (temp->getTransactionDate())->printDate();
                cout << "\nTransaction Time = " ;
                (temp->getTransactionTime())->printTime();
                cout << "\nDeparture Time = ";
                (temp->getDepartureTime())->printTime();
                cout << "\nCustomer ID = " << temp->getCustomerID();
                cout << "\nCustomer Name = " << temp->getCustomerName();
                cout << "\nCustomer ID Card = " << temp->getCustomerIDCard();

				temp = temp->getNext();
                cout <<"\n\n";
                transactionNumber++;
			}
		}

        return true;
	}


    TransactionNode* searchTransaction(string name){
        TransactionNode* ptr = head;
        if(ptr == NULL){
            cout << "Transaction Record is Empty.\n";
            return NULL;
        }else{
            while(ptr != NULL){
                if((name.compare(ptr->getCustomerName())) == 0){
                    cout << "\n Result found from database\n";
                    return ptr;
                }
                else{
                    ptr = ptr->getNext();
                }
            }
        
        cout << "This customer can't exist\n";
        return NULL;
        }
    }



    void EditCustomerTicketInfo(TransactionNode* node){
        float totalAmount;
        int choice;
        cout << "\n\t1: Edit Source Station";
        cout << "\n\t2: Edit Target Station";
        cout << "\n\t3: Edit Total Amount";
        cout << "\n Which information do you want to edit = ";
        cin >> choice;

        switch(choice){
            case 1:{
                string sourceStation;
                cout <<"\n Enter new source station = ";
                cin >> sourceStation;
                node->setSourceStation(sourceStation);
                cout << "\nChanged Successfully\n";
            }

                break;
            case 2:{
                string targetStation;
                cout <<"\n Enter new target station = ";
                cin >> targetStation;
                node->setTargeteStation(targetStation);
                cout << "\nChanged Successfully\n";
            }

                break;
            case 3:{
                float totalAmount;
                cout << "\nEnter new total price = ";
                cin >> totalAmount;
                node->setPrice(totalAmount);
                cout << "\nChanged Successfully\n";
            }

                break;
            default:
                cout <<"\n Invalid Input.\n";
                break;
        }

    }


    int findIndex(string username){
        if(head != NULL){

            int counter = 1;
            TransactionNode* ptr = head;
            while(ptr != NULL){
                if((username.compare(ptr->getCustomerName())) ==0 )
                    return counter;
                else{
                    ptr = ptr->getNext();
                    counter++;
                }
            }

        }

            return 0;
    }



    void deleteTransaction(int index){
       if (head == NULL)
        return;

        TransactionNode* temp = head;
    
        // If head needs to be removed
        if (index == 1) {
            head = temp->getNext();

            delete temp;
            return;
        }
    
        // Find previous node of the node to be deleted
        for(int i = 1; i < index-1; i++) {
            if(temp != NULL) {
                temp = temp->getNext();
            }
        }

        if (temp == NULL || temp->getNext() == NULL)
            return;
    
        // Node temp->next is the node to be deleted
        TransactionNode* next = temp->getNext()->getNext();
        
        delete temp->getNext(); 
        temp->setNext(next);
        cout << "\n Record is deleted\n";
    }

    ~TransactionList(){
        if(head != NULL){
            while(head != NULL){
                TransactionNode* temp = head;
                head = head->getNext();
                delete temp;
            }
        }   
    }
};

subway* getStationInfo(int flag){    
    string currStation, prevStation, nextStation;
    int distancePrev, distanceNext, timePrev, timeNext;
    float costPrev, costNext;
    
    cout << " Enter Current Station Name = ";
    cin >> currStation;
    cout << "Enter travel distance between previous station = ";
    cin >>  distancePrev;
    cout << "Enter travel expense between previous station = ";
    cin >> costPrev;
    cout << "Enter travel time between previous station = ";
    cin >> timePrev;

    cout << "Enter travel distance between next station = ";
    cin >> distanceNext;
    cout << "Enter travel expense between next station = ";
    cin >> costNext;
    cout << "Enter travel time between next station = ";
    cin >> timeNext;

    subway* station = new subway(ID, currStation, prevStation, nextStation, distancePrev, costPrev, 
                        timePrev, distanceNext, costNext, timeNext);
    
    return station; 
}

void DisplayTransaction(TransactionNode* temp){
    cout << "\nTransaction ID = " << temp->getTransactionID();
    cout << "\nTicket ID = " << temp->getTicketID();
    cout << "\nSource Station = " << temp->getSourceStation();
    cout << "\nTarget Station = " << temp->gettargetStation();
    cout << "\nTotal Ticket Amount = RM " << temp->getTicketAmount();
    cout << "\nTransaction Date = ";
    (temp->getTransactionDate())->printDate();
    cout << "\nTransaction Time = " ;
    (temp->getTransactionTime())->printTime();
    cout << "\nDeparture Time = ";
    (temp->getDepartureTime())->printTime();
    cout << "\nCustomer ID = " << temp->getCustomerID();
    cout << "\nCustomer Name = " << temp->getCustomerName();
    cout << "\nCustomer ID Card = " << temp->getCustomerIDCard() << "\n\n";    

}


List LoadSubwayStationDetails(){
    List obj;
    subway* station = new subway(ID, "Titiwangsa", "", "PWTC", 0, 0, 0, 4, 0.40, 3);
	obj.Insert(station);

    station = new subway(ID, "PWTC", "Titiwangsa", "Sultan Ismail", 4, 0.40, 3, 8, 0.80, 7);
	obj.Insert(station);

    station = new subway(ID, "Sultan Ismail", "PWTC", "Majlis Jamek", 8, 0.80, 7, 8, 0.80, 7);
	obj.Insert(station);

    station = new subway(ID, "Majlis Jamek", "Sultan Ismail", "Plaza Rakyat", 8, 0.80, 7, 6, 0.60, 5);
	obj.Insert(station);

    station = new subway(ID, "Plaza Rakyat", "Majlis Jamek", "Hang Tuah", 6, 0.60, 5, 10, 1.00, 9);
	obj.Insert(station);

    station = new subway(ID, "Hang Tuah", "Plaza Rakyat", "Pudu", 10, 1.00, 9, 5, 0.50, 4);
	obj.Insert(station);

    station = new subway(ID, "Pudu", "Hang Tuah", "Chan Sow Lin", 5, 0.50, 4, 5, 0.50, 4);
	obj.Insert(station);

    station = new subway(ID, "Chan Sow Lin", "Pudu", "", 5, 0.50, 4, 0, 0.0, 0);
	obj.Insert(station);

    return obj;	
}


int main(){
    char ch1,ch2;
    int choice, chAdmin, chPassenger;
    TransactionNode* node = NULL;
    TransactionList TList;
    List stations = LoadSubwayStationDetails();

    do{
        cout << "\tLogin as:\n\t\t1: Admin\n\t\t2: Passenger\n";
        cout << "Enter your choice = ";
        cin >> choice;
        system("clear");                                 /// clear the terminal
        switch (choice){
        case 1:                                          /// Login as Admin ///

            do{
                cout << "\n\t1: Add New subway Station";
                cout << "\n\t2: Edit subway Station Information";
                cout << "\n\t3: View Purchase Transactions";
                cout << "\n\t4: Sort Purchase Transactions ascending order";
                cout << "\n\t5: Search Customer Ticket Information";
                cout << "\n\t6: Edit Customer Ticket Information";
                cout << "\n\t7: Delete Customer Ticket Information";
                cout << "\n\t8: View Details of all Stations";

                cout << "\nEnter your choice = ";
                cin >> chAdmin;
                system("clear");    
                
                switch (chAdmin){
                case 1:{
                    int index;
                    stations.printStations();
                    cout << "\n Enter index number where you want to add new station = ";
                    cin >> index;
                    if(index > (stations.getCount()+1)){
                        cout << "\nYou can add upto index No: "<<stations.getCount()+1<<"\n\n";
                    }
                    else{
                        int st = stations.stationType(index);
                        subway* ptr = getStationInfo(st);
                        stations.addNewStation(ptr, index);
                        
                        cout << "\nAfter insertion:\n";
                        stations.printStations();
                    }
                }                            
         
                    break;

                case 2:                             /// admin selected option: 2 ///
                    stations.EditStationInformation();
                    break;


                case 3:
                    TList.displayAllTransactions();
                    break;


                case 4:
                    TList.sort();
                    cout << "After Sorting\n";
                    TList.displayAllTransactions();
                    break;


                case 5:{
                    string name;
                    cout <<"\n Enter customer name to search = ";
                    cin >> name;
                    node = TList.searchTransaction(name);
                    if(node != NULL){
                        DisplayTransaction(node);
                    }
                }
                    break;


                case 6:{
                    string name;
                    cout <<"\n Enter customer name to edit = ";
                    cin >> name;
                    node = TList.searchTransaction(name);
                    if(node != NULL){
                        TList.EditCustomerTicketInfo(node);
                    }
                }

                    break;


                case 7:{
                    string name;
                    int index;
                    cout <<"\n Enter customer name to delete = ";
                    cin >> name;
                    index = TList.findIndex(name);                     /// find index of given name

                    if(index > 0){
                        TList.deleteTransaction(index);
                    }
                    else
                        cout << " not found\n";
                }

                    break;

                
                case 8:
                    stations.traverse();
                    break;
                
                default:
                    cout << " Incorrect input.\n ";
                    break;
                }

                cout << " Go back to Admin page ? (y/n)= ";
                cin >> ch1;
                system("clear");
            
            }while(ch1 == 'y' || ch1 == 'Y');


            break;
        case 2:                                            /// Login as Passenger ///
        
            do{
                cout << "\n\t1: Search subway Station Details";
                cout << "\n\t2: Book Ticket";
                cout << "\n\t3: View purchase transaction history";
                cout << "\n\t4: Delete purchase transaction";
                cout << "\nEnter your choice = ";
                cin >> chPassenger;
                system("clear");    
                
                switch (chPassenger)
                {
                case 1:                             /// passenger selected option: 1 ///
                    stations.printSubwayStationDetails();
                    break;

                case 2:                             /// passenger selected option: 2 ///
                    node = stations.decideRoute();  
                    if(node == NULL){
                        cout << "Error Occur\n";
                    }
                    else{
                        TList.insert(node);             /// insert ticket record ///
                        system("clear");
                        cout << "\n Your Ticket Details are:\n\n";
                        TList.displayAllTransactions();
                    }
                    break;

                case 3:
                    TList.displayAllTransactions();
                    break;

                case 4:{
                    bool isRecordExist = TList.displayAllTransactions();
                    int index;
                    if(isRecordExist){
                        cout << "Enter transaction number that you want to delete = ";
                        cin >> index;
                        if(index > 0 || index <= TList.getTCount())
                            TList.deleteTransaction(index);
                        else
                            cout << "Invalid Index\n";
                    }
                }
                break;
                
                default:
                    cout << " Incorrect input.\n ";
                    break;
                }

                cout << " Go back to Passenger page ?  (y/n)= ";
                cin >> ch1;
                system("clear");
            
            }while(ch1 == 'y' || ch1 == 'Y');

            
            break;

        default:
            cout << " Incorrect input.\n ";
            break;
        }

            cout << " Do you want to exit (y/n)= ";
            cin >> ch2;
            system("clear");
	} while (ch2 == 'n' || ch2 == 'N');


    delete node;

    return 0;
}
