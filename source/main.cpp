#include <iostream>
#include <vector>
#include <map>
using namespace std;

class Vehicle;

class Trip {
public:
    Trip(Vehicle* vehicle, std::string pick_up_location, std::string drop_location, int departure_time)
        : vehicle(vehicle), pick_up_location(pick_up_location), drop_location(drop_location), departure_time(departure_time), booked_seats(0) {}

    // Getter functions
    Vehicle* getVehicle() const {
        return vehicle;
    }

    std::string getPickUpLocation() const {
        return pick_up_location;
    }

    std::string getDropLocation() const {
        return drop_location;
    }

    int getDepartureTime() const {
        return departure_time;
    }

    int getBookedSeats() const {
        return booked_seats;
    }

    // Setter functions
    void setVehicle(Vehicle* v) {
        vehicle = v;
    }

    void setPickUpLocation(std::string location) {
        pick_up_location = location;
    }

    void setDropLocation(std::string location) {
        drop_location = location;
    }

    void setDepartureTime(int time) {
        departure_time = time;
    }

    void setBookedSeats(int seats) {
        booked_seats = seats;
    }

private:
    Vehicle* vehicle;
    std::string pick_up_location;
    std::string drop_location;
    int departure_time;
    int booked_seats;
};

class BinaryTreeNode;

class TransportService {
public:
    TransportService(std::string name) : name(name), BSThead(nullptr) {}

    // Getter functions
    std::string getName() const {
        return name;
    }

    BinaryTreeNode* getBSTHead() const {
        return BSThead;
    }

    // Setter functions
    void setName(std::string service_name) {
        name = service_name;
    }

    void setBSTHead(BinaryTreeNode* node) {
        BSThead = node;
    }

    void addTrip(int key, Trip* trip);

private:
    std::string name;
    BinaryTreeNode* BSThead;
};

class BinaryTreeNode {
public:
    BinaryTreeNode(int departuretime = 0, Trip* tripenodeptr = nullptr, BinaryTreeNode* parentptr = nullptr)
        : leftptr(nullptr), rightptr(nullptr), parentptr(parentptr), departuretime(departuretime), tripnodeptr(tripenodeptr) {}

    // Getter functions
    BinaryTreeNode* getLeftPtr() const {
        return leftptr;
    }

    BinaryTreeNode* getRightPtr() const {
        return rightptr;
    }

    BinaryTreeNode* getParentPtr() const {
        return parentptr;
    }

    int getDepartureTime() const {
        return departuretime;
    }

    Trip* getTripNodePtr() const {
        return tripnodeptr;
    }

    // Setter functions
    void setLeftPtr(BinaryTreeNode* left) {
        leftptr = left;
    }

    void setRightPtr(BinaryTreeNode* right) {
        rightptr = right;
    }

    void setParentPtr(BinaryTreeNode* parent) {
        parentptr = parent;
    }

    void setDepartureTime(int time) {
        departuretime = time;
    }

    void setTripNodePtr(Trip* trip) {
        tripnodeptr = trip;
    }

private:
    BinaryTreeNode* leftptr;
    BinaryTreeNode* rightptr;
    BinaryTreeNode* parentptr;
    int departuretime;
    Trip* tripnodeptr;
};

class Vehicle {
public:
    Vehicle(std::string vehicle_number, int seating_capacity)
        : vehicle_number(vehicle_number), seating_capacity(seating_capacity) {}

    // Getter functions
    std::string getVehicleNumber() const {
        return vehicle_number;
    }

    int getSeatingCapacity() const {
        return seating_capacity;
    }

    // Setter functions
    void setVehicleNumber(std::string number) {
        vehicle_number = number;
    }

    void setSeatingCapacity(int capacity) {
        seating_capacity = capacity;
    }

    void addTrip(Trip* trip) {
        trips.push_back(trip);
    }

    vector<Trip*> getTrips()
    {
        return trips;
    }

private:
    std::string vehicle_number;
    int seating_capacity;

    std::vector<Trip*> trips;
};

class Location {
public:
    Location(std::string name) : name(name) {}

    // Getter functions
    std::string getName() const {
        return name;
    }

    TransportService* getServicePtr(std::string droplocation) const 
    {
        int i;

        for(i=0;i<(int)serviceptrs.size();i++)
        {
            if(serviceptrs[i]->getName() == droplocation)
            {
                return serviceptrs[i];
            }
        }
        return nullptr;
    }

    // Setter functions
    void setName(std::string location_name) {
        name = location_name;
    }

    TransportService* setServicePtr(std::string droplocation) 
    {
        TransportService* temp_service_ptr;
        temp_service_ptr = getServicePtr(droplocation);
        
        if(temp_service_ptr!= nullptr)
        {
            return temp_service_ptr;
        }
        else
        {
            temp_service_ptr = new TransportService(droplocation);
            serviceptrs.push_back(temp_service_ptr);
            return temp_service_ptr;
        }
    }

    void addTrip(Trip* trip) {
        trips.push_back(trip);
    }

    vector<Trip*> get_trips()
    {
        return trips;
    }

private:
    std::string name;
    std::vector<TransportService* >serviceptrs;
    std::vector<Trip*> trips;
};

class BinaryTree {
protected:
    BinaryTreeNode* root;

public:
    BinaryTree() : root(nullptr) {}
    BinaryTree(BinaryTreeNode* Root): root(Root) {}

    BinaryTreeNode* get_root()
    {
        return root;
    }

    void set_root(BinaryTreeNode* bst_root)
    {
        this->root = bst_root;
    }

    // int find_height(BinaryTreeNode* current)
    // {
    //     if(current==nullptr)
    //     {
    //         return 0;
    //     }
    //     else
    //     {
    //         BinaryTreeNode *left = current->getLeftPtr();
    //         BinaryTreeNode *right = current->getRightPtr();

    //         return max(find_height(left),find_height(right))+1;
    //     }
    // }
    int getHeight() const {
        // Implement this function to return the height of the tree
        BinaryTreeNode* current;
        current = root;
        if(current==nullptr)return 0;
        BinaryTree *left = new BinaryTree(current->getLeftPtr());
        BinaryTree *right = new BinaryTree(current->getRightPtr());

        return max(left->getHeight(),right->getHeight())+1;

        // int height = find_height(current);
        // return height;
    }

    int getNumberOfNodes() const {
        // Implement this function to return the number of nodes in the tree
        BinaryTreeNode* current;
        current = root;
        if(current==nullptr)return 0;
        BinaryTree *left = new BinaryTree(current->getLeftPtr());
        BinaryTree *right = new BinaryTree(current->getRightPtr());

        return (left->getNumberOfNodes()+right->getNumberOfNodes())+1;
    }
};

class BinarySearchTree : public BinaryTree {
public:
    BinarySearchTree() {}

    BinaryTreeNode* getElementWithMinimumKey() const {
        // Implement this function to return the element with the minimum key
	BinaryTreeNode* current=root;
    if(current==nullptr)return current;
    while(current->getLeftPtr()!=nullptr)current=current->getLeftPtr();
    return current;
    
    }

    BinaryTreeNode* getElementWithMaximumKey() const {
        // Implement this function to return the element with the maximum key
        
        BinaryTreeNode* current=root;
        if(current==nullptr)return current;
        while(current->getRightPtr()!=nullptr)current=current->getRightPtr();
        return current;
        // return nullptr; // Placeholder
    }

    BinaryTreeNode* searchNodeWithKey(int key) const {
        // Implement this function to search for a node with the given key or the next larger key
        
        BinaryTreeNode* current=root;
        int currentKey;
        while(current!=nullptr)
        {
            currentKey=current->getDepartureTime();
            if(key == currentKey)
            {
                return current;
            }
            else if(key<currentKey)
            {
                current=current->getLeftPtr();
            }
            else 
            {
                current=current->getRightPtr();
            }
            // else return current;
            // currentKey=current->getDepartureTime();
        }
        return nullptr;
    }

    BinaryTreeNode* getSuccessorNode(BinaryTreeNode* node) const {
        
        BinaryTreeNode *current=node;
        if (node->getRightPtr()!=NULL)
        {
            current=node->getRightPtr();
            // if(current==nullptr)return current;
            while(current->getLeftPtr()!=nullptr)current=current->getLeftPtr();
            return current;
        }

        while(current->getParentPtr()!=nullptr)
        {
            current=current->getParentPtr();
            if(current->getDepartureTime()>node->getDepartureTime())return current;
        }
        return nullptr;
    }

    BinaryTreeNode* getSuccessorNodeByKey(int key) const {
        // Implement this function to return the successor node by key
        
        BinaryTreeNode* node;
        // searching the node with the given key
        node = searchNodeWithKey(key);
        
        // finding successor with node
        return getSuccessorNode(node);
    }

    BinaryTreeNode* getPredecessorNode(BinaryTreeNode* node) const {
        // Implement this function to return the predecessor node of the given node

        BinaryTreeNode *current=node;
        if (node->getLeftPtr()!=NULL)
        {
            current=node->getLeftPtr();
            // if(current==nullptr)return current;
            while(current->getRightPtr()!=nullptr)current=current->getRightPtr();
            return current;
        }

        while(current->getParentPtr()!=nullptr)
        {
            current=current->getParentPtr();
            if(current->getDepartureTime()<node->getDepartureTime())return current;
        }
        return nullptr;
    }

    BinaryTreeNode* getPredecessorNodeByKey(int key) const {
        // Implement this function to return the predecessor node by key
        
        BinaryTreeNode* node;
        // searching the node with the given key
        node = searchNodeWithKey(key);
        
        // finding successor with node
        return getPredecessorNode(node);
    }

    BinaryTreeNode* insert_node_with_key(int key, BinaryTreeNode* temp_node)
    {
        BinaryTreeNode* current;
        BinaryTreeNode* current_parent;
        current = get_root();

        while(current!= nullptr)
        {
            current_parent = current;
            
            if(current->getDepartureTime()<key)
            {
                current = current->getRightPtr();
            }
            else if(current->getDepartureTime()>key)
            {
                current = current->getLeftPtr();
            }
            else
            {
                return current;
            }
        }

        if(current_parent->getDepartureTime()>key)
        {
            current_parent->setLeftPtr(temp_node);
        }
        else
        {
            current_parent->setRightPtr(temp_node);
        }
        temp_node->setParentPtr(current_parent);

        return temp_node;
    }

    void transplant(BinaryTreeNode* u, BinaryTreeNode* v)
    {
        if(u->getParentPtr() == nullptr)
        {
            root = v;
        }
        else if(u == u->getParentPtr()->getLeftPtr())
        {
            u->getParentPtr()->setLeftPtr(v);
        }
        else
        {
            u->getParentPtr()->setRightPtr(v);
        }

        if(v!=nullptr)
        {
            v->setParentPtr(u->getParentPtr());
        }
    }

    void delete_node(BinaryTreeNode* z)
    {
        if(z->getLeftPtr()==nullptr)
        {
            transplant(z,z->getRightPtr());
        }
        else if(z->getRightPtr()== nullptr)
        {
            transplant(z,z->getLeftPtr());
        }
        else
        {
            BinaryTreeNode* y;
            y = getPredecessorNode(z->getRightPtr());
            if(y->getParentPtr()!=z)
            {
                transplant(y,y->getRightPtr());
                y->setRightPtr(z->getRightPtr());
                y->getParentPtr()->setParentPtr(y);
            }
            transplant(z,y);
            y->setLeftPtr(z->getLeftPtr());
            y->getLeftPtr()->setParentPtr(y);
        }
    }

    vector<Trip*> get_trips_from_to_key(vector<Trip*> trips,int from_key, int to_key, BinaryTreeNode* current_node)
    {
        if(current_node == nullptr)
        {
            return trips;
        }
        else if(current_node->getDepartureTime()<from_key)
        {
            trips = get_trips_from_to_key(trips, from_key,to_key,current_node->getRightPtr());
        }
        else if(current_node->getDepartureTime()> from_key && current_node->getDepartureTime()<to_key)
        {
            trips.push_back(current_node->getTripNodePtr());
            trips = get_trips_from_to_key(trips, from_key, to_key,current_node->getLeftPtr());
            trips = get_trips_from_to_key(trips, from_key,to_key,current_node->getRightPtr());
        }
        else
        {
            trips = get_trips_from_to_key(trips,from_key,to_key,current_node->getLeftPtr());
        }

        return trips;
    }
};

class TravelDesk {
public:
    void addTrip(std::string vehicle_number, int seating_capacity, std::string pick_up_location, std::string drop_location, int departure_time) {
        // Implement this function to add a trip
        Trip* temp_trip;
        Vehicle* temp_vehicle;
        BinaryTreeNode* temp_node; 
        Location* temp_location;
        int i;

        temp_location = nullptr;
        temp_vehicle = new Vehicle(vehicle_number,seating_capacity);
        temp_trip = new Trip(temp_vehicle,pick_up_location, drop_location, departure_time);
        temp_node = new BinaryTreeNode(departure_time,temp_trip,nullptr);
        
        for(i=0;i<(int)locations.size();i++)
        {
            // check if such pick up location exists or not 
            if(locations[i]->getName() == pick_up_location)
            {
                temp_location = locations[i];
                break;
            }
        }

        if(temp_location!=nullptr)
        {
            // check if such transport service exists or not
            TransportService* temp_service_ptr;
            temp_service_ptr = temp_location->getServicePtr(drop_location);

            if(temp_service_ptr!=nullptr)
            {
                BinarySearchTree* temp_bst = new BinarySearchTree();
                BinaryTreeNode* check_node;
                temp_bst->set_root(temp_service_ptr->getBSTHead());

                // check if such a with same departure time exists or not
                check_node = temp_bst ->searchNodeWithKey(departure_time);
                if(check_node == nullptr)
                {
                    temp_bst->insert_node_with_key(departure_time,temp_node);
                    temp_location->addTrip(temp_trip);
                    temp_vehicle->addTrip(temp_trip);
                    vehicles.push_back(temp_vehicle);
                }
                else
                {
                    return;
                }
            }
            else
            {
                temp_service_ptr = new TransportService(drop_location);
                temp_service_ptr->setBSTHead(temp_node);
                temp_location->addTrip(temp_trip);
                temp_vehicle->addTrip(temp_trip);
                vehicles.push_back(temp_vehicle);
            }
        }
        else
        {
            // add new pick up location tree
            TransportService* temp_service_ptr;
            temp_location = new Location(pick_up_location);
            locations.push_back(temp_location);
            temp_service_ptr = temp_location->setServicePtr(drop_location);
            temp_service_ptr->setBSTHead(temp_node);
            temp_location->addTrip(temp_trip);
            temp_vehicle->addTrip(temp_trip);
            vehicles.push_back(temp_vehicle);
        }
    }

    std::vector<Trip*> showTrips(std::string pick_up_location, int after_time, int before_time) {
        // Implement this function to retrieve trips within a specified time range
        
        vector<Trip*> trips;
        Location* temp_location;
        temp_location = nullptr;
        int i;

        for(i=0;i<(int)locations.size();i++)
        {
            if(locations[i]->getName()== pick_up_location)
            {
                temp_location = locations[i];
            }
        }

        if(temp_location == nullptr)
        {
            return {}; // Placeholder
        }
        else
        {
            vector<Trip*> temp_trips;
            temp_trips = temp_location->get_trips();
            for(i=0;i<(int)temp_trips.size();i++)
            {
                if(temp_trips[i]->getDepartureTime()>after_time && temp_trips[i]->getDepartureTime()<before_time)
                {
                    trips.push_back(temp_trips[i]);
                }
            }
        }
        return trips;
    }
    std::vector<Trip*> showTripsbydestination(std::string pick_up_location, std::string destination,int after_time, int before_time) {
        // Implement this function to retrieve trips within a specified time range form pickup to droplocatin
        vector<Trip*> trips;
        Location* temp_location;
        temp_location = nullptr;
        int i;

        for(i=0;i<(int)locations.size();i++)
        {
            if(locations[i]->getName()== pick_up_location)
            {
                temp_location = locations[i];
            }
        }

        if(temp_location == nullptr)
        {
            return {}; // Placeholder
        }
        else
        {
            TransportService* temp_service;
            temp_service = temp_location->getServicePtr(destination);
            if(temp_service == nullptr)
            {
                return {};
            }
            BinarySearchTree* temp_bst = new BinarySearchTree;
            temp_bst->set_root(temp_service->getBSTHead());
            BinaryTreeNode* current_node;
            current_node = temp_bst->get_root();


            // if(current_node->getDepartureTime()>= after_time )
            // {
            //     while((current_node->getDepartureTime()<= before_time && current_node!=nullptr))
            //     {
            //         trips.push_back(current_node->getTripNodePtr());
            //         current_node = current_node->getRightPtr();
            //     }
            //     current_node = temp_bst->get_root()->getLeftPtr();
            //     while((current_node->getDepartureTime()>=after_time && current_node!= nullptr))
            //     {
            //         trips.push_back(current_node->getTripNodePtr());
            //         current_node = current_node->getLeftPtr();
            //     }
            // }
            // else
            // {
            //     while((current_node->getDepartureTime()<after_time && current_node!= nullptr))
            //     {
            //         current_node = current_node->getRightPtr();
            //     }
            //     BinaryTreeNode* new_temp_node;
            //     new_temp_node = current_node;
            //     while((current_node->getDepartureTime()<= before_time && current_node!=nullptr))
            //     {
            //         trips.push_back(current_node->getTripNodePtr());
            //         current_node = current_node->getRightPtr();
            //     }
            //     current_node = new_temp_node->getLeftPtr();
            //     while((current_node->getDepartureTime()<= before_time && current_node!=nullptr))
            //     {
            //         trips.push_back(current_node->getTripNodePtr());
            //         current_node = current_node->getRightPtr();
            //     }
            // }
            trips = temp_bst->get_trips_from_to_key(trips,after_time,before_time,current_node);
        }
        return trips;
    }

    Trip* bookTrip(std::string pick_up_location, std::string drop_location, std::string vehicle_number, int departure_time) {
        // Implement this function to book a trip
        Location* temp_location;
        temp_location = getLocation(pick_up_location);

        if(temp_location == nullptr)
        {
            return nullptr; // Placeholder
        }
        else
        {
            TransportService* temp_service;
            temp_service = temp_location->getServicePtr(drop_location);
            if(temp_service == nullptr)
            {
                return nullptr;
            }
            BinarySearchTree* temp_bst = new BinarySearchTree;
            temp_bst->set_root( temp_service->getBSTHead());
            BinaryTreeNode* current_node;
            current_node = temp_bst->searchNodeWithKey(departure_time);
            
            if(current_node == nullptr)
            {
                return nullptr;
            }
            else
            {
                if(current_node->getTripNodePtr()->getVehicle()->getVehicleNumber()!=vehicle_number)
                {
                    return nullptr;
                }
                int current_seats =current_node->getTripNodePtr()->getBookedSeats();
                int total_seats = current_node->getTripNodePtr()->getVehicle()->getSeatingCapacity();
                
                //book seat
                current_seats+=1;
                current_node->getTripNodePtr()->setBookedSeats(current_seats);

                if(current_seats == total_seats)
                {
                    temp_bst->delete_node(current_node);
                }
                return current_node->getTripNodePtr();
            }
        }
    }
    Location* getLocation(std::string location){
        vector<Trip*> trips;
        Location* temp_location;
        temp_location = nullptr;
        int i;

        for(i=0;i<(int)locations.size();i++)
        {
            if(locations[i]->getName()== location)
            {
                temp_location = locations[i];
            }
        }

        return temp_location;
    }

private:
    std::vector<Vehicle*> vehicles;
    std::vector<Location*> locations;
};
